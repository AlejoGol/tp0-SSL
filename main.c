#include <stdio.h>
#include "scanner.h"

/*
void show_token(struct token un_token){
    switch (un_token.tipo_token)
    {
    case FDT:
        printf("Fin De Texto \n");
        break;
    case SEP:
        printf("Separador: %s \n", un_token.lexema);
        break;
    case CAD:
        printf("Cadena: %s \n", un_token.lexema);
        break;
    default:
        break;
    }
}*/

int main()
{
    struct token nuevo_token;
    /* char* buffer = malloc(100); */
    do
    {
        char buffer[100] = {0}; // mejor
        nuevo_token = get_token(buffer, 100);
        //show_token(nuevo_token);
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
    /* free(buffer); */
    /*int counter = 0;
    buffer[0] = 'a';
    while(counter < 90){
        buffer[counter++] = 'a';
    }
    printf("%s \n", buffer);*/
    return 0;
}
