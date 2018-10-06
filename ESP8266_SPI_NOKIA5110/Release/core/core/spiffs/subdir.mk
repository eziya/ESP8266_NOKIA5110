################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:\sloeber\arduinoPlugin\packages\esp8266\hardware\esp8266\2.4.2\cores\esp8266\spiffs\spiffs_cache.c \
D:\sloeber\arduinoPlugin\packages\esp8266\hardware\esp8266\2.4.2\cores\esp8266\spiffs\spiffs_check.c \
D:\sloeber\arduinoPlugin\packages\esp8266\hardware\esp8266\2.4.2\cores\esp8266\spiffs\spiffs_gc.c \
D:\sloeber\arduinoPlugin\packages\esp8266\hardware\esp8266\2.4.2\cores\esp8266\spiffs\spiffs_hydrogen.c \
D:\sloeber\arduinoPlugin\packages\esp8266\hardware\esp8266\2.4.2\cores\esp8266\spiffs\spiffs_nucleus.c 

C_DEPS += \
.\core\core\spiffs\spiffs_cache.c.d \
.\core\core\spiffs\spiffs_check.c.d \
.\core\core\spiffs\spiffs_gc.c.d \
.\core\core\spiffs\spiffs_hydrogen.c.d \
.\core\core\spiffs\spiffs_nucleus.c.d 

AR_OBJ += \
.\core\core\spiffs\spiffs_cache.c.o \
.\core\core\spiffs\spiffs_check.c.o \
.\core\core\spiffs\spiffs_gc.c.o \
.\core\core\spiffs\spiffs_hydrogen.c.o \
.\core\core\spiffs\spiffs_nucleus.c.o 


# Each subdirectory must supply rules for building sources it contributes
core\core\spiffs\spiffs_cache.c.o: D:\sloeber\arduinoPlugin\packages\esp8266\hardware\esp8266\2.4.2\cores\esp8266\spiffs\spiffs_cache.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"D:\sloeber\arduinoPlugin\packages\esp8266\tools\xtensa-lx106-elf-gcc\1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-gcc" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-ID:\sloeber\/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/tools/sdk/include" "-ID:\sloeber\/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/tools/sdk/lwip2/include" "-ID:\sloeber\/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/tools/sdk/libc/xtensa-lx106-elf/include" "-ID:/Workspace/Arduino/ESP8266_SPI_NOKIA5110/Release/core" -c -Wall -Wextra  -Os -g -Wpointer-arith -Wno-implicit-function-declaration -Wl,-EL -fno-inline-functions -nostdlib -mlongcalls -mtext-section-literals -falign-functions=4 -MMD -std=gnu99 -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC -DTCP_MSS=536   -DARDUINO=10802 -DARDUINO_ESP8266_ESP12 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="\"ESP8266_ESP12\""   -DESP8266   -I"D:\sloeber\arduinoPlugin\packages\esp8266\hardware\esp8266\2.4.2\cores\esp8266" -I"D:\sloeber\arduinoPlugin\packages\esp8266\hardware\esp8266\2.4.2\variants\adafruit" -I"D:\sloeber\arduinoPlugin\packages\esp8266\hardware\esp8266\2.4.2\libraries\SPI" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

core\core\spiffs\spiffs_check.c.o: D:\sloeber\arduinoPlugin\packages\esp8266\hardware\esp8266\2.4.2\cores\esp8266\spiffs\spiffs_check.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"D:\sloeber\arduinoPlugin\packages\esp8266\tools\xtensa-lx106-elf-gcc\1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-gcc" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-ID:\sloeber\/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/tools/sdk/include" "-ID:\sloeber\/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/tools/sdk/lwip2/include" "-ID:\sloeber\/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/tools/sdk/libc/xtensa-lx106-elf/include" "-ID:/Workspace/Arduino/ESP8266_SPI_NOKIA5110/Release/core" -c -Wall -Wextra  -Os -g -Wpointer-arith -Wno-implicit-function-declaration -Wl,-EL -fno-inline-functions -nostdlib -mlongcalls -mtext-section-literals -falign-functions=4 -MMD -std=gnu99 -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC -DTCP_MSS=536   -DARDUINO=10802 -DARDUINO_ESP8266_ESP12 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="\"ESP8266_ESP12\""   -DESP8266   -I"D:\sloeber\arduinoPlugin\packages\esp8266\hardware\esp8266\2.4.2\cores\esp8266" -I"D:\sloeber\arduinoPlugin\packages\esp8266\hardware\esp8266\2.4.2\variants\adafruit" -I"D:\sloeber\arduinoPlugin\packages\esp8266\hardware\esp8266\2.4.2\libraries\SPI" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

