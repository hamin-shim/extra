//
// Created by 심하민 on 2023/01/31.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int len;
    char word[51]
} word_info;

int compare(const void*a, const void*b){
    word_info *word1 = (word_info*) a;
    word_info *word2 = (word_info*) b;
    if(word1->len ==word2->len){
        return strcmp(word1->word, word2->word);
    }
    return word1->len<word2->len ? -1 : 1;
}

int main(){
    int N;
    scanf("%d", &N);
    word_info * words = (word_info*) malloc(sizeof (word_info)*N);
    for(int i=0;i<N;i++){
        scanf("%s", words[i].word);
        words[i].len = strlen(words[i].word);
    }
    qsort(words, N, sizeof (word_info), compare);
    for(int i=0;i<N;i++){
        if(i!=0 && !strcmp(words[i].word,words[i-1].word)) continue;
        else printf("%s\n", words[i].word);
    }
}