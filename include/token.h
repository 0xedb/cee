#ifndef C_TOKEN
#define C_TOKEN

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
#endif