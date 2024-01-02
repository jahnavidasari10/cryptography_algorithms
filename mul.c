#include <stdio.h>
#include<string.h>
int gcd(int a,int b){
    if(a==0) return b;
    return gcd(b%a,a);
}
void encrypt(char input[], int key, char output[]) {
    int i;
    for (i = 0; input[i] != '\0'; i++) {
        if (input[i] >= 'a' && input[i] <= 'z') {
            output[i] = ((input[i] - 'a') * key) % 26 + 'a';
        } else if (input[i] >= 'A' && input[i] <= 'Z') {
            output[i] = ((input[i] - 'A') * key) % 26 + 'A';
        } else {
            output[i] = input[i];
        }
    }
    output[i] = '\0';
}

void decrypt(char input[], int key, char output[]) {
    int i, key_inverse;
    for (key_inverse = 1; key_inverse <=26; key_inverse++) {
        if ((key * key_inverse) % 26 == 1) {
            break;
        }
        
    }
    for (i = 0; input[i] != '\0'; i++) {
        if (input[i] >= 'a' && input[i] <= 'z') {
            output[i] = ((input[i] - 'a') * key_inverse) % 26 + 'a';
        } else if (input[i] >= 'A' && input[i] <= 'Z') {
            output[i] = ((input[i] - 'A') * key_inverse) % 26 + 'A';
        } else {
            output[i] = input[i];
        }
    }
    output[i] = '\0';
}

int main() {
    char  input[1000],encrypted[1000], decrypted[1000];
    int key;
    FILE *inputFile = fopen("plaintext.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening file 'plaintext.txt'\n");
        return 1;
    }
    fgets(input, sizeof(input), inputFile);
    fclose(inputFile);
    printf("Enter the key for encryption: ");
    scanf("%d", &key);
    if(gcd(key,26)!=1){
        printf("Invalid Key");
    }
    encrypt(input, key, encrypted);
    FILE *encryptFile = fopen("encrypted.txt", "w");
    fprintf(encryptFile, "%s", encrypted);
    fclose(encryptFile);

    decrypt(encrypted, key, decrypted);
    FILE *decryptFile = fopen("decrypted.txt", "w");
    fprintf(decryptFile, "%s", decrypted);
    fclose(decryptFile);

    return 0;
}
