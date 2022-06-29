package io.openfuture.trustwallet;

public class HDWallet {
    static native long nativeCreate(int strength, String passphrase);

    static native void importPrivateKey(String rawPrivateKey);
}
