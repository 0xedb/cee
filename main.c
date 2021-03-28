#include <stdio.h>
#include "include/token.h"

int main() {
    token_t* test = init_token("false", 2);
    
    printf("\n%s", test -> token);
    printf("\n%d", test -> type);
    return 0;
}