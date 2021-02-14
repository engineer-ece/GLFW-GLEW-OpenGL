import glfw
from OpenGL.GL import *
from OpenGL.GL import shaders
import numpy as np
import math

vShader = """
#version 330
layout (location=0) in vec3 pos;
uniform float xMove;
void main(){
 gl_Position = vec4(0.3*pos.x + xMove,0.3*pos.y,0.3*pos.z,1.0);
} 

"""


fShader = """
#version 330
out vec4 colour;
void main(){
 colour = vec4(1.0,1.0,1.0,1.0);
}
"""

ShaderProgram = None
xMove = None
direction = False
offset = 0.0
maxOffset = 0.7
inc = .05

def init():
  global xMove
  global vShader
  global fShader
  global ShaderProgram

  vertexShader = shaders.compileShader(vShader,GL_VERTEX_SHADER)
  fragmentShader = shaders.compileShader(fShader,GL_FRAGMENT_SHADER)
  
  ShaderProgram = shaders.compileProgram(vertexShader,fragmentShader)
  a=1
  z=0
  tri = [-a,-a,z,
          a,-a,z,
          z, z,z] 
  tri = np.array(tri,dtype=np.float32)
  

  VAO = glGenVertexArrays(1)
  glBindVertexArray(VAO)

  VBO = glGenBuffers(1)
  glBindBuffer(GL_ARRAY_BUFFER,VBO)
  glBufferData(GL_ARRAY_BUFFER,tri.nbytes,tri,GL_STATIC_DRAW)
 
  position = glGetAttribLocation(ShaderProgram,'pos')
  glVertexAttribPointer(position, 3, GL_FLOAT, GL_FALSE, 0, None)
  glEnableVertexAttribArray(position)
  
  xMove = glGetUniformLocation(ShaderProgram,"xMove");

def render():
  global ShaderProgram
  global VAO
  
  global direction
  global offset
  global maxOffset
  global inc
 
  if(direction):
   offset += inc
  else:
   offset -= inc
  

  if(abs(offset) >= maxOffset):
    direction = ~ direction

  glClearColor(0,1,0.5,1)
  glClear(GL_COLOR_BUFFER_BIT)



  glUseProgram(ShaderProgram)
  glUniform1f(xMove,offset)   
  glDrawArrays(GL_TRIANGLES,0,3)
  glUseProgram(0)

  
 
def main():
  
  if not glfw.init():
     return
  
  window = glfw.create_window(800,600,"Gobal Krishnan V",None,None)

  if not window:
    glfw.terminate()
    return 
  
  size=0;
  w,h = glfw.get_framebuffer_size(window)
  glfw.make_context_current(window)
  
  init()


  glViewport(0,0,w,h)
  while not glfw.window_should_close(window):
     glfw.poll_events();

     glClear(GL_COLOR_BUFFER_BIT)
     glClearColor(0.0,1.0,0.5,1.0)
     
     render()
     glfw.swap_buffers(window);
  
  glfw.terminate()

if __name__ == "__main__":
 main()
