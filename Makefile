# Compiler to use
CC = gcc 
INC_DIR = ./Include
SRC_DIR = ./Src
OBJ_DIR = ./Object
CFLAGS  =-c -Wall
SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/romanconverter.c $(SRC_DIR)/romancalculator.c
OBJS = $(OBJ_DIR)/main.o $(OBJ_DIR)/romanconverter.o $(OBJ_DIR)/romancalculator.o
INCLUDES = -I$(INC_DIR)

EXEC = romanConverter

LIBS=-lcheck

.PHONY: all clean
 
all: $(OBJS)
	$(CC) $(OBJS) -o $(EXEC)
 

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	

test: romanTest
	./romanTest
	
romanTest: $(OBJ_DIR)/roman-test.o $(OBJ_DIR)/romanconverter.o $(OBJ_DIR)/romancalculator.o
	gcc -o romanTest $(OBJ_DIR)/romanconverter.o $(OBJ_DIR)/romancalculator.o $(OBJ_DIR)/roman-test.o $(LIBS)

$(OBJ_DIR)/roman-test.o: $(SRC_DIR)/roman-test.c
	$(CC) $(CFLAGS) $(INCLUDES) $(SRC_DIR)/roman-test.c -o $(OBJ_DIR)/roman-test.o

$(SRC_DIR)/roman-test.c: $(SRC_DIR)/roman-test.check
	checkmk $(SRC_DIR)/roman-test.check >$(SRC_DIR)/roman-test.c
 
clean:
	@echo "Cleaning up.."
	-rm -rf $(OBJ_DIR)/*.o
	-rm $(EXEC)
	-rm romanTest
	-rm $(SRC_DIR)/roman-test.c
	
cleanTest:
	-rm romanConverterTest
	-rm $(SRC_DIR)/roman-test.c
