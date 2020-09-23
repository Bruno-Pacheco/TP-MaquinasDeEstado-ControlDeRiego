#include "mylib.h"

int main()
{
    parametros_t config = inicio();

    estados_t estado = off;   //estado inicial "riego apagado"
    estados_t (*pfun[])(parametros_t)={friego_off, friego_on};
    printf("****CENTRAL DE RIEGO AUTOMATICO****\n\n");

    while (1)
    {
        estado = (*pfun[estado])(config);
        if (estado == 1){
            printf("\n***aspersores prendidos***\n");
        }else printf("\n***aspersores apagados***\n");
    }
    return 0;
}
