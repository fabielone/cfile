
void borrar(Alumno arrDatos[], short *length)
{
    short opc;
    PonTextoCentradoPantalla(2, "                                 ");
    PonTextoCentradoPantalla(2, "Borrar");

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
                strcpy(arrDatos[i].Status, "0");
            }
        }

        listar(arrDatos, length);

        mensajes("Deseas borrar otro alumno? 0.NO / 1.SI. ", 32);

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

    } while (opc != 48);
}