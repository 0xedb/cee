#ifndef TOKEN_H
#define TOKEN_H

typedef struct {
  const char *literal;
  enum {
    // special
    ILLEGAL, /* ` */
    EOF,     /* EOF */

    IDENT,  /* name */
    INT,    /* int */
    STRING, /* "b" */
    ASSIGN, /* = */

    // delimiters
    COMMA,     /* , */
    SEMICOLON, /* ; */

    // operators
    PLUS,  /* + */
    MINUS, /* - */
    DIV,   /* / */
    MULT,  /* * */
    LST,   /* < */
    GRT,   /* > */
    EQL,   /* == */
    NQL,   /* != */

    keyword_beg,
    FUNCTION, /* fn */
    LET,      /* let */
    IF,       /* if */
    EL,       /* ret */
    RET,      /* ret */
    keyword_end,
  } type;
} token_t;

token_t *init_token(const char *value, int type);

#endif