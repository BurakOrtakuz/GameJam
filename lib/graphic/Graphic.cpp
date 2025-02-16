#include <graphic/Graphic.hpp>

void	init_window()
{
	glfwInit();
}

const GLFWvidmode *get_primary_monitor()
{
	return (glfwGetVideoMode(glfwGetPrimaryMonitor()));
}

static int
	gl_load_glad(void)
{
	return (gladLoadGLLoader((GLADloadproc)glfwGetProcAddress) != 0);
}

GLFWwindow *
	gl_create_window(int width, int height, const char *title)
{
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
	glfwWindowHint(GLFW_RESIZABLE, false);

	GLFWwindow *window = glfwCreateWindow(width, height, title, 0, 0);
	glfwMakeContextCurrent(window);
	if (!gl_load_glad())
		return (NULL);

	glViewport(0, 0, width, height);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glfwSwapInterval(0); // VSync off

	return (window);
}

void
	gl_keyboard_hook(GLFWwindow *window, void (*callback)(GLFWwindow*, int, int, int, int))
{
	glfwSetKeyCallback(window, callback);
}

void
	gl_framebuffer_size_hook(GLFWwindow *window, void (*callback)(GLFWwindow*, int, int))
{
	glfwSetFramebufferSizeCallback(window, callback);
}

void
	gl_destroy_window(GLFWwindow* window)
{
	(void)window;
	glfwTerminate();
}

/* ***************************** [v] SHADER [v] ***************************** */
static void
	checkCompileErrors(unsigned int object, std::string type)
{
	int success;
	char infoLog[1024];
	if (type != "PROGRAM")
	{
		glGetShaderiv(object, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(object, 1024, NULL, infoLog);
			std::cout << "| ERROR::SHADER: Compile-time error: Type: " << type << "\n"
				<< infoLog << "\n -- --------------------------------------------------- -- "
				<< std::endl;
		}
	}
	else
	{
		glGetProgramiv(object, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(object, 1024, NULL, infoLog);
			std::cout << "| ERROR::Shader: Link-time error: Type: " << type << "\n"
				<< infoLog << "\n -- --------------------------------------------------- -- "
				<< std::endl;
		}
	}
}

static unsigned int compile(const char* vertexSource, const char* fragmentSource)
{
	unsigned int sVertex, sFragment, id;
	// vertex Shader
	sVertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(sVertex, 1, &vertexSource, NULL);
	glCompileShader(sVertex);
	checkCompileErrors(sVertex, "VERTEX");
	// fragment Shader
	sFragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(sFragment, 1, &fragmentSource, NULL);
	glCompileShader(sFragment);
	checkCompileErrors(sFragment, "FRAGMENT");
	// shader program
	id = glCreateProgram();
	glAttachShader(id, sVertex);
	glAttachShader(id, sFragment);
	glLinkProgram(id);
	checkCompileErrors(id, "PROGRAM");
	// delete the shaders as they're linked into our program now and no longer necessary
	glDeleteShader(sVertex);
	glDeleteShader(sFragment);
	return (id);
}


unsigned int gl_compile_shader(const char *vShaderFile, const char *fShaderFile)
{
	// 1. retrieve the vertex/fragment source code from filePath
	std::string vertexCode;
	std::string fragmentCode;
	std::string geometryCode;
	
		// open files
		std::ifstream vertexShaderFile(vShaderFile);
		std::ifstream fragmentShaderFile(fShaderFile);
		std::stringstream vShaderStream, fShaderStream;
		// read file's buffer contents into streams
		vShaderStream << vertexShaderFile.rdbuf();
		fShaderStream << fragmentShaderFile.rdbuf();
		// close file handlers
		vertexShaderFile.close();
		fragmentShaderFile.close();
		// convert stream into string
		vertexCode = vShaderStream.str();
		fragmentCode = fShaderStream.str();

	const char *vShaderCode = vertexCode.c_str();
	const char *fShaderCode = fragmentCode.c_str();
	return (compile(vShaderCode, fShaderCode));
}
/* ***************************** [^] SHADER [^] ***************************** */

unsigned int gl_init_render(float *vertices, size_t size)
{
	unsigned int _quadVAO, VBO;

	glGenVertexArrays(1, &_quadVAO);
	glGenBuffers(1, &VBO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);

	glBindVertexArray(_quadVAO);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	return (_quadVAO);
}

void
	gl_generate_texture(struct s_texture& text)
{
	glBindTexture(GL_TEXTURE_2D, text.id);
	glTexImage2D(GL_TEXTURE_2D, 0, text.internal_Format, text.width, text.height, 0, text.image_Format, GL_UNSIGNED_BYTE, text.data);
	// set Texture wrap and filter modes
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, text.wrap_S);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, text.wrap_T);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, text.filter_Min);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, text.filter_Max);
	// unbind texture
	glBindTexture(GL_TEXTURE_2D, 0);
}
