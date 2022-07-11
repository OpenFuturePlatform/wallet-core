#include "open.h"


#include <iostream>
#include <string>
#include <phpcpp.h>

/**
 *  Namespace to use
 */
using namespace std;

// void wallet_generate()
// {
//      // Create a new multi-coin HD wallet, with new recovery phrase (mnemonic)
//     cout << "Creating a new HD wallet ... " << endl;
//     TWHDWallet* walletNew = TWHDWalletCreate(128, TWStringCreateWithUTF8Bytes(""));
//     cout << "done." << endl;
//     cout << "Secret mnemonic for new wallet: '";
//     cout << TWStringUTF8Bytes(TWHDWalletMnemonic(walletNew)) << "'." << endl;
//     TWHDWalletDelete(walletNew);
// }

Php::Value wallet_generate()
{
    return OpenWalletGenerate();
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
