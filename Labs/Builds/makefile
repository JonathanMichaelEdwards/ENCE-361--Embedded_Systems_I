#  ============================================================================
#  Author:       Jonathan Edwards
#  Date:         02/24/2020 (V1)
#  Description:  makefile for running build commands and flashing.
#
#  note: Please copy me in the Debug Folder of project.
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
