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

/* ***************** [v] UPLOAD ANIMATION SPRITES [v] **************** */

/* ******************* [v] FORK MAIN CHARACTER [v] ******************* */

void	Game::uploadForkBattle_stance()
{
	std::vector<std::string> textures;
	textures.push_back("battle_stance_1");
	textures.push_back("battle_stance_2");

	ResourceManager::loadTexture("assets/Characters/Fork_mc/Battle_stance/Battle_stance-1.png", true, "battle_stance_1");
	ResourceManager::loadTexture("assets/Characters/Fork_mc/Battle_stance/Battle_stance-2.png", true, "battle_stance_2");

	maps["level1"]._player->addAnimation(textures, "battle_stance", 2);
}

void	Game::uploadForkClimb()
{
	std::vector<std::string> textures;
	textures.push_back("climb1");
	textures.push_back("climb2");
	textures.push_back("climb3");
	textures.push_back("climb4");
	textures.push_back("climb5");
	textures.push_back("climb6");
	textures.push_back("climb7");
	textures.push_back("climb8");

	ResourceManager::loadTexture("assets/Characters/Fork_mc/Climb/Climb-1.png", true, "climb1");
	ResourceManager::loadTexture("assets/Characters/Fork_mc/Climb/Climb-2.png", true, "climb2");
	ResourceManager::loadTexture("assets/Characters/Fork_mc/Climb/Climb-3.png", true, "climb3");
	ResourceManager::loadTexture("assets/Characters/Fork_mc/Climb/Climb-4.png", true, "climb4");
	ResourceManager::loadTexture("assets/Characters/Fork_mc/Climb/Climb-5.png", true, "climb5");
	ResourceManager::loadTexture("assets/Characters/Fork_mc/Climb/Climb-6.png", true, "climb6");
	ResourceManager::loadTexture("assets/Characters/Fork_mc/Climb/Climb-7.png", true, "climb7");
	ResourceManager::loadTexture("assets/Characters/Fork_mc/Climb/Climb-8.png", true, "climb8");
	

	maps["level1"]._player->addAnimation(textures, "climb", 8);
}

void	Game::uploadForkDamage()
{
	std::vector<std::string> textures;
	textures.push_back("damage1");
	textures.push_back("damage2");

	ResourceManager::loadTexture("assets/Characters/Fork_mc/Damage/Fork_damage_frame_1.png", true, "damage1");
	ResourceManager::loadTexture("assets/Characters/Fork_mc/Damage/Fork_damage_frame_2.png", true, "damage2");
	

	maps["level1"]._player->addAnimation(textures, "damage", 2);
}

void	Game::uploadForkDash()
{
	std::vector<std::string> textures;
	textures.push_back("dash1");
	textures.push_back("dash2");

	ResourceManager::loadTexture("assets/Characters/Fork_mc/Dash/Dash-loop_1.png", true, "dash1");
	ResourceManager::loadTexture("assets/Characters/Fork_mc/Dash/Dash-loop_2.png", true, "dash2");

	maps["level1"]._player->addAnimation(textures, "dash", 2);
}

void	Game::uploadForkDeath()
{
	std::vector<std::string> textures;
	textures.push_back("death1");
	textures.push_back("death2");
	textures.push_back("death3");
	textures.push_back("death4");
	textures.push_back("death5");
	textures.push_back("death6");
	textures.push_back("death7");
	textures.push_back("death8");

	ResourceManager::loadTexture("assets/Characters/Fork_mc/Death/Fork_death-1.png", true, "death1");
	ResourceManager::loadTexture("assets/Characters/Fork_mc/Death/Fork_death-2.png", true, "death2");
	ResourceManager::loadTexture("assets/Characters/Fork_mc/Death/Fork_death-3.png", true, "death3");
	ResourceManager::loadTexture("assets/Characters/Fork_mc/Death/Fork_death-4.png", true, "death4");
	ResourceManager::loadTexture("assets/Characters/Fork_mc/Death/Fork_death-5.png", true, "death5");
	ResourceManager::loadTexture("assets/Characters/Fork_mc/Death/Fork_death-6.png", true, "death6");
	ResourceManager::loadTexture("assets/Characters/Fork_mc/Death/Fork_death-7.png", true, "death7");
	ResourceManager::loadTexture("assets/Characters/Fork_mc/Death/Fork_death-8.png", true, "death8");

	maps["level1"]._player->addAnimation(textures, "death", 8);
}

