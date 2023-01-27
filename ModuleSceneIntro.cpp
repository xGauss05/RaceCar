#include "Application.h"
#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"
#include "ModulePlayer.h"
#include "PhysBody3D.h"
#include "PhysVehicle3D.h"

void Circuit::Start() {
	obstacle.SetPos(0, 1, 30);
	obstacle.size.Set(10, 10, 10);
	obstacle.color.Set(0, 255, 255);
	obstacleBody = App->physics->AddBody(obstacle, 1000);

	sandTerrain.SetPos(0, -1, 0);
	sandTerrain.size.Set(100, 2, 100);
	sandTerrain.color.Set(1, 0.945f, 0.686f);
	sandTerrainBody = App->physics->AddBody(sandTerrain, 0);

}

void Circuit::Render() {
	obstacleBody->GetTransform(obstacle.transform.M);
	obstacle.Render();

	sandTerrainBody->GetTransform(sandTerrain.transform.M);
	sandTerrain.Render();
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
	
	float speed = 0.5f;

	//if (App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_REPEAT) cameraPositionAroundPlayer += App->camera->Y * speed;
	//if (App->input->GetKey(SDL_SCANCODE_LSHIFT) == KEY_REPEAT) cameraPositionAroundPlayer -= App->camera->Y * speed;

	//if (App->input->GetKey(SDL_SCANCODE_W) == KEY_REPEAT) cameraPositionAroundPlayer -= App->camera->Z * speed;
	//if (App->input->GetKey(SDL_SCANCODE_S) == KEY_REPEAT) cameraPositionAroundPlayer += App->camera->Z * speed;

	//if (App->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT) cameraPositionAroundPlayer -= App->camera->X * speed;
	//if (App->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT) cameraPositionAroundPlayer += App->camera->X * speed;

	vec3 newPosCamera = App->player->vehicle->GetPosition();
	
	/*if(App->input->GetKey(SDL_SCANCODE_LSHIFT) == KEY_REPEAT)
		speed = 8.0f * dt;*/

	//App->camera->LookAt(newPosCamera);

	mat4x4 vehicleTransform;

	App->player->vehicle->GetTransform(vehicleTransform.M);

	vec3 frontDirectionVehicle;
	frontDirectionVehicle.x = vehicleTransform.M[8];
	frontDirectionVehicle.y = vehicleTransform.M[9];
	frontDirectionVehicle.z = vehicleTransform.M[10];

	newPosCamera -= frontDirectionVehicle * 25;
	newPosCamera.y += 10;
	newPosCamera += cameraPositionAroundPlayer;

	//newPosCamera.y += 10;

	//newPosCamera += App->camera->Z * 15;

	App->camera->Position = newPosCamera;

	App->camera->LookAt(App->player->vehicle->GetPosition());

	circuit.Render();

	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
}

