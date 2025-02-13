#ifndef GRAPHIC_HPP
#define GRAPHIC_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <stb_images/stb_image.h>
#include <fstream>
#include <sstream>

extern void init_window(void);
extern const GLFWvidmode *get_primary_monitor(void);
extern GLFWwindow *gl_create_window(int, int, const char*);
extern void	gl_keyboard_hook(GLFWwindow*, void (*)(GLFWwindow*, int, int, int, int));
extern void	gl_framebuffer_size_hook(GLFWwindow*, void (*)(GLFWwindow*, int, int));
extern void gl_destroy_window(GLFWwindow*);

/* ***************************** [v] SHADER [v] ***************************** */
extern unsigned int gl_compile_shader(const char *, const char *);
/* ***************************** [^] SHADER [^] ***************************** */

extern unsigned int		gl_init_render(float *, size_t);

struct s_texture
{
	unsigned char	*data;
	unsigned int    width;
	unsigned int    height;
	unsigned int    id;
	unsigned int	wrap_S;
	unsigned int	wrap_T;
	unsigned int	filter_Min;
	unsigned int	filter_Max;
	unsigned int	internal_Format;
	unsigned int	image_Format;
};

extern void gl_generate_texture(struct s_texture& text);

#endif
