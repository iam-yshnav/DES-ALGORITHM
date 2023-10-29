#include <stdio.h>
#include <string.h>

// Simplified DES encryption (XOR operation)
void desEncrypt(char *plaintext, char *ciphertext, char *key) {
    for (int i = 0; i < 64; i++) {
        ciphertext[i] = (plaintext[i] - '0') ^ (key[i] - '0') + '0'; // XOR operation with the key
    }
    ciphertext[64] = '\0'; // Null-terminate the string
}

// Simplified DES decryption (XOR operation)
void desDecrypt(char *ciphertext, char *plaintext, char *key) {
    for (int i = 0; i < 64; i++) {
        plaintext[i] = (ciphertext[i] - '0') ^ (key[i] - '0') + '0'; // XOR operation with the key
    }
    plaintext[64] = '\0'; // Null-terminate the string
}

int main() {
    char plaintext[65]; // Increased size to accommodate the null terminator
    char key[65];
    char ciphertext[65];

    printf("Enter the 64-bit plaintext: ");
    scanf("%s", plaintext);

    printf("Enter the 64-bit key: ");
    scanf("%s", key);

    if (strlen(plaintext) < 64) {
        // Pad with zeros
        for (int i = strlen(plaintext); i < 64; i++) {
            plaintext[i] = '0';
        }
        plaintext[64] = '\0'; // Null-terminate the string
    } else if (strlen(plaintext) > 64) {
        // Truncate to 64 bits
        plaintext[64] = '\0'; // Null-terminate the string
    }

    if (strlen(key) < 64) {
        // Pad with zeros
        for (int i = strlen(key); i < 64; i++) {
            key[i] = '0';
        }
        key[64] = '\0'; // Null-terminate the string
    } else if (strlen(key) > 64) {
        // Truncate to 64 bits
        key[64] = '\0'; // Null-terminate the string
    }

    desEncrypt(plaintext, ciphertext, key);
    printf("Ciphertext: %s\n", ciphertext);

    desDecrypt(ciphertext, plaintext, key);
    printf("Decrypted: %s\n", plaintext);

    return 0;
}
