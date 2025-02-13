/* **************************** [v] INCLUDES [v] **************************** */
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <graphic/Graphic.hpp>
#include <Utils.hpp>
#include <Game.hpp>
/* **************************** [^] INCLUDES [^] **************************** */

int	main(void)
{
	Game game;

	game.init();
	game.start();
	
	return 0;
}

