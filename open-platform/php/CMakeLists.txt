cmake_minimum_required(VERSION 3.8 FATAL_ERROR)
project(open-php-cpp VERSION 1.0.0 DESCRIPTION "Open PHP library")

message(STATUS "Begin cmaking of PHP extension ...")

if(NOT("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang"))
	message(FATAL_ERROR "You should use clang compiler")
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(WALLET_CORE ../../)
set(PHP_CPP usr/include/)
set(PHP_PATH /usr/include/php/20190902)
set(PHP_LIBS "php")
set(PHP_LIB_PATH "")

include_directories(${CMAKE_SOURCE_DIR} ${WALLET_CORE}/open-platform/core-cpp ${WALLET_CORE}/open-platform/php/zend  ${PHP_PATH}/ ${PHP_PATH}/main ${PHP_PATH}/Zend ${PHP_PATH}/TSRM)
link_directories(${WALLET_CORE}/open-platform/core-cpp ${WALLET_CORE}/build ${WALLET_CORE}/build/trezor-crypto)

find_library(WALLET_OPEN_CORE_LIB_FILE OpenWallet PATH ${WALLET_CORE}/open-platform/core-cpp)

# add_library(walletgenerate SHARED walletgenerate.cpp)

# sources of this exec
add_executable(walletgenerate walletgenerate.cpp)

# link with our library, and default platform libraries
target_link_libraries(walletgenerate phpcpp OpenWallet)
