#include <TrustWalletCore/TWCoinType.h>
#include <TrustWalletCore/TWAnySigner.h>
#include <TrustWalletCore/TWCoinTypeConfiguration.h>
#include <TrustWalletCore/TWHDWallet.h>
#include <TrustWalletCore/TWPrivateKey.h>
#include <TrustWalletCore/TWString.h>

#include <Data.h>
#include <HexCoding.h>
#include <PrivateKey.h>
#include <HDWallet.h>
#include <Coin.h>


#include <iostream>
#include <string>
#include <phpcpp.h>

#include <iostream>
#include <string>
#include <vector>
#include <array>


/**
 *  Namespace to use
 */
using namespace TW;
using namespace std;

const char  fillchar = '=';

                        // 00000000001111111111222222
                        // 01234567890123456789012345
static std::string  cvt = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                          "abcdefghijklmnopqrstuvwxyz"
                          "0123456789+/";

string OpenWalletGenerate()
{   
    cout << "Creating a new HD wallet ... " << endl;
    TWHDWallet* walletNew = TWHDWalletCreate(128, TWStringCreateWithUTF8Bytes(""));
    const char* mnemonicWORD = TWStringUTF8Bytes(TWHDWalletMnemonic(walletNew));
    std::string str(mnemonicWORD);
    cout << mnemonicWORD << "'." << endl;
    TWHDWalletDelete(walletNew);
    return mnemonicWORD;
}

string OpenImportPrivateKey(string privateKey, int coin)
{
    const TWCoinType coinType = TWCoinType::TWCoinTypeEthereum; // TWCoinTypeBitcoin, TWCoinTypeEthereum
    cout << "Working with coin: " <<
        TWStringUTF8Bytes(TWCoinTypeConfigurationGetName(coinType)) << " " <<
        TWStringUTF8Bytes(TWCoinTypeConfigurationGetSymbol(coinType)) << endl;

    Data privKeyData = parse_hex(privateKey);
    TWData* data = TWDataCreateWithBytes(privKeyData.data(), privKeyData.size());
    TWPrivateKey * privateKeyImported = TWPrivateKeyCreateWithData(data);
    string address = TWStringUTF8Bytes(TWCoinTypeDeriveAddress(coinType, privateKeyImported));
    cout << "Derived address from Private: '" << address << "'" << endl;
    return address;
}

// string OpenSignTransaction(string privateKey, string address, string chainId, int gasPrice, int gasLimit, int amount)
// {

//     string chainIdB64 = base64(parse_hex("01"));
//     string gasPriceB64 = base64(parse_hex(decimalToHex(gasPrice)));
//     string gasLimitB64 = base64(parse_hex(decimalToHex(gasLimit)));
//     string amountB64 = base64(parse_hex(decimalToHex(amount)));
//     string transaction = "{"
//                 "\"chainId\":\"" + chainIdB64 +
//                 "\",\"gasPrice\":\"" + gasPriceB64 +
//                 "\",\"gasLimit\":\"" + gasLimitB64 +
//                 "\",\"toAddress\":\"" + address +
//                 "\",\"transaction\":{\"transfer\":{\"amount\":\"" + amountB64 +
//                 "\"}}}";            

//     Data privKeyData = parse_hex(privateKey);
//     TWData* data = TWDataCreateWithBytes(privKeyData.data(), privKeyData.size());
//     TWPrivateKey * privateKeyImported = TWPrivateKeyCreateWithData(data);
//     auto secretPrivKey = TWPrivateKeyData(privateKeyImported);

//     auto json = TWStringCreateWithUTF8Bytes(transaction.c_str());
//     auto result = TWAnySignerSignJSON(json, secretPrivKey, TWCoinTypeEthereum);
//     auto signedTransaction = string(TWStringUTF8Bytes(result));
  
//     cout << "Signed transaction data (to be broadcast to network):  (len " << signedTransaction.length() << ") '" << signedTransaction << "'" << endl;
//     return signedTransaction;
// }

string decimalToHex(int decimal){
    int remainder, product = 1;
    string hex_dec = "";
    while (decimal != 0) {
    remainder = decimal % 16;
    char ch;
    if (remainder >= 10)
      ch = remainder + 55;
    else
      ch = remainder + 48;
    hex_dec += ch;
  
    decimal = decimal / 16;
    product *= 10;
  }
  reverse(hex_dec.begin(), hex_dec.end());
  return hex_dec;
}

string base64(const std::vector<char>& data)
{
  std::string::size_type  i;
  char               c;
  unsigned int       len = data.size();
  std::string             ret;

  for (i = 0; i < len; ++i)
  {
    c = (data[i] >> 2) & 0x3f;
    ret.append(1, cvt[c]);
    c = (data[i] << 4) & 0x3f;
    if (++i < len)
      c |= (data[i] >> 4) & 0x0f;

    ret.append(1, cvt[c]);
    if (i < len)
    {
      c = (data[i] << 2) & 0x3f;
      if (++i < len)
        c |= (data[i] >> 6) & 0x03;

      ret.append(1, cvt[c]);
    }
    else
    {
      ++i;
      ret.append(1, fillchar);
    }

    if (i < len)
    {
      c = data[i] & 0x3f;
      ret.append(1, cvt[c]);
    }
    else
    {
      ret.append(1, fillchar);
    }
  }

  return(ret);
}