#include "Application.h"
#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"
#include "ModulePlayer.h"
#include "PhysBody3D.h"
#include "PhysVehicle3D.h"

void Circuit::Start() {

	sandTerrain.SetPos(0, 0, 0);
	sandTerrain.size.Set(125, 2, 175);
	sandTerrain.color.Set(1, 0.945f, 0.686f);
	sandTerrainBody = App->physics->AddBody(sandTerrain, 0);
	sandTerrainBody->id = 4;


	sandPath.SetPos(0, 1, 0);
	sandPath.size.Set(125, 0.9f, 175);
	sandPath.color.Set(0.989f, 0.873f, 0.451f);

	columnGoalLeft.SetPos(-5, 3, 0);
	columnGoalLeft.size.Set(0.1f, 10, 0.1f);
	columnGoalLeft.color.Set(0.2f, 0.2f, 0.2f);

	columnGoalRight.SetPos(5, 3, 0);
	columnGoalRight.size.Set(0.1f, 10, 0.1f);
	columnGoalRight.color.Set(0.2f, 0.2f, 0.2f);

	goalTopPart.SetPos(0, 7, 0);
	goalTopPart.size.Set(10, 2, 0.1f);
	goalTopPart.color.Set(1, 0, 0);

	// left stairs
	{
		Color color;
		color.Set(0.510f, 0.435f, 0.463f);

		stairs1.SetPos(0, 0.5f, 87.5f);
		stairs1.size.Set(70, 2, 30);
		stairs1.color = color;
		stairsBody1 = App->physics->AddBody(stairs1, 0);
		stairsBody1->id = 5;

		stairs2.SetPos(0, 17.5f, 122.5f);
		stairs2.size.Set(30, 2, 70);
		stairs2.SetRotation(-30, { 1, 0, 0 });
		stairs2.color = color;
		stairsBody2 = App->physics->AddBody(stairs2, 0);
		stairsBody2->id = 5;

		stairs3.SetPos(0, 35, 168);
		stairs3.size.Set(30, 2, 30);
		stairs3.color = color;
		stairsBody3 = App->physics->AddBody(stairs3, 0);
		stairsBody3->id = 5;

		stairs4.SetPos(15, 35, 183);
		stairs4.size.Set(42.426f, 2, 42.426f);
		stairs4.SetRotation(45, { 0, 1, 0 });
		stairs4.color = color;
		stairsBody4 = App->physics->AddBody(stairs4, 0);
		stairsBody4->id = 5;

		stairs5.SetPos(30, 35, 198);
		stairs5.size.Set(30, 2, 30);
		stairs5.color = color;
		stairsBody5 = App->physics->AddBody(stairs5, 0);
		stairsBody5->id = 5;

		stairs6.SetPos(60, 35, 198);
		stairs6.size.Set(30, 2, 30);
		stairs6.color = color;
		stairsBody6 = App->physics->AddBody(stairs6, 0);
		stairsBody6->id = 5;

		stairs7.SetPos(90, 35, 198);
		stairs7.size.Set(30, 2, 30);
		stairs7.color = color;
		stairsBody7 = App->physics->AddBody(stairs7, 0);
		stairsBody7->id = 5;

		stairs8.SetPos(105, 35, 183);
		stairs8.size.Set(42.426f, 2, 42.426f);
		stairs8.SetRotation(45, { 0, 1, 0 });
		stairs8.color = color;
		stairsBody8 = App->physics->AddBody(stairs8, 0);
		stairsBody8->id = 5;

		stairs9.SetPos(120, 35, 168);
		stairs9.size.Set(30, 2, 30);
		stairs9.color = color;
		stairsBody9 = App->physics->AddBody(stairs9, 0);
		stairsBody9->id = 5;
	}

	// corridor
	{
		Color color;
		color.Set(0.510f, 0.435f, 0.463f);

		corridor1.SetPos(120, 35, 118);
		corridor1.size.Set(30, 2, 70);
		corridor1.color = color;
		corridorBody1 = App->physics->AddBody(corridor1, 0);
		corridorBody1->id = 5;

		/*corridor2.SetPos(120, 35, 83);
		corridor2.size.Set(30, 4, 5);
		corridor2.SetRotation(30, { 1, 0, 0 });
		corridor2.color = color;
		corridorBody2 = App->physics->AddBody(corridor2, 0);
		corridorBody2->id = 5;*/

		corridor3.SetPos(120, 35, 0);
		corridor3.size.Set(30, 2, 70);
		corridor3.color = color;
		corridorBody3 = App->physics->AddBody(corridor3, 0);
		corridorBody3->id = 5;

		/*corridor4.SetPos(120, 35, -35);
		corridor4.size.Set(30, 4, 5);
		corridor4.SetRotation(30, { 1, 0, 0 });
		corridor4.color = color;
		corridorBody4 = App->physics->AddBody(corridor4, 0);
		corridorBody4->id = 5;*/

		corridor5.SetPos(120, 35, -118);
		corridor5.size.Set(30, 2, 70);
		corridor5.color = color;
		corridorBody5 = App->physics->AddBody(corridor5, 0);
		corridorBody5->id = 5;

		corridor6.SetPos(120, 35, -168);
		corridor6.size.Set(30, 2, 30);
		corridor6.color = color;
		corridorBody6 = App->physics->AddBody(corridor6, 0);
		corridorBody6->id = 5;

		corridor7.SetPos(105, 35, -183);
		corridor7.size.Set(42.426f, 2, 42.426f);
		corridor7.SetRotation(45, { 0, 1, 0 });
		corridor7.color = color;
		corridorBody7 = App->physics->AddBody(corridor7, 0);
		corridorBody7->id = 5;

		corridor8.SetPos(90, 35, -198);
		corridor8.size.Set(30, 2, 30);
		corridor8.color = color;
		corridorBody8 = App->physics->AddBody(corridor8, 0);
		corridorBody8->id = 5;


		corridor9.SetPos(60, 35, -198);
		corridor9.size.Set(30, 2, 30);
		corridor9.color = color;
		corridorBody9 = App->physics->AddBody(corridor9, 0);
		corridorBody9->id = 5;

		corridor10.SetPos(30, 35, -198);
		corridor10.size.Set(30, 2, 30);
		corridor10.color = color;
		corridorBody10 = App->physics->AddBody(corridor10, 0);
		corridorBody10->id = 5;

		corridor11.SetPos(15, 35, -183);
		corridor11.size.Set(42.426f, 2, 42.426f);
		corridor11.SetRotation(45, { 0, 1, 0 });
		corridor11.color = color;
		corridorBody11 = App->physics->AddBody(corridor11, 0);
		corridorBody11->id = 5;

		corridor12.SetPos(0, 35, -168);
		corridor12.size.Set(30, 2, 30);
		corridor12.color = color;
		corridorBody12 = App->physics->AddBody(corridor12, 0);
		corridorBody12->id = 5;

		corridor13.SetPos(0, 35, -118);
		corridor13.size.Set(30, 2, 70);
		corridor13.color = color;
		corridorBody13 = App->physics->AddBody(corridor13, 0);
		corridorBody13->id = 5;

	}

	// walls
	{
		Color color;
		color.Set(0.510f, 0.435f, 0.463f);

		wall1.SetPos(105, 37.5f, 0);
		wall1.size.Set(2, 5, 70);
		wall1.color = color;
		wallBody1 = App->physics->AddBody(wall1, 0);
		wallBody1->id = 5;

		wall2.SetPos(135, 37.5f, 0);
		wall2.size.Set(2, 5, 70);
		wall2.color = color;
		wallBody2 = App->physics->AddBody(wall2, 0);
		wallBody2->id = 5;

	}

	// sensors
	{
		bottomSensor.SetPos(0, -10, 0);
		bottomSensor.size.Set(1000, 2, 1000);
		bottomSensor.color.Set(0.8f, 0.3f, 0.2f, 0.1f);
		bottomSensorBody = App->physics->AddBody(bottomSensor, 0);
		bottomSensorBody->SetAsSensor(true);
		bottomSensorBody->collision_listeners.add(App->scene_intro);
		bottomSensorBody->id = 2;

		cpoint1Sensor.SetPos(0, 7, 100);
		cpoint1Sensor.size.Set(30, 10, 3);
		cpoint1Sensor.color.Set(0.8f, 0.3f, 0.2f, 0.1f);
		cpoint1SensorBody = App->physics->AddBody(cpoint1Sensor, 0);
		cpoint1SensorBody->SetAsSensor(true);
		cpoint1SensorBody->id = 3;

		cpoint2Sensor.SetPos(120, 40, 100);
		cpoint2Sensor.size.Set(30, 10, 3);
		cpoint2Sensor.color.Set(0.8f, 0.3f, 0.2f, 0.1f);
		cpoint2SensorBody = App->physics->AddBody(cpoint2Sensor, 0);
		cpoint2SensorBody->SetAsSensor(true);
		cpoint2SensorBody->id = 6;

		cpoint3Sensor.SetPos(120, 40, 0);
		cpoint3Sensor.size.Set(30, 10, 3);
		cpoint3Sensor.color.Set(0.8f, 0.3f, 0.2f, 0.1f);
		cpoint3SensorBody = App->physics->AddBody(cpoint3Sensor, 0);
		cpoint3SensorBody->SetAsSensor(true);
		cpoint3SensorBody->id = 7;

		cpoint4Sensor.SetPos(120, 40, -100);
		cpoint4Sensor.size.Set(30, 10, 3);
		cpoint4Sensor.color.Set(0.8f, 0.3f, 0.2f, 0.1f);
		cpoint4SensorBody = App->physics->AddBody(cpoint4Sensor, 0);
		cpoint4SensorBody->SetAsSensor(true);
		cpoint4SensorBody->id = 8;

		cpoint5Sensor.SetPos(0, 40, -100);
		cpoint5Sensor.size.Set(30, 10, 3);
		cpoint5Sensor.color.Set(0.8f, 0.3f, 0.2f, 0.1f);
		cpoint5SensorBody = App->physics->AddBody(cpoint5Sensor, 0);
		cpoint5SensorBody->SetAsSensor(true);
		cpoint5SensorBody->id = 9;

		cpointGoalSensor.SetPos(0, 0, 0);
		cpointGoalSensor.size.Set(10, 10, 3);
		cpointGoalSensor.color.Set(0.8f, 0.3f, 0.2f, 0.1f);
		cpointGoalSensorBody = App->physics->AddBody(cpointGoalSensor, 0);
		cpointGoalSensorBody->SetAsSensor(true);
		cpointGoalSensorBody->id = 10;
	}

	// door 1
	{
		Color color;
		color.Set(1, 1, 1);

		vec3 position;
		position = { 60, 42, -183 };

		column1Left.SetPos(position.x, position.y, position.z);
		column1Left.size.Set(0.1f, 10, 0.1f);
		column1Left.color = color;
		columnBody1Left = App->physics->AddBody(column1Left, 0);
		columnBody1Left->SetAsSensor(true);
		columnBody1Left->id = 5;

		door1Left.SetPos(position.x, position.y, position.z - 5);
		door1Left.size.Set(1, 10, 14);
		door1Left.color = color;
		doorBody1Left = App->physics->AddBody(door1Left, 100);
		doorBody1Left->id = 5;
		
		App->physics->AddConstraintHinge(*doorBody1Left, *columnBody1Left, { 0, 0, 7 }, { 0, 0, 0 }, { 0, 1, 0 }, { 0, 1, 0 });


		position = { 60, 42, -213 };

		column1Right.SetPos(position.x, position.y, position.z);
		column1Right.size.Set(0.1f, 10, 0.1f);
		column1Right.color = color;
		columnBody1Right = App->physics->AddBody(column1Right, 0);
		columnBody1Right->SetAsSensor(true);
		columnBody1Right->id = 5;

		door1Right.SetPos(position.x, position.y, position.z + 5);
		door1Right.size.Set(1, 10, 14);
		door1Right.color = color;
		doorBody1Right = App->physics->AddBody(door1Right, 100);
		doorBody1Right->id = 5;

		App->physics->AddConstraintHinge(*doorBody1Right, *columnBody1Right, { 0, 0, -7 }, { 0, 0, 0 }, { 0, 1, 0 }, { 0, 1, 0 });

	}

	// cacti
	{
		Color color;
		color.Set(0.239f, 0.522f, 0.192f);

		cactus1.SetPos(10, 3, 20);
		cactus1.size.Set(2, 6, 2);
		cactus1.color = color;
		cactusBody1 = App->physics->AddBody(cactus1, 0);
		cactusBody1->id = 5;

		cactus2.SetPos(-10, 3, -20);
		cactus2.size.Set(2, 6, 2);
		cactus2.color = color;
		cactusBody2 = App->physics->AddBody(cactus2, 0);
		cactusBody2->id = 5;

		cactus3.SetPos(20, 3, -20);
		cactus3.size.Set(2, 6, 2);
		cactus3.color = color;
		cactusBody3 = App->physics->AddBody(cactus3, 0);
		cactusBody3->id = 5;

		cactus4.SetPos(-10, 3, 20);
		cactus4.size.Set(2, 6, 2);
		cactus4.color = color;
		cactusBody4 = App->physics->AddBody(cactus4, 0);
		cactusBody4->id = 5;

		cactus5.SetPos(-30, 3, 20);
		cactus5.size.Set(2, 6, 2);
		cactus5.color = color;
		cactusBody5 = App->physics->AddBody(cactus5, 0);
		cactusBody5->id = 5;
	}

	// desert balls
	{
		Color color;
		color.Set(0.545f, 0.443f, 0.361f);

		desertBall1.SetPos(15, 3, 10);
		desertBall1.radius = 2;
		desertBall1.color = color;
		desertBallBody1 = App->physics->AddBody(desertBall1, 1);
		desertBallBody1->id = 5;

		desertBall2.SetPos(-15, 3, 14);
		desertBall2.radius = 2;
		desertBall2.color = color;
		desertBallBody2 = App->physics->AddBody(desertBall2, 1);
		desertBallBody2->id = 5;

		desertBall3.SetPos(11, 3, -29);
		desertBall3.radius = 2;
		desertBall3.color = color;
		desertBallBody3 = App->physics->AddBody(desertBall3, 1);
		desertBallBody3->id = 5;
	}

	elmoTexture = App->renderer3D->LoadTexture("Assets/Textures/elmo.jpg");
	door1Texture = App->renderer3D->LoadTexture("Assets/Textures/open_door1.jpg");
	door2Texture = App->renderer3D->LoadTexture("Assets/Textures/open_door2.jpg");
	thisIsFine = App->renderer3D->LoadTexture("Assets/Textures/this_is_fine.jpg");
}

