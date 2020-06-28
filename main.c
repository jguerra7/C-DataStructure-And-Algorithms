#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "Trie.h"
#include "Headers/ArrayList.h"
int main() {


    Trie *trie = trieInitialization();

    trieAddWord(trie, "mostafa");

    //trieRemoveWord(trie, "mostafa");

    trieAddWord(trie, "mohammad");

    ArrayList *list = trieSuggestion(trie, "moytafa", 1);

    for (int i = 0; i < arrayListGetLength(list); i++) {
        char *word = arrayListGet(list, i);
        printf("%s\n", word);
    }

}
