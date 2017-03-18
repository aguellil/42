/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arkanoid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 19:58:41 by aguellil          #+#    #+#             */
/*   Updated: 2017/03/18 02:27:50 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>

static void ft_callback_error(int error, const char* description)
{
    fputs(description, stderr);
}

static void ft_callback_keyboard(GLFWwindow* window, int key, int scancode, \
											int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

static void ft_rectangle_display()
{
//	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex3f(-1.0, 0.5, 0.0);
	glVertex3f(-1.0, -0.5, 0.0);
	glVertex3f(1.0, -0.5, 0.0);
	glVertex3f(1.0, 0.5, 0.0);
	glEnd();
}

int main(void)
{
    GLFWwindow* window;
    glfwSetErrorCallback(ft_callback_error);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(640, 480, "Arkanoid", NULL, NULL);
    glfwSetKeyCallback(window, ft_callback_keyboard);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    while (!glfwWindowShouldClose(window))
    {
//        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
//        ratio = width / (float) height;
        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
//        glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
/*      glRotatef((float) glfwGetTime() * 2.f, 0.f, 0.f, 1.f);
        glBegin(GL_TRIANGLES);
        glColor3f(1.f, 0.f, 0.f);
        glVertex3f(-0.6f, -0.4f, 0.f);
        glColor3f(0.f, 1.f, 0.f);
        glVertex3f(0.6f, -0.4f, 0.f);
        glColor3f(0.f, 0.f, 1.f);
        glVertex3f(0.f, 0.6f, 0.f);
        glEnd();
*/
//		glColor3f(0.0f, 0.0f, 0.0f);
//		glRectf(-0.75f,0.75f, 0.75f, -0.75f);
//		glVertex4f(x,y,z,w);
//		glVertex2i(x,y);
		ft_rectangle_display();
		glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}
