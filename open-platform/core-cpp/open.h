#pragma once

#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> OpenWalletGenerate(int coin=60);
std::string OpenImportPrivateKey(std::string privateKey, int coin=60);
std::string OpenSignTransaction(std::string privateKey, std::string toAddress, std::string chainId,
                                long gasPrice, long gasLimit, long amount, int nonce);
std::string OpenSignTokenTransaction(std::string privateKey, std::string toAddress, std::string chainId,
                                long gasPrice, long gasLimit, long amount, int nonce, std::string tokenAddress);                                                                  
std::string OpenEncodeBase32(std::string rawString, std::string password);
std::string OpenDecodeBase32(std::string encodedString, std::string password);