cmake_minimum_required (VERSION 3.8 FATAL_ERROR)
project(jni-library)
set(WALLET_CORE "../../")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set (CMAKE_C_STANDARD 13)
set (CMAKE_C_STANDARD_REQUIRED ON)

#IF YOU WANT TO USE ANY CLASS FROM WALLET CORE UNCOMMENT THIS SECTION AND COMMENT SECTION BELLOW
# include_directories (${CMAKE_SOURCE_DIR} ${WALLET_CORE}/include ${WALLET_CORE}/open-platform/core-cpp ${WALLET_CORE}/src ${WALLET_CORE}/build/local/include)
# link_directories (${WALLET_CORE}/open-platform/core-cpp ${WALLET_CORE}/build ${WALLET_CORE}/build/trezor-crypto ${WALLET_CORE}/build/local/lib)

include_directories (${CMAKE_SOURCE_DIR}  ${WALLET_CORE}/open-platform/core-cpp )
link_directories (${WALLET_CORE}/open-platform/core-cpp  ${WALLET_CORE}/build ${WALLET_CORE}/build/trezor-crypto)

find_library(WALLET_CORE_LIB_FILE TrustWalletCore PATH ${WALLET_CORE}/build)
if (NOT WALLET_CORE_LIB_FILE)
    message (FATAL_ERROR "TrustWalletCore library not found.  ${SETUP_MESSAGE}")
else ()
    message ("TrustWalletCore library found here: ${WALLET_CORE_LIB_FILE}")
endif ()

find_library(WALLET_OPEN_CORE_LIB_FILE OpenWallet PATH ${WALLET_CORE}/open-platform/core-cpp)
if (NOT WALLET_OPEN_CORE_LIB_FILE)
    message (FATAL_ERROR "OpenWallet library not found.  ${SETUP_MESSAGE}")
else ()
    message ("OpenWallet library found here: ${WALLET_OPEN_CORE_LIB_FILE}")
endif ()

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

find_package(JNI REQUIRED)
include_directories(${JNI_INCLUDE_DIRS})
set(SOURCE_FILES TrustWallet.cpp Aes.cpp)
add_library(trust-core-jvm SHARED ${SOURCE_FILES})

target_link_libraries (trust-core-jvm OpenWallet TrustWalletCore TrezorCrypto protobuf pthread ${PLATFORM_LIBS})
