#ifndef GAME_HPP
# define GAME_HPP 202502

#include <Utils.hpp>
#include <Shader.hpp>
#include <GameMap.hpp>
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
	void		newTexture(const char *, bool, const char *);
	void		newMap(const char *, const char *);
	void		processInput(float dt);
	void		render(void);
	void		update(float);
	static void	updateKeyStatus(int key, bool status);
private:
	constexpr static float _playerVelocity = 500.0f;
	static bool				_keys[1024];
	unsigned int			SCREEN_WIDTH;
	unsigned int			SCREEN_HEIGHT;
	unsigned int 			_quadVAO;
	Game::GameState			_state;
	SpriteRenderer			*_renderer;
	GLFWwindow  			*_window;
	Shader					_shader;
	Player					*_player;
	std::vector<Wall>		*_walls;
	Player					*_enemy;
	Camera  				*_camera;
	map<string, Texture2D>	textures;
	map<string, GameMap>	maps;

};

#endif /* GAME_HPP */