#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void keyGenerator(char input[],char key[],char newKey[]){
    int keyLen=strlen(key);
    int i,j=0;
    for(i=0;input[i]!='\0';i++,j++){
        if(j==keyLen){
            j=0;
        }
        newKey[i]=key[j];
    }
    newKey[i]='\0';
}
void vigenere_encrypt(char input[],char newKey[],char output[]){
    int i;
    for(i=0;input[i]!='\0';i++){
        if(input[i]>='A' && input[i]<='Z'){
            output[i]=(input[i]-'A'+ newKey[i]-'A')%26 +'A';
        }
        else if(input[i]>='a' && input[i]<='z'){
            output[i]=(input[i]-'a'+ newKey[i]-'a')%26 +'a';
        }
        else{
            output[i]=input[i];
        }
    }
    output[i]='\0';
}
void vigenere_decrypt(char input[],char newKey[],char output[]){
    int i;
    for(i=0;input[i]!='\0';i++){
        if(input[i]>='A' && input[i]<='Z'){
            if((input[i]-'A')- (newKey[i]-'A')<0){
                output[i]=((input[i]-'A')- (newKey[i]-'A'))%26 +26 +'A';
            }
            else{
                output[i]=((input[i]-'A')- (newKey[i]-'A'))%26 +'A';
            }
        }
        else if(input[i]>='a' && input[i]<='z'){
            if((input[i]-'a')- (newKey[i]-'a')<0){
                output[i]=((input[i]-'a')- (newKey[i]-'a'))%26 +26 +'a';
            }
            else{
                output[i]=((input[i]-'a')- (newKey[i]-'a'))%26 +'a';
            }
        }
        else{
            output[i]=input[i];
        }
    }
    output[i]='\0';
}
void autokey_encrypt(char input[],int key,char output[]){
    int i;
    for( i=0;input[i]!='\0';i++){
        int temp;
        if(input[i]>='A'&&input[i]<='Z'){
			temp=input[i]-'A';
			output[i]=(((input[i]-'A')+key)%26)+'A';
		}
		else if(input[i]>='a'&& input[i]<='z'){
			temp=input[i]-'a';
			output[i]=(((input[i]-'a')+key)%26)+'a';
		}
		else{
            output[i]=input[i];
        }
		key=temp;
    }
    output[i] = '\0';
}
void autokey_decrypt(char input[],int key,char output[],char keyIndex[]){
    int i;
    for( i=0;input[i]!='\0';i++){
        int temp;
        if(input[i]>='A'&&input[i]<='Z'){
			temp=keyIndex[i]-'A';
			if((input[i]-'A'-temp)%26 <0){
                output[i]=(((input[i]-'A'-key)%26)+26)+'A';
            }
            else if((input[i]-'A'-temp)%26 >=0){
                
                output[i]=((input[i]-'A'-key)%26)+'A';
            }
		}
		else if(input[i]>='a'&& input[i]<='z'){
			temp=keyIndex[i]-'a';
            if((input[i]-'a'-key)%26 <0){
                
                output[i]=(((input[i]-'a'-key)%26)+26)+'a';
            }
            else if((input[i]-'a'-key)%26 >=0){
                
                output[i]=((input[i]-'a'-key)%26)+'a';
            }
            else{
            output[i]=input[i];
            }
		}
        key=temp;
    }
    output[i] = '\0';
}
int main(){
    char input[1000],encrypted[1000],decrypted[1000];
    char key[100];
    int KEY;
    printf("Enter key for autokey:\n");
    scanf("%d",&KEY);
    FILE *inputFile = fopen("plaintext.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening file 'plaintext.txt'\n");
        return 1;
    }
    fgets(input, sizeof(input), inputFile);
    fclose(inputFile);
    printf("Enter the key for vigenere encryption: ");
    scanf("%s", &key);
     char newKey[100];
    keyGenerator(input,key,newKey);
    int choice;
    printf("1.Autokey \n 2.vigenere\n");
    scanf("%d",&choice);
    if(choice==1){
        autokey_encrypt(input,KEY,encrypted);
        FILE *encryptFile = fopen("encrypted.txt", "w");
        fprintf(encryptFile, "%s", encrypted);
        fclose(encryptFile);
        autokey_decrypt(encrypted, KEY, decrypted,input);
        FILE *decryptFile = fopen("decrypted.txt", "w");
        fprintf(decryptFile, "%s", decrypted);
        fclose(decryptFile);
    }
    if(choice==2){
        vigenere_encrypt(input,newKey,encrypted);
        FILE *encryptFile = fopen("encrypted.txt", "w");
        fprintf(encryptFile, "%s", encrypted);
        fclose(encryptFile);
        vigenere_decrypt(encrypted, newKey, decrypted);
        FILE *decryptFile = fopen("decrypted.txt", "w");
        fprintf(decryptFile, "%s", decrypted);
        fclose(decryptFile);
    }

	return 0;
}