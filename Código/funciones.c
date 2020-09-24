#include "mylib.h"

parametros_t inicio ()
{
    FILE *conf;
    parametros_t config;
    char bf[30], *key, *val, *delta, i;       //bf: string q usaremos para leer cada renglon
    char nombres[3][20]={"mm_lluvia", "humedad", "luz_solar"};  //nombres claves

    if ((conf=fopen("config.conf","rb"))==NULL){
        printf ("No se encontro el archivo conf.config\n");
        system ("exit");
    }

    fgets(bf,30,conf);
   // printf("%s", bf);
    do{
        key=bf;
        if(*key != '#' && strlen(key)>=0)   //si no comienza con # o es un renglon vacío...
        {
            val=getkey(key);        //en key solo deja el nombre clave, y devuelve el valor configurado
            for (i=0; i<3; i++){
                if(!strcmp(key, nombres[i])){    //devuelve un cero si los strings son iguales
                    switch (i){
                        case 0:
                            delta=getdelta(val);
                            config.lluvia_t.lluvia_set=atoi(val);
                            config.lluvia_t.deltaLL=atoi(delta);
                            break;
                        case 1:
                            delta=getdelta(val);
                            config.humedad_t.humedad_set=atoi(val);
                            config.humedad_t.deltaH=atoi(delta);
                            break;
                        case 2:
                            delta=getdelta(val);
                            config.luzsolar_t.luzsolar_set=atoi(val);
                            config.luzsolar_t.deltaLS=atoi(delta);
                            break;
                    }   //end switch
                }   //end if
            }   //end for
        }   //end if
        fgets(bf,30,conf);
       // printf("%s", bf);
    }while(!feof(conf));    //end do

    return config;
}   //end inicio

char *getkey (char *key)
{
    char i=0;
    while (*(key+i)!=' ')i++;   //recorro la palabra hasta el espacio
    *(key+i)=0; //donde esta el espacio pongo un enter(/0)
    return key+i+1;
}

char *getdelta (char *val)
{
    char i=0;
    while (*(val+i)!='-')i++;
    *(val+i)=0;
    return val+i+1;
}

estados_t friego_off (parametros_t config)
{
    estados_t humedad, lluvia, luz, agua = sensor_agua ();        //levantamos las medidas de los sensores
    config.humedad_t.humedad = sensor_humedad (config);
    config.lluvia_t.lluvia = sensor_lluvia (config);
    config.luzsolar_t.luzsolar= sensor_luz (config);

    if (config.humedad_t.humedad < (config.humedad_t.humedad_set-config.humedad_t.deltaH)){
        humedad = on; // la tierra esta seca, indica SI riego
    } else humedad = off;
    if (config.lluvia_t.lluvia < (config.lluvia_t.lluvia_set-config.lluvia_t.deltaLL)){
        lluvia = on; // llovia poca cant de agua, o no llovio, indica se puede regar
    } else lluvia = off;
    if (config.luzsolar_t.luzsolar < (config.luzsolar_t.luzsolar_set-config.luzsolar_t.deltaLS)){
        luz = on; // hay poca luz solar, indica se puede regar
    } else luz = off;
    if ((agua*humedad*lluvia*luz)){     //si se cumplen todas las condiciones para el riego este producto vale 1
        printf("***Asperores Prendidos***\n");
        return on;      //riego
    }
    else{
        printf("***Aspersores Apagados***\n");
        return off;       //no riego
    }
}

estados_t friego_on (parametros_t config)
{
    estados_t humedad, lluvia, luz, agua = sensor_agua ();        //levantamos las medidas de los sensores
    config.humedad_t.humedad = sensor_humedad (config);
    config.lluvia_t.lluvia = sensor_lluvia (config);
    config.luzsolar_t.luzsolar= sensor_luz (config);

    if (config.humedad_t.humedad > (config.humedad_t.humedad_set+config.humedad_t.deltaH)){
        humedad = off; // la tierra esta humeda, indica NO riego
    } else humedad = on;
    if (config.lluvia_t.lluvia > (config.lluvia_t.lluvia_set+config.lluvia_t.deltaLL)){
        lluvia = off; // llovio cierta cantidad de agua, indica NO riego
    } else lluvia = on;
    if (config.luzsolar_t.luzsolar > (config.luzsolar_t.luzsolar_set+config.luzsolar_t.deltaLS)){
        luz = off; // hay demasiada luz solar, indica NO riego
    } else luz = on;
    if ((agua*humedad*lluvia*luz)){     //si se cumplen todas las condiciones para el riego este producto vale 1
        printf("***Aspersores Prendidos***\n");
        return on;      //riego
    }
    else{
        printf("***Aspersores Apagados***\n");
        return off;       //no riego
    }
}

estados_t sensor_agua ()
{
    estados_t agua;
    printf("\nHay agua? 0.no   1.si :\t");
    scanf("%d", &agua);
    return agua;
}

estados_t sensor_humedad (parametros_t config)
{
    printf ("\nIngrese porcentaje de humedad:");
    scanf ("%d", &config.humedad_t.humedad);
    return config.humedad_t.humedad;
}

estados_t sensor_lluvia (parametros_t config)
{
    printf ("\nIngrese mm de lluvia:");
    scanf ("%d", &config.lluvia_t.lluvia);
    return config.lluvia_t.lluvia;
}

estados_t sensor_luz (parametros_t config)
{
    printf ("\nIngrese porcentaje de luz solar:");
    scanf ("%d", &config.luzsolar_t.luzsolar);
    return config.luzsolar_t.luzsolar;
}
