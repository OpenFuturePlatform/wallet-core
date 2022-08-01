cmake_minimum_required (VERSION 3.8 FATAL_ERROR)
project (wallet-core-open-cpp)

if (NOT ("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang"))
    message(FATAL_ERROR "You should use clang compiler")
endif()

set (SETUP_MESSAGE "Please provide TrustWalletCore build directory with -DWALLET_CORE.   Example: cmake . -DWALLET_CORE=../wallet-core")

if (NOT WALLET_CORE)
    message (FATAL_ERROR "${SETUP_MESSAGE}")
endif ()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set (CMAKE_C_STANDARD 11)
set (CMAKE_C_STANDARD_REQUIRED ON)

find_package(Boost REQUIRED)

# Include dirs:
include_directories (${CMAKE_SOURCE_DIR} ${WALLET_CORE}/include ${WALLET_CORE}/src ${WALLET_CORE}/build/local/include ${WALLET_CORE}/trezor-crypto/include ${WALLET_CORE}/open-platform/core-cpp)
link_directories (${WALLET_CORE}/build ${WALLET_CORE}/build/trezor-crypto ${WALLET_CORE}/build/local/lib)

find_library(WALLET_CORE_LIB_FILE TrustWalletCore PATH ${WALLET_CORE}/build)

if (NOT WALLET_CORE_LIB_FILE)
    message (FATAL_ERROR "TrustWalletCore library not found.  ${SETUP_MESSAGE}")
else ()
    message ("TrustWalletCore library found here: ${WALLET_CORE_LIB_FILE}")
endif ()

file(GLOB_RECURSE sources "*.cpp" "*.h")
add_library(OpenWallet SHARED ${sources})

target_include_directories(OpenWallet PRIVATE ${WALLET_CORE}/include ${WALLET_CORE}/src ${WALLET_CORE}/build/local/include ${WALLET_CORE}/trezor-crypto/include)
target_link_libraries(OpenWallet PUBLIC TrustWalletCore TrezorCrypto protobuf pthread ${PLATFORM_LIBS})
target_compile_options(OpenWallet PRIVATE "-Wall")
