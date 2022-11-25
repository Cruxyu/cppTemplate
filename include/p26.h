
class Row {
    char* symbols;
    char** words;
    unsigned long symbolsCount = 0;
    int wordsCount = 0;
    void sortWords();
public:
    Row(char*);
    unsigned long getSymbolsCount();
    int getWordsCount();
    void addWord(char*);
    void prettyPrint();
    ~Row();
};

char* wordToLower(char*);
int checkSymbol(char c);
