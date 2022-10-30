#Encryption

## The algorythm

AES - Advanced encryption standard. 

Parameters: 

1. block size **128 bits**
2. mode **CTR** (counter)

### Key derivation function

####1. Scrypt 

Parameters:

1. Key length: dKLen=32
2. Iterations: p=16384
3. Memory cost: r=8
4. Parallelization: n4


###2. PBKDF2

PBE Ciphers: pbkdf2HmacSha256 

params: 

Key length: 32

Iterations: 262144


How encryption works in Trust Wallet
```json
{
  "activeAccounts": [
    {
      "address": "0xA3Dcd899C0f3832DFDFed9479a9d828c6A4EB2A7",
      "coin": 60,
      "derivationPath": "m/44'/60'/0'/0/0",
      "publicKey": "0448a9ffac8022f1c7eb5253746e24d11d9b6b2737c0aecd48335feabb95a179916b1f3a97bed6740a85a2d11c663d38566acfb08af48a47ce0c835c65c9b23d0d"
    }
  ],
  "crypto": {
    "cipher": "aes-128-ctr",
    "cipherparams": {
      "iv": "ca9414fa727828808cf6c6b3267c3970"
    },
    "ciphertext": "fa189bd89c277828fb7bb1c3a1b1506e92963a3cb8dfe1be48c74d6d6d2e9fc8",
    "kdf": "scrypt",
    "kdfparams": {
      "dklen": 32,
      "n": 16384,
      "p": 4,
      "r": 8,
      "salt": ""
    },
    "mac": "6cdfeac3862d535b457d41e8a5d5f937f6cc5dd52bd4caa7345a11202036da7b"
  },
  "id": "a4d0742f-bffa-4ce6-9af7-6a7170200348",
  "name": "ecnryptedKey",
  "type": "private-key",
  "version": 3
}
```

Where the **ciphertext** is the encrypted **master Private Key** of the HD wallet. With the given JSON decryption goes all the way back extracting private key. 
The **mac** field is stands for the keyed-hash message authentication code of the encrypted data and second block of the derived key.
Computed with the Keccak SHA256 hash function. 