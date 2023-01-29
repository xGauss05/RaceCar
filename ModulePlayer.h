#pragma once
#include "Module.h"
#include "Globals.h"
#include "p2Point.h"


struct PhysVehicle3D;

#define MAX_ACCELERATION 1000.0f
#define TURN_DEGREES 15.0f * DEGTORAD
#define BRAKE_POWER 2.0f
#define BONUS_TIME 10.0f
#define MAX_LAPS 3

class ModulePlayer : public Module
{
public:
	ModulePlayer(bool start_enabled = true);
	virtual ~ModulePlayer();

	bool Start();
	update_status Update(float dt);
	void OnCollision(PhysBody3D* body1, PhysBody3D* body2);
	bool CleanUp();
	void ResetGame();
	void Respawn();
	void IncreaseLap();
	void ChangeFriction(float friction);
	
public:

	Cube vehicleSensor;
	PhysBody3D* vehicleSensorBody;

	PhysVehicle3D* vehicle;
	float turn;
	float acceleration;
	float brake;
	float mass;
	float timer;
	
	bool activeGravity = true;
	bool activeImpulse = true;
	bool activeFriction = true;
	bool canJump = true;
	bool playTurboFx = false;
	bool playJumpFx = false;
	bool firstcPoint, secondcPoint, thirdcPoint, fourthcPoint, fifthcPoint;
	
	uint laps;
	vec3 respawnPosition;
	mat4x4 respawnTransform;

private:
	int checkpointFx, turboFx, honkFx, jumpFx, deathFx,
		goalFx, winFx;
	
	uint lastTerrain = 0;
};