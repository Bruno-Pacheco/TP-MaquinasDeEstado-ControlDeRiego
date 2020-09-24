#include "mylib.h"

int main()
{
    parametros_t config = inicio();
    estados_t estado = off;   //estado inicial "riego apagado"

    /** Declarando un puntero a funciones
    estados_t (*pfun[])(parametros_t)={friego_off, friego_on};*/
	
    printf("****CENTRAL DE RIEGO AUTOMATICO****\n\n");

    while (1)
    {
	/** Se puede reemplazar el switch por este renglón
	estado = (*pfun[estado])(config);*/

        switch(estado)
        {
            case off:
                estado = friego_off(config);
                break;
            case on:
                estado = friego_on(config);
                break;
        }
    }
    return 0;
}
