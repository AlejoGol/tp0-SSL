#ifndef SCANNER_H_INCLUDED
#define SCANNER_H_INCLUDED

enum tipoToken
{
    FDT,
    SEP,
    CAD
};

struct token
{
    char lexema[100];
    int tipo_token;
};

struct token get_token(char *lexema, int lexema_len);

#endif // SCANNER_H_INCLUDED