#ifndef GAME_HPP
# define GAME_HPP 202502

#include <Utils.hpp>
#include <Shader.hpp>
#include <Game/GameMap.hpp>
#include <Texture2D.hpp>
#include <SpriteRenderer.hpp>
#include <map>
#include <Player.hpp>
#include <Camera.hpp>

using std::map;
using std::string;

class Game
{
public:
	enum class GameState
	{
		GAME_ACTIVE,
		GAME_MENU,
		GAME_WIN
	};
public:
	Game(void);
	~Game(void);

	void		init(void);
	void		initRender(void);
	void		start(void);
	void		loop(void);
	void		newMap(const char *, const char *);
	void		process(float dt);
	void		processInput(float dt);
	void		render(void);
	void		update(float);
	void		resetInputs();
	static void	updateKeyStatus(int key, bool status);
	std::map<std::string, unsigned int> uniformShaders;
	float deltaTime = 0.0f;
private:
	constexpr static float _playerVelocity = 500.0f;
	static bool				_keys[1024];
	unsigned int			SCREEN_WIDTH;
	unsigned int			SCREEN_HEIGHT;
	unsigned int 			_quadVAO;
	Game::GameState			_state;
	SpriteRenderer			*_renderer;
	GLFWwindow  			*_window;
	// Player					*_player;
	// Player					*_enemy;
	std::vector<Wall>		*_walls;
	Camera  				*_camera;
	map<string, GameMap>	maps;
	unsigned int VAO, VBO;

	void    createLight();
	void	printLight();

/* **************** [] UPLOAD ANIMATION SPRITES [] **************** */
/* ******************* [v] FORK MAIN CHARACTER [v] ******************* */
void	uploadForkBattle_stance();
void	uploadForkClimb();
void	uploadForkDamage();
void	uploadForkDash();
void	uploadForkDeath();
void	uploadForkDoublePunch();
void	uploadForkJump();
void	uploadForkSprint();
void	uploadForkHide();
void	uploadForkQuickPunch();
void	uploadForkStill();
void	uploadForkHurt();
/* ******************* [^] FORK MAIN CHARACTER [^] ******************* */

void	uploadBackground();
void	upload_Platform();
void	upload_Discard();
void	upload_GroundTextures();
};

#endif /* GAME_HPP */