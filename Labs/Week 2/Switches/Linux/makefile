#  ============================================================================
#  Author:       Jonathan Edwards
#  Date:         02/27/2020 (V1)
#  Description:  makefile for running build commands and flashing on Linux.
#  ============================================================================


# file for .bin and .out format
TARGET = main
RM = rm -f
INCLUDES = -I./../include \
-I"/home/jonathan/ti/ccs930/ccs/tools/compiler/ti-cgt-arm_18.12.4.LTS/lib" \
-I"/home/jonathan/ti/ccs930/ccs/tools/compiler/ti-cgt-arm_18.12.4.LTS/include" \
-I"/home/jonathan/ti/tivaware_c_series_2_1_4_178"

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS = $(TARGET).out

SOURCES_LOCATION  = ../src
SOURCES = $(wildcard $(SOURCES_LOCATION)/*.c)
OBJECTS = $(patsubst $(SOURCES_LOCATION)/%.c, src/%.obj, $(SOURCES))

START_OBJ = tm4c123gh6pm_startup_ccs.obj

ORDERED_OBJS += \
$(START_OBJ) \
$(OBJECTS) \
$(INCLUDES) \
"../tm4c123gh6pm.cmd" \
-l"/home/jonathan/ti/ccs930/ccs/tools/compiler/ti-cgt-arm_18.12.4.LTS/lib/libc.a" \
-l"/home/jonathan/ti/tivaware_c_series_2_1_4_178/driverlib/ccs/Debug/driverlib.lib"


# Default target.
all: $(EXE_OUTPUTS)


# startup c file
$(START_OBJ): ../tm4c123gh6pm_startup_ccs.c
	@echo Building file: "$<"
	@echo Invoking: ARM Compiler
	"/home/jonathan/ti/ccs930/ccs/tools/compiler/ti-cgt-arm_18.12.4.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me -i"/home/jonathan/ti/ccs930/ccs/tools/compiler/ti-cgt-arm_18.12.4.LTS/lib" -i"/home/jonathan/ti/ccs930/ccs/tools/compiler/ti-cgt-arm_18.12.4.LTS/include" --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo Finished building: "$<"
	@echo


src/%.obj: ../src/%.c
	@echo Building file: "$<"
	@echo Invoking: ARM Compiler
	"/home/jonathan/ti/ccs930/ccs/tools/compiler/ti-cgt-arm_18.12.4.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me $(INCLUDES) --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="src/$(basename $(<F)).d_raw" --obj_directory="src" "$<"
	@echo 'Finished building: "$<"'
	@echo


# Tool invocations
$(TARGET).out: $(OBJECTS) $(START_OBJ)
	@echo Building target: "$@"
	@echo Invoking: ARM Linker
	"/home/jonathan/ti/ccs930/ccs/tools/compiler/ti-cgt-arm_18.12.4.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi -z -m"$(TARGET).map" --heap_size=256 --stack_size=512 -i"/home/jonathan/ti/ccs930/ccs/tools/compiler/ti-cgt-arm_18.12.4.LTS/lib" -i"/home/jonathan/ti/ccs930/ccs/tools/compiler/ti-cgt-arm_18.12.4.LTS/include" --reread_libs --diag_wrap=off --display_error_number --warn_sections --xml_link_info="$(TARGET)_linkInfo.xml" --rom_model -o $(TARGET).out $(ORDERED_OBJS)
	@echo Finished building target: "$@"
	@echo


# Target: Clean Project.
.PHONY: cleanProject
clean:
	-$(RM) $(START_OBJ) tm4c123gh6pm_startup_ccs.d_raw src/**.obj src/**.d_raw $(TARGET).out Builds/$(TARGET).bin
	-@echo 'Finished clean'
	-@echo
