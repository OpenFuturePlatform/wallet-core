<?php

class OPEN
{

    /**
     *  @var string The OPEN api key to be used for requests. 
     */
    public static $apiKey;

    /** 
     * @var string The OPEN secret key to be used for requests. 
     */
    public static $secretKey;

    /** 
     * @var string The base URL for the OPEN API.
     */
    public static $apiBase = 'https://api.openfuture.io/public/api/v1/';
    


    public static function getApiKey()
    {
        return self::$apiKey;
    }


    public static function getSecretKey()
    {
        return self::$secretKey;
    }

    public static function setApiKey($apiKey)
    {
        self::$apiKey = $apiKey;
    }

    public static function setSecretKey($secretKey)
    {
        self::$secretKey = $secretKey;
    }

    public function generateWallet($coinType = 60)
    {
        $generatedWallet = wallet_generate($coinType);

        $timeStamp = self::get_timestamp();
        $args = array(
            'address'   => $generatedWallet[0],
            "blockchain" => self::get_coin($coinType),
            'timestamp' => strval($timeStamp),
        );
        $hash = self::get_signature($args);
        self::send_request("wallet/save", $hash, $args);

        return $generatedWallet;
    }

    public function importWallet($privateKey, $coinType)
    {
        return wallet_import($privateKey, $coinType);
    }

    public function getNonce($address, $network)
    {

        $timeStamp = self::get_timestamp();
        $args = array(
            'address'   => $address,
            "blockchain" => $network,
            'timestamp' => strval($timeStamp),
        );
        $hash = self::get_signature($args);
        self::send_request("wallet/fetch", $hash, $args);
    }

    public function sign($privateKey, $address, $chainId, $gasPrice, $gasLimit, $amount, $nonce)
    {
        return wallet_sign($privateKey, $address, $chainId, $gasPrice, $gasLimit, $amount, $nonce);
    }

    public function broadcast($signedTransaction, $coinType = 60)
    {
        $timeStamp = self::get_timestamp();
        $args = array(
            'address'   => $signedTransaction,
            "blockchain" => self::get_coin($coinType),
            'timestamp' => strval($timeStamp),
        );
        $hash = self::get_signature($args);
        return self::send_request("wallet/broadcast", $hash, $args);
    }

    public function encrypt($privateKey, $password)
    {
        return wallet_encrypt($privateKey, $password);
    }

    public function decrypt($data, $password)
    {
        return wallet_decrypt($data, $password);
    }

    public static function get_timestamp(): int
    {
        $currentDate = new DateTime();
        //echo "Current Date: " . $currentDate->format('Y-m-d H:i:s') . "\n";
        return $currentDate->getTimestamp();
    }

    public static function get_signature($args): string
    {
        $jsonString = json_encode($args);
        return hash_hmac('sha256', $jsonString, self::$secretKey);
    }

    public static function send_request(string $endpoint, string $hash, array $params = array())
    {

        $headers = array(
            'OPEN-API-KEY: ' . self::$apiKey,
            'OPEN-API-SIGNATURE: ' . $hash,
            'Content-Type: application/json'
        );

        //echo "Hash: " . $hash . "\n";

        $url = self::$apiBase . $endpoint;

        $payload = json_encode($params);

        $ch = curl_init();

        curl_setopt($ch, CURLOPT_URL, $url);
        curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
        curl_setopt($ch, CURLOPT_POSTFIELDS, $payload);
        curl_setopt($ch, CURLOPT_HTTPHEADER, $headers);
        curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, FALSE);
        curl_setopt($ch, CURLOPT_POST, true);

        $response = curl_exec($ch);

        curl_close($ch);

        return $response;
    }

    public static function get_coin($coinCode)
    {
        switch ($coinCode) {
            case 0:
                return "BTC";
            case 60:
                return "ETH";
            case 714:
                return "BNB";
            default:
                return "ETH";
        }
    }
}
