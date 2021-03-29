#include "token.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *tokens[] = {
    [ILLEGAL] = "ILLEGAL", [END] = "EOF",

    [IDENT] = "IDENT",     [INT] = "int",     [STRING] = "\"", [ASSIGN] = "=",
    [COMMA] = ",",         [SEMICOLON] = ";", [PLUS] = "+",    [MINUS] = "-",
    [DIV] = "/",           [MULT] = "*",      [LST] = "<",     [GRT] = ">",
    [EQL] = "==",          [NQL] = "!=",      [NOT] = "!",     [DOT] = ".",
    [FUNCTION] = "fn",     [LET] = "let",     [IF] = "if",     [EL] = "el",
    [RET] = "ret",         [COLON] = ":",     [LPAREN] = "(",  [RPAREN] = ")",
    [LCURL] = "{",         [RCURL] = "}",     [LBRAC] = "[",   [RBRAC] = "]",

};

void token_print(token_t *t) {
  printf("%s \t %s\n", tokens[t->type], t->literal);
}

_Bool token_is_letter(char c) { return isalpha(c) || (c == '_'); }

_Bool token_is_number(char c) { return isdigit(c); }

_Bool token_is_keyword(token_t *t) {
  return t->type > keyword_beg && t->type < keyword_end;
}

token_t *token_init(const char *t, int type) {
  token_t *token = (token_t *)calloc(1, sizeof(token_t));

  token->literal = t;
  token->type = type;

  return token;
}

enum token_type token_lookup_identifier(const char *ch) {
  for (size_t i = keyword_beg + 1; i < keyword_end; ++i) {
    if (strcmp(tokens[i], ch) == 0) {
      return i;
    }
  }

  return IDENT;
}