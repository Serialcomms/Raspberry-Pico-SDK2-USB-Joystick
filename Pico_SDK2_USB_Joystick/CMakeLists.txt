# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)

# == DO NEVER EDIT THE NEXT LINES for Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.0.0)
set(toolchainVersion 13_2_Rel1)
set(picotoolVersion 2.0.0)
include(${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
# ====================================================================================
set(PICO_BOARD pico CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

if (PICO_SDK_VERSION_STRING VERSION_LESS "2.0.0")
  message(FATAL_ERROR "Raspberry Pi Pico SDK version 2.0.0 (or later) required. Your version is ${PICO_SDK_VERSION_STRING}")
endif()

# define PROJECT_NAME variable
project(Pico_SDK2_USB_Joystick C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1

add_executable(Pico_SDK2_USB_Joystick 

    USB_main.c 
    USB_initialise.c 
    USB_bus_reset.c
    USB_buffer_status.c 
    USB_buffer_control.c 
    USB_setup_packet.c 
    
    USB_descriptor_device.c 
    USB_descriptor_config.c 
    USB_endpoints_host.c 
    USB_endpoints_pico.c 
    USB_interrupts.c 
    USB_data_packet.c 
    USB_queue_control.c
    USB_queue_transmit.c
    USB_queue_receive.c 
    USB_sie_status.c  
    USB_sie_errors.c 
    USB_setup_hid.c
    USB_setup_control.c
    USB_setup_device.c
    USB_setup_address.c 
    USB_setup_type_standard.c
    USB_setup_type_class.c 
    USB_setup_interface.c
    USB_setup_descriptors.c 
    USB_set_configuration.c
    USB_build_endpoints.c  
    USB_setup_strings.c
    USB_EP0_handlers.c 
    USB_EP1_handlers.c 
    USB_HID_descriptor.c 
    USB_joystick.c
    USB_setup_show.c  
)

pico_set_program_name(Pico_SDK2_USB_Joystick "Pico_SDK2_USB_Joystick")
pico_set_program_version(Pico_SDK2_USB_Joystick "0.1")

# Modify the below lines to enable/disable output over UART/USB
pico_enable_stdio_uart(Pico_SDK2_USB_Joystick 1)
pico_enable_stdio_usb(Pico_SDK2_USB_Joystick 0)

# Add the standard library to the build
target_link_libraries(Pico_SDK2_USB_Joystick

    pico_stdlib
    pico_printf
    hardware_irq
    hardware_rtc
    hardware_uart   
)

add_compile_options(

    -Wall
    -Wno-format
    -Wno-unused-function
    -Wno-maybe-uninitialized
)

target_compile_definitions(${PROJECT_NAME} PRIVATE

    PICO_INCLUDE_RTC_DATETIME=1
    PICO_PRINTF_ALWAYS_INCLUDED=1
)

# Add the standard include files to the build
target_include_directories(Pico_SDK2_USB_Joystick PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}
  ${CMAKE_CURRENT_LIST_DIR}/.. # for our common lwipopts or any other standard includes, if required
)

pico_add_extra_outputs(Pico_SDK2_USB_Joystick)
