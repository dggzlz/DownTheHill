#RENDER_MAKEFILE

CC := cc68x
CCFLAGS := -g
ASLFLAGS := gen -D -L2

# Define directories
SRC_DIRS := ../stage2 ../stage3
OBJ_DIR := dth

# Collect source files from all source directories
SRC_FILES := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))

# Generate list of object files
OBJ_FILES := $(patsubst %.c,$(OBJ_DIR)/%.o,$(notdir $(SRC_FILES)))

# Target executable
RENDER_EXE := tst_rend

# Rule to compile object files from source files
$(OBJ_DIR)/%.o: $(SRC_DIRS)/%.c
	$(CC) $(CCFLAGS) -c $< -o $@

# Rule to build the executable
$(RENDER_EXE): $(OBJ_FILES)
	$(CC) $(CCFLAGS) $^ -o 

# Ensure OBJ_DIR exists before compiling object files
$(OBJ_FILES): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Default target
all: $(RENDER_EXE)
