// #include "../../include/TrustWalletCore/TWCoinType.h"
// #include "../../include/TrustWalletCore/TWAnySigner.h"
// #include "../../include/TrustWalletCore/TWCoinTypeConfiguration.h"
// #include "../../include/TrustWalletCore/TWHDWallet.h"
// #include "../../include/TrustWalletCore/TWPrivateKey.h"
// #include "../../include/TrustWalletCore/TWString.h"
//#include "../../src/interface/TWString.cpp"

#include <TrustWalletCore/TWCoinType.h>
#include <TrustWalletCore/TWAnySigner.h>
#include <TrustWalletCore/TWCoinTypeConfiguration.h>
#include <TrustWalletCore/TWHDWallet.h>
#include <TrustWalletCore/TWPrivateKey.h>
#include <TrustWalletCore/TWString.h>


#include <iostream>
#include <string>
#include <phpcpp.h>

/**
 *  Namespace to use
 */
using namespace std;

void wallet_generate()
{
     // Create a new multi-coin HD wallet, with new recovery phrase (mnemonic)
    cout << "Creating a new HD wallet ... " << endl;
    TWHDWallet* walletNew = TWHDWalletCreate(128, TWStringCreateWithUTF8Bytes(""));
    cout << "done." << endl;
    cout << "Secret mnemonic for new wallet: '";
    cout << TWStringUTF8Bytes(TWHDWalletMnemonic(walletNew)) << "'." << endl;
    TWHDWalletDelete(walletNew);
}


// Symbols are exported according to the "C" language
extern "C" 
{
    // export the "get_module" function that will be called by the Zend engine
    PHPCPP_EXPORT void *get_module()
    {
        // create extension
        static Php::Extension extension("wallet_generate","1.0");
        
        // add function to extension
        extension.add<wallet_generate>("wallet_generate");
        
        // return the extension module
        return extension.module();
    }
}
