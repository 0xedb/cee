#ifndef TOKEN_H
#define TOKEN_H

enum token_type {
  // special
  ILLEGAL, /* ` */
  END,     /* END */

  IDENT,  /* name */
  INT,    /* int */
  STRING, /* "b" */
  ASSIGN, /* = */

  // delimiters
  COMMA,     /* , */
  SEMICOLON, /* ; */
  DOT,       /* . */

  // operators
  PLUS,  /* + */
  MINUS, /* - */
  DIV,   /* / */
  MULT,  /* * */
  NOT,   /* ! */
  LST,   /* < */
  GRT,   /* > */
  EQL,   /* == */
  NQL,   /* != */

  // TODO: add colon, parenthesis
  COLON,  /* : */
  LPAREN, /* ( */
  RPAREN, /* ) */
  LCURL,  /* { */
  RCURL,  /* } */
  LBRAC,  /* [ */
  RBRAC,  /* ] */

  // keywords
  keyword_beg,
  FUNCTION, /* fn */
  LET,      /* let */
  IF,       /* if */
  EL,       /* ret */
  RET,      /* ret */
  keyword_end,
};

extern const char *tokens[];

typedef struct {
  const char *literal;
  enum token_type type;
} token_t;

token_t *token_init(const char *value, int type);
void token_print(token_t *t);
_Bool token_is_keyworkd(token_t *t);
_Bool token_is_letter(char c);
_Bool token_is_number(char c);
enum token_type token_lookup_identifier(const char *ch);

#endif /* TOKEN_H */