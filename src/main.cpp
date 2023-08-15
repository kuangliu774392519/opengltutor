#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include "check_gl.hpp" // includes glad/glad.h
#include <GLFW/glfw3.h> // must be placed behind glad/glad.h
#include <stdexcept>
#include <iostream>
#include <cstring>
#include <cstdlib>


void  render()
{

    glBegin(GL_TRIANGLES);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    constexpr int n=600;
    constexpr float pi=3.1415926535897f;

    float radius=0.3f;
    float inner_radius=0.15f;

    for(int i=0;i<250;i++)
    {
        float angle=i/(float)n*pi*2;
        float angle_next=(i+1)/(float)n*pi*2;

        glColor3f(1,0,0);
        glVertex3f(radius* sinf(angle),0.5+radius* cosf(angle),0.0f);
        glVertex3f(radius* sinf(angle_next),0.5+radius* cosf(angle_next),0.0f);
        glVertex3f(inner_radius* sinf(angle),0.5+inner_radius* cosf(angle),0.0f);

        glVertex3f(inner_radius* sinf(angle_next),0.5+inner_radius* cosf(angle_next),0.0f);
        glVertex3f(inner_radius* sinf(angle),0.5+inner_radius* cosf(angle),0.0f);
        glVertex3f(radius* sinf(angle_next),0.5+inner_radius* cosf(angle_next),0.0f);

    }
    for(int i=350;i<n;i++)
    {
        float angle=i/(float)n*pi*2;
        float angle_next=(i+1)/(float)n*pi*2;

        glColor3f(1,0,0);
        glVertex3f(radius* sinf(angle),0.5+radius* cosf(angle),0.0f);
        glVertex3f(radius* sinf(angle_next),0.5+radius* cosf(angle_next),0.0f);
        glVertex3f(inner_radius* sinf(angle),0.5+inner_radius* cosf(angle),0.0f);

        glVertex3f(inner_radius* sinf(angle_next),0.5+inner_radius* cosf(angle_next),0.0f);
        glVertex3f(inner_radius* sinf(angle),0.5+inner_radius* cosf(angle),0.0f);
        glVertex3f(radius* sinf(angle_next),0.5+inner_radius* cosf(angle_next),0.0f);

    }





    for(int i=50;i<550;i++)
    {
        float angle=i/(float)n*pi*2;
        float angle_next=(i+1)/(float)n*pi*2;

        glColor3f(0,0,1);

        glVertex3f(0.5+radius* sinf(angle),radius* cosf(angle),0.0f);
        glVertex3f(0.5+radius* sinf(angle_next),radius* cosf(angle_next),0.0f);
        glVertex3f(0.5+inner_radius* sinf(angle),inner_radius* cosf(angle),0.0f);

        glVertex3f(0.5+inner_radius* sinf(angle_next),inner_radius* cosf(angle_next),0.0f);
        glVertex3f(0.5+inner_radius* sinf(angle),inner_radius* cosf(angle),0.0f);
        glVertex3f(0.5+radius* sinf(angle_next),inner_radius* cosf(angle_next),0.0f);

    }


    for(int i=0;i<50;i++)
    {
        float angle=i/(float)n*pi*2;
        float angle_next=(i+1)/(float)n*pi*2;

        glColor3f(0,1,0);

        glVertex3f(radius* sinf(angle)-0.5,radius* cosf(angle),0.0f);
        glVertex3f(radius* sinf(angle_next)-0.5,radius* cosf(angle_next),0.0f);
        glVertex3f(inner_radius* sinf(angle)-0.5,inner_radius* cosf(angle),0.0f);

        glVertex3f(inner_radius* sinf(angle_next)-0.5,inner_radius* cosf(angle_next),0.0f);
        glVertex3f(inner_radius* sinf(angle)-0.5,inner_radius* cosf(angle),0.0f);
        glVertex3f(radius* sinf(angle_next)-0.5,inner_radius* cosf(angle_next),0.0f);

    }

    for(int i=150;i<n;i++)
    {
        float angle=i/(float)n*pi*2;
        float angle_next=(i+1)/(float)n*pi*2;

        glColor3f(0,1,0);

        glVertex3f(radius* sinf(angle)-0.5,radius* cosf(angle),0.0f);
        glVertex3f(radius* sinf(angle_next)-0.5,radius* cosf(angle_next),0.0f);
        glVertex3f(inner_radius* sinf(angle)-0.5,inner_radius* cosf(angle),0.0f);

        glVertex3f(inner_radius* sinf(angle_next)-0.5,inner_radius* cosf(angle_next),0.0f);
        glVertex3f(inner_radius* sinf(angle)-0.5,inner_radius* cosf(angle),0.0f);
        glVertex3f(radius* sinf(angle_next)-0.5,inner_radius* cosf(angle_next),0.0f);

    }


    CHECK_GL(glEnd);
}


int main() {
   
   if(!glfwInit())// 初始化GLFW库
  {
    throw std::runtime_error("failed to initialize GLFW");

  }

//创建窗口并设置上下文
  auto window=glfwCreateWindow(640,640,"Example",nullptr,nullptr);
  if(!window){
    glfwTerminate();
    throw std::runtime_error("GLFW failed to create window");
  }
  glfwMakeContextCurrent(window);


  //初始化GLAD,加载函数指针.该操作必须在glfwMakeContextCurrent之后
    if(!gladLoadGL())
     {
        glfwTerminate();
        throw std::runtime_error("GLAD failed to load GL functions");
     }

     printf("OpenGL version:",glGetString(GL_VERSION));


    while (!glfwWindowShouldClose(window)){


        render();




        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }




}
