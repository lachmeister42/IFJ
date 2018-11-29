#include "main.h"


int main(int argC, char ** argV){
    initGC();
    initParser(stdin);
    parse();
    deInitGC();
    return 0;
}
