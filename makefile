
# =========================================================
# Aztroz by Giordano de Brito
# =========================================================

COMPILER = gcc
CFLAGS = -I/usr/include/SDL2/ -lSDL2 -lSDL2_image -lm
HEADER = src/global.h

# Source files / scripts
SOURCE_DIR = src
SOURCE = main.c control.c resources.c

# Object files
OBJ_DIR = objects
_OBJ = $(patsubst %.c, %.o, $(SOURCE))
OBJ = $(patsubst %, $(OBJ_DIR)/%, $(_OBJ))

# Name of the executable
PROJECT = aztroz.game

$(OBJ_DIR)/%.o: $(SOURCE_DIR)/%.c $(HEADER)
	$(COMPILER) -c -o $@ $< $(CFLAGS)

$(PROJECT): $(OBJ)
	$(COMPILER) -o $@ $^ $(CFLAGS)
