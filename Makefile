# Compiler to use
CC = gcc 
INC_DIR = ./Include
SRC_DIR = ./Src
OBJ_DIR = ./Object
CFLAGS  = -c -Wall
SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/foo.c
OBJS = $(OBJ_DIR)/main.o $(OBJ_DIR)/foo.o
INCLUDES = -I$(INC_DIR)

EXEC = romanCalc


.PHONY: all clean
 
all: $(OBJS)
	$(CC) $(OBJS) -o $(EXEC)
 
# % pattern wildcard matching
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	


 
clean:
	@echo "Cleaning up.."
	-rm -rf $(OBJ_DIR)/*.o
	-rm $(EXEC)
