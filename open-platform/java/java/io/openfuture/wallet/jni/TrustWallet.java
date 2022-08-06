package io.openfuture.wallet.jni;

public class TrustWallet {
    public static native String generateHDWallet();

    public static native String importPrivateKey(String privateKey, int coinType);

    public static native String generateAddress(String seedCode, int coinType);

    public static native String generatePrivateKey(String seedCode, int coinType);

    public static native String signTransaction(String privateKey,
                                                String address,
                                                String chainId,
                                                long gasPrice,
                                                long gasLimit,
                                                long amount);
}
