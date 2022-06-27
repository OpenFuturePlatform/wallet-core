// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <TrustWalletCore/TWCoinType.h>
#include <TrustWalletCore/TWHRP.h>
#include <TrustWalletCore/TWData.h>
#include <TrustWalletCore/TWAnySigner.h>
#include <TrustWalletCore/TWCoinTypeConfiguration.h>
#include <TrustWalletCore/TWHDWallet.h>
#include <TrustWalletCore/TWHash.h>
#include <TrustWalletCore/TWPrivateKey.h>
#include <TrustWalletCore/TWPublicKey.h>
#include <TrustWalletCore/TWString.h>
#include <TrustWalletCore/TWPurpose.h>
#include <TrustWalletCore/TWHDVersion.h>

#include <Data.h>
#include <HexCoding.h>
#include <PrivateKey.h>
#include <HDWallet.h>
#include <Coin.h>

#include <iostream>
#include <string>
#include <cstdint>
#include <vector>
#include <array>

using namespace TW;
using namespace std;

int main() {
    try {
    

        TWHDWallet* walletImp = nullptr;
        {
            auto secretMnemonic = TWStringCreateWithUTF8Bytes("ripple scissors kick mammal hire column oak again sun offer wealth tomorrow wagon turn fatal");
            walletImp = TWHDWalletCreateWithMnemonic(secretMnemonic, TWStringCreateWithUTF8Bytes(""));
            TWStringDelete(secretMnemonic);
            cout << "Secret mnemonic: '";
            cout << TWStringUTF8Bytes(TWHDWalletMnemonic(walletImp)) << "'." << endl;
            cout << endl;
           
            // cout << "Creating a new HD wallet ... ";
            // walletImp = TWHDWalletCreate(128, TWStringCreateWithUTF8Bytes(""));
            // cout << "done." << endl;
            // cout << "Secret mnemonic for new wallet: '";
            // cout << TWStringUTF8Bytes(TWHDWalletMnemonic(walletImp)) << "'." << endl;
        }

        {
            // coin type: we use Ethereum
            const TWCoinType coinType = TWCoinType::TWCoinTypeBitcoin; // TWCoinTypeBitcoin, TWCoinTypeEthereum
            cout << "Working with coin: " <<
                TWStringUTF8Bytes(TWCoinTypeConfigurationGetName(coinType)) << " " <<
                TWStringUTF8Bytes(TWCoinTypeConfigurationGetSymbol(coinType)) << endl;

            // Derive extended private key.
            // extended private keys are a Base58 encoding of the private key, chain code, and some additional metadata
            TWPrivateKey* privateKey = TWHDWalletGetKeyForCoin(walletImp, coinType);    
            //TWPrivateKey* privateKey = TWHDWalletGetDerivedKey(walletImp, coinType, 0, 0, 0);

            // string prvKey = TWStringUTF8Bytes(TWHDWalletGetExtendedPrivateKey(walletImp, TWPurposeBIP44, coinType, TWHDVersionXPRV));
            // string pubKey = TWStringUTF8Bytes(TWHDWalletGetExtendedPublicKey(walletImp, TWPurposeBIP44, coinType, TWHDVersionXPUB));
            // string extPrvAccount = TWStringUTF8Bytes(TWHDWalletGetExtendedPrivateKeyAccount(walletImp, TWPurposeBIP44, coinType, TWHDVersionXPRV, 1));

            // cout << "Extended Private Key:         '" << prvKey << "'" << endl;    
            // cout << "Extended Public Key:          '" << pubKey << "'" << endl;  

            TWData* twPrivateKeyData = TWPrivateKeyData(privateKey);
            bool isValid = TWPrivateKeyIsValid(twPrivateKeyData, TWCurveSECP256k1);
            string privateKeyStr = TWStringUTF8Bytes(TWStringCreateWithHexData(twPrivateKeyData));
            cout << "Secret Private Data  is valid  " << isValid  << endl;
            cout << "Private Key                   '" << privateKeyStr   << "'"  << endl;
            
            // Derive default address.
            //string address = TWStringUTF8Bytes(TWCoinTypeDeriveAddress(coinType, privateKey));
            string address = TWStringUTF8Bytes(TWHDWalletGetAddressForCoin(walletImp, coinType));
            cout << "Derived address from Wallet:  '" << address << "'" << endl;

            //TWData* data = TWDataCreateWithHexString(TWStringCreateWithHexData(twPrivateKeyData));
            Data privKeyData = parse_hex(privateKeyStr);
            TWData* data = TWDataCreateWithBytes(privKeyData.data(), privKeyData.size());
            TWPrivateKey * privateKeyImported = TWPrivateKeyCreateWithData(data);

            address = TWStringUTF8Bytes(TWCoinTypeDeriveAddress(coinType, privateKeyImported));
            cout << "Derived address from Private: '" << address << "'" << endl;

            auto bytes = TW::parse_hex("fffffffffffffffffffffffffffffffebaaedce6af48a03bbfd25e8cd0364141");
            auto valid = TW::PrivateKey::isValid(bytes, TWCurveSECP256k1);
            auto derivationPath = TW::derivationPath(coinType);
            //walletImp->impl.getPrivateKeyFromExtended(prvKey, coinType, derivationPath);
           
            
            //const auto derivationPath = DerivationPath(TW::purpose(coinType), TW::slip44Id(coinType), 0, 0, 0);
            //TWPrivateKey* privateKey = new TWPrivateKey{ wallet->impl.getPrivateKeyFromExtended(coinType, derivationPath) };
            //cout << "Secret Private Data            " << secretPrivKeyData << endl;
            //cout << "Secret Private Data  is valid  " << valid  << endl;

            // Derive default address.
            //string address = TWStringUTF8Bytes(TWHDWalletGetAddressForCoin(walletImp, coinType));//TWStringUTF8Bytes(TWCoinTypeDeriveAddress(coinType, privateKey));
            //cout << "Derived address:              '" << address << "'" << endl;
    
        }
    
        TWHDWalletDelete(walletImp);
    } catch (const exception& ex) {
        cout << "EXCEPTION: " << ex.what() << endl;
        throw ex;
    }
}
