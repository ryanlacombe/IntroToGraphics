#include <gl_core_4_4.h>
#include <GLFW/glfw3.h>
#include <cstdio>

int main() 
{
	if (glfwInit() == false)
	{
		return -1;
	}

	GLFWwindow* window = glfwCreateWindow(1280, 720, "Computer Graphics", nullptr, nullptr);

	if (window == nullptr)
	{
		glfwTerminate();
		return -2;
	}

	glfwMakeContextCurrent(window);

	if (ogl_LoadFunctions() == ogl_LOAD_FAILED)
	{
		glfwDestroyWindow(window);
		glfwTerminate();
		return -3;
	}

	int major = ogl_GetMajorVersion();
	int minor = ogl_GetMinorVersion();
	printf("GL: %i.%i\n", major, minor);

	while (!glfwWindowShouldClose(window) && glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS)
	{
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwDestroyWindow(window);

	glfwTerminate();
	return 0;
}