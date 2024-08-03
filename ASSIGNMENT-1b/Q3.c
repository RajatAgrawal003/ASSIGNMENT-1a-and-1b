#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000
#define MAX_WORD_LENGTH 50
typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int findWord(WordCount words[], int numWords, const char *word) {
    for (int i = 0; i < numWords; i++) {
        if (strcmp(words[i].word, word) == 0) {
            return i;
        }
    }
    return -1;
}
int main() {
    char paragraph[MAX];
    WordCount words[MAX];
    int numWords = 0;
    printf("Enter a paragraph: ");
    fgets(paragraph, MAX, stdin);
   char *token = strtok(paragraph, " \n\t");
    while (token != NULL) {
        int index = findWord(words, numWords, token);
        if (index == -1) {
            strcpy(words[numWords].word, token);
            words[numWords].count = 1;
            numWords++;
        } else {
            words[index].count++;
        }
        token = strtok(NULL, " \n\t");
    }

    printf("Word frequencies:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}
