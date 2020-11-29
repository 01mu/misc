#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <stdbool.h>

char * init_word(char ** word, int ws) {
    int i, wc = 0;
    char * str = NULL;

    for(i = 0; i < ws; i++) {
        wc += strlen(word[i]);
    }

    str = malloc(sizeof(char) * wc + 1);
    str[0] = '\0';

    for(i = 0; i < ws; i++) {
        sprintf(str, "%s%s", str, word[i]);
    }

    return str;
}

bool arrayStringsAreEqual(char ** word1, int word1Size, char ** word2, int word2Size) {
    return strcmp(init_word(word1, word1Size), init_word(word2, word2Size)) == 0;
}

int main()
{
    char * word1[2] = {"ab", "c"}, * word2[2] = {"a", "bc"};
    int word1Size = 2, word2Size = 2;

    printf("%i\n", arrayStringsAreEqual(word1, word1Size, word2, word2Size));
}
