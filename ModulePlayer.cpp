#include "Globals.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "Primitive.h"
#include "PhysVehicle3D.h"
#include "PhysBody3D.h"

ModulePlayer::ModulePlayer(bool start_enabled) : Module(start_enabled), vehicle(NULL)
{
	turn = acceleration = brake = 0.0f;
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");

	checkpointFx = App->audio->LoadFx("Assets/Audio/Sfx/checkpoint.wav");
	VehicleInfo car;
	// Car properties ----------------------------------------
	car.chassis_size.Set(2, 2, 4);
	car.chassis_offset.Set(0, 1.5, 0);
	car.mass = 500.0f;
	car.suspensionStiffness = 15.88f;
	car.suspensionCompression = 0.83f;
	car.suspensionDamping = 0.88f;
	car.maxSuspensionTravelCm = 1000.0f;
	car.frictionSlip = 5000;
	car.maxSuspensionForce = 6000.0f;
	mass = car.mass;
	// Wheel properties ---------------------------------------
	float connection_height = 1.2f;
	float wheel_radius = 0.6f;
	float wheel_width = 0.5f;
	float suspensionRestLength = 1.2f;

	// Don't change anything below this line ------------------

	float half_width = car.chassis_size.x*0.5f;
	float half_length = car.chassis_size.z*0.5f;
	
	vec3 direction(0,-1,0);
	vec3 axis(-1,0,0);
	
	car.num_wheels = 4;
	car.wheels = new Wheel[4];

	// FRONT-LEFT ------------------------
	car.wheels[0].connection.Set(half_width - 0.3f * wheel_width, connection_height, half_length - wheel_radius);
	car.wheels[0].direction = direction;
	car.wheels[0].axis = axis;
	car.wheels[0].suspensionRestLength = suspensionRestLength;
	car.wheels[0].radius = wheel_radius;
	car.wheels[0].width = wheel_width;
	car.wheels[0].front = true;
	car.wheels[0].drive = true;
	car.wheels[0].brake = false;
	car.wheels[0].steering = true;

	// FRONT-RIGHT ------------------------
	car.wheels[1].connection.Set(-half_width + 0.3f * wheel_width, connection_height, half_length - wheel_radius);
	car.wheels[1].direction = direction;
	car.wheels[1].axis = axis;
	car.wheels[1].suspensionRestLength = suspensionRestLength;
	car.wheels[1].radius = wheel_radius;
	car.wheels[1].width = wheel_width;
	car.wheels[1].front = true;
	car.wheels[1].drive = true;
	car.wheels[1].brake = false;
	car.wheels[1].steering = true;

	// REAR-LEFT ------------------------
	car.wheels[2].connection.Set(half_width - 0.3f * wheel_width, connection_height, -half_length + wheel_radius);
	car.wheels[2].direction = direction;
	car.wheels[2].axis = axis;
	car.wheels[2].suspensionRestLength = suspensionRestLength;
	car.wheels[2].radius = wheel_radius;
	car.wheels[2].width = wheel_width;
	car.wheels[2].front = false;
	car.wheels[2].drive = false;
	car.wheels[2].brake = true;
	car.wheels[2].steering = false;

	// REAR-RIGHT ------------------------
	car.wheels[3].connection.Set(-half_width + 0.3f * wheel_width, connection_height, -half_length + wheel_radius);
	car.wheels[3].direction = direction;
	car.wheels[3].axis = axis;
	car.wheels[3].suspensionRestLength = suspensionRestLength;
	car.wheels[3].radius = wheel_radius;
	car.wheels[3].width = wheel_width;
	car.wheels[3].front = false;
	car.wheels[3].drive = false;
	car.wheels[3].brake = true;
	car.wheels[3].steering = false;

	vehicleSensor.SetPos(10, 10, 0);
	vehicleSensor.size.Set(5, 5, 5);
	vehicleSensor.color.Set(0, 0, 1);
	vehicleSensorBody = App->physics->AddBody(vehicleSensor, 1);
	vehicleSensorBody->SetAsSensor(true);
	vehicleSensorBody->collision_listeners.add(this);
	vehicleSensorBody->id = 1;

	vehicle = App->physics->AddVehicle(car);
	vehicle->SetPos(0, 5, 0);
	
	vehicle->collision_listeners.add(this);
	
	App->physics->AddConstraintP2P(*vehicle, *vehicleSensorBody, { 0, 0, 0 }, { 0, 0, 0 });

	timer = 60;
	canJump = true;
	laps = 0;
	firstcPoint = secondcPoint = thirdcPoint = fourthcPoint = fifthcPoint = false;
	return true;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	return true;
}

// Update: draw background
void ModulePlayer::ResetGame() 
{
	mat4x4 baseTranform;
	vehicle->SetTransform(baseTranform.M);
	vehicle->SetAngularVelocity(0, 0, 0);
	vehicle->SetLinearVelocity(0, 0, 0);
	vehicle->SetPos(0, 5, 0);
	timer = 60;
	laps = 0;
	firstcPoint = secondcPoint = thirdcPoint = fourthcPoint = fifthcPoint = false;
}

void ModulePlayer::IncreaseLap() 
{
	laps++;
	firstcPoint = secondcPoint = thirdcPoint = fourthcPoint = fifthcPoint = false;
}

void ModulePlayer::ChangeFriction(float friction)
{
	vehicle->vehicle->m_wheelInfo[0].m_frictionSlip = friction;
	vehicle->vehicle->m_wheelInfo[1].m_frictionSlip = friction;
	vehicle->vehicle->m_wheelInfo[2].m_frictionSlip = friction;
	vehicle->vehicle->m_wheelInfo[3].m_frictionSlip = friction;
}

