package io.openfuture.wallet.jni;

public class Aes {
    public static native String encryptAes(String data, String password);
    public static native String decryptAes(String encryptedData, String password);
}
