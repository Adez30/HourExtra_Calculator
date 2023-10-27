/*-------------------------------------------------|
| Autor: Angel              Matricula: 1-20-2464   |
| Fecha: 25/109/2023                               |
| ------------------------------------------------ |
| Calculadora de horas extras.                     |
|                                                  |
|                                                  |
----------------------------------------------------*/

/*Librerias a utilizar*/
#include <stdio.h>

/*Nombramientos de las variables globales*/
int Hora_de_salida = 5;
int min_de_salida = 30;
int hora_de_salida_extra;
int min_de_salida_extra;
int valor_horas_extras;

/*Iniciando funcion*/
int calcular_horas_extras();

/*Programa principal*/
int main()
{
    /*Nombramiento de variables tipo int*/
    int opcion;
    int total_pago = 0;
    int total_horas_trabajadas = 0;
    int total_min_trabajadas = 0;

    /*Menu*/
    printf("\nBienvenidos a Extra Calculator, que desea hacer: \n Opcion 1. Calcular horas extras, \n opcion 2. SALIR.");
    printf("\nSeleccione el numero correspondiente a la accion. ");
    scanf("%i", &opcion);

    /*Condicional para detectar que opcion elige el usario del menu*/
    if (opcion == 1)

    {

        printf("Bienvedio a la calculadora de horas extras. ");

        /* Nombra miento de un elemento de arreglos con un total de 5 elementos*/
        int total_pago_semanal[5] = {0};
        /*nombramiento de un arreglo puntero tipo char que almacenara los idas de luenes a viernes*/
        char *dias[] = {"Lunes", "Martes", "Miércoles", "Jueves", "Viernes"};

        /*Bucle*/
        for (int i = 0; i < 5; i++) /* Bucle que repetira la accion 5 veces*/
        {
            printf("\n Introduce la hora de salida hoy %s (en formato HH MM): ", dias[i]); /*Le dice al usuario que ingrese la hora de salida
             y lo y comienza contar y los dias con el arreglo puntero */
            scanf("%d %d", &hora_de_salida_extra, &min_de_salida_extra);                   /*Escanea la hora y min de salida*/

            /*Condicional para el calculo de horas extras*/
            if (Hora_de_salida < hora_de_salida_extra || (Hora_de_salida == hora_de_salida_extra && min_de_salida < min_de_salida_extra))
            /*Detecta si hora de salida es menor que la hora de salida extra o si hora de salida es igual a la hora de salida extras
             y si min de salida es menor que la salida extra para proceder con el programa de la condicional.*/

            {
                /*Si la condicion anterior se cumple procede a imprimir la hora de salida*/
                printf("\nSu hora de salida fue: %2d:%02d pm\n", hora_de_salida_extra, min_de_salida_extra);
                /*Ejecuta la funcion la cual calcula las horas extras y el valor de estas.*/
                calcular_horas_extras();
                /*Imprime las horas extras anteriormente calculadas con la funcion*/
                printf("\nSus horas extras trabajadas fueron: %d:%02d\n", hora_de_salida_extra, min_de_salida_extra);
                /*Imprime el valor de sus horas extras*/
                printf("\nEl valor de sus horas extras es: $%d\n", valor_horas_extras);
                /*Almacena el valor de las horas extras de cada dia*/
                total_pago_semanal[i] = valor_horas_extras;
            }
            /*Si la condicion anterior no se cumple imprime el siguiente mensaje*/
            else
            {
                printf("No trabajó horas extras.\n");
            }
        } /*Find el bucle anterior*/

        /*bucle*/
        for (int i = 0; i < 5; i++)
        {
            total_pago += total_pago_semanal[i]; /*Calcula el total del valor de las horas trabajas a las semana*/
        }
        printf("\nEl pago total semanal es: $%d\n", total_pago); /*Imprime el total de pago de las horas extras */
        return 0;
    }
    /*Condicional para detectar que opcion elige el usario del menu*/

    else if (opcion == 2) /*Opcion para salir del programa*/
    {
        printf("Saliendo....");
        return 0;
    }
    else /*Condicional por si eligen alguna opcion no existente*/
        printf("Opcion no encontrada");
}
/*Creacion de la Funcion*/
int calcular_horas_extras() /*Nombramiento de la funcion y el tipo de dato de la funcion*/
{
    /*Nombramiento de las variables de la funcion*/
    int pago_por_horas;
    int pago_por_min;

    /*condiconal*/
    if (min_de_salida_extra < min_de_salida) /*Condicional para restar las horas y minutos correctamente*/
    {
        hora_de_salida_extra -= 1; /*Si se cumple la condicion anterior se le restara 1 a la hora de salida extra*/
        min_de_salida_extra += 60; /*Si se cumple la condicion anterior se le suma 60 al min de salida extra*/
    }

    hora_de_salida_extra = hora_de_salida_extra - Hora_de_salida; /*Operacion para obtener la hora extra trabajada resta la hora de
    salida extra ingresada y la resta por la hora de salida fija*/
    min_de_salida_extra = min_de_salida_extra - min_de_salida;
    /*Operacion para obtener la hora extra trabajada resta el min de salida extra
    ingresada y la resta por el min de salida fija*/

    printf("Cuanto vale las horas extras: $"); /*Pregunta al usuario cuanto valen las horas extras*/
    scanf("%d", &valor_horas_extras);          /*escanea el valor ingresado anteriormente*/

    pago_por_min = (valor_horas_extras / 60) * min_de_salida_extra; /*Calcula el valor total de los min extras dividiendo el valor de horas
     extras trabajas ingresadas anteriormente entre 60 para luego multiplicarle los miin de salidas extras*/
    pago_por_horas = (valor_horas_extras * hora_de_salida_extra);   /*Calcula el valor total de las horas extras multiplicando
       el valor de horas extras por la hora de salida extras*/
    valor_horas_extras = pago_por_horas + pago_por_min;             /*suma los 2 valores anteriormente calculados*/
}
