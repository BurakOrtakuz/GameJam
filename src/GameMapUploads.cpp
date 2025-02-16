#include <glm/gtc/matrix_transform.hpp>
#include <CollisionManager.hpp>
#include <graphic/Graphic.hpp>
#include <ResourceManager.hpp>
#include <TagManager.hpp>
#include <glm/glm.hpp>
#include <glad/glad.h>
#include <Utils.hpp>
#include <Game.hpp>
#include <iostream>


void	Game::uploadSimpleTextures()
{
	ResourceManager::loadTexture("assets/Simple_textures/Ground/Simple_Left_corner_grass.png", true, "ground_texture_corner_L");	//0
	ResourceManager::loadTexture("assets/Simple_textures/Ground/Simple_Middle_grass.png", true, "ground_texture_middle");			//1
	ResourceManager::loadTexture("assets/Simple_textures/Ground/Simple_Right_corner_grass.png", true, "ground_texture_corner_R");	//2
	ResourceManager::loadTexture("assets/Simple_textures/Ground/Simple_soil_txt.png", true, "ground_texture_soil");					//3
	ResourceManager::loadTexture("assets/Simple_textures/Key/Key1.png", true, "key1");												//4
	ResourceManager::loadTexture("assets/Simple_textures/Key/Key2.png", true, "key2");												//5
	ResourceManager::loadTexture("assets/Simple_textures/Key/Keywhole.png", true, "keywhole");										//6
	ResourceManager::loadTexture("assets/Simple_textures/Obsticles/Sarkit.png", true, "sarkit");									//7
	ResourceManager::loadTexture("assets/Simple_textures/Obsticles/Spikes.png", true, "spikes");									//8
	ResourceManager::loadTexture("assets/Simple_textures/Platform/Platform_corner_L.png", true, "platform_corner_L");				//9
	ResourceManager::loadTexture("assets/Simple_textures/Platform/Platform_corner_R.png", true, "platform_corner_R");				//10
	ResourceManager::loadTexture("assets/Simple_textures/Platform/Platform_mid.png", true, "platform_mid");							//11
	ResourceManager::loadTexture("assets/Simple_textures/Wall/Simple_wall_wine.png", true, "wall_wine");							//12
	ResourceManager::loadTexture("assets/Simple_textures/Wall/Walltexture.png", true, "wall_texture");							//13
	ResourceManager::loadTexture("assets/Obsticles/Acid_frames/Af7.png", true, "asit7");								//14
	ResourceManager::loadTexture("assets/Door/Doorframe.png", true, "door1");								//14
	ResourceManager::loadTexture("assets/Door/DoorL.png", true, "door2");								//14
	ResourceManager::loadTexture("assets/Door/DoorR.png", true, "door3");								//14
	
}


void	Game::uploadBackground()
{
	ResourceManager::loadTexture("assets/Wall_textures/Walltexture.png", true, "background");	//0
}

/* ********************* [v] PLATFORM UPLOADS [v] ********************* */

void	Game::upload_Platform()
{
	ResourceManager::loadTexture("assets/Platform/Platform_L_M.png", true, "platform_L_M");			//1
	ResourceManager::loadTexture("assets/Platform/Platform_L.png", true, "platform_L");				//2
	ResourceManager::loadTexture("assets/Platform/Platform_M.png", true, "platform_M");				//3
	ResourceManager::loadTexture("assets/Platform/Platform_R_M.png", true, "platform_R_M");			//4
	ResourceManager::loadTexture("assets/Platform/Platform_R.png", true, "platform_R");				//5
}

void	Game::upload_Discard()
{
	ResourceManager::loadTexture("assets/Discard/Ground_texture_corner_L.png", true, "ground_texture_corner_L");	//6
	ResourceManager::loadTexture("assets/Discard/Ground_texture_corner_R.png", true, "ground_texture_corner_R");	//7
	ResourceManager::loadTexture("assets/Discard/Ground_texture_middle.png", true, "ground_texture_middle");		//8
	ResourceManager::loadTexture("assets/Obsticles/Acid_frames/Af4.png", true, "acid4");							//9
}

/* ********************* [v] GROUND UPLOADS [v] ********************* */

void	Game::upload_GroundTextures()
{
	// ResourceManager::loadTexture("assets/Ground_textures/Floor_design.png", true, "floor_design");							//10
	// ResourceManager::loadTexture("assets/Ground_textures/Left_corner_bottom_soil.png", true, "left_corner_bottom_soil");		//11
	// ResourceManager::loadTexture("assets/Ground_textures/Left_corner_grass.png", true, "left_corner_grass");					//
	// ResourceManager::loadTexture("assets/Ground_textures/Left_wall_soil.png", true, "left_wall_soil");						//
	// ResourceManager::loadTexture("assets/Ground_textures/Middle_grass.png", true, "middle_grass");							//
	// ResourceManager::loadTexture("assets/Ground_textures/Middle_part_bottom_soil.png", true, "middle_part_bottom_soil");		//
	// ResourceManager::loadTexture("assets/Ground_textures/Middle_soil.png", true, "middle_soil");								//
	// ResourceManager::loadTexture("assets/Ground_textures/Rıght_corner_bottom_soil.png", true, "right_corner_bottom_soil");	//
	// ResourceManager::loadTexture("assets/Ground_textures/Rıght_corner_grass.png", true, "right_corner_grass");				//
	// ResourceManager::loadTexture("assets/Ground_textures/Rıght_wall_soil.png", true, "right_wall_soil");						//
}