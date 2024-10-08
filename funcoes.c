#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clearBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}