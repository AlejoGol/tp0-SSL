#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "scanner.h"

struct token get_token(char *lexema, int lexema_len)
{
    struct token nuevo_token;
    int caracter;
    do
    {
        caracter = getchar();
    } while (isspace(caracter));
    if (feof(stdin))
    {
        nuevo_token.tipo_token = FDT;
    }
    else
    {
        if (caracter == ',')
        {
            lexema[0] = caracter;
            nuevo_token.tipo_token = SEP;
        }
        else
        {
            int counter = 0;
            while (!feof(stdin) && caracter != ',' && !isspace(caracter) && counter < lexema_len)
            {
                lexema[counter] = caracter;
                counter++;
                caracter = getchar();
            }
            ungetc(caracter, stdin);
            nuevo_token.tipo_token = CAD;
        }
    }
    strcpy(nuevo_token.lexema, lexema);
    return nuevo_token;

    /*
    struct token nuevo_token;
    int caracter;
    caracter = getchar();
    if (!feof(stdin))
    {
        if (caracter == ',')
        {
            strcpy(nuevo_token.lexema, ",");
            nuevo_token.tipo_token = SEP;
        }
        else
        {
            if (!isspace(caracter))
            {
                nuevo_token.tipo_token = CAD;
                ungetc(caracter, stdin);
                strcpy(nuevo_token.lexema, get_lexema());
            }
        }
        caracter = getchar();
    }
    else
    {
        strcpy(nuevo_token.lexema, "");
        nuevo_token.tipo_token = FDT;
    }
    return nuevo_token;
    */
}
/*
char *get_lexema() //char* lexema, int lexema_len
{
    char lexema[100] = "";
    int caracter;
    caracter = getchar();
    while (!feof(stdin) && !isspace(caracter) && caracter != ',')
    {
        append(lexema, caracter);
        caracter = getchar();
    }
    ungetc(caracter, stdin);
    return lexema;
}

void append(char *s, char c)
{
    int len = strlen(s);
    s[len] = c;
    s[len + 1] = '\0';
}*/