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
#include "Ethereum/Signer.h"
#include "proto/Ethereum.pb.h"
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
using namespace TW::Ethereum;
using namespace TW::Base64;
using namespace TW::Base32;
using namespace std;

const TWCoinType getCoinTypeFromSlip44Code(int code) {
    switch (code) {
    case 0:
        return TWCoinType::TWCoinTypeBitcoin;
    case 60:
        return TWCoinType::TWCoinTypeEthereum;
    case 144:
        return TWCoinType::TWCoinTypeXRP;
    case 195:
        return TWCoinType::TWCoinTypeTron;
    case 354:
        return TWCoinType::TWCoinTypePolkadot;
    case 501:
        return TWCoinType::TWCoinTypeSolana;
    case 714:
        return TWCoinType::TWCoinTypeBinance;
    case 966:
        return TWCoinType::TWCoinTypePolygon;
    case 1815:
        return TWCoinType::TWCoinTypeCardano;
    default:
        return TWCoinType::TWCoinTypeEthereum;
    }
}

vector<string> OpenWalletGenerate(int coin = 60) {

    TWHDWallet* wallet = TWHDWalletCreate(128, TWStringCreateWithUTF8Bytes(""));

    const TWCoinType coinType = getCoinTypeFromSlip44Code(coin);

    string address = TWStringUTF8Bytes(TWHDWalletGetAddressForCoin(wallet, coinType));

    TWData* twPrivateKeyData = TWPrivateKeyData(TWHDWalletGetKeyForCoin(wallet, coinType));
    string privateKeyStr = TWStringUTF8Bytes(TWStringCreateWithHexData(twPrivateKeyData));

    TWHDWalletDelete(wallet);
    // address & privateKey
    vector<string> vect{address, privateKeyStr};
    return vect;
}

string OpenImportPrivateKey(string privateKey, int coin = 60) {
    const TWCoinType coinType = getCoinTypeFromSlip44Code(coin);

    Data privKeyData = parse_hex(privateKey);
    TWData* data = TWDataCreateWithBytes(privKeyData.data(), privKeyData.size());
    TWPrivateKey* privateKeyImported = TWPrivateKeyCreateWithData(data);

    return TWStringUTF8Bytes(TWCoinTypeDeriveAddress(coinType, privateKeyImported));
}

string OpenSignTransaction(string privateKeyStr, string toAddress, string chainId, long gasPrice,
                           long gasLimit, long amount, int nonce) {

    uint256_t chainID = uint256_t((chainId));

    auto transaction = TransactionNonTyped::buildNativeTransfer(
        /* nonce: */ nonce,
        /* gasPrice: */ gasPrice,
        /* gasLimit: */ gasLimit,
        /* to: */ parse_hex(toAddress),
        /* amount: */ amount);

    auto privateKey = PrivateKey(parse_hex(privateKeyStr));

    auto signature = TW::Ethereum::Signer::sign(privateKey, chainID, transaction);

    auto signedTransaction = transaction->encoded(signature, chainID);

    return hex(signedTransaction);
}

string OpenSignTokenTransaction(string privateKeyStr, string toAddress, string chainId,
                                long gasPrice, long gasLimit, long amount, int nonce,
                                string tokenAddress) {

    uint256_t chainID = uint256_t((chainId));

    auto transaction = TransactionNonTyped::buildERC20Transfer(
        /* nonce: */ nonce,
        /* gasPrice: */ gasPrice,
        /* gasLimit: */ gasLimit,
        /* token: */ parse_hex(tokenAddress),
        /* to: */ parse_hex(toAddress),
        /* amount: */ amount);

    auto privateKey = PrivateKey(parse_hex(privateKeyStr));

    auto signature = TW::Ethereum::Signer::sign(privateKey, chainID, transaction);

    auto signedTransaction = transaction->encoded(signature, chainID);

    return hex(signedTransaction);
}

string OpenEncodeBase32(string rawString, string password) {
    cout << "String to encode: '" << rawString << "'" << endl;
    Data decoded = parse_hex(rawString);
    string encoded = Base64::encode(decoded); // Base32::encode(decoded, password.c_str());
    cout << "Encoded: '" << encoded << "'" << endl;
    return encoded;
}

string OpenDecodeBase32(string encodedString, string password) {
    cout << "String to decode: '" << encodedString << "'" << endl;
    // Data decoded;
    // bool res = Base32::decode(encodedString, decoded, password.c_str());
    // string decoded_hex = hex(decoded);
    Data decoded = Base64::decode(encodedString);
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
