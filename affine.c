#include <stdio.h>


void encrypt(char input[], int key1,int key2, char output[]) {
    int i;
    for (i = 0; input[i] != '\0'; i++) {
        if (input[i] >= 'a' && input[i] <= 'z') {
            output[i] = (((input[i] - 'a') * key1)+ key2) % 26 + 'a';
        } else if (input[i] >= 'A' && input[i] <= 'Z') {
            output[i] = (((input[i] - 'A') * key1)+ key2) % 26 + 'A';
        } else {
            output[i] = input[i];
        }
    }
    output[i] = '\0';
}


void decrypt(char input[], int key1,int key2, char output[]) {
    int i, key_inverse;
    
    for (key_inverse = 1; key_inverse < 26; key_inverse++) {
        if ((key1 * key_inverse) % 26 == 1) {
            key1=key_inverse;
            break;
        }
    }
    //key2=(26-key2)%26;
    for (i = 0; input[i] != '\0'; i++) {
        if (input[i] >= 'a' && input[i] <= 'z') {
            output[i] = (key1*(input[i] + 'a'-key2)%26)+ 'a';
        } else if (input[i] >= 'A' && input[i] <= 'Z') {
            output[i] = ((key1*(input[i] +'A'-key2)%26))  + 'A';
        } else {
            output[i] = input[i];
        }
    }
    output[i] = '\0';
}

int main() {
    char  input[1000],encrypted[1000], decrypted[1000];
    int key1,key2;

    FILE *inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening file \n");
        return 1;
    }
    fgets(input, sizeof(input), inputFile);
    fclose(inputFile);
    printf("Enter the key1 for encryption: ");
    scanf("%d", &key1);
    printf("Enter the key2 for encryption: ");
    scanf("%d", &key2);

    encrypt(input, key1,key2, encrypted);
    FILE *encryptFile = fopen("encrypted.txt", "w");
    fprintf(encryptFile, "%s", encrypted);
    fclose(encryptFile);

    decrypt(encrypted, key1,key2, decrypted);
    FILE *decryptFile = fopen("decrypted.txt", "w");
    fprintf(decryptFile, "%s", decrypted);
    fclose(decryptFile);

    return 0;
}
