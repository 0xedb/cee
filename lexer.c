#include <string.h>
#include <stdlib.h>
#include "include/lexer.h"

void read_char(lexer_t* l) {
    if(l -> offset >= strlen(l -> src)) {
        l -> offset = 0;
        l -> ch = 0;  
    } else {
        l -> ch = l -> src[l -> offset];
    }

    l -> pos = l -> offset;
    ++l->offset;
}

token_t* next_token(lexer_t *l) {
    token_t* tok = (token_t*)calloc(1, sizeof(token_t));
    return NULL;
}

void eat_whitespace(lexer_t *l) {
    while(l -> ch == ' ' || l -> ch == '\t' || 
    l -> ch == '\r' || l -> ch == '\n')
    
    read_char(l);
}

