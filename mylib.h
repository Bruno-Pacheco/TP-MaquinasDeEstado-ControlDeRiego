#ifndef MYLIB_H_INCLUDED
#define MYLIB_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef enum{
    riego_off,
    riego_on
} estados_t;

typedef struct {
    char hum_set;
    char lluv_set;
    char luz_set;
    /**el sensor de agua no estará en la configuración,
    ya que no es un parámetro configurable por el usuario,*/
}conf_t;

typedef struct {
}hum_t;

typedef struct {
}lluv_t;

typedef struct {
}luz_set;

conf_t inicio(void);    //abre el archivo de conf y carga las variables con los parametros
estados_t friego_off (conf_t);
estados_t friego_on (conf_t);

#endif // MYLIB_H_INCLUDED
