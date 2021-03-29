#include <stdlib.h>
#include "token.h"


token_t* init_token(const char *tok, int type) {
    token_t* token = (token_t*)calloc(1, sizeof(token_t));

    token ->literal = tok;
    token ->type = type;

    return token;
}