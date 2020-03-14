#  ============================================================================
#  Author:       Jonathan Edwards
#  Date:         02/24/2020 (V1)
#  Description:  makefile for running build commands and flashing.
#  ============================================================================



# file for .bin and .out format
TARGET = Blink


# Printing pretty.
PRINT_BEGIN      = ===========================================================================================================================
PRINT_END        = =========================================================================================================================== & echo. & echo.
FLASH            = ------------------------------------------------ Flashing Program to board ------------------------------------------------
LINK_MESSAGE     = ----------------------------- Creating and Linkng all object files to create an executable file ---------------------------
CREATE_BIN_FILE  = --------------------------------------------- Generating a bin file to flash ----------------------------------------------
BIN_COMPLETED    = Succesfully generated a bin file format & echo. & echo.Press F4 to flash or F5 to enter Debug mode.



# Default target.
all: build flash


build:
	@echo $(PRINT_BEGIN)
	@echo $(LINK_MESSAGE)
	cd .. && make clean && gmake -k -j 12 all -O
	@echo $(PRINT_END)
	@echo $(PRINT_BEGIN)
	@echo $(CREATE_BIN_FILE)
	tiobj2bin ../$(TARGET).out $(TARGET).bin armofd armhex
	@echo $(BIN_COMPLETED)
	@echo $(PRINT_END)


flash:
	@echo $(PRINT_BEGIN)
	@echo $(FLASH)
	openocd -f interface/ti-icdi-auto.cfg -f target/stellaris.cfg -c "program $(TARGET).bin verify reset exit"
	@echo.
	@echo Succesfully flashed $(TARGET).bin
	@echo $(PRINT_END)



#  ============================================================================
#  Author:       Jonathan Edwards
#  Date:         02/05/2020 (V1)
#  Description:  Compiles and links all object files to create an exe output 
#                file for Windows.
#  ============================================================================



# # App Name.
# TARGET = main

# # Definitions.
# CC = g++ $(INCLUDES)
# CFLAGS = -g -Wall -std=c++11
# INCLUDES = -I./../include

# # Getting Object Name Automatically.
# SOURCES_LOCATION  = ../src
# SOURCES = $(wildcard $(SOURCES_LOCATION)/*.cpp)
# OBJECTS = $(patsubst $(SOURCES_LOCATION)/%.cpp, %.o, $(SOURCES))


# # Printing pretty.
# PRINT_BEGIN      = ======================================================================================================================
# PRINT_END        = ====================================================================================================================== & echo. & echo.
# REMOVE_MESSAGE   = -------------------------------------- Removing all object and executable files --------------------------------------
# LINK_NAN_MESSAGE = ------------------------------------------ Creating non linked object files ------------------------------------------
# LINK_OBJ_MESSAGE = -------------------------------- Linkng all object files to create an executable file --------------------------------
# COMPLETE_MESSAGE = Succesfully Compiled Program...



# # Default target.
# all: clean $(TARGET)
# 	@echo $(COMPLETE_MESSAGE)


# # Compile: create object files from C source files.
# %.o: $(SOURCES_LOCATION)/%.cpp
# 	$(CC) -c -o $@ $< $(CFLAGS)


# # Link: create ELF output file from object files.
# $(TARGET): $(OBJECTS)
# 	@echo $(PRINT_END)
# 	@echo $(LINK_OBJ_MESSAGE)
# 	@echo $(PRINT_BEGIN)
# 	$(CC) -o $@ $^ $(OPENGL_LIB) 
# 	@echo $(PRINT_END)
	

# # Target: Clean Project.
# .PHONY: cleanProject
# clean:
# 	@echo $(REMOVE_MESSAGE)
# 	@echo $(PRINT_BEGIN)
# 	del /f *.o main.exe
# 	@echo $(PRINT_END)
# 	@echo $(LINK_NAN_MESSAGE)
# 	@echo $(PRINT_BEGIN)
