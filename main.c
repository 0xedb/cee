
#include "lexer/lexer.h"
#include "token/token.h"
#include <stdio.h>

int main() {

  const char *input = "__jay 3}{[ama!=+-*/~!!~==";

  lexer_t *l = lexer_init(input);

  for (token_t *tok = lexer_next_token(l); tok->type != END;
       tok = lexer_next_token(l)) {
    token_print(tok);
  }
}
