

void modificar(Alumno arrDatos[], short *length)
{
    short opc;
    PonTextoCentradoPantalla(2, "                                 ");
    PonTextoCentradoPantalla(2, "Modificar");

    do
    {

        struct Alumno swap;
        char tempchar[25];

        PonTextoCentradoPantalla(9, "Ingrese Matricula: ");
        fgets(tempchar, 25, stdin);
        clearportion(2, 4, 79, 19);

        for (int i = 0; i < *length; i++)
        {
            if (strcasecmp(tempchar, arrDatos[i].Matricula) == 0)
            {
                gotoxy(4, 4);

                printf("Estudiante #:%hu", i);

                gotoxy(4, 5);
                printf("Matricula:");
                fgets(arrDatos[i].Matricula, 25, stdin);
                gotoxy(4, 6);
                printf("Nombre:");
                fgets(arrDatos[i].Nombre, 25, stdin);
                gotoxy(4, 7);
                printf("Apellido Paterno:");
                fgets(arrDatos[i].ApellidoP, 25, stdin);
                gotoxy(4, 8);
                printf("Apellido Materno:");
                fgets(arrDatos[i].ApellidoM, 25, stdin);
                gotoxy(4, 9);
                printf("Edad:");
                fgets(arrDatos[i].Edad, 25, stdin);
                gotoxy(4, 10);
                printf("Carrera:");
                fgets(arrDatos[i].Carrera, 25, stdin);
                gotoxy(4, 11);
            }
        }

        listar(arrDatos, length);

        // mensajes("opcion no valida", 31);
        // delay(500);
        mensajes("Deseas modificar otro alumno? 0.NO / 1.SI. ", 32);
        opc = getch();
        if ((opc == 49 || opc == 48))
        {
        }
        else
        {

            do
            {

                mensajes("opcion no valida", 31);
                delay(500);
                mensajes("Deseas agregar otro alumno? 0.NO / 1.SI. ", 32);
                opc = getch();
            } while (opc != 48 && opc != 49);
        }

    } while (opc == 49);
}

void modificarFile(Alumno arrDatos[], short *length)
{
    short opc;
    PonTextoCentradoPantalla(2, "                                 ");
    PonTextoCentradoPantalla(2, "Modificar");

    do
    {

        struct Alumno swap;
        char tempchar[25];

        PonTextoCentradoPantalla(9, "Ingrese Matricula: ");
        fgets(tempchar, 25, stdin);
        clearportion(2, 4, 79, 19);

        for (int i = 0; i < *length; i++)
        {
            if (strcasecmp(tempchar, arrDatos[i].Matricula) == 0)
            {
                gotoxy(4, 4);

                printf("Estudiante #:%hu", i);

                gotoxy(4, 5);
                printf("Matricula:");
                fgets(arrDatos[i].Matricula, 25, stdin);
                gotoxy(4, 6);
                printf("Nombre:");
                fgets(arrDatos[i].Nombre, 25, stdin);
                gotoxy(4, 7);
                printf("Apellido Paterno:");
                fgets(arrDatos[i].ApellidoP, 25, stdin);
                gotoxy(4, 8);
                printf("Apellido Materno:");
                fgets(arrDatos[i].ApellidoM, 25, stdin);
                gotoxy(4, 9);
                printf("Edad:");
                fgets(arrDatos[i].Edad, 25, stdin);
                gotoxy(4, 10);
                printf("Carrera:");
                fgets(arrDatos[i].Carrera, 25, stdin);
                gotoxy(4, 11);
            }
        }

        listar(arrDatos, length);

        // mensajes("opcion no valida", 31);
        // delay(500);
        mensajes("Deseas modificar otro alumno? 0.NO / 1.SI. ", 32);
        opc = getch();
        if ((opc == 49 || opc == 48))
        {
        }
        else
        {

            do
            {

                mensajes("opcion no valida", 31);
                delay(500);
                mensajes("Deseas agregar otro alumno? 0.NO / 1.SI. ", 32);
                opc = getch();
            } while (opc != 48 && opc != 49);
        }

    } while (opc == 49);
}