void	Game::uploadForkDoublePunch()
{
	std::vector<std::string> textures;
	textures.push_back("double_punch1");
	textures.push_back("double_punch2");
	textures.push_back("double_punch3");
	textures.push_back("double_punch4");
	textures.push_back("double_punch5");
	textures.push_back("double_punch6");
	textures.push_back("double_punch7");
	textures.push_back("double_punch8");

	ResourceManager::loadTexture("assets/Characters/Fork_mc/Double_punch/Double_punch-1.png", true, "double_punch1");
	ResourceManager::loadTexture("assets/Characters/Fork_mc/Double_punch/Double_punch-2.png", true, "double_punch2");
	ResourceManager::loadTexture("assets/Characters/Fork_mc/Double_punch/Double_punch-3.png", true, "double_punch3");
	ResourceManager::loadTexture("assets/Characters/Fork_mc/Double_punch/Double_punch-4.png", true, "double_punch4");
	ResourceManager::loadTexture("assets/Characters/Fork_mc/Double_punch/Double_punch-5.png", true, "double_punch5");
	ResourceManager::loadTexture("assets/Characters/Fork_mc/Double_punch/Double_punch-6.png", true, "double_punch6");
	ResourceManager::loadTexture("assets/Characters/Fork_mc/Double_punch/Double_punch-7.png", true, "double_punch7");
	ResourceManager::loadTexture("assets/Characters/Fork_mc/Double_punch/Double_punch-8.png", true, "double_punch8");

	maps["level1"]._player->addAnimation(textures, "doublePunch", 8);
}

//EKSİK: DOUBLE PUNCH IMPACT FRAMES

//EKSİK: FALL IMPACT

void	Game::uploadForkJump()
{
	std::vector<std::string> textures;
	textures.push_back("jump1");
	textures.push_back("jump2");
	textures.push_back("jump3");
	textures.push_back("jump4");
	textures.push_back("jump5");
	textures.push_back("jump6");
	textures.push_back("jump7");
	textures.push_back("jump8");

	ResourceManager::loadTexture("assets/Characters/Fork_mc/Fork_jump/_Fork_jump-1.png", true, "jump1");
	ResourceManager::loadTexture("assets/Characters/Fork_mc/Fork_jump/_Fork_jump-2.png", true, "jump2");
	ResourceManager::loadTexture("assets/Characters/Fork_mc/Fork_jump/_Fork_jump-3.png", true, "jump3");
	ResourceManager::loadTexture("assets/Characters/Fork_mc/Fork_jump/_Fork_jump-4.png", true, "jump4");
	ResourceManager::loadTexture("assets/Characters/Fork_mc/Fork_jump/_Fork_jump-5.png", true, "jump5");
	ResourceManager::loadTexture("assets/Characters/Fork_mc/Fork_jump/_Fork_jump-6.png", true, "jump6");
	ResourceManager::loadTexture("assets/Characters/Fork_mc/Fork_jump/_Fork_jump-7.png", true, "jump7");
	ResourceManager::loadTexture("assets/Characters/Fork_mc/Fork_jump/_Fork_jump-8.png", true, "jump8");

	maps["level1"]._player->addAnimation(textures, "jump", 30);
}

void	Game::uploadForkSprint()
{
	std::vector<std::string> textures;
	textures.push_back("sprint1");
	textures.push_back("sprint2");
	textures.push_back("sprint3");
	textures.push_back("sprint4");
	textures.push_back("sprint5");
	textures.push_back("sprint6");
	textures.push_back("sprint7");
	textures.push_back("sprint8");

	ResourceManager::loadTexture("assets/Characters/Fork_mc/Fork_sprint/1_run_loop.png", true, "sprint1");
	ResourceManager::loadTexture("assets/Characters/Fork_mc/Fork_sprint/2_run_loop.png", true, "sprint2");
	ResourceManager::loadTexture("assets/Characters/Fork_mc/Fork_sprint/3_run_loop.png", true, "sprint3");
	ResourceManager::loadTexture("assets/Characters/Fork_mc/Fork_sprint/4_run_loop.png", true, "sprint4");
	ResourceManager::loadTexture("assets/Characters/Fork_mc/Fork_sprint/5_run_loop.png", true, "sprint5");
	ResourceManager::loadTexture("assets/Characters/Fork_mc/Fork_sprint/6_run_loop.png", true, "sprint6");
	ResourceManager::loadTexture("assets/Characters/Fork_mc/Fork_sprint/7_run_loop.png", true, "sprint7");
	ResourceManager::loadTexture("assets/Characters/Fork_mc/Fork_sprint/8_run_loop.png", true, "sprint8");

	maps["level1"]._player->addAnimation(textures, "sprint", 10);
}

