#include "open.h"

#include <iostream>
#include <phpcpp.h>
#include <string>

/**
 *  Namespace to use
 */
using namespace std;

Php::Value wallet_generate(Php::Parameters& params) {
    Php::Value coinType = params[0];
    return OpenWalletGenerate(coinType);
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
    Php::Value nonce   = params[6];

    return OpenSignTransaction(prvKey, address, chainId, gasPrice, gasLimit, amount, nonce);
}

Php::Value wallet_sign_token(Php::Parameters& params) {
    Php::Value prvKey   = params[0];
    Php::Value address  = params[1];
    Php::Value chainId  = params[2];
    Php::Value gasPrice = params[3];
    Php::Value gasLimit = params[4];
    Php::Value amount   = params[5];
    Php::Value nonce    = params[6];
    Php::Value tokenAddress    = params[7];

    return OpenSignTokenTransaction(prvKey, address, chainId, gasPrice, gasLimit, amount, nonce, tokenAddress);
}

Php::Value wallet_encrypt(Php::Parameters& params) {
    Php::Value prvKey   = params[0];
    Php::Value password  = params[1];

    return OpenAesEncryptCtr(prvKey, password);
}

Php::Value wallet_decrypt(Php::Parameters& params) {
    Php::Value encryptedData   = params[0];
    Php::Value password  = params[1];

    return OpenAesDecryptCtr(encryptedData, password);
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
        extension.add<wallet_sign_token>("wallet_sign_token");
        extension.add<wallet_encrypt>("wallet_encrypt");
        extension.add<wallet_decrypt>("wallet_decrypt");

        // return the extension module
        return extension.module();
    }
}
