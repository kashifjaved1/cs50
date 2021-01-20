#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(){

    string text = get_string("Text: ");

    int total_letters = count_letters(text);
    int total_words = count_words(text);
    int total_sentences = count_sentences(text);

    printf("%i, %i, %i\n", total_letters, total_words, total_sentences);

    float L = (total_letters / (float) total_words) * 100;

    float S = (total_sentences / (float) total_words) * 100;

    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if(index < 1){
        printf("Before Grade 1\n");
    }
    else if(index >= 16){
        printf("Grade 16+\n");
    }
    else{
        printf("Grade %i\n", index);
    }

}

int count_letters(string text){

    int letters = 0;

    for(int i = 0; i <= strlen(text); i++){

        if(isalpha(text[i]) && !isspace(text[i])){

            letters++;

        }

    }

    return letters;

}

int count_words(string text){

    int words = 0;

    for(int i = 0; i <= strlen(text); i++){

        if(isspace(text[i])){

            words++;

        }

    }

    return words + 1;

}

int count_sentences(string text){

    int sentences = 0;

    for(int i = 0; i <= strlen(text); i++){

        if(text[i] == '.' || text[i] == '!' || text[i] == '?'){

            sentences++;

        }

    }

    return sentences;

}