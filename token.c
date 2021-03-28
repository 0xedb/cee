#include <stdio.h>
#include <stdlib.h>
#include "include/token.h"
 
token_t* init_token(const char* tok, int type) {
    token_t* token = (token_t*) calloc(1, sizeof(token_t));
    token -> type = type;
    token -> token = tok;

    return token;
}

void print_token(token_t* tok) {
    printf("%d  %s\n", tok -> type, tok ->token );
}