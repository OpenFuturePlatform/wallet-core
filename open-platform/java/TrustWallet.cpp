#include <jni.h>

#include <open.h>

#include <iostream>
#include <string>
#include <array>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
/* Header for class io_openfuture_wallet_jni_TrustWallet */

#ifndef _Included_io_openfuture_wallet_jni_TrustWallet
#define _Included_io_openfuture_wallet_jni_TrustWallet
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     io_openfuture_wallet_jni_TrustWallet
 * Method:    generateHDWallet
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_io_openfuture_wallet_jni_TrustWallet_generateHDWallet
  (JNIEnv *env, jclass thisObject){
    try {
        string mnemonicWord = OpenWalletGenerate();
        return env->NewStringUTF(mnemonicWord.c_str());
    } catch (const std::exception& ex) {
        std::cout << "EXCEPTION: " << ex.what() << std::endl;
        throw ex;
    }
}

/*
 * Class:     io_openfuture_wallet_jni_TrustWallet
 * Method:    importPrivateKey
 * Signature: (Ljava/lang/String;I)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_io_openfuture_wallet_jni_TrustWallet_importPrivateKey
  (JNIEnv *env, jclass thisObject, jstring jPrivateKey, jint coinType){
    try {
        jboolean isCopy;
        const char *convertedValue = (env)->GetStringUTFChars(jPrivateKey, &isCopy);
        std::string privateKey = convertedValue;
        string address = OpenImportPrivateKey(privateKey, 1);
        return env->NewStringUTF(address.c_str());
    } catch (const std::exception& ex) {
        std::cout << "EXCEPTION: " << ex.what() << std::endl;
        throw ex;
    }
}

/*
 * Class:     io_openfuture_wallet_jni_TrustWallet
 * Method:    signTransaction
 * Signature: (Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;JJJ)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_io_openfuture_wallet_jni_TrustWallet_signTransaction
  (JNIEnv *env, jclass thisObject, jstring jPrivateKey, jstring jAddress, jstring jChainId, jlong jGasPrice, jlong jGasLimit, jlong jAmount){
    try {
        jboolean isCopy;
        const char *convertedPrivateKey = (env)->GetStringUTFChars(jPrivateKey, &isCopy);
        std::string privateKey = convertedPrivateKey;
        const char *convertedAddress = (env)->GetStringUTFChars(jAddress, &isCopy);
        std::string address = convertedAddress;
        const char *convertedChainId = (env)->GetStringUTFChars(jChainId, &isCopy);
        std::string chainId = convertedChainId;

        string signature = OpenSignTransaction(privateKey, address, chainId, jGasPrice, jGasLimit, jAmount);
        return env->NewStringUTF(signature.c_str());
    } catch (const std::exception& ex) {
        std::cout << "EXCEPTION: " << ex.what() << std::endl;
        throw ex;
    }
}

#ifdef __cplusplus
}
#endif
#endif
