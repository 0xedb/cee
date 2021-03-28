#ifndef TOKEN_H
#define TOKEN_H

typedef struct {
  const char *token;
  enum {
    TOKEN_BAD,
    TOKEN_EOF,
    TOKEN_ID,

    TOKEN_INT,
    TOKEN_LET,
    TOKEN_EQL
  } type;
} token_t;

token_t *init_token(const char *tok, int type);

void print_token(token_t *tok);
#endif // TOKEN_H