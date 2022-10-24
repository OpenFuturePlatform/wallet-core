#include <TrustWalletCore/TWAnySigner.h>
#include <TrustWalletCore/TWCoinType.h>
#include <TrustWalletCore/TWCoinTypeConfiguration.h>
#include <TrustWalletCore/TWHDWallet.h>
#include <TrustWalletCore/TWPrivateKey.h>
#include <TrustWalletCore/TWString.h>
#include <TrustWalletCore/TWAES.h>
#include <TrustWalletCore/TWPBKDF2.h>

#include "Base32.h"
#include "Base64.h"
#include <Coin.h>
#include <Data.h>
#include <HDWallet.h>
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
using namespace TW::Base32;
using namespace std;

vector<string> OpenWalletGenerate() {
    cout << "Creating a new HD wallet ... " << endl;
    TWHDWallet* walletNew = TWHDWalletCreate(128, TWStringCreateWithUTF8Bytes(""));
    const char* mnemonicWORD = TWStringUTF8Bytes(TWHDWalletMnemonic(walletNew));
    std::string str(mnemonicWORD);
    const TWCoinType coinType = TWCoinType::TWCoinTypeEthereum;
    TWPrivateKey* privateKey = TWHDWalletGetKeyForCoin(walletNew, coinType);
    TWData* twPrivateKeyData = TWPrivateKeyData(privateKey);
    string privateKeyStr = TWStringUTF8Bytes(TWStringCreateWithHexData(twPrivateKeyData));
    string address = TWStringUTF8Bytes(TWHDWalletGetAddressForCoin(walletNew, coinType));
    // cout << privateKeyStr << endl;
    // cout << address << endl;
    // cout << "'" << mnemonicWORD << "'" << endl;
    TWHDWalletDelete(walletNew);
    // address & privateKey
    vector<string> vect{address, privateKeyStr};
    return vect;
}

string OpenImportPrivateKey(string privateKey, int coin) {
    const TWCoinType coinType = TWCoinType::TWCoinTypeEthereum; // TWCoinTypeBitcoin
    /*cout << "Working with coin: " << TWStringUTF8Bytes(TWCoinTypeConfigurationGetName(coinType))
         << " " << TWStringUTF8Bytes(TWCoinTypeConfigurationGetSymbol(coinType)) << endl;*/

    Data privKeyData = parse_hex(privateKey);
    TWData* data = TWDataCreateWithBytes(privKeyData.data(), privKeyData.size());
    TWPrivateKey* privateKeyImported = TWPrivateKeyCreateWithData(data);
    string address = TWStringUTF8Bytes(TWCoinTypeDeriveAddress(coinType, privateKeyImported));
    // cout << "Derived address from Private: '" << address << "'" << endl;
    return address;
}

string OpenSignTransaction(string privateKey, string address, string chainId, long gasPrice,
                           long gasLimit, long amount) {

    string chainIdB64 = Base64::encode(parse_hex("01"));
    string gasPriceB64 = Base64::encode(store(uint256_t((gasPrice))));
    string gasLimitB64 = Base64::encode(store(uint256_t(gasLimit)));
    string amountB64 = Base64::encode(store(uint256_t(amount)));

    string transaction = "{"
                         "\"chainId\":\"" +
                         chainIdB64 + "\",\"gasPrice\":\"" + gasPriceB64 + "\",\"gasLimit\":\"" +
                         gasLimitB64 + "\",\"toAddress\":\"" + address +
                         "\",\"transaction\":{\"transfer\":{\"amount\":\"" + amountB64 + "\"}}}";

    // cout << "transaction: " << transaction << endl;

    // Get vector byte from hex private key string
    Data privKeyData = parse_hex(privateKey);
    // Convert vector byte data to TWData object
    TWData* data = TWDataCreateWithBytes(privKeyData.data(), privKeyData.size());
    // Get TWPrivateKey object from TWData
    TWPrivateKey* privateKeyImported = TWPrivateKeyCreateWithData(data);
    TWData* secretPrivKey = TWPrivateKeyData(privateKeyImported);

    TWString* json = TWStringCreateWithUTF8Bytes(transaction.c_str());
    TWString* result = TWAnySignerSignJSON(json, secretPrivKey, TWCoinTypeEthereum);
    auto signedTransaction = string(TWStringUTF8Bytes(result));

    return signedTransaction;
}

string OpenEncodeBase32(string rawString, string password) {
    cout << "String to encode: '" << rawString << "'" << endl;
    Data decoded = parse_hex(rawString);
    string encoded = Base32::encode(decoded, password.c_str());
    cout << "Encoded: '" << encoded << "'" << endl;
    return encoded;
}

string OpenDecodeBase32(string encodedString, string password) {
    cout << "String to decode: '" << encodedString << "'" << endl;
    Data decoded;
    bool res = Base32::decode(encodedString, decoded, password.c_str());
    string decoded_hex = hex(decoded);
    cout << "Decoded: '" << decoded_hex << "'" << endl;
    return decoded_hex;
}

string OpenAesEncryptCtr(string data, string password) {
    TWData* hexedPassword = TWDataCreateWithHexString(TWStringCreateWithUTF8Bytes(password.c_str()));
    TWData* salt = TWDataCreateWithHexString(TWStringCreateWithUTF8Bytes("NaCl"));
    TWData* iv = TWDataCreateWithHexString(TWStringCreateWithUTF8Bytes("4949494949494949"));

    TWData* key = TWPBKDF2HmacSha256(hexedPassword, salt, 1000, 32);

    string encrypted;
    for (unsigned i = 0; i < data.length(); i += 10) {
        string fragment = data.substr(i, 10);
        TWData* encryptedFragmentData = TWAESEncryptCTR(key, TWDataCreateWithHexString(TWStringCreateWithUTF8Bytes(fragment.c_str())), iv);
        string encryptedFragment(TWStringUTF8Bytes(TWStringCreateWithHexData(encryptedFragmentData)));
        encrypted += encryptedFragment;
    }

    TWDataDelete(hexedPassword);
    TWDataDelete(salt);
    TWDataDelete(iv);

    return encrypted;
}

string OpenAesDecryptCtr(string encryptedData, string password) {
    TWData* hexedPassword = TWDataCreateWithHexString(TWStringCreateWithUTF8Bytes(password.c_str()));
    TWData* salt = TWDataCreateWithHexString(TWStringCreateWithUTF8Bytes("NaCl"));
    TWData* iv = TWDataCreateWithHexString(TWStringCreateWithUTF8Bytes("4949494949494949"));

    TWData* key = TWPBKDF2HmacSha256(hexedPassword, salt, 1000, 32);

    string decrypted;
    for (unsigned i = 0; i < encryptedData.length(); i += 10) {
        string fragment = encryptedData.substr(i, 10);
        TWData* decryptedFragmentData = TWAESDecryptCTR(key, TWDataCreateWithHexString(TWStringCreateWithUTF8Bytes(fragment.c_str())), iv);

        string decryptedFragment(TWStringUTF8Bytes(TWStringCreateWithHexData(decryptedFragmentData)));
        decrypted += decryptedFragment;
    }

    TWDataDelete(hexedPassword);
    TWDataDelete(salt);
    TWDataDelete(iv);

    return decrypted;
}
