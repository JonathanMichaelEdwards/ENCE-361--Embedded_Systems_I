SOURCES_LOCATION  = ../src
SOURCES = $(wildcard $(SOURCES_LOCATION)/*.c)
OBJECTS = $(patsubst $(SOURCES_LOCATION)/%.c, src/%.obj, $(SOURCES))


# file for .bin and .out format
TARGET = Blink
RM := DEL /F
INCLUDES = -I./../include \
-I"C:/ti/ccs930/ccs/tools/compiler/ti-cgt-arm_18.12.4.LTS/lib" \
-I"C:/ti/ccs930/ccs/tools/compiler/ti-cgt-arm_18.12.4.LTS/include" \
-I"C:/ti/tivaware_c_series_2_1_4_178"

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS = $(TARGET).out

START_OBJ = tm4c123gh6pm_startup_ccs.obj 

ORDERED_OBJS += \
$(START_OBJ) \
$(OBJECTS) \
$(INCLUDES) \
"../tm4c123gh6pm.cmd" \
-l"C:/ti/ccs930/ccs/tools/compiler/ti-cgt-arm_18.12.4.LTS/lib/libc.a" \
-l"C:/ti/tivaware_c_series_2_1_4_178/driverlib/ccs/Debug/driverlib.lib" 

# Default target.
all: $(OBJS) $(TARGET).out




# startup c file
$(START_OBJ): ../tm4c123gh6pm_startup_ccs.c
	@echo Building file: "$<"
	@echo Invoking: ARM Compiler
	"C:/ti/ccs930/ccs/tools/compiler/ti-cgt-arm_18.12.4.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/ti/ccs930/ccs/tools/compiler/ti-cgt-arm_18.12.4.LTS/lib" --include_path="C:/ti/ccs930/ccs/tools/compiler/ti-cgt-arm_18.12.4.LTS/include" --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo Finished building: "$<"
	@echo.
# "C:/ti/ccs930/ccs/tools/compiler/ti-cgt-arm_18.12.4.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="D:/Documents/Systems/ENCE-361/Labs/Week 2/Lab 1/$(TARGET)" --include_path="D:/Documents/Systems/ENCE-361/Labs/Week 2/Lab 1/$(TARGET)/include" --include_path="C:/ti/tivaware_c_series_2_1_4_178" --include_path="C:/ti/ccs930/ccs/tools/compiler/ti-cgt-arm_18.12.4.LTS/include" --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	

# all other c files being used 
%.obj: ../../src/%.c
	@echo Building file: "$<"
	@echo Invoking: ARM Compiler
	"C:/ti/ccs930/ccs/tools/compiler/ti-cgt-arm_18.12.4.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me $(INCLUDES) --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="src/$(basename $(<F)).d_raw" --obj_directory="src" "$<"
	@echo 'Finished building: "$<"'
	@echo.


# Tool invocations
$(TARGET).out: $(OBJECTS) $(START_OBJ)
	@echo Building target: "$@"
	@echo Invoking: ARM Linker
	"C:/ti/ccs930/ccs/tools/compiler/ti-cgt-arm_18.12.4.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi -z -m"$(TARGET).map" --heap_size=256 --stack_size=512 -i"C:/ti/ccs930/ccs/tools/compiler/ti-cgt-arm_18.12.4.LTS/lib" -i"C:/ti/ccs930/ccs/tools/compiler/ti-cgt-arm_18.12.4.LTS/include" --reread_libs --diag_wrap=off --display_error_number --warn_sections --xml_link_info="$(TARGET)_linkInfo.xml" --rom_model -o "$(TARGET).out" $(ORDERED_OBJS)
	@echo Finished building target: "$@"
	@echo.


# Target: Clean Project.
.PHONY: cleanProject
clean:
	-$(RM) "$(START_OBJ)" "tm4c123gh6pm_startup_ccs.d_raw" "src\**.obj" "src\**.d_raw" "Builds\$(TARGET).bin" $(TARGET).out
	-@echo 'Finished clean'
	-@echo.
