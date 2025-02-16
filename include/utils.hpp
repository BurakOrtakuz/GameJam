#ifndef UTILS_HPP
# define UTILS_HPP 202502

#include <cstdio>
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>


/* ************************ [v] INPUT CALL BACKS [v] ************************ */
extern void framebuffer_size_callback(GLFWwindow*, int, int);
extern void key_callback(GLFWwindow*, int, int, int, int);
float lerp(float x, float y, float f);
/* ************************ [^] INPUT CALL BACKS [^] ************************ */


template <typename T>
T errCheck(T err, T res, const char *message)
{
    if (res == err)
    {
        std::puts("errCheck runned!");
        throw std::runtime_error(message);
    }
    return (res);
}

#endif /* UTILS_HPP */
