# Select platform and installation for extra arduino files AND toolchain (compiler...)
SET(PLATFORM_ARCHITECTURE "STM32F1")
# while the name will be the name of the folder
SET(PLATFORM_PATH "/home/fx/Arduino/hardware/arduino/")
SET(PLATFORM_TOOLCHAIN_PATH "/home/fx/.arduino15/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/")
# and here we go
SET(CMAKE_TOOLCHAIN_FILE cmake/ArduinoToolchain.cmake)
MESSAGE(STATUS "Starting hello-stm32")

cmake_minimum_required(VERSION 2.8)
Project("Serializer" C CXX ASM)

#print_board_list()


set(ARDUINO_DEFAULT_BOARD genericSTM32F103C)        # Default Board ID, when not specified
set(ARDUINO_DEFAULT_PORT ttyACM0) # Default Port, when not specified
set(ARDUINO_CPU          STM32F103C8)

# this is needed for the nano, it should be set automatically, maybe something changed with sdk 1.8.x ?
set(ARDUINO_CPUMENU .menu.cpu.${ARDUINO_CPU})
#PRINT_SETTINGS(${ARDUINO_DEFAULT_BOARD})

# Where you store your downloaded libs or manually installed
SET(CUSTOM_LIB_DIR /home/fx/Arduino/libraries)

link_directories( ${CUSTOM_LIB_DIR})
include_directories(${CMAKE_SOURCE_DIR})
#
SET(libPrefix ${ARDUINO_DEFAULT_BOARD}_)
include_directories(touchScreen)
# This reduces size by 10% or so
#ADD_DEFINITIONS("-ffunction-sections -fdata-sections ")
generate_arduino_firmware(serializer 
                SRCS demo.cpp touchySerializer.cpp
                PORT ${ARDUINO_DEFAULT_PORT}
                BOARD_CPU ${ARDUINO_CPU}
                )

# EOF