void	Game::uploadForkHide()
{
	std::vector<std::string> textures;
	textures.push_back("hide1");
	textures.push_back("hide2");
	textures.push_back("hide3");
	textures.push_back("hide4");
	textures.push_back("hide5");
	textures.push_back("hide6");
	textures.push_back("hide7");
	textures.push_back("hide8");

	ResourceManager::loadTexture("assets/Characters/Fork_mc/Hide/Hide-1.png", true, "hide1");
	ResourceManager::loadTexture("assets/Characters/Fork_mc/Hide/Hide-2.png", true, "hide2");
	ResourceManager::loadTexture("assets/Characters/Fork_mc/Hide/Hide-3.png", true, "hide3");
	ResourceManager::loadTexture("assets/Characters/Fork_mc/Hide/Hide-4.png", true, "hide4");
	ResourceManager::loadTexture("assets/Characters/Fork_mc/Hide/Hide-5.png", true, "hide5");
	ResourceManager::loadTexture("assets/Characters/Fork_mc/Hide/Hide-6.png", true, "hide6");
	ResourceManager::loadTexture("assets/Characters/Fork_mc/Hide/Hide-7.png", true, "hide7");
	ResourceManager::loadTexture("assets/Characters/Fork_mc/Hide/Hide-8.png", true, "hide8");

	maps["level1"]._player->addAnimation(textures, "hide", 10, false);
}
//285 560
void	Game::uploadForkQuickPunch()
{
	std::vector<std::string> textures;
	textures.push_back("quickPunch1");
	textures.push_back("quickPunch2");
	textures.push_back("quickPunch3");
	textures.push_back("quickPunch4");
	textures.push_back("quickPunch5");

	ResourceManager::loadTexture("assets/Characters/Fork_mc/Quick_punch/Quick_punch-1.png", true, "quickPunch1");
	ResourceManager::loadTexture("assets/Characters/Fork_mc/Quick_punch/Quick_punch-2.png", true, "quickPunch2");
	ResourceManager::loadTexture("assets/Characters/Fork_mc/Quick_punch/Quick_punch-3.png", true, "quickPunch3");
	ResourceManager::loadTexture("assets/Characters/Fork_mc/Quick_punch/Quick_punch-4.png", true, "quickPunch4");
	ResourceManager::loadTexture("assets/Characters/Fork_mc/Quick_punch/Quick_punch-5.png", true, "quickPunch5");

	maps["level1"]._player->addAnimation(textures, "quickPunch", 9);
}

////EKSİK: SINGLE PUNCH IMPACT FRAMES

void	Game::uploadForkStill()
{
	std::vector<std::string> textures;
	textures.push_back("still1");

	ResourceManager::loadTexture("assets/Characters/Fork_mc/Fork_still.png", true, "still1");

	maps["level1"]._player->addAnimation(textures, "still", 2);
}

void	Game::uploadForkHurt()
{
	std::vector<std::string> textures;
	textures.push_back("hurt1");

	ResourceManager::loadTexture("assets/Characters/Fork_mc/Fork_hurt.png", true, "hurt1");
	
	maps["level1"]._player->addAnimation(textures, "hurt", 1);
}

/* ******************* [^] FORK MAIN CHARACTER [^] ******************* */

/* ********************** [v] MO MINI BOSS [v] *********************** */
// void	Game::uploadMoStill()
// {
// 	std::vector<std::string> textures;
// 	textures.push_back("still1");

// 	ResourceManager::loadTexture("assets/Characters/Mo_(mini_boss)/Still.png", true, "still1");

// 	maps["level1"]._mo->addAnimation(textures, "still");
// }

// void	Game::upladMoAttack()
// {
// 	std::vector<std::string> textures;
// 	textures.push_back("attack1");
// 	textures.push_back("attack2");
// 	textures.push_back("attack3");
// 	textures.push_back("attack4");
// 	textures.push_back("attack5");
// 	textures.push_back("attack6");

// 	ResourceManager::loadTexture("assets/Characters/Mo_(mini_boss)/Attack/Attack-1.png", true, "attack1");
// 	ResourceManager::loadTexture("assets/Characters/Mo_(mini_boss)/Attack/Attack-2.png", true, "attack2");
// 	ResourceManager::loadTexture("assets/Characters/Mo_(mini_boss)/Attack/Attack-3.png", true, "attack3");
// 	ResourceManager::loadTexture("assets/Characters/Mo_(mini_boss)/Attack/Attack-4.png", true, "attack4");
// 	ResourceManager::loadTexture("assets/Characters/Mo_(mini_boss)/Attack/Attack-5.png", true, "attack5");
// 	ResourceManager::loadTexture("assets/Characters/Mo_(mini_boss)/Attack/Attack-6.png", true, "attack6");

// 	maps["level1"]._mo->addAnimation(textures, "attack");
// }
// /* ********************** [^] MO MINI BOSS [^] *********************** */

// /* ************************ [v] SIPY MOB [v] ************************* */
// void	Game::uploadSipyAttack()
// {
// 	std::vector<std::string> textures;
// 	textures.push_back("attack1");
// 	textures.push_back("attack2");
// 	textures.push_back("attack3");
// 	textures.push_back("attack4");
// 	textures.push_back("attack5");

// 	ResourceManager::loadTexture("assets/Characters/Sipy_(mob)/Attack/Attack-1.png", true, "attack1");
// 	ResourceManager::loadTexture("assets/Characters/Sipy_(mob)/Attack/Attack-2.png", true, "attack2");
// 	ResourceManager::loadTexture("assets/Characters/Sipy_(mob)/Attack/Attack-3.png", true, "attack3");
// 	ResourceManager::loadTexture("assets/Characters/Sipy_(mob)/Attack/Attack-4.png", true, "attack4");
// 	ResourceManager::loadTexture("assets/Characters/Sipy_(mob)/Attack/Attack-5.png", true, "attack5");

// 	maps["level1"]._sipy->addAnimation(textures, "attack");
// }

// void	Game::uploadSipyDeath()
// {
// 	std::vector<std::string> textures;
// 	textures.push_back("death1");
// 	textures.push_back("death2");
// 	textures.push_back("death3");
// 	textures.push_back("death4");

// 	ResourceManager::loadTexture("assets/Characters/Sipy_(mob)/Death/Death-1.png", true, "death1");
// 	ResourceManager::loadTexture("assets/Characters/Sipy_(mob)/Death/Death-2.png", true, "death2");
// 	ResourceManager::loadTexture("assets/Characters/Sipy_(mob)/Death/Death-3.png", true, "death3");
// 	ResourceManager::loadTexture("assets/Characters/Sipy_(mob)/Death/Death-4.png", true, "death4");

// 	maps["level1"]._sipy->addAnimation(textures, "death");
// }

// void	Game::uploadSipyStance()
// {
// 	std::vector<std::string> textures;
// 	textures.push_back("stance1");
// 	textures.push_back("stance2");
// 	textures.push_back("stance3");
// 	textures.push_back("stance4");
// 	textures.push_back("stance5");
// 	textures.push_back("stance6");

// 	ResourceManager::loadTexture("assets/Characters/Sipy_(mob)/Stance/Stance-1.png", true, "stance1");
// 	ResourceManager::loadTexture("assets/Characters/Sipy_(mob)/Stance/Stance-2.png", true, "stance2");
// 	ResourceManager::loadTexture("assets/Characters/Sipy_(mob)/Stance/Stance-3.png", true, "stance3");
// 	ResourceManager::loadTexture("assets/Characters/Sipy_(mob)/Stance/Stance-4.png", true, "stance4");
// 	ResourceManager::loadTexture("assets/Characters/Sipy_(mob)/Stance/Stance-5.png", true, "stance5");
// 	ResourceManager::loadTexture("assets/Characters/Sipy_(mob)/Stance/Stance-6.png", true, "stance6");

// 	maps["level1"]._sipy->addAnimation(textures, "stance");
// }
/* ************************ [^] SIPY MOB [^] ************************* */

/* ************************ [v] WOWO MOB [v] ************************* */
/* ************************ [^] WOWO MOB [^] ************************* */

/*
void	Game::uploadForkDash()
{
	std::vector<std::string> textures;
	textures.push_back("dash1");
	textures.push_back("dash2");

	ResourceManager::loadTexture("assets/Characters/Fork_mc/Dash/Dash-loop_1.png", true, "dash1");
	ResourceManager::loadTexture("assets/Characters/Fork_mc/Dash/Dash-loop_2.png", true, "dash2");

	maps["level1"]._player->addAnimation(textures, "dash");
}
*/
