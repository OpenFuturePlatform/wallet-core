#pragma once

#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> OpenWalletGenerate();
std::string OpenImportPrivateKey(std::string privateKey, int coin);
std::string OpenSignTransaction(std::string privateKey, std::string address, std::string chainId,
                                long gasPrice, long gasLimit, long amount);
std::string OpenEncodeBase32(std::string rawString, std::string password);
std::string OpenDecodeBase32(std::string encodedString, std::string password);
std::string OpenAesEncryptCtr(std::string data, std::string password);
std::string OpenAesDecryptCtr(std::string encryptedData, std::string password);