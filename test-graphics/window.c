#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>  
#include <stdlib.h>  
#include <math.h>
#include "files.h"


int main() {
 char *const vertexSrcTmp = malloc(1000);
 char *const fragmentSrcTmp = malloc(1000);
 char buffer[512];
 float vertices[] = {
   -0.5f,  0.5f, 1.0f, 0.0f, 0.0f, // Top-left
   0.5f,  0.5f, 0.0f, 1.0f, 0.0f, // Top-right
   0.5f, -0.5f, 0.0f, 0.0f, 1.0f, // Bottom-right
   -0.5f, -0.5f, 1.0f, 1.0f, 1.0f  // Bottom-left
 };
 GLuint elements[] = {
    0, 1, 2,
    2, 3, 0
};
 GLuint vao, vbo, ebo, colAttrib, posAttrib;
 GLuint fragmentShader, vertexShader, shaderProgram ;
 GLint status, uniColor;


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
  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);

  glGenBuffers(1, &vbo);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glGenBuffers(1, &ebo);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, GL_STATIC_DRAW);

  vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &vertexSrc, NULL);
  glCompileShader(vertexShader);

  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &status);
  if(status == GL_TRUE) {
    fprintf(fptr, "%s\n", "Vertex shader succesfully compiled");
  } else if(status == GL_FALSE) {
    fprintf(fptr, "%s\n", "Vertex shader failed to compiled");
  }

  fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader, 1, &fragmentSrc, NULL);
  glCompileShader(fragmentShader);


  glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &status);
  if(status == GL_TRUE) {
    fprintf(fptr, "%s\n", "Fragment shader succesfully compiled");
  } else if(status == GL_FALSE) {
    fprintf(fptr, "%s\n", "Fragment shader failed to compiled");
  }

  shaderProgram = glCreateProgram();
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
  posAttrib = glGetAttribLocation(shaderProgram, "position");
  glEnableVertexAttribArray(posAttrib);
  glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 5*sizeof(float), 0);

  
  colAttrib = glGetAttribLocation(shaderProgram, "color");
  glEnableVertexAttribArray(colAttrib);
  glVertexAttribPointer(colAttrib, 3, GL_FLOAT, GL_FALSE, 5*sizeof(float), (void*)(2*sizeof(float)));

  fprintf(fptr, "%s %d\n", "Error: ", glGetError());
  fprintf(fptr, "%s %s\n", "GL version: ",  glGetString(GL_VERSION));

  float count = 0.01;
  float color = 0; 
  while(!glfwWindowShouldClose(window)) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
      glfwSetWindowShouldClose(window, GL_TRUE);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glfwSwapBuffers(window);
    glfwPollEvents();
  }
  glfwTerminate();
  free(vertexSrcTmp);
  free(fragmentSrcTmp);
  fclose(fptr);
  return 0;
}

