#include <stdio.h>
int main(){
	FILE *inputFile,*outputFile;
	char inputFileName[]="plaintext.txt";
	char outputFileName[]="ciphertext.txt";
	int key;
	printf("Enter key: \n");
	scanf("%d",&key);
	inputFile=fopen(inputFileName,"r");
	if(inputFile==NULL){
		printf("error");
		return 0;
	}
	outputFile=fopen(outputFileName,"w");
	if(outputFile==NULL){
		printf("Error");
		return 0;
	}
	char ch;
	while((ch=fgetc(inputFile))!=EOF){
		if(ch>='A' && ch<='Z'){
			ch=(((ch-'A')+key)%26)+'A';
		}
		else{
			ch=(((ch-'a')+key)%26)+'a';
		}
		fputc(ch,outputFile);
	}
	fclose(inputFile);
	fclose(outputFile);
	inputFile=fopen(inputFileName,"r");
	printf("original: \n");
	while((ch=fgetc(inputFile))!=EOF){
		printf("%c",ch);
	}
	outputFile=fopen(outputFileName,"r");
	printf("\nEncrypted: \n");
	while((ch=fgetc(outputFile))!=EOF){
		printf("%c",ch);
	}
	return 0;
}