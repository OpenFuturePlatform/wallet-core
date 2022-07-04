#include <open.h>

#include <iostream>
#include <string>
#include <array>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main() {
    try {
        string mneminicWord = OpenWalletGenerate();
        string privateKey = "0x15e9df2c39a3d2b12f9e72e23cabeaccd2cd25255a816f4d0b30e39188e3ece4";
        string address = OpenImportPrivateKey(privateKey, 1);
        const string dummyReceiverAddress = "0xC37054b3b48C3317082E7ba872d7753D13da4986";
        string signature = OpenSignTransaction(privateKey, dummyReceiverAddress, "01", 3600000000, 21000, 924400000000000);
        std::cout << "'" << signature << "'" << std::endl;
    } catch (const std::exception& ex) {
        std::cout << "EXCEPTION: " << ex.what() << std::endl;
        throw ex;
    }
}
