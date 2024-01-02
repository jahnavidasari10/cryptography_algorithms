#include<stdio.h>
void encrypt(char input[],int key,char output[]){
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
void decrypt(char input[],int key,char output[],char keyIndex[]){
    int i;
    for( i=0;input[i]!='\0';i++){
        int temp;
        if(input[i]>='A'&&input[i]<='Z'){
			temp=keyIndex[i]-'A';
			if((input[i]-'A'-temp)%26 <0){
                printf("%d",input[i]-'A'-key);
                output[i]=(((input[i]-'A'-key)%26)+26)+'A';
            }
            else if((input[i]-'A'-temp)%26 >=0){
                printf("%d",input[i]-'A'-key);
                output[i]=((input[i]-'A'-key)%26)+'A';
            }
		}
		else if(input[i]>='a'&& input[i]<='z'){
			temp=keyIndex[i]-'a';
            if((input[i]-'a'-key)%26 <0){
                printf("%d \n",input[i]-'a'-key+26);
                output[i]=(((input[i]-'a'-key)%26)+26)+'a';
            }
            else if((input[i]-'a'-key)%26 >=0){
                printf("%d \n",input[i]-'a'-key);
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

    encrypt(input, key, encrypted);
    FILE *encryptFile = fopen("encrypted.txt", "w");
    fprintf(encryptFile, "%s", encrypted);
    fclose(encryptFile);
    decrypt(encrypted, key, decrypted,input);
    FILE *decryptFile = fopen("decrypted.txt", "w");
    fprintf(decryptFile, "%s", decrypted);
    fclose(decryptFile);

	return 0;
}