#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>  
#include <stdlib.h>  
#include "files.h"


int main() {
 char *const vertexSrcTmp = malloc(1000);
 char *const fragmentSrcTmp = malloc(1000);
 char buffer[512];
 float vertices[] = {
    0.0f,  0.5f, // Vertex 1 (X, Y)
    0.5f, -0.5f, // Vertex 2 (X, Y)
    -0.5f, -0.5f  // Vertex 3 (X, Y)
  };

 FILE *fptr = fopen("test.txt", "w");
    if (fptr == NULL)
    {
        printf("Could not open file");
        return 0;
    }
   
  copy_file_content(vertexSrcTmp, "vertex.glsl");
  copy_file_content(fragmentSrcTmp, "fragment.glsl");
  const char *const vertexSrc = vertexSrcTmp;
  const char *const fragmentSrc = fragmentSrcTmp;

  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

  GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL", NULL, NULL); 
  glfwMakeContextCurrent(window);

  glewExperimental = GL_TRUE;
  glewInit();

  GLuint vbo;
  glGenBuffers(1, &vbo);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &vertexSrc, NULL);
  glCompileShader(vertexShader);

  GLint status = GL_FALSE;
  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &status);
  if(status == GL_TRUE) {
    fprintf(fptr, "%s\n", "Vertex shader succesfully compiled");
  } else if(status == GL_FALSE) {
    fprintf(fptr, "%s\n", "Vertex shader failed to compiled");
  }

  GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader, 1, &fragmentSrc, NULL);
  glCompileShader(fragmentShader);


  glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &status);
  if(status == GL_TRUE) {
    fprintf(fptr, "%s\n", "Fragment shader succesfully compiled");
  } else if(status == GL_FALSE) {
    fprintf(fptr, "%s\n", "Fragment shader failed to compiled");
  }

  GLuint shaderProgram = glCreateProgram();
  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragmentShader);
  //fprintf(fptr, "%s %d\n", "Errors1: ", glGetError());

  glBindFragDataLocation(shaderProgram, 0, "outColor");
  glLinkProgram(shaderProgram);
  glGetProgramiv(shaderProgram, GL_LINK_STATUS, &status);
  if(status == GL_TRUE)
    fprintf(fptr, "%s\n", "Vertex shader succesfully linked");
  else if(status == GL_FALSE)
    fprintf(fptr, "%s\n", "Vertex shader failed to be  linked");
  glUseProgram(shaderProgram);
  GLuint vao;
  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);
  GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
  glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(posAttrib);
  fprintf(fptr, "%s %s\n", "GL version: ",  glGetString(GL_VERSION));




  while(!glfwWindowShouldClose(window))
  {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
      glfwSetWindowShouldClose(window, GL_TRUE);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glfwSwapBuffers(window);
    glfwPollEvents();
  }
  glfwTerminate();
  free(vertexSrcTmp);
  free(fragmentSrcTmp);
  fclose(fptr);
  return 0;
}

