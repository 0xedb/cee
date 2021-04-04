#include "repl.h"
#include <stdio.h>

const char *PROMPT = ">>>";

const char *GREETING =
    "▄████▄  ▓█████ ▓█████     ██▓    ▄▄▄       ███▄    █   ▄████ \n"
    "▒██▀ ▀█  ▓█   ▀ ▓█   ▀    ▓██▒   ▒████▄     ██ ▀█   █  ██▒ ▀█▒\n"
    "▒▓█    ▄ ▒███   ▒███      ▒██░   ▒██  ▀█▄  ▓██  ▀█ ██▒▒██░▄▄▄░\n"
    "▒▓▓▄ ▄██▒▒▓█  ▄ ▒▓█  ▄    ▒██░   ░██▄▄▄▄██ ▓██▒  ▐▌██▒░▓█  ██▓\n"
    "▒ ▓███▀ ░░▒████▒░▒████▒   ░██████▒▓█   ▓██▒▒██░   ▓██░░▒▓███▀▒\n"
    "░ ░▒ ▒  ░░░ ▒░ ░░░ ▒░ ░   ░ ▒░▓  ░▒▒   ▓▒█░░ ▒░   ▒ ▒  ░▒   ▒ \n"
    "  ░  ▒    ░ ░  ░ ░ ░  ░   ░ ░ ▒  ░ ▒   ▒▒ ░░ ░░   ░ ▒░  ░   ░ \n"
    "░           ░      ░        ░ ░    ░   ▒      ░   ░ ░ ░ ░   ░ \n"
    "░ ░         ░  ░   ░  ░       ░  ░     ░  ░         ░       ░ \n"
    "░                                                             \n";

void repl_start(FILE *in, FILE *out) {
  puts(GREETING);
  puts("\nWelcome to the Cee(lang) Programming Language");

  // while(1) {
  //     puts(PROMPT);

  // get input

  // use lexer on it

  // output

  // }
}