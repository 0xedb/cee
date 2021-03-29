#include "token.h"
#include <stdio.h>
#include <stdlib.h>

const char *tokens[] = {
    [ILLEGAL] = "ILLEGAL", [END] = "EOF",

    [IDENT] = "IDENT",     [INT] = "int",     [STRING] = "\"", [ASSIGN] = "=",
    [COMMA] = ",",         [SEMICOLON] = ";", [PLUS] = "+",    [MINUS] = "-",
    [DIV] = "/",           [MULT] = "*",      [LST] = "<",     [GRT] = ">",
    [EQL] = "==",          [NQL] = "!=",

    [FUNCTION] = "fn",     [LET] = "let",     [IF] = "if",     [EL] = "el",
    [RET] = "ret"

};

void token_print(token_t *tok) {
  printf("%s: %s", tokens[tok->type], tok->literal);
}

_Bool token_is_keyworkd(token_t *tok) {
  return tok->type > keyword_beg && tok->type < keyword_end;
}

token_t *token_init(const char *tok, int type) {
  token_t *token = (token_t *)calloc(1, sizeof(token_t));

  token->literal = tok;
  token->type = type;

  return token;
}
