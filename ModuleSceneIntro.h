#pragma once
#include "Module.h"
#include "p2DynArray.h"
#include "Globals.h"
#include "Primitive.h"

#define MAX_SNAKE 2

struct PhysBody3D;
struct PhysMotor3D;

struct Circuit {
	void Start();

	void Render();
	// Void pit (hell)
	Cube bottomSensor;
	PhysBody3D* bottomSensorBody;

	// 1st checkpoint
	Cube cpoint1Sensor;
	PhysBody3D* cpoint1SensorBody;

	// 2nd checkpoint
	Cube cpoint2Sensor;
	PhysBody3D* cpoint2SensorBody;

	// 3rd checkpoint
	Cube cpoint3Sensor;
	PhysBody3D* cpoint3SensorBody;

	// 4th checkpoint
	Cube cpoint4Sensor;
	PhysBody3D* cpoint4SensorBody;

	// 5th checkpoint
	Cube cpoint5Sensor;
	PhysBody3D* cpoint5SensorBody;

	// Goal checkpoint
	Cube cpointGoalSensor;
	PhysBody3D* cpointGoalSensorBody;

	// goal
	Cube columnGoalLeft;
	Cube columnGoalRight;
	Cube goalTopPart;

	// sand area
	Cube sandTerrain;
	PhysBody3D* sandTerrainBody;

	// stairs
	Cube stairs1;
	PhysBody3D* stairsBody1;

	Cube stairs2;
	PhysBody3D* stairsBody2;

	Cube stairs3;
	PhysBody3D* stairsBody3;

	Cube stairs4;
	PhysBody3D* stairsBody4;

	Cube stairs5;
	PhysBody3D* stairsBody5;
	
	Cube stairs6;
	PhysBody3D* stairsBody6;
	
	Cube stairs7;
	PhysBody3D* stairsBody7;

	Cube stairs8;
	PhysBody3D* stairsBody8;

	Cube stairs9;
	PhysBody3D* stairsBody9;

	// corridor
	Cube corridor1;
	PhysBody3D* corridorBody1;

	/*Cube corridor2;
	PhysBody3D* corridorBody2;*/

	Cube corridor3;
	PhysBody3D* corridorBody3;

	/*Cube corridor4;
	PhysBody3D* corridorBody4;*/

	Cube corridor5;
	PhysBody3D* corridorBody5;

	Cube corridor6;
	PhysBody3D* corridorBody6;

	Cube corridor7;
	PhysBody3D* corridorBody7;

	Cube corridor8;
	PhysBody3D* corridorBody8;

	Cube corridor9;
	PhysBody3D* corridorBody9;

	Cube corridor10;
	PhysBody3D* corridorBody10;

	Cube corridor11;
	PhysBody3D* corridorBody11;

	Cube corridor12;
	PhysBody3D* corridorBody12;

	Cube corridor13;
	PhysBody3D* corridorBody13;

	// walls 
	Cube wall1;
	PhysBody3D* wallBody1;

	Cube wall2;
	PhysBody3D* wallBody2;

	Cube wall3;
	PhysBody3D* wallBody3;

	Cube wall4;
	PhysBody3D* wallBody4;

	Cube wall5;
	PhysBody3D* wallBody5;

	Cube wall6;
	PhysBody3D* wallBody6;

	Cube wall7;
	PhysBody3D* wallBody7;

	Cube wall8;
	PhysBody3D* wallBody8;

	// door
	Cube door1Left;
	PhysBody3D* doorBody1Left;

	Cube column1Left;
	PhysBody3D* columnBody1Left;

	Cube door1Right;
	PhysBody3D* doorBody1Right;

	Cube column1Right;
	PhysBody3D* columnBody1Right;

	// path
	Cube sandPath;

	// cacti
	Cube cactus1;
	PhysBody3D* cactusBody1;

	Cube cactus2;
	PhysBody3D* cactusBody2;

	Cube cactus3;
	PhysBody3D* cactusBody3;

	Cube cactus4;
	PhysBody3D* cactusBody4;

	Cube cactus5;
	PhysBody3D* cactusBody5;

	Sphere desertBall1;
	PhysBody3D* desertBallBody1;

	Sphere desertBall2;
	PhysBody3D* desertBallBody2;

	Sphere desertBall3;
	PhysBody3D* desertBallBody3;

	int textureTest;
};

class ModuleSceneIntro : public Module
{
public:
	ModuleSceneIntro(bool start_enabled = true);
	~ModuleSceneIntro();

	bool Start();
	update_status Update(float dt);
	bool CleanUp();

	void OnCollision(PhysBody3D* body1, PhysBody3D* body2);

public:

	Circuit circuit;

	vec3 cameraPositionAroundPlayer;


	/*
	PhysBody3D* pb_snake[MAX_SNAKE];
	Sphere s_snake[MAX_SNAKE];

	PhysBody3D* pb_snake2[MAX_SNAKE];
	Sphere s_snake2[MAX_SNAKE];
	*/

	/*PhysBody3D* pb_chassis;
	Cube p_chassis;

	PhysBody3D* pb_wheel;
	Cylinder p_wheel;

	PhysBody3D* pb_wheel2;
	Cylinder p_wheel2;

	PhysMotor3D* left_wheel;
	PhysMotor3D* right_wheel;*/
};
