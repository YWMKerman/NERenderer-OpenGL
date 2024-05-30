# Makefile

C_COMPILER = gcc
CPP_COMPILER = g++
CFLAGS = -Wall
LINK = -lglfw -lGL -lX11 -lpthread -lXrandr -lXi -ldl
SHADER_DIR = src/shader
BIN_DIR = build

all: shader main

shader:
	rm -f $(SHADER_DIR)/render.glsl
	touch $(SHADER_DIR)/render.glsl
	cat $(SHADER_DIR)/render/0_header.glsl >> $(SHADER_DIR)/render.glsl
	echo "\n" >> $(SHADER_DIR)/render.glsl
	cat $(SHADER_DIR)/render/1_definition.glsl >> $(SHADER_DIR)/render.glsl
	echo "\n" >> $(SHADER_DIR)/render.glsl
	cat $(SHADER_DIR)/render/2_variable.glsl >> $(SHADER_DIR)/render.glsl
	echo "\n" >> $(SHADER_DIR)/render.glsl
	cat $(SHADER_DIR)/render/3_function.glsl >> $(SHADER_DIR)/render.glsl
	echo "\n" >> $(SHADER_DIR)/render.glsl
	cat $(SHADER_DIR)/render/4_main.glsl >> $(SHADER_DIR)/render.glsl

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
	  src/opengl/texture1D.o \
	  src/opengl/texture2D.o \
	  src/opengl/framebuffer.o \
	  \
	  src/renderer/renderer.o \
	  \
	  src/main/main.o
	mkdir -p $(BIN_DIR)
	$(CPP_COMPILER) $(CFLAGS) $(LINK) $^ -o $(BIN_DIR)/$@

third-party/glad/src/glad.o: third-party/glad/src/glad.c
	$(C_COMPILER) $(CFLAGS) -c $^ -o $@

%.o: %.cpp
	$(CPP_COMPILER) $(CFLAGS) -c $^ -o $@

.PHONY: clean
clean:
	rm -rf $(BIN_DIR)
	rm -f $(SHADER_DIR)/render.glsl
	find . -name "*.o" | xargs rm -f
