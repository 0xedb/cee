#ifndef C_LEXER
#define C_LEXER

#include "token.h"

typedef struct {
  int pos, offset;
  const char *src;
  unsigned char ch;
} lexer_t;

// readchar

void read_char(lexer_t *l);

token_t *next_token(lexer_t *l);

void eat_whitespace(lexer_t *l);

#endif