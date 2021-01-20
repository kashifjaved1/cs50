#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void ciphertext(string key, string text);

int main(int argc, string argv[])
{
    int valid = 0, count = 0;
    string plaintext = get_string("Plaintext: ");
    
    for(int i = 0; i < strlen(argv[1]); i++){
        if(argv[1][i] == argv[1][i + 1]){
            printf("INVALID KEY, Repeated Alphabets not allowed.");
            break;
        }
        else if(!isalpha(argv[1][i])){
            printf("INVALID KEY, Only Alphabets are allowed.");
            break;
        }
        else{
            valid = 1;
            count++;
        }
    }

    if(valid == 1 && count == 26){
        printf("Ciphertext: ")
        ciphertext(argv[1], plaintext);
    }

}

void ciphertext(string key, string text){
    int index = 0;
    for(int i = 0; i <= strlen(text); i++){
    	if(isalpha(text[i])){
    		index = tolower(text[i]) - 'a';
            if(isupper(text[i])){
                printf("%c", toupper(key[index]));
            }
            else{
                printf("%c", tolower(key[index]));
            }
    	}
    }
}
