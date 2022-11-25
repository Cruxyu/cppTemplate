#include "p26.h"
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <stdio.h>
#include <ctype.h>


using namespace std;


Row::~Row(){
    for(int i = 0; i < wordsCount; i++){
        delete words[i];
    }
    delete []words;
    delete []symbols;
}

Row::Row(char* argv) {
    this->symbolsCount = strlen(argv);
    symbols = new char[this->symbolsCount];
    for(unsigned long i = 0; i < this->symbolsCount; i++) {
        if(checkSymbol(argv[i]) == 0) {
            cout << "You can only use symbols > and <" << endl;
            exit(-1); }
        symbols[i] = argv[i];
    }
    words = new char*[this->symbolsCount+1];
}

char* wordToLower(char* word) {
    // TODO: FIX static_cast
    for(unsigned long i = 0; i < strlen(word); i++){
        word[i] = static_cast<char>(tolower(word[i]));
    }
    return word;
}

void Row::addWord(char* word) {
    int i;
    for (i = this->wordsCount; i > 0; i--) {
        if (strcmp(this->words[i-1], word) > 0) {
            this->words[i] = this->words[i-1];
        }else{
            break;
        }
    }
    this->words[i] = new char[strlen(word)];
    strcpy(this->words[i], wordToLower(word));
    this->wordsCount++;
}


void Row::prettyPrint() {
    int tailCount = this->wordsCount-1, headCount = 0;
    for(unsigned long i = 0; i < this->symbolsCount; i++) {
        cout << this->words[symbols[i]=='>'?tailCount--:headCount++] << " " << symbols[i] << " ";
    }
    cout << this->words[headCount] << endl;
}

unsigned long Row::getSymbolsCount(){
    return this->symbolsCount;
}

int Row::getWordsCount(){
    return this->wordsCount;
}

int checkSymbol(char c) {
    return (c == '>' || c == '<') ? 1 : 0;
}
