#pragma once

#include <iostream>
#include <string>

extern "C" {

std::string OpenWalletGenerate();

std::string OpenImportPrivateKey(std::string privateKey, int coin);

}