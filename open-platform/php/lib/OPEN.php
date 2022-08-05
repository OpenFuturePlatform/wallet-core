<?php

class OPEN
{

    public function generateWallet()
    {
        return wallet_generate();
    }

    public function importWallet($privateKey, $coinType)
    {
        return wallet_import($privateKey, $coinType);
    }

    public function sign($privateKey, $address, $chainId, $gasPrice, $gasLimit, $amount)
    {
        return wallet_sign($privateKey, $address, $chainId, $gasPrice, $gasLimit, $amount);
    }

}