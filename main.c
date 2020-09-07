#include "mylib.h"

int main()
{
    conf_t config;
    config = inicio ();         //abre config.conf y lo carga en config
    estados_t estado = riego_off;
    while (1){
        switch (estado){
            case riego_off:
            estado = friego_off(config);
            break;
            case riego_on:
            estado = friego_on(config);
            break;

        }
    }
    return 0;
}
