#include "open.h"

#include <iostream>
#include <phpcpp.h>
#include <string>

/**
 *  Namespace to use
 */
using namespace std;

Php::Value wallet_generate() {
    return OpenWalletGenerate();
}

Php::Value wallet_import(Php::Parameters& params) {
    Php::Value prvKey = params[0];
    Php::Value coinType = params[1];

    return OpenImportPrivateKey(prvKey, coinType);
}

Php::Value wallet_sign(Php::Parameters& params) {
    Php::Value prvKey   = params[0];
    Php::Value address  = params[1];
    Php::Value chainId  = params[2];
    Php::Value gasPrice = params[3];
    Php::Value gasLimit = params[4];
    Php::Value amount   = params[5];

    return OpenSignTransaction(prvKey, address, chainId, gasPrice, gasLimit, amount);
}

// Symbols are exported according to the "C" language
extern "C" {
    // export the "get_module" function that will be called by the Zend engine
    PHPCPP_EXPORT void* get_module() {
        // create extension
        static Php::Extension extension("wallet_generate", "1.0");

        // add function to extension
        extension.add<wallet_generate>("wallet_generate");
        extension.add<wallet_import>("wallet_import");
        extension.add<wallet_sign>("wallet_sign");

        // return the extension module
        return extension.module();
    }
}
