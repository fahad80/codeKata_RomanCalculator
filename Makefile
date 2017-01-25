# Compiler to use
CC = gcc 
INC_DIR = ./Include
SRC_DIR = ./Src
OBJ_DIR = ./Object
CFLAGS  =-c -Wall
SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/romancalc.c
OBJS = $(OBJ_DIR)/main.o $(OBJ_DIR)/romancalc.o
INCLUDES = -I$(INC_DIR)

EXEC = romanCalc

LIBS=-lcheck

.PHONY: all clean
 
all: $(OBJS)
	$(CC) $(OBJS) -o $(EXEC)
 
# % pattern wildcard matching
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	

test: romanCalcTest
	./romanCalcTest
	
romanCalcTest: $(OBJ_DIR)/romancalc-test.o $(OBJ_DIR)/romancalc.o
	gcc -o romanCalcTest $(OBJ_DIR)/romancalc.o $(OBJ_DIR)/romancalc-test.o $(LIBS)

$(OBJ_DIR)/romancalc-test.o: $(SRC_DIR)/romancalc-test.c
	$(CC) $(CFLAGS) $(INCLUDES) $(SRC_DIR)/romancalc-test.c -o $(OBJ_DIR)/romancalc-test.o

$(SRC_DIR)/romancalc-test.c: $(SRC_DIR)/romancalc-test.check
	checkmk $(SRC_DIR)/romancalc-test.check >$(SRC_DIR)/romancalc-test.c
 
clean:
	@echo "Cleaning up.."
	-rm -rf $(OBJ_DIR)/*.o
	-rm $(EXEC)
	-rm romanCalcTest
	-rm $(SRC_DIR)/romancalc-test.c
	
cleanTest:
	-rm romanCalcTest
	-rm $(SRC_DIR)/romancalc-test.c
