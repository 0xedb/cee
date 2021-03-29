#ifndef _REPL_H
#define _REPL_H
#include <stdio.h>
#include "../lexer/lexer.h"

extern const char* PROMPT;
extern const char* GREETING;

void repl_start(FILE* in, FILE* out);

#endif // _REPL_H