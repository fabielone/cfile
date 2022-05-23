

short menuordenar()
{

    short opc;
    mensajes("Elija una opcion. ", 32);

    RecuadroTextoCentrado(24, 7, 56, 17, 38, "[Ordenar Por:]");
    //  Textos Del menu
    ColorTexto(0);
    PonTextoCentradoPantalla(9, "Matricula-----------[1]");
    PonTextoCentradoPantalla(10, "Nombre--------------[2]");
    PonTextoCentradoPantalla(11, "Apellido Paterno----[3]");
    PonTextoCentradoPantalla(12, "Apellido Materno----[4]");
    PonTextoCentradoPantalla(13, "Edad----------------[5]");
    PonTextoCentradoPantalla(14, "Carrera-------------[6]");
    PonTextoCentradoPantalla(15, "Salir---------------[0]");
    PonTextoCentradoPantalla(16, "Seleccione----------[ ]");
    // Escaner el numero de opcion

    gotoxy(48, 13);

    do
    {
        gotoxy(50, 16);
        opc = getch();
        printf("%hu", opc);

        if ((opc >= 48 && opc <= 54))
        {

            clearportion(24, 7, 56, 17);
            return opc;
        }
        else
        {
            mensajes("opcion no valida", 31);
            gotoxy(48, 13);
        }
    } while (opc < 48 || opc > 54);
    // El salto para que no se coma el cuadro el mensaje de abajo
}

void ordenar(Alumno arrDatos[], short *length)
{
    short opc;
    PonTextoCentradoPantalla(2, "                                 ");
    PonTextoCentradoPantalla(2, "ordenar");

    opc = menuordenar();
    while (opc != 48)
    {
        struct Alumno swap;

        switch (opc)
        {
        case 49:
            /* Ordenar Por Matricula


            */

            for (int c = 0; c < *length - 1; c++)
            {
                for (int d = 0; d < *length - c - 1; d++)
                {

                    if (atoi(arrDatos[d].Matricula) > atoi(arrDatos[d + 1].Matricula))
                    {

                        swap = arrDatos[d];
                        arrDatos[d] = arrDatos[d + 1];
                        arrDatos[d + 1] = swap;
                    }
                }
            }

            listar(arrDatos, length);

            break;

        case 50:
            for (int c = 0; c < *length - 1; c++)
            {
                for (int d = 0; d < *length - c - 1; d++)
                {

                    {
                        if (strcmp(arrDatos[d].Nombre, arrDatos[d + 1].Nombre) > 0)
                        {
                            swap = arrDatos[d];
                            arrDatos[d] = arrDatos[d + 1];
                            arrDatos[d + 1] = swap;
                        }
                    }
                }
            }

            listar(arrDatos, length);

            break;

        case 51:
            for (int c = 0; c < *length - 1; c++)
            {
                for (int d = 0; d < *length - c - 1; d++)
                {

                    {
                        if (strcmp(arrDatos[d].ApellidoP, arrDatos[d + 1].ApellidoP) > 0)
                        {
                            swap = arrDatos[d];
                            arrDatos[d] = arrDatos[d + 1];
                            arrDatos[d + 1] = swap;
                        }
                    }
                }
            }

            listar(arrDatos, length);

            break;

        case 52:
            for (int c = 0; c < *length - 1; c++)
            {
                for (int d = 0; d < *length - c - 1; d++)
                {

                    {
                        if (strcmp(arrDatos[d].ApellidoM, arrDatos[d + 1].ApellidoM) > 0)
                        {
                            swap = arrDatos[d];
                            arrDatos[d] = arrDatos[d + 1];
                            arrDatos[d + 1] = swap;
                        }
                    }
                }
            }

            listar(arrDatos, length);

            break;

        case 54:
            for (int c = 0; c < *length - 1; c++)
            {
                for (int d = 0; d < *length - c - 1; d++)
                {

                    if (atoi(arrDatos[d].Edad) > atoi(arrDatos[d + 1].Edad))
                    {

                        swap = arrDatos[d];
                        arrDatos[d] = arrDatos[d + 1];
                        arrDatos[d + 1] = swap;
                    }
                }
            }

            listar(arrDatos, length);
            break;

        case 53:
            for (int c = 0; c < *length - 1; c++)
            {
                for (int d = 0; d < *length - c - 1; d++)
                {

                    {
                        if (strcmp(arrDatos[d].Carrera, arrDatos[d + 1].Carrera) > 0)
                        {
                            swap = arrDatos[d];
                            arrDatos[d] = arrDatos[d + 1];
                            arrDatos[d + 1] = swap;
                        }
                    }
                }
            }

            listar(arrDatos, length);
            break;

        default:
            break;
        }

        opc = menuordenar();
    }
}


void ordenarFile(Alumno arrDatos[], short *length)
{
    short opc;
    PonTextoCentradoPantalla(2, "                                 ");
    PonTextoCentradoPantalla(2, "ordenar");

    opc = menuordenar();
    while (opc != 48)
    {
        struct Alumno swap;

        switch (opc)
        {
        case 49:
            /* Ordenar Por Matricula


            */

            for (int c = 0; c < *length - 1; c++)
            {
                for (int d = 0; d < *length - c - 1; d++)
                {

                    if (atoi(arrDatos[d].Matricula) > atoi(arrDatos[d + 1].Matricula))
                    {

                        swap = arrDatos[d];
                        arrDatos[d] = arrDatos[d + 1];
                        arrDatos[d + 1] = swap;
                    }
                }
            }

            listar(arrDatos, length);

            break;

        case 50:
            for (int c = 0; c < *length - 1; c++)
            {
                for (int d = 0; d < *length - c - 1; d++)
                {

                    {
                        if (strcmp(arrDatos[d].Nombre, arrDatos[d + 1].Nombre) > 0)
                        {
                            swap = arrDatos[d];
                            arrDatos[d] = arrDatos[d + 1];
                            arrDatos[d + 1] = swap;
                        }
                    }
                }
            }

            listar(arrDatos, length);

            break;

        case 51:
            for (int c = 0; c < *length - 1; c++)
            {
                for (int d = 0; d < *length - c - 1; d++)
                {

                    {
                        if (strcmp(arrDatos[d].ApellidoP, arrDatos[d + 1].ApellidoP) > 0)
                        {
                            swap = arrDatos[d];
                            arrDatos[d] = arrDatos[d + 1];
                            arrDatos[d + 1] = swap;
                        }
                    }
                }
            }

            listar(arrDatos, length);

            break;

        case 52:
            for (int c = 0; c < *length - 1; c++)
            {
                for (int d = 0; d < *length - c - 1; d++)
                {

                    {
                        if (strcmp(arrDatos[d].ApellidoM, arrDatos[d + 1].ApellidoM) > 0)
                        {
                            swap = arrDatos[d];
                            arrDatos[d] = arrDatos[d + 1];
                            arrDatos[d + 1] = swap;
                        }
                    }
                }
            }

            listar(arrDatos, length);

            break;

        case 54:
            for (int c = 0; c < *length - 1; c++)
            {
                for (int d = 0; d < *length - c - 1; d++)
                {

                    if (atoi(arrDatos[d].Edad) > atoi(arrDatos[d + 1].Edad))
                    {

                        swap = arrDatos[d];
                        arrDatos[d] = arrDatos[d + 1];
                        arrDatos[d + 1] = swap;
                    }
                }
            }

            listar(arrDatos, length);
            break;

        case 53:
            for (int c = 0; c < *length - 1; c++)
            {
                for (int d = 0; d < *length - c - 1; d++)
                {

                    {
                        if (strcmp(arrDatos[d].Carrera, arrDatos[d + 1].Carrera) > 0)
                        {
                            swap = arrDatos[d];
                            arrDatos[d] = arrDatos[d + 1];
                            arrDatos[d + 1] = swap;
                        }
                    }
                }
            }

            listar(arrDatos, length);
            break;

        default:
            break;
        }

        opc = menuordenar();
    }
}
