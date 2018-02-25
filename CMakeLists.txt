# Select platform and installation for extra arduino files AND toolchain (compiler...)
SET(PLATFORM_ARCHITECTURE "STM32F1")
# Must be named arduino
#  else the cmake code will look for ARDUINO
# while the name will be the name of the folder
SET(PLATFORM_PATH "/home/fx/Arduino/hardware/arduino/")
#SET(PLATFORM_TOOLCHAIN_PATH "/home/fx/.arduino15/./packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin")
SET(PLATFORM_TOOLCHAIN_PATH "/home/fx/.arduino15/packages/arduino/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin/")
#"/home/fx/.arduino15/packages/STM32/tools/arm-none-eabi-gcc/6-2017-q2-update/bin")
# and here we go
SET(CMAKE_TOOLCHAIN_FILE cmake/ArduinoToolchain.cmake)
MESSAGE(STATUS "Starting hello-stm32")

cmake_minimum_required(VERSION 2.8)
Project("Hello_stm32" C CXX ASM)

print_board_list()


set(ARDUINO_DEFAULT_BOARD genericSTM32F103C)        # Default Board ID, when not specified
set(ARDUINO_DEFAULT_PORT ttyACM0) # Default Port, when not specified
set(ARDUINO_CPU          STM32F103C8)

# this is needed for the nano, it should be set automatically, maybe something changed with sdk 1.8.x ?
set(ARDUINO_CPUMENU .menu.cpu.${ARDUINO_CPU})
PRINT_SETTINGS(${ARDUINO_DEFAULT_BOARD})

# Where you store your downloaded libs or manually installed
SET(CUSTOM_LIB_DIR /home/fx/Arduino/libraries)

link_directories( ${CUSTOM_LIB_DIR})
SET(FAST_LCD 1)
IF(FAST_LCD)
    include_directories(${CUSTOM_LIB_DIR}/Adafruit_ILI9341_STM/)
    SET(LCD_LIB Adafruit_ILI9341_STM)
    ADD_DEFINITIONS(-DFAST_LCD)
    include_directories(lcd)
    SET(EXTRA_SRC lcd/ucg_compat.cpp)
ELSE(FAST_LCD)
# u8glib is complicated and needs special care
    include_directories(${CUSTOM_LIB_DIR}/Ucglib/cppsrc)
    include_directories(${CUSTOM_LIB_DIR}/Ucglib/csrc)
    set(Ucglib_RECURSE True)
    SET(LCD_LIB Ucglib)
ENDIF(FAST_LCD)
#
# Be careful with the includes in the ino files
# #include <foo.h> // this is a comment
# will fail
# same with extra tabs or space after the #include "blah.h"
#
SET(libPrefix ${ARDUINO_DEFAULT_BOARD}_)
include_directories(touchScreen)
include_directories(serializer)
include_directories(serial_io)
include_directories(screenManager)
include_directories(screens)
include_directories(xpt)
# This reduces size by 10% or so
#ADD_DEFINITIONS("-ffunction-sections -fdata-sections ")
generate_arduino_firmware(touchscreen_demo 
                SKETCH dummy_sketch.ino
                SRCS mainApp.cpp touchScreen/ili_touch.cpp serializer/touchySerializer.cpp serial_io/serialIo.cpp  screenManager/screenManager.cpp 
			screens/screenUtil.cpp
            xpt/aXPT2046_Touchscreen.cpp
			screens/idleScreen.cpp screens/bootScreen.cpp screens/queryScreen.cpp screens/ingestingScreen.cpp
			${EXTRA_SRC}
                LIBS ${libPrefix}${LCD_LIB} 
                PORT ${ARDUINO_DEFAULT_PORT}
                BOARD_CPU ${ARDUINO_CPU}
                )

# EOF
