
# =========================================================
# Aztroz by Giordano de Brito
# =========================================================

COMPILER = gcc
CFLAGS =	-I/usr/include/SDL2/ \
			-lSDL2 \
			-lSDL2_image \
			-lm # Math library
HEADER = global.h

# Source files / scripts
SOURCE_DIR = src
SOURCE = main.c control.c resources.c render.c window.c

# Object files
OBJ_DIR = objects
_OBJ = $(patsubst %.c, %.o, $(SOURCE))
OBJ = $(patsubst %, $(OBJ_DIR)/%, $(_OBJ))

# Output name
PROJECT = aztroz.game

$(OBJ_DIR)/%.o: $(SOURCE_DIR)/%.c $(SOURCE_DIR)/$(HEADER)
	$(COMPILER) -c -o $@ $< $(CFLAGS)

$(PROJECT): $(OBJ)
	$(COMPILER) -o $@ $^ $(CFLAGS)
