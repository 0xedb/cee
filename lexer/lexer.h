#include "../token/token.h"

#ifndef LEXER_H
#define LEXER_H

typedef struct {
  const char *input;
  unsigned int pos, offset;
  char ch;
} lexer_t;

lexer_t *lexer_init(const char *i);

void lexer_read_char(lexer_t *l);

token_t *lexer_next_token(lexer_t *l);

void lexer_eat_whitespace(lexer_t *l);

char lexer_peek_offset(lexer_t *l);

char lexer_peek_cur(lexer_t *l);

const char *lexer_read_number(lexer_t *l);

const char *lexer_read_identifier(lexer_t *l);

#endif // LEXER_H