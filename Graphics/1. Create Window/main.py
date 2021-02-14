# python3 main.py
import glfw
from OpenGL.GL import *
from OpenGL.GL import shaders
import numpy as np
import math

  
 
def main():
  
  if not glfw.init():
     return
  
  window = glfw.create_window(700,600,"Gobal Krishnan V",None,None)

  if not window:
    glfw.terminate()
    return 
  
  size=0;
  w,h = glfw.get_framebuffer_size(window)
  glfw.make_context_current(window)
  
  

  glViewport(0,0,w,h)
  while not glfw.window_should_close(window):
     glfw.poll_events();

     glClear(GL_COLOR_BUFFER_BIT)
     glClearColor(0.0,1.0,0.5,1.0)
     
     
     glfw.swap_buffers(window);
  
  glfw.terminate()

if __name__ == "__main__":
 main()
