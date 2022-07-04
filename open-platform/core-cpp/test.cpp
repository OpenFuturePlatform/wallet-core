// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <TrustWalletCore/TWHDWallet.h>
#include <TrustWalletCore/TWString.h>
#include <open.h>


#include <iostream>
#include <string>
#include <cstdint>
#include <vector>
#include <array>

using namespace std;


int main() {
    try {
    

        // TWHDWallet* walletImp = nullptr;
        // {
        //     cout << "Creating a new HD wallet ... ";
        //     walletImp = TWHDWalletCreate(128, TWStringCreateWithUTF8Bytes(""));
        //     cout << "done." << endl;
        //     cout << "Secret mnemonic for new wallet: '";
        //     cout << TWStringUTF8Bytes(TWHDWalletMnemonic(walletImp)) << "'." << endl;
        // }
        cout << "Working..." << endl;
        // TWHDWalletDelete(walletImp);
        string mneminicWord = OpenWalletGenerate();
    } catch (const exception& ex) {
        cout << "EXCEPTION: " << ex.what() << endl;
        throw ex;
    }
}
