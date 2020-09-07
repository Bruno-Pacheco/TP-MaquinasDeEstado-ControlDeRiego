#include "mylib.h"

int main()
{
    conf_t config;
    config = inicio();

    estados_t estado = riego_off;   //estado inicial "riego apagado"
    estados_t (*pfun[])(conf_t) = {friego_off,friego_on};//le cargo a mi puntero las posiciones de las dos funciones principales

    while (1){
        estado = (*pfun[estado])(config);
    }
    return 0;
}
