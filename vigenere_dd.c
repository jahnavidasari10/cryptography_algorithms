#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Function to perform Auto key encryption
void Auto_enc(int key, FILE *input, FILE *encrypt) {
    int ch, enc;
    int prev = key;
    while ((ch = fgetc(input)) != EOF) {
        if (isupper(ch)) {
            enc = (ch - 'A' + prev) % 26 + 'A';
            prev = (ch - 'A') % 26;
        } else if (islower(ch)) {
            enc = (ch - 'a' + prev) % 26 + 'a';
            prev = (ch - 'a') % 26;
        } else if (ch == ' ') {
            enc = ' ';
        }
        fputc(enc, encrypt);
    }
}

// Function to perform Auto key decryption
void Auto_dec(int key, FILE *encrypt, FILE *decrypt) {
    int ch, dec;
    int rev = key;
    while ((ch = fgetc(encrypt)) != EOF) {
        if (isupper(ch)) {
            dec = (ch - 'A' - rev + 26) % 26 + 'A';
            rev = (dec - 'A') % 26;
        } else if (islower(ch)) {
            dec = (ch - 'a' - rev + 26) % 26 + 'a';
            rev = (dec - 'a') % 26;
        } else if (ch == ' ') {
            dec = ' ';
        }
        fputc(dec, decrypt);
    }
}

// Function to perform Vigenere encryption
void Vigenere_enc(char *vkey, FILE *input, FILE *encrypt) {
    int ch, enc;
    int i = 0;
    int keyLength = strlen(vkey);
    
    while ((ch = fgetc(input)) != EOF) {
        if (isalpha(ch)) {
            if (isupper(ch)) {
                enc = ((ch - 'A' + (vkey[i] - 'A')) % 26) + 'A';
            } else {
                enc = ((ch - 'a' + (vkey[i] - 'a')) % 26) + 'a';
            }
            fputc(enc, encrypt);
            i = (i + 1) % keyLength;
        } else {
            fputc(ch, encrypt);
        }
    }
}

// Function to perform Vigenere decryption
void Vigenere_dec(char *vkey, FILE *encrypt, FILE *decrypt) {
    int ch, dec;
    int i = 0;
    int keyLength = strlen(vkey); 
    
    while ((ch = fgetc(encrypt)) != EOF) {
        if (isalpha(ch)) {
            if (isupper(ch)) {
                dec = ((ch - 'A' - (vkey[i] - 'A') + 26) % 26) + 'A';
            } else {
                dec = ((ch - 'a' - (vkey[i] - 'a') + 26) % 26) + 'a';
            }
            fputc(dec, decrypt);
            i = (i + 1) % keyLength;
        } else {
            fputc(ch, decrypt);
        }
    }
}

int main(void) {
    int choice;
    int key;
    char vkey[10];
    printf("1. Vigenere Cipher\n2. Auto key cipher\n");
    scanf("%d", &choice);
    
    // Open the input and output files
    FILE *input = fopen("input.txt", "r");
    FILE *encrypt = fopen("encrypted.txt", "w");
    
    switch(choice){
        case 1:
            printf("Enter key: ");
            scanf("%s", vkey);
            Vigenere_enc(vkey, input, encrypt);
            break;
        case 2:
            scanf("%d", &key);
            Auto_enc(key, input, encrypt);
            break;
    }
    
    fclose(encrypt);
    encrypt = fopen("encrypted.txt", "r");
    FILE *decrypt = fopen("decrypted.txt", "w");
    
    switch(choice){
        case 1:
            Vigenere_dec(vkey, encrypt, decrypt);
            break;
        case 2:
            Auto_dec(key, encrypt, decrypt);
            break;
    }
    
    // Close the encrypted and decrypted files
    fclose(encrypt);
    fclose(decrypt);
    
    return 0;
}