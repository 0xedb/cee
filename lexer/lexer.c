#include "lexer.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

lexer_t *lexer_init(const char *i) {
  lexer_t *l = (lexer_t *)calloc(1, sizeof(lexer_t));
  l->input = i;

  lexer_read_char(l);

  return l;
}

void lexer_read_char(lexer_t *l) {
  if (l->offset >= strlen(l->input)) {
    l->ch = 0;
  } else {
    l->ch = l->input[l->offset];
  }
  l->pos = l->offset;
  ++(l->offset);
}

char lexer_peek_offset(lexer_t *l) {
  if (l->offset >= strlen(l->input))
    return 0;
  return l->input[l->offset];
}

char lexer_peek_cur(lexer_t *l) {
  if (l->offset >= strlen(l->input))
    return 0;
  return l->input[l->pos];
}

void lexer_eat_whitespace(lexer_t *l) {
  while (isspace(l->ch))
    lexer_read_char(l);
}

const char *lexer_read_number(lexer_t *l) {
  unsigned pos = l->pos;

  while (token_is_number(l->ch)) {
    lexer_read_char(l);
  }

  const unsigned sz = l->pos - pos;

  char *number = calloc(sz + 1, sizeof(char));
  number[sz] = '\0';

  for (size_t i = pos, j = 0; i < l->pos; ++i, ++j) {
    number[j] = l->input[i];
  }

  return number;
}

const char *lexer_read_identifier(lexer_t *l) {
  unsigned pos = l->pos;

  while (token_is_letter(l->ch))
    lexer_read_char(l);

  const unsigned sz = l->pos - pos;

  char *identifier = calloc(sz + 1, sizeof(char));
  identifier[sz] = '\0';

  for (size_t i = pos, j = 0; i < l->pos; ++i, ++j) {
    identifier[j] = l->input[i];
  }

  return identifier;
}

token_t *lexer_next_token(lexer_t *l) {
  token_t *tok = (token_t *)calloc(1, sizeof(token_t));
  lexer_eat_whitespace(l);

  switch (l->ch) {
  case '"':
    tok = token_init(tokens[STRING], STRING);
    break;

  case '=':
    if (lexer_peek_offset(l) == '=') {
      lexer_read_char(l);
      tok = token_init(tokens[EQL], EQL);
    } else {
      tok = token_init(tokens[ASSIGN], ASSIGN);
    }
    break;

  case ',':
    tok = token_init(tokens[COMMA], COMMA);
    break;

  case ';':
    tok = token_init(tokens[SEMICOLON], SEMICOLON);
    break;

  case '+':
    tok = token_init(tokens[PLUS], PLUS);
    break;

  case '-':
    tok = token_init(tokens[MINUS], MINUS);
    break;

  case '/':
    tok = token_init(tokens[DIV], DIV);
    break;

  case '*':
    tok = token_init(tokens[MULT], MULT);
    break;

  case '<':
    tok = token_init(tokens[LST], LST);
    break;

  case '>':
    tok = token_init(tokens[GRT], GRT);
    break;

  case ':':
    tok = token_init(tokens[COLON], COLON);
    break;

  case '(':
    tok = token_init(tokens[LPAREN], LPAREN);
    break;

  case ')':
    tok = token_init(tokens[RPAREN], RPAREN);
    break;

  case '{':
    tok = token_init(tokens[LCURL], LCURL);
    break;

  case '}':
    tok = token_init(tokens[RCURL], RCURL);
    break;

  case '[':
    tok = token_init(tokens[LBRAC], LBRAC);
    break;

  case ']':
    tok = token_init(tokens[RBRAC], RBRAC);
    break;

  case '!':
    // equal or not equal
    if (lexer_peek_offset(l) == '=') {
      lexer_read_char(l);
      tok = token_init(tokens[NQL], NQL);
    } else
      tok = token_init(tokens[NOT], NOT);
    break;

  case 0:
    return token_init(tokens[END], END);

  default:
    if (token_is_letter(l->ch)) {
      tok->literal = lexer_read_identifier(l);
      tok->type = IDENT;
      return tok;
    } else if (token_is_number(l->ch)) {
      tok->literal = lexer_read_number(l);
      tok->type = INT;
      return tok;
    } else {
      tok = token_init(tokens[ILLEGAL], ILLEGAL);
      break;
    }
  }

  lexer_read_char(l);
  return tok;
}