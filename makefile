SRC_DIR	:= src
OBJ_DIR := obj
BIN_DIR := bin

EXE1 := main
FIL1 := $(OBJ_DIR)/main.o
SRC  := $(wildcard $(SRC_DIR)/*.cpp)
OBJ  := $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

CC		   := g++
CPPFLAGS := -Iinclude -MMD -MP
CFLAGS 	 := -Wall -g

.PHONY: all tests clean cleanrun

all: $(EXE1)

$(EXE1): $(filter-out $(FIL2), $(OBJ))
	$(CC) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

clean:
	@$(RM) -rv $(BIN_DIR) $(OBJ_DIR)
	rm *.inorder *.postorder *.preorder main

cleanrun:
	@$(RM) -rv $(BIN_DIR)/*.out $(BIN_DIR)/*.log



-include $(OBJ:.o=.d)
