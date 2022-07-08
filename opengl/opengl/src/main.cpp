#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <math.h>

#include"shaderClass.h"
#include"VBO.h"
#include"VAO.h"
#include"EBO.h"

int main() {
	// Initialize the GLWF
	glfwInit();

	// Tell GLFW what version of OpenGL we are using
	// In this case, we are using OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	// Tell GLFW we are using the CORE profile
	// So that means we only have the modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create a GLFWwindow object with 800 pixels by 600 pixels, with name "Open GL"
	GLFWwindow* window = glfwCreateWindow(800, 600, "Open GL", NULL, NULL);

	// Verify if an error occurs in the creation of the window object
	if (window == NULL) {
		std::cout << "Failed to load the window with GLFW" << std::endl;
		glfwTerminate();
		return -1;
	}

	// Introduce the window to the current context
	glfwMakeContextCurrent(window);
	
	// Load GLAD so it configures OpenGL
	gladLoadGL();

	// Specify the viewport of OpenGL in the Window
	// In this case the viewport goes from x = 0, y = 0, to x = 800, y = 600
	glViewport(0, 0, 800, 600);

	// Create a shader object using shaders default.vert and default.frag
	Shader shaderProgram("default.vert", "default.frag");

	// Vertices coordinates
	GLfloat vertices[] = {
		-0.5f, -0.5f * float(std::sqrt(3)) / 3, 0.0f,
		0.5f, -0.5f * float(std::sqrt(3)) / 3, 0.0f,
		0.0f, 0.5f * float(std::sqrt(3)) * 2 / 3, 0.0f,
		-0.5f / 2, 0.5f * float(std::sqrt(3)) / 6, 0.0f,
		0.5f / 2, 0.5f * float(std::sqrt(3)) / 6, 0.0f,
		0.0f, -0.5f * float(std::sqrt(3)) / 3, 0.0f,
	};

	GLuint indices[] = {
		0, 3, 5,
		3, 2, 4,
		5, 4, 1
	};

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	// Specify the color of background
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);

	// Clear the back buffer and asign the new color
	glClear(GL_COLOR_BUFFER_BIT);

	// Swap the back buffer with the front buffer
	glfwSwapBuffers(window);

	// Generates Vertex Array Object and bind it
	VAO VAO1;
	VAO1.Bind();

	// Generate Vertex Buffer Object and link it to vertices
	VBO VBO1(vertices, sizeof(vertices));
	// Generate Element Buffer Object and link it to indices
	EBO EBO1(indices, sizeof(indices));

	// Link VBO to VAO
	VAO1.LinkVBO(VBO1, 0);

	// Unbind all to prevente accidentally modifying them
	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();

	// Main while loop
	while (!glfwWindowShouldClose(window)) {
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		shaderProgram.Activate();
		
		// Bind the VAO so OpenGL knows to use it
		VAO1.Bind();
		
		// Draw the triangle using GL_TRIANGLES
		glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);
		glfwSwapBuffers(window);
		// Take care of all OpenGL events
		glfwPollEvents();
	}

	// Delete the objects created
	VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();
	shaderProgram.Deactivate();

	// Delete window before ending the program
	glfwDestroyWindow(window);

	// Terminate GLFW before ending
	glfwTerminate();
	return 0;
}