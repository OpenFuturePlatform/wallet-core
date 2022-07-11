cmake_minimum_required (VERSION 3.8 FATAL_ERROR)
project (wallet-core-open-cpp-test)

if (NOT ("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang"))
    message(FATAL_ERROR "You should use clang compiler")
endif()

include_directories (${CMAKE_SOURCE_DIR}  ${WALLET_CORE}/open-platform/core-cpp  ${WALLET_CORE}/open-platform/test )
link_directories (${WALLET_CORE}/open-platform/core-cpp ${WALLET_CORE}/build ${WALLET_CORE}/build/trezor-crypto)

find_library(WALLET_OPEN_CORE_LIB_FILE OpenWallet PATH ${WALLET_CORE}/open-platform/core-cpp)
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests OpenTests.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} OpenWallet TrustWalletCore TrezorCrypto protobuf pthread)


