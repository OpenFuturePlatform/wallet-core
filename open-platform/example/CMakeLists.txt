cmake_minimum_required (VERSION 3.8 FATAL_ERROR)
project (wallet-core-open-cpp)

set(WALLET_CORE "../../")

if (NOT ("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang"))
    message(FATAL_ERROR "You should use clang compiler")
endif()


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set (CMAKE_C_STANDARD 11)
set (CMAKE_C_STANDARD_REQUIRED ON)

set(WALLET_CORE "../../")

include_directories (${CMAKE_SOURCE_DIR}  ${WALLET_CORE}/open-platform/core-cpp )
link_directories (${WALLET_CORE}/open-platform/core-cpp)


find_library(WALLET_OPEN_CORE_LIB_FILE OpenWallet PATH ${WALLET_CORE}/open-platform/core-cpp)
if (NOT WALLET_OPEN_CORE_LIB_FILE)
    message (FATAL_ERROR "OpenWallet library not found.  ${SETUP_MESSAGE}")
else ()
    message ("OpenWallet library found here: ${WALLET_OPEN_CORE_LIB_FILE}")
endif ()

# Create all libraries and executables in the root binary dir
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

if (NOT CMAKE_BUILD_TYPE)
	set (CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the type of build, options are: Debug Release RelWithDebInfo MinSizeRel." FORCE)
endif ()

if (WIN32)
	add_definitions (-D_WIN32_WINNT=0x0600
					-D_CRT_SECURE_NO_WARNINGS
					-DWINVER=0x0600
					-DWIN32_LEAN_AND_MEAN)
else ()
	add_compile_options (-Werror=switch)
endif ()

if (WIN32)
	add_definitions(/bigobj)
endif ()

if (APPLE)
	set (PLATFORM_LINK_FLAGS "-framework Foundation -framework OpenCL")
elseif (WIN32)
	set (PLATFORM_LINK_FLAGS "/STACK:8000000") #provides 8MB default stack size for linux on windows
endif ()

SET (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${PLATFORM_LINK_FLAGS}")

# sources of this exec
add_executable (test test.cpp)

# link with our library, and default platform libraries
target_link_libraries (test OpenWallet)