void Circuit::Render() {

	App->renderer3D->DrawTexture(elmoTexture, { -500,-8,-500 }, -1000, false);
	App->renderer3D->DrawTexture(door1Texture, { 60, 42, -213 }, 10, true);
	App->renderer3D->DrawTexture(door2Texture, { 0,10,10 }, 10, true);
	App->renderer3D->DrawTexture(thisIsFine, { -10,10,10 }, 10, true, 90.0f);

	bottomSensorBody->GetTransform(bottomSensor.transform.M);
	bottomSensor.Render();

	if (!App->player->firstcPoint) 
	{
		cpoint1SensorBody->GetTransform(cpoint1Sensor.transform.M);
		cpoint1Sensor.Render();
	}

	if (!App->player->secondcPoint)
	{
		cpoint2SensorBody->GetTransform(cpoint2Sensor.transform.M);
		cpoint2Sensor.Render();
	}

	if (!App->player->thirdcPoint)
	{
		cpoint3SensorBody->GetTransform(cpoint3Sensor.transform.M);
		cpoint3Sensor.Render();
	}

	if (!App->player->fourthcPoint)
	{
		cpoint4SensorBody->GetTransform(cpoint4Sensor.transform.M);
		cpoint4Sensor.Render();
	}

	if (!App->player->fifthcPoint)
	{
		cpoint5SensorBody->GetTransform(cpoint5Sensor.transform.M);
		cpoint5Sensor.Render();
	}

	if (App->player->firstcPoint && App->player->secondcPoint && App->player->thirdcPoint &&
		App->player->fourthcPoint && App->player->fifthcPoint)
	{
		cpointGoalSensorBody->GetTransform(cpointGoalSensor.transform.M);
		cpointGoalSensor.Render();
	}

	// for static objects
	sandTerrain.Render();

	columnGoalLeft.Render();
	columnGoalRight.Render();
	goalTopPart.Render();

	sandPath.Render();

	// stairs
	{
		stairs1.Render();

		stairs2.Render();

		stairs3.Render();

		stairs4.Render();

		stairs5.Render();

		stairs6.Render();

		stairs7.Render();

		stairs8.Render();

		stairs9.Render();
	}

	// corridors
	{
		corridor1.Render();

		//corridor2.Render();

		corridor3.Render();

		//corridor4.Render();

		corridor5.Render();

		corridor6.Render();

		corridor7.Render();

		corridor8.Render();

		corridor9.Render();

		corridor10.Render();

		corridor11.Render();

		corridor12.Render();

		corridor13.Render();
	}

	// walls
	{
		wall1.Render();

		wall2.Render();
	}

	// door1
	{
		doorBody1Left->GetTransform(door1Left.transform.M);
		door1Left.Render();
		column1Left.Render();

		doorBody1Right->GetTransform(door1Right.transform.M);
		door1Right.Render();
		column1Right.Render();
	}

	// cacti
	{
		cactusBody1->GetTransform(cactus1.transform.M);
		cactus1.Render();

		cactusBody2->GetTransform(cactus2.transform.M);
		cactus2.Render();
		
		cactusBody3->GetTransform(cactus3.transform.M);
		cactus3.Render();

		cactusBody4->GetTransform(cactus4.transform.M);
		cactus4.Render();

		cactusBody5->GetTransform(cactus5.transform.M);
		cactus5.Render();
	}

	// desert ball
	{
		desertBallBody1->GetTransform(desertBall1.transform.M);
		desertBall1.Render();

		desertBallBody2->GetTransform(desertBall2.transform.M);
		desertBall2.Render();

		desertBallBody3->GetTransform(desertBall3.transform.M);
		desertBall3.Render();


	}
}

