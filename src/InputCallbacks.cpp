#include <Utils.hpp>
#include <iostream>
#include <Game.hpp>

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    (void)window; (void)key;  (void)scancode;  (void)action; (void)mode;
	if ((key == 'Q' || key == GLFW_KEY_ESCAPE) && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
	if (key >= 0 && key < 1024)
	{
		std::cout << "key: " << key << std::endl;
		if (action == GLFW_PRESS)
			Game::updateKeyStatus(key,true);
		else if (action == GLFW_RELEASE)
			Game::updateKeyStatus(key,false);
	}
	
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    (void) window;
	// make sure the viewport matches the new window dimensions; note that width and 
	// height will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);
}