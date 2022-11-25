#include "p26.h"
#include <iostream>

int main(int argc, char** argv) {
    if(argc != 2) {
        std::cout << "Usage example: ./a.out \">><<>\"" << std::endl;
        return -1;
    }
    Row row(argv[1]);
    char word[256];
    for(unsigned long count = 0; count <= row.getSymbolsCount(); count++){
        std::cin >> word;
        row.addWord(word);
    }
    row.prettyPrint();
    return 0;
}
