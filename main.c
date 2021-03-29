#include <stdio.h>
#include "token/token.h"

int main() {

  token_t *tok = token_init("name", 21);
  token_print(tok);

  printf("\n%u", token_is_keyworkd(tok));
}