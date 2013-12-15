################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
PLL.obj: ../PLL.s $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv5/tools/compiler/tms470/bin/cl470" -mv7M3 --code_state=16 --abi=eabi -me -g --include_path="C:/ti/ccsv5/tools/compiler/tms470/include" --include_path="D:/Dropbox/ArmBook/Individual Examples/SysTick_1968asm/ccs/../.." --include_path="D:/Dropbox/ArmBook/Individual Examples/SysTick_1968asm/ccs/../../" --include_path="D:/Dropbox/ArmBook/Individual Examples/SysTick_1968asm/ccs/../../driverlib" --include_path="D:/Dropbox/ArmBook/Individual Examples/SysTick_1968asm/ccs/../../utils" --include_path="D:/Dropbox/ArmBook/Individual Examples/SysTick_1968asm/ccs/../../inc" --include_path="D:/Dropbox/CCS_1968/CCSValvanoWareWorkspace/" --include_path="C:/StellarisWare" --include_path="C:/StellarisWare/utils" --include_path="C:/StellarisWare/driverlib" --include_path="C:/StellarisWare/inc" --gcc --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="PLL.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

SysTick.obj: ../SysTick.s $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv5/tools/compiler/tms470/bin/cl470" -mv7M3 --code_state=16 --abi=eabi -me -g --include_path="C:/ti/ccsv5/tools/compiler/tms470/include" --include_path="D:/Dropbox/ArmBook/Individual Examples/SysTick_1968asm/ccs/../.." --include_path="D:/Dropbox/ArmBook/Individual Examples/SysTick_1968asm/ccs/../../" --include_path="D:/Dropbox/ArmBook/Individual Examples/SysTick_1968asm/ccs/../../driverlib" --include_path="D:/Dropbox/ArmBook/Individual Examples/SysTick_1968asm/ccs/../../utils" --include_path="D:/Dropbox/ArmBook/Individual Examples/SysTick_1968asm/ccs/../../inc" --include_path="D:/Dropbox/CCS_1968/CCSValvanoWareWorkspace/" --include_path="C:/StellarisWare" --include_path="C:/StellarisWare/utils" --include_path="C:/StellarisWare/driverlib" --include_path="C:/StellarisWare/inc" --gcc --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="SysTick.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

SysTickTestMain.obj: ../SysTickTestMain.s $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv5/tools/compiler/tms470/bin/cl470" -mv7M3 --code_state=16 --abi=eabi -me -g --include_path="C:/ti/ccsv5/tools/compiler/tms470/include" --include_path="D:/Dropbox/ArmBook/Individual Examples/SysTick_1968asm/ccs/../.." --include_path="D:/Dropbox/ArmBook/Individual Examples/SysTick_1968asm/ccs/../../" --include_path="D:/Dropbox/ArmBook/Individual Examples/SysTick_1968asm/ccs/../../driverlib" --include_path="D:/Dropbox/ArmBook/Individual Examples/SysTick_1968asm/ccs/../../utils" --include_path="D:/Dropbox/ArmBook/Individual Examples/SysTick_1968asm/ccs/../../inc" --include_path="D:/Dropbox/CCS_1968/CCSValvanoWareWorkspace/" --include_path="C:/StellarisWare" --include_path="C:/StellarisWare/utils" --include_path="C:/StellarisWare/driverlib" --include_path="C:/StellarisWare/inc" --gcc --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="SysTickTestMain.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

startup_ccsValvanoWare.obj: ../startup_ccsValvanoWare.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv5/tools/compiler/tms470/bin/cl470" -mv7M3 --code_state=16 --abi=eabi -me -g --include_path="C:/ti/ccsv5/tools/compiler/tms470/include" --include_path="D:/Dropbox/ArmBook/Individual Examples/SysTick_1968asm/ccs/../.." --include_path="D:/Dropbox/ArmBook/Individual Examples/SysTick_1968asm/ccs/../../" --include_path="D:/Dropbox/ArmBook/Individual Examples/SysTick_1968asm/ccs/../../driverlib" --include_path="D:/Dropbox/ArmBook/Individual Examples/SysTick_1968asm/ccs/../../utils" --include_path="D:/Dropbox/ArmBook/Individual Examples/SysTick_1968asm/ccs/../../inc" --include_path="D:/Dropbox/CCS_1968/CCSValvanoWareWorkspace/" --include_path="C:/StellarisWare" --include_path="C:/StellarisWare/utils" --include_path="C:/StellarisWare/driverlib" --include_path="C:/StellarisWare/inc" --gcc --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="startup_ccsValvanoWare.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