update_status ModulePlayer::Update(float dt)
{
	turn = acceleration = brake = 0.0f;
	
	vehicle->GetTransform(vehicleSensor.transform.M);
	vehicleSensorBody->SetTransform(vehicleSensor.transform.M);

	if (App->physics->debug){ vehicleSensor.Render(); }

	if (timer >= 0) timer -= dt;
	
	if (timer <= 0) ResetGame();

	if (App->input->GetKey(SDL_SCANCODE_R) == KEY_DOWN) {
		ResetGame();
	}
	if (App->input->GetKey(SDL_SCANCODE_O) == KEY_DOWN) {
		mass += 10.0f;
		vehicle->vehicle->getRigidBody()->setMassProps(mass, vehicle->vehicle->getRigidBody()->getLocalInertia());
	}

	if (App->input->GetKey(SDL_SCANCODE_L) == KEY_DOWN) 
	{
		mass -= 10.0f;
		vehicle->vehicle->getRigidBody()->setMassProps(mass, vehicle->vehicle->getRigidBody()->getLocalInertia());
	}

	if (App->input->GetKey(SDL_SCANCODE_I) == KEY_DOWN)
	{
		if (activeImpulse) {
			activeImpulse = false;
		}
		else {
			activeImpulse = true;
		}
	}

	if (App->input->GetKey(SDL_SCANCODE_K) == KEY_DOWN)
	{
		if (activeFriction) {
			activeFriction = false;
			ChangeFriction(0.0f);
		}
		else {
			activeFriction = true;
			switch (lastTerrain) {
			case 0:
				ChangeFriction(2.0f);
				break;
			case 1:
				ChangeFriction(5000.0f);
				break;
			}
			
		}
	}

	if (App->input->GetKey(SDL_SCANCODE_J) == KEY_DOWN)
	{
		if (activeGravity) {
			activeGravity = false;
		}
		else {
			activeGravity = true;
		}
	}

	if (!activeGravity) {
		App->physics->ModifyGravity({ 0, 0,0 });
	}
	

	if (App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_DOWN)
	{
		if (activeImpulse) {
			float jump = 60000 / (dt * 1000);
			LOG("dt = %f; jump = %f", dt, jump);
			vehicle->Push(0, jump, 0);
		}
	}

	float turbo = 0;
	if (App->input->GetKey(SDL_SCANCODE_LSHIFT) == KEY_REPEAT) {
		if (activeImpulse)
			turbo = 500;
	}

	if(App->input->GetKey(SDL_SCANCODE_W) == KEY_REPEAT)
	{
		acceleration += MAX_ACCELERATION + turbo;
		//brake = BRAKE_POWER;
	}

	if(App->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT)
	{
		if(turn < TURN_DEGREES)
			turn +=  TURN_DEGREES;
	}

	if(App->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT)
	{
		if(turn > -TURN_DEGREES)
			turn -= TURN_DEGREES;
	}

	if(App->input->GetKey(SDL_SCANCODE_S) == KEY_REPEAT)
	{
		//brake = BRAKE_POWER;
		acceleration += -MAX_ACCELERATION;
		brake = turbo;
	}

	

	vehicle->ApplyEngineForce(acceleration);
	vehicle->Turn(turn);
	vehicle->Brake(brake);

	vehicle->Render();

	char title[80];
	sprintf_s(title, "Sandy Shores Circuit | %.1f Km/h | Time: %.f s | Lap: %d / 3", vehicle->GetKmh(), timer, laps);
	
	if (laps >= MAX_LAPS)
	{
		sprintf_s(title, "Sandy Shores Circuit | %.1f Km/h | Time: %.f s | Lap: %d / %d | Con fucking gratulations." , vehicle->GetKmh(), timer, laps, MAX_LAPS);
	}
	App->window->SetTitle(title);
	return UPDATE_CONTINUE;
}

void ModulePlayer::OnCollision(PhysBody3D* body1, PhysBody3D* body2) 
{
	//LOG("OnCollision vehicle");
	
	switch (body2->id) {
	case 2: // Death field
		LOG("Deathfield collision");
		ResetGame();
		break;
	case 3: // 1st checkpoint
		LOG("1st checkpoint.");
		if (!firstcPoint) 
		{
			//App->audio->PlayFx(checkpointFx);
			timer += BONUS_TIME;
			firstcPoint = true;
		}
		break;
	case 4:	//Sand
		lastTerrain = 0;
		if (activeFriction)
			ChangeFriction(2.0f);
		break;
	case 5:	//Asphalt
		lastTerrain = 1;
		if (activeFriction)
			ChangeFriction(5000.0f);
		break;
	case 6: // 2nd checkpoint
		LOG("2nd checkpoint.");
		if (!secondcPoint && firstcPoint) 
		{
			//App->audio->PlayFx(checkpointFx);
			timer += BONUS_TIME;
			secondcPoint = true;
		}
		break;
	case 7:
		LOG("3rd checkpoint.");
		if (!thirdcPoint && secondcPoint && firstcPoint)
		{
			//App->audio->PlayFx(checkpointFx);
			timer += BONUS_TIME;
			thirdcPoint = true;
		}
		break;
	case 8:
		LOG("4th checkpoint.");
		if (!fourthcPoint && thirdcPoint && secondcPoint && firstcPoint)
		{
			//App->audio->PlayFx(checkpointFx);
			timer += BONUS_TIME;
			fourthcPoint = true;
		}
		break;
	case 9:
		LOG("5th checkpoint.");
		if (!fifthcPoint && fourthcPoint && thirdcPoint && secondcPoint && 
			firstcPoint)
		{
			//App->audio->PlayFx(checkpointFx);
			timer += BONUS_TIME;
			fifthcPoint = true;
		}
		break;
	case 10:
		LOG("Goal checkpoint");
		IncreaseLap();
		break;
	default: break;
	}
}

