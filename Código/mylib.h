#ifndef MYLIB_H_INCLUDED
#define MYLIB_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    struct{
        char humedad, humedad_set, deltaH;
    } humedad_t;
    struct{
        char luzsolar, luzsolar_set, deltaLS;
    }luzsolar_t;
    struct{
        unsigned int lluvia, lluvia_set;
        char deltaLL;
    }lluvia_t;
} parametros_t;


typedef enum{
    off,
    on
} estados_t;

parametros_t inicio (void);
char * getkey (char *);
char *getdelta (char *);

estados_t friego_off (conf_t);
estados_t friego_on (conf_t);

estados_t sensor_agua ();
estados_t sensor_humedad (conf_t);
estados_t sensor_lluvia (conf_t);
estados_t sensor_luz (conf_t);

#endif // MYLIB_H_INCLUDED
