################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
temp\ src/Blink.obj: ../temp\ src/Blink.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"/home/jonathan/ti/ccs930/ccs/tools/compiler/ti-cgt-arm_18.12.4.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/home/jonathan/Desktop/Arm_Linux_Pro/hello" --include_path="/home/jonathan/ti/tivaware_c_series_2_1_4_178" --include_path="/home/jonathan/Desktop/Arm_Linux_Pro/hello/include" --include_path="/home/jonathan/ti/ccs930/ccs/tools/compiler/ti-cgt-arm_18.12.4.LTS" --include_path="/home/jonathan/ti/ccs930/ccs/tools/compiler/ti-cgt-arm_18.12.4.LTS/include" --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="temp src/Blink.d_raw" --obj_directory="temp src" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: "$<"'
	@echo ' '

temp\ src/ColorChange.obj: ../temp\ src/ColorChange.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"/home/jonathan/ti/ccs930/ccs/tools/compiler/ti-cgt-arm_18.12.4.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/home/jonathan/Desktop/Arm_Linux_Pro/hello" --include_path="/home/jonathan/ti/tivaware_c_series_2_1_4_178" --include_path="/home/jonathan/Desktop/Arm_Linux_Pro/hello/include" --include_path="/home/jonathan/ti/ccs930/ccs/tools/compiler/ti-cgt-arm_18.12.4.LTS" --include_path="/home/jonathan/ti/ccs930/ccs/tools/compiler/ti-cgt-arm_18.12.4.LTS/include" --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="temp src/ColorChange.d_raw" --obj_directory="temp src" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: "$<"'
	@echo ' '

temp\ src/PressToBlink.obj: ../temp\ src/PressToBlink.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"/home/jonathan/ti/ccs930/ccs/tools/compiler/ti-cgt-arm_18.12.4.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/home/jonathan/Desktop/Arm_Linux_Pro/hello" --include_path="/home/jonathan/ti/tivaware_c_series_2_1_4_178" --include_path="/home/jonathan/Desktop/Arm_Linux_Pro/hello/include" --include_path="/home/jonathan/ti/ccs930/ccs/tools/compiler/ti-cgt-arm_18.12.4.LTS" --include_path="/home/jonathan/ti/ccs930/ccs/tools/compiler/ti-cgt-arm_18.12.4.LTS/include" --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="temp src/PressToBlink.d_raw" --obj_directory="temp src" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: "$<"'
	@echo ' '


