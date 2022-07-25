#pragma once

#include <iostream>
#include <string>

std::string OpenWalletGenerate();
std::string OpenImportPrivateKey(std::string privateKey, int coin);
std::string OpenSignTransaction(std::string privateKey, std::string address, std::string chainId,
                                long gasPrice, long gasLimit, long amount);
std::string OpenEncodeBase32(std::string rawString, std::string password); 
std::string OpenDecodeBase32(std::string encodedString, std::string password);                                 