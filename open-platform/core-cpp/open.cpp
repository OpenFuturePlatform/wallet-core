#include <TrustWalletCore/TWAnySigner.h>
#include <TrustWalletCore/TWCoinType.h>
#include <TrustWalletCore/TWCoinTypeConfiguration.h>
#include <TrustWalletCore/TWHDWallet.h>
#include <TrustWalletCore/TWPrivateKey.h>
#include <TrustWalletCore/TWString.h>

#include <Coin.h>
#include <Data.h>
#include <HDWallet.h>
#include "Base64.h"
#include <HexCoding.h>
#include <PrivateKey.h>

#include <iostream>
#include <string>

#include <array>
#include <iostream>
#include <string>
#include <vector>

/**
 *  Namespace to use
 */
using namespace TW;
using namespace TW::Base64;
using namespace std;

string OpenWalletGenerate() {
    cout << "Creating a new HD wallet ... " << endl;
    TWHDWallet* walletNew = TWHDWalletCreate(128, TWStringCreateWithUTF8Bytes(""));
    const char* mnemonicWORD = TWStringUTF8Bytes(TWHDWalletMnemonic(walletNew));
    std::string str(mnemonicWORD);
    cout << "'" << mnemonicWORD << "'" << endl;
    TWHDWalletDelete(walletNew);
    return mnemonicWORD;
}

string OpenImportPrivateKey(string privateKey, int coin) {
    const TWCoinType coinType = TWCoinType::TWCoinTypeEthereum; // TWCoinTypeBitcoin, TWCoinTypeEthereum
    cout << "Working with coin: " << TWStringUTF8Bytes(TWCoinTypeConfigurationGetName(coinType))
         << " " << TWStringUTF8Bytes(TWCoinTypeConfigurationGetSymbol(coinType)) << endl;

    Data privKeyData = parse_hex(privateKey);
    TWData* data = TWDataCreateWithBytes(privKeyData.data(), privKeyData.size());
    TWPrivateKey* privateKeyImported = TWPrivateKeyCreateWithData(data);
    string address = TWStringUTF8Bytes(TWCoinTypeDeriveAddress(coinType, privateKeyImported));
    cout << "Derived address from Private: '" << address << "'" << endl;
    return address;
}

string OpenSignTransaction(string privateKey, string address, string chainId, long gasPrice, long gasLimit, long amount) {

    string chainIdB64  = Base64::encode(parse_hex("01"));
    string gasPriceB64 = Base64::encode(store(uint256_t((gasPrice))));
    string gasLimitB64 = Base64::encode(store(uint256_t(gasLimit)));
    string amountB64   = Base64::encode(store(uint256_t(amount)));

    string transaction = "{"
                         "\"chainId\":\"" +
                         chainIdB64 + "\",\"gasPrice\":\"" + gasPriceB64 + "\",\"gasLimit\":\"" +
                         gasLimitB64 + "\",\"toAddress\":\"" + address +
                         "\",\"transaction\":{\"transfer\":{\"amount\":\"" + amountB64 + "\"}}}";

    cout << "transaction: " << transaction << endl;                     

    Data privKeyData = parse_hex(privateKey);
    TWData* data = TWDataCreateWithBytes(privKeyData.data(), privKeyData.size());
    TWPrivateKey* privateKeyImported = TWPrivateKeyCreateWithData(data);
    auto secretPrivKey = TWPrivateKeyData(privateKeyImported);

    auto json = TWStringCreateWithUTF8Bytes(transaction.c_str());
    auto result = TWAnySignerSignJSON(json, secretPrivKey, TWCoinTypeEthereum);
    auto signedTransaction = string(TWStringUTF8Bytes(result));

    return signedTransaction;

}