// --------------------------------------------------

ModuleSceneIntro::ModuleSceneIntro(bool start_enabled) : Module(start_enabled)
{
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;
	App->audio->PlayMusic("Assets/Audio/Bgm/bgm.ogg");
	App->camera->Move(vec3(1.0f, 1.0f, 0.0f));
	App->camera->LookAt(vec3(0, 0, 0));

	cameraPositionAroundPlayer = vec3(0, 0, 0);

	circuit.Start();

	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// Update
update_status ModuleSceneIntro::Update(float dt)
{
	/*Plane p(0, 1, 0, 0);
	p.axis = true;
	p.Render();*/

	if (!App->camera->cameraDebug) {
		vec3 newPosCamera = App->player->vehicle->GetPosition();

		mat4x4 vehicleTransform;

		App->player->vehicle->GetTransform(vehicleTransform.M);

		vec3 frontDirectionVehicle;
		frontDirectionVehicle.x = vehicleTransform.M[8];
		frontDirectionVehicle.y = vehicleTransform.M[9];
		frontDirectionVehicle.z = vehicleTransform.M[10];

		newPosCamera -= frontDirectionVehicle * 25;
		newPosCamera.y += 10;
		newPosCamera += cameraPositionAroundPlayer;

		App->camera->Position = newPosCamera;

		App->camera->LookAt(App->player->vehicle->GetPosition());
	}

	circuit.Render();

	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
	if (body2->id == 2) {
		LOG("Cube touched vehicle");
	}
}

