#include "mylib.h"

int main()
{
    parametros_t config = inicio();
    estados_t estado = off;   //estado inicial "riego apagado"

    printf("****CENTRAL DE RIEGO AUTOMATICO****\n\n");

    while (1)
    {
        switch(estado)
        {
            case off:
                friego_off(config);
                break;
            case on:
                friego_on(config);
                break;
        }
    }
    return 0;
}
