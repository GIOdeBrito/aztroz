
# =========================================================
# Aztroz by Giordano de Brito
# =========================================================

# Default architecture
ARCH ?= x86

ifeq ($(ARCH), x86)
	COMPILER = gcc
	CFLAGS = 	-I/usr/include/SDL2/ \
				-lSDL2 \
				-lSDL2_image \
				-lm # Math library
	PROJECT = aztroz.x86_64
else
	COMPILER = arm-linux-gnueabihf-gcc
    CFLAGS = -I/usr/include/SDL2/ \
             -lSDL2 \
             -lSDL2_image \
             -lm \
             -L/usr/lib/arm-linux-gnueabihf/ # ARM library path
	PROJECT = aztroz.arm
endif

HEADER = global.h

# Source files / scripts
SOURCE_DIR = src
SOURCE = main.c control.c resources.c render.c window.c utility.c

# Object files
OBJ_DIR = objects
_OBJ = $(patsubst %.c, %.o, $(SOURCE))
OBJ = $(patsubst %, $(OBJ_DIR)/%, $(_OBJ))

$(OBJ_DIR)/%.o: $(SOURCE_DIR)/%.c $(SOURCE_DIR)/$(HEADER)
	$(COMPILER) -c -o $@ $< $(CFLAGS)

$(PROJECT): $(OBJ)
	$(COMPILER) -o $@ $^ $(CFLAGS)
