#include <stdio.h>
#include "scanner.h"

int main()
{
    struct token nuevo_token;
    do
    {
        char buffer[100] = {0}; 
        nuevo_token = get_token(buffer, 100);
        switch (nuevo_token.tipo_token)
        {
        case FDT:
            printf("Fin De Texto \n");
            break;
        case SEP:
            printf("Separador: %s \n", nuevo_token.lexema);
            break;
        case CAD:
            printf("Cadena: %s \n", nuevo_token.lexema);
            break;
        default:
            break;
        }
    } while (!feof(stdin));
    return 0;
}
