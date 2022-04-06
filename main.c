// Archivo Principal

#include "./struct.h"
#include "./listar.h"
#include "./menu.h"
#include "./insertar.h"
#include "./borrar.h"
#include "./modificar.h"
#include "./ordenar.h"
#include "./buscar.h"
#include "./libreria.h"

void main()
{

    // struct ArrAlumno arrDatos;

    Alumno arrDatos[100];

    short selecion, numtablas = 0;

    // para hacer recuadro
    // funcion para mostra menu y regresar un numero

    selecion = menu();

    listar(arrDatos, 1);

    while (selecion != 0)
    {
        switch (selecion)
        {
        case 1:
            /* funcion de insertar


            */
            insertar(arrDatos, 1);
            listar(arrDatos, 1);

            break;

        case 2:
            /* funcion de borrar */
            borrar(arrDatos, 1);
            listar(arrDatos, 1);
            break;

        case 3:
            /* funcion de modificar */
            modificar(arrDatos);
            listar(arrDatos, 1);
            break;

        case 4:
            /* funcion de ordenar */
            ordenar(arrDatos);
            listar(arrDatos, 1);
            break;

        case 5:
            /* funcion de listar */
            listar(arrDatos, 1);
            listar(arrDatos, 1);
            break;

        case 6:
            /* funcion de buscar */
            buscar(arrDatos, 1);
            listar(arrDatos, 1);
            break;

        default:
            break;
        }

        // selecion=menu();
        selecion = 0;
    }

    // funcion de salida
}