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
}