core\core\spiffs\spiffs_gc.c.o: D:\sloeber\arduinoPlugin\packages\esp8266\hardware\esp8266\2.4.2\cores\esp8266\spiffs\spiffs_gc.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"D:\sloeber\arduinoPlugin\packages\esp8266\tools\xtensa-lx106-elf-gcc\1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-gcc" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-ID:\sloeber\/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/tools/sdk/include" "-ID:\sloeber\/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/tools/sdk/lwip2/include" "-ID:\sloeber\/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/tools/sdk/libc/xtensa-lx106-elf/include" "-ID:/Workspace/Arduino/ESP8266_SPI_NOKIA5110/Release/core" -c -Wall -Wextra  -Os -g -Wpointer-arith -Wno-implicit-function-declaration -Wl,-EL -fno-inline-functions -nostdlib -mlongcalls -mtext-section-literals -falign-functions=4 -MMD -std=gnu99 -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC -DTCP_MSS=536   -DARDUINO=10802 -DARDUINO_ESP8266_ESP12 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="\"ESP8266_ESP12\""   -DESP8266   -I"D:\sloeber\arduinoPlugin\packages\esp8266\hardware\esp8266\2.4.2\cores\esp8266" -I"D:\sloeber\arduinoPlugin\packages\esp8266\hardware\esp8266\2.4.2\variants\adafruit" -I"D:\sloeber\arduinoPlugin\packages\esp8266\hardware\esp8266\2.4.2\libraries\SPI" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

core\core\spiffs\spiffs_hydrogen.c.o: D:\sloeber\arduinoPlugin\packages\esp8266\hardware\esp8266\2.4.2\cores\esp8266\spiffs\spiffs_hydrogen.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"D:\sloeber\arduinoPlugin\packages\esp8266\tools\xtensa-lx106-elf-gcc\1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-gcc" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-ID:\sloeber\/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/tools/sdk/include" "-ID:\sloeber\/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/tools/sdk/lwip2/include" "-ID:\sloeber\/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/tools/sdk/libc/xtensa-lx106-elf/include" "-ID:/Workspace/Arduino/ESP8266_SPI_NOKIA5110/Release/core" -c -Wall -Wextra  -Os -g -Wpointer-arith -Wno-implicit-function-declaration -Wl,-EL -fno-inline-functions -nostdlib -mlongcalls -mtext-section-literals -falign-functions=4 -MMD -std=gnu99 -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC -DTCP_MSS=536   -DARDUINO=10802 -DARDUINO_ESP8266_ESP12 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="\"ESP8266_ESP12\""   -DESP8266   -I"D:\sloeber\arduinoPlugin\packages\esp8266\hardware\esp8266\2.4.2\cores\esp8266" -I"D:\sloeber\arduinoPlugin\packages\esp8266\hardware\esp8266\2.4.2\variants\adafruit" -I"D:\sloeber\arduinoPlugin\packages\esp8266\hardware\esp8266\2.4.2\libraries\SPI" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

core\core\spiffs\spiffs_nucleus.c.o: D:\sloeber\arduinoPlugin\packages\esp8266\hardware\esp8266\2.4.2\cores\esp8266\spiffs\spiffs_nucleus.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"D:\sloeber\arduinoPlugin\packages\esp8266\tools\xtensa-lx106-elf-gcc\1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-gcc" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-ID:\sloeber\/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/tools/sdk/include" "-ID:\sloeber\/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/tools/sdk/lwip2/include" "-ID:\sloeber\/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/tools/sdk/libc/xtensa-lx106-elf/include" "-ID:/Workspace/Arduino/ESP8266_SPI_NOKIA5110/Release/core" -c -Wall -Wextra  -Os -g -Wpointer-arith -Wno-implicit-function-declaration -Wl,-EL -fno-inline-functions -nostdlib -mlongcalls -mtext-section-literals -falign-functions=4 -MMD -std=gnu99 -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC -DTCP_MSS=536   -DARDUINO=10802 -DARDUINO_ESP8266_ESP12 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="\"ESP8266_ESP12\""   -DESP8266   -I"D:\sloeber\arduinoPlugin\packages\esp8266\hardware\esp8266\2.4.2\cores\esp8266" -I"D:\sloeber\arduinoPlugin\packages\esp8266\hardware\esp8266\2.4.2\variants\adafruit" -I"D:\sloeber\arduinoPlugin\packages\esp8266\hardware\esp8266\2.4.2\libraries\SPI" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '


