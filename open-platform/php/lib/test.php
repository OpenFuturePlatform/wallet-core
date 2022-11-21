<?php

require "OPEN.php";

$open = new OPEN();
$open->setApiKey("op_jGbshr6NCZvQM2rpX4+8");
$open->setSecretKey("op_UUu2Zu4Aam+eKnmnYc1rbeXj0Jj85QjxZWeDSzKf");


$result = $open->generateWallet(195);
echo "Address: " . $result[0]  . "\n";
echo "Private Key: " . $result[1]  . "\n";

//$open->getNonce("0x4a171823A277Fdf0E8e3438b1382cb500608Aa38", "ETH");

//echo "\nImport address from Private Key\n";
//$prvKey = "0x15e9df2c39a3d2b12f9e72e23cabeaccd2cd25255a816f4d0b30e39188e3ece4";
//$address = $open->importWallet($result[1], 1);
//echo $address . "\n";

// $privateKey = "723b79529c433a8ed714e8f2d67288a09faa0c75aba40a1968d2be65aee1c04f";

// $address = $open->importWallet($privateKey, 60);
// echo "\nImport address from Private Key\n";
// echo $address . "\n";
// $toAddress = "0x014D9Fcdb245CF31BfbaD92F3031FE036fE91Bc3";
// $goerliChainId = "05";
// $gasPrice = "42000000000"; //22GWei 
// $gasLimit = "21000";
// $amount = "924400000000000"; //0.0009244 ETH
// $nonce = 3;
// $signature = $open->sign($privateKey, $toAddress, $goerliChainId, $gasPrice, $gasLimit, $amount, $nonce);
// echo "\nSignature: ";
// echo $signature . "\n";

// $trxReceipt = $open->broadcast($signature, 60);
// echo "\nBroadcast result: ";
// echo $trxReceipt . "\n";