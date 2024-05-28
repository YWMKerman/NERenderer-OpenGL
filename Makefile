# Makefile

C_COMPILER = gcc
CPP_COMPILER = g++
CFLAGS = -Wall
LINK = -lglfw -lGL -lX11 -lpthread -lXrandr -lXi -ldl
BINDIR = build

all: main

main: third-party/glad/src/glad.o \
	  \
	  src/math/vector3.o \
	  src/math/spectrum.o \
	  \
	  src/base/camera.o \
	  src/base/shape.o \
	  src/base/material.o \
	  src/base/object.o \
	  src/base/scene.o \
	  \
	  src/opengl/openglwindow.o \
	  src/opengl/shader.o \
	  src/opengl/mesh.o \
	  src/opengl/texture.o \
	  src/opengl/framebuffer.o \
	  \
	  src/renderer/renderer.o \
	  \
	  src/main/main.o
	mkdir -p $(BINDIR)
	$(CPP_COMPILER) $(CFLAGS) $(LINK) $^ -o $(BINDIR)/$@

third-party/glad/src/glad.o: third-party/glad/src/glad.c
	$(C_COMPILER) $(CFLAGS) -c $^ -o $@

%.o: %.cpp
	$(CPP_COMPILER) $(CFLAGS) -c $^ -o $@

.PHONY: clean
clean:
	find . -name "*.o" | xargs rm -f
