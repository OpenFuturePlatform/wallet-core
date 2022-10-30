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
        //vector<string> result = OpenWalletGenerate();
        //cout << "address    : " << result[0] << endl;
        //cout << "private Key: " << result[1] << endl;
        string privateKey = "723b79529c433a8ed714e8f2d67288a09faa0c75aba40a1968d2be65aee1c04f";//result[1];//"0x15e9df2c39a3d2b12f9e72e23cabeaccd2cd25255a816f4d0b30e39188e3ece4";
        string address = OpenImportPrivateKey(privateKey, 1);
        cout << "Derived address    : " << address << endl;
        const string dummyReceiverAddress = "0x014D9Fcdb245CF31BfbaD92F3031FE036fE91Bc3";
        const string tokenAddress = "0x6bf8526b51d4a1601fed1046f13dbf5ac663028e";
        // Steps for sending:
        // 1. put together a send message 
        // 2. sign this message
        // 3. broadcast this message to the P2P network
        string signatureETH = OpenSignTransaction(privateKey, dummyReceiverAddress, "05", 2700000000, 21000, 924400000000000, 34);
        //string signatureToken = OpenSignTokenTransaction(privateKey, dummyReceiverAddress, "05", 4200000000, 36000, 1, 34, tokenAddress);
    
        cout << "Sign ETH    : " << signatureETH << endl;
        //cout << "Sign Token    : " << signatureToken << endl;

        //std::cout << "'" << signature << "'" << std::endl;
        //string encodedStr = OpenEncodeBase32(privateKey, "123456");
        //string decodedStr = OpenDecodeBase32(encodedStr, "123456");
        
    } catch (const std::exception& ex) {
        std::cout << "EXCEPTION: " << ex.what() << std::endl;
        throw ex;
    }
}
