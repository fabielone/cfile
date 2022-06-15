
short menumodificar()
{

    short opc;
    mensajes("Elija una opcion. ", 32);
    clearportion(2, 4, 81, 19);

    RecuadroTextoCentrado(24, 7, 56, 17, 38, "[Modificar Por:]");
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

void modificarFile()
{
    short opc;
    PonTextoCentradoPantalla(2, "                                 ");
    PonTextoCentradoPantalla(2, "Modificar");

    opc = menumodificar();

    while (opc != 48)
    {
        if (opc == 49)
        {

            char tempchar[25];
            FILE *cfPtr; // accounts.dat file pointer
            // memset(tempchar, 0, 25);
            PonTextoCentradoPantalla(9, "Ingrese Matricula: ");
            //fgets(tempchar, 25, stdin);
            validarNumeros(tempchar,25,"none");
            clearportion(2, 4, 79, 19);

            gotoxy(2, 4);
            printf(" # |");
            printf(" Matricula | ");
            printf(" Nombre  | ");
            printf("Ape Paterno | ");
            printf("Ape Materno | ");
            printf("Edad | ");
            printf("  Carrera    |");
            printf("Act\n");

            int cont = 0;
            int i = 0;
            int length = countFile();

            if ((cfPtr = fopen("c2.txt", "r+")) == NULL)
            {
                puts("File could not be opened.");
            }
            else
            {

                PonTextoCentradoPantalla(2, "                 ");
                PonTextoCentradoPantalla(2, "listar");
                clearportion(2, 4, 81, 19);

                gotoxy(2, 4);
                printf(" # |");
                printf(" Matricula | ");
                printf(" Nombre  | ");
                printf("Ape Paterno | ");
                printf("Ape Materno | ");
                printf("Edad | ");
                printf("  Carrera    |");
                printf("Act");

                // read all records from file (until eof)
                while (!feof(cfPtr))
                {
                    // create clientData with default information
                    Alumno student = {"", "", "", "", "", "", ""};
                    Alumno swap;

                    int result = fread(&student, sizeof(struct Alumno), 1, cfPtr);

                    // display record
                    if (result != 0 && strcasecmp(tempchar, student.Matricula) == 0)
                    {

                        clearportion(2, 4, 79, 19);
                        gotoxy(4, 4);

                        printf("Estudiante #:%hu", i);

                        gotoxy(4, 5);
                        printf("Matricula:");
                        //fgets(swap.Matricula, 25, stdin);
                        validarLetras(swap.Matricula,25,"none");

                        gotoxy(4, 6);
                        printf("Nombre:");
                        //fgets(swap.Nombre, 25, stdin);
                        validarLetras(swap.Nombre,25,"none");
                        gotoxy(4, 7);
                        printf("Apellido Paterno:");
                        //fgets(swap.ApellidoP, 25, stdin);
                        validarLetras(swap.ApellidoP,25,"none");
                        gotoxy(4, 8);
                        printf("Apellido Materno:");
                        //fgets(swap.ApellidoM, 25, stdin);
                        validarLetras(swap.ApellidoM,25,"none");
                        gotoxy(4, 9);
                        printf("Edad:");
                        //fgets(swap.Edad, 25, stdin);
                        validarNumeros(swap.Edad,25,"none");
                        gotoxy(4, 10);
                        printf("Carrera:");
                       // fgets(swap.Carrera, 25, stdin);
                       validarLetras(swap.Carrera,25,"none");
                        gotoxy(4, 11);
                        strcpy(swap.Status, "1");

                        fseek(cfPtr, i * sizeof(struct Alumno), SEEK_SET);
                        fwrite(&swap, sizeof(struct Alumno), 1, cfPtr);

                        clearportion(2, 4, 79, 19);

                        gotoxy(2, 5);
                        printf(" %d \n ", i + 1);
                        gotoxy(5, 5);
                        printf("|\n");
                        CortarTexto(swap.Matricula, 7, 5, 6);
                        gotoxy(17, 5);
                        printf("|");

                        CortarTexto(swap.Nombre, 18, 5, 10);
                        gotoxy(28, 5);
                        printf("|");

                        CortarTexto(swap.ApellidoP, 29, 5, 13);
                        gotoxy(42, 5);
                        printf("|");

                        CortarTexto(swap.ApellidoM, 43, 5, 13);
                        gotoxy(56, 5);
                        printf("|");

                        CortarTexto(swap.Edad, 57, 5, 3);
                        gotoxy(63, 5);
                        printf("|");

                        CortarTexto(swap.Carrera, 64, 5, 14);
                        gotoxy(78, 5);
                        printf("|");
                        CortarTexto(swap.Status, 79, 5, 1);
                        i++;
                    }
                }

                fclose(cfPtr); // fclose closes the file
            }

            do
            {

                mensajes("Presione 0 para salir ", 32);
                opc = getch();
            } while (opc != 48);
        }

        if (opc == 50)
        {
            struct Alumno swap;
            char tempchar[25];
            FILE *cfPtr; // accounts.dat file pointer
            // memset(tempchar, 0, 25);
            PonTextoCentradoPantalla(9, "Ingrese Matricula: ");
            fgets(tempchar, 25, stdin);
            clearportion(2, 4, 79, 19);

            gotoxy(2, 4);
            printf(" # |");
            printf(" Matricula | ");
            printf(" Nombre  | ");
            printf("Ape Paterno | ");
            printf("Ape Materno | ");
            printf("Edad | ");
            printf("  Carrera    |");
            printf("Act\n");

            int cont = 0;
            int i = 0;
            int length = countFile();

            if ((cfPtr = fopen("c2.txt", "rb")) == NULL)
            {
                puts("File could not be opened.");
            }
            else
            {

                PonTextoCentradoPantalla(2, "                 ");
                PonTextoCentradoPantalla(2, "listar");
                clearportion(2, 4, 81, 19);

                gotoxy(2, 4);
                printf(" # |");
                printf(" Matricula | ");
                printf(" Nombre  | ");
                printf("Ape Paterno | ");
                printf("Ape Materno | ");
                printf("Edad | ");
                printf("  Carrera    |");
                printf("Act");

                // read all records from file (until eof)
                while (!feof(cfPtr))
                {
                    // create clientData with default information
                    Alumno student = {"", "", "", "", "", "", ""};

                    int result = fread(&student, sizeof(struct Alumno), 1, cfPtr);
                    // display record
                    if (result != 0 && strcasecmp(tempchar, student.Matricula) == 0)
                    {
                        gotoxy(2, 5 + i);
                        printf(" %d \n ", i + 1);
                        gotoxy(5, 5 + i);
                        printf("|\n");
                        CortarTexto(student.Matricula, 7, 5 + i, 6);
                        gotoxy(17, 5 + i);
                        printf("|");

                        CortarTexto(student.Nombre, 18, 5 + i, 10);
                        gotoxy(28, 5 + i);
                        printf("|");

                        CortarTexto(student.ApellidoP, 29, 5 + i, 13);
                        gotoxy(42, 5 + i);
                        printf("|");

                        CortarTexto(student.ApellidoM, 43, 5 + i, 13);
                        gotoxy(56, 5 + i);
                        printf("|");

                        CortarTexto(student.Edad, 57, 5 + i, 3);
                        gotoxy(63, 5 + i);
                        printf("|");

                        CortarTexto(student.Carrera, 64, 5 + i, 14);
                        gotoxy(78, 5 + i);
                        printf("|");
                        CortarTexto(student.Status, 79, 5 + i, 1);
                        i++;
                    }
                }

                fclose(cfPtr); // fclose closes the file
            }

            do
            {

                mensajes("Presione 0 para salir ", 32);
                opc = getch();
            } while (opc != 48);
        }
        if (opc == 51)
        {
            struct Alumno swap;
            char tempchar[25];
            FILE *cfPtr; // accounts.dat file pointer
            // memset(tempchar, 0, 25);
            PonTextoCentradoPantalla(9, "Ingrese Matricula: ");
            fgets(tempchar, 25, stdin);
            clearportion(2, 4, 79, 19);

            gotoxy(2, 4);
            printf(" # |");
            printf(" Matricula | ");
            printf(" Nombre  | ");
            printf("Ape Paterno | ");
            printf("Ape Materno | ");
            printf("Edad | ");
            printf("  Carrera    |");
            printf("Act\n");

            int cont = 0;
            int i = 0;
            int length = countFile();

            if ((cfPtr = fopen("c2.txt", "rb")) == NULL)
            {
                puts("File could not be opened.");
            }
            else
            {

                PonTextoCentradoPantalla(2, "                 ");
                PonTextoCentradoPantalla(2, "listar");
                clearportion(2, 4, 81, 19);

                gotoxy(2, 4);
                printf(" # |");
                printf(" Matricula | ");
                printf(" Nombre  | ");
                printf("Ape Paterno | ");
                printf("Ape Materno | ");
                printf("Edad | ");
                printf("  Carrera    |");
                printf("Act");

                // read all records from file (until eof)
                while (!feof(cfPtr))
                {
                    // create clientData with default information
                    Alumno student = {"", "", "", "", "", "", ""};

                    int result = fread(&student, sizeof(struct Alumno), 1, cfPtr);
                    // display record
                    if (result != 0 && strcasecmp(tempchar, student.Matricula) == 0)
                    {
                        gotoxy(2, 5 + i);
                        printf(" %d \n ", i + 1);
                        gotoxy(5, 5 + i);
                        printf("|\n");
                        CortarTexto(student.Matricula, 7, 5 + i, 6);
                        gotoxy(17, 5 + i);
                        printf("|");

                        CortarTexto(student.Nombre, 18, 5 + i, 10);
                        gotoxy(28, 5 + i);
                        printf("|");

                        CortarTexto(student.ApellidoP, 29, 5 + i, 13);
                        gotoxy(42, 5 + i);
                        printf("|");

                        CortarTexto(student.ApellidoM, 43, 5 + i, 13);
                        gotoxy(56, 5 + i);
                        printf("|");

                        CortarTexto(student.Edad, 57, 5 + i, 3);
                        gotoxy(63, 5 + i);
                        printf("|");

                        CortarTexto(student.Carrera, 64, 5 + i, 14);
                        gotoxy(78, 5 + i);
                        printf("|");
                        CortarTexto(student.Status, 79, 5 + i, 1);
                        i++;
                    }
                }

                fclose(cfPtr); // fclose closes the file
            }

            do
            {

                mensajes("Presione 0 para salir ", 32);
                opc = getch();
            } while (opc != 48);
        }

        if (opc == 52)
        {
            struct Alumno swap;
            char tempchar[25];
            FILE *cfPtr; // accounts.dat file pointer
            // memset(tempchar, 0, 25);
            PonTextoCentradoPantalla(9, "Ingrese Matricula: ");
            fgets(tempchar, 25, stdin);
            clearportion(2, 4, 79, 19);

            gotoxy(2, 4);
            printf(" # |");
            printf(" Matricula | ");
            printf(" Nombre  | ");
            printf("Ape Paterno | ");
            printf("Ape Materno | ");
            printf("Edad | ");
            printf("  Carrera    |");
            printf("Act\n");

            int cont = 0;
            int i = 0;
            int length = countFile();

            if ((cfPtr = fopen("c2.txt", "rb")) == NULL)
            {
                puts("File could not be opened.");
            }
            else
            {

                PonTextoCentradoPantalla(2, "                 ");
                PonTextoCentradoPantalla(2, "listar");
                clearportion(2, 4, 81, 19);

                gotoxy(2, 4);
                printf(" # |");
                printf(" Matricula | ");
                printf(" Nombre  | ");
                printf("Ape Paterno | ");
                printf("Ape Materno | ");
                printf("Edad | ");
                printf("  Carrera    |");
                printf("Act");

                // read all records from file (until eof)
                while (!feof(cfPtr))
                {
                    // create clientData with default information
                    Alumno student = {"", "", "", "", "", "", ""};

                    int result = fread(&student, sizeof(struct Alumno), 1, cfPtr);
                    // display record
                    if (result != 0 && strcasecmp(tempchar, student.Matricula) == 0)
                    {
                        gotoxy(2, 5 + i);
                        printf(" %d \n ", i + 1);
                        gotoxy(5, 5 + i);
                        printf("|\n");
                        CortarTexto(student.Matricula, 7, 5 + i, 6);
                        gotoxy(17, 5 + i);
                        printf("|");

                        CortarTexto(student.Nombre, 18, 5 + i, 10);
                        gotoxy(28, 5 + i);
                        printf("|");

                        CortarTexto(student.ApellidoP, 29, 5 + i, 13);
                        gotoxy(42, 5 + i);
                        printf("|");

                        CortarTexto(student.ApellidoM, 43, 5 + i, 13);
                        gotoxy(56, 5 + i);
                        printf("|");

                        CortarTexto(student.Edad, 57, 5 + i, 3);
                        gotoxy(63, 5 + i);
                        printf("|");

                        CortarTexto(student.Carrera, 64, 5 + i, 14);
                        gotoxy(78, 5 + i);
                        printf("|");
                        CortarTexto(student.Status, 79, 5 + i, 1);
                        i++;
                    }
                }

                fclose(cfPtr); // fclose closes the file
            }

            do
            {

                mensajes("Presione 0 para salir ", 32);
                opc = getch();
            } while (opc != 48);
        }

        if (opc == 53)
        {
            struct Alumno swap;
            char tempchar[25];
            FILE *cfPtr; // accounts.dat file pointer
            // memset(tempchar, 0, 25);
            PonTextoCentradoPantalla(9, "Ingrese Matricula: ");
            fgets(tempchar, 25, stdin);
            clearportion(2, 4, 79, 19);

            gotoxy(2, 4);
            printf(" # |");
            printf(" Matricula | ");
            printf(" Nombre  | ");
            printf("Ape Paterno | ");
            printf("Ape Materno | ");
            printf("Edad | ");
            printf("  Carrera    |");
            printf("Act\n");

            int cont = 0;
            int i = 0;
            int length = countFile();

            if ((cfPtr = fopen("c2.txt", "rb")) == NULL)
            {
                puts("File could not be opened.");
            }
            else
            {

                PonTextoCentradoPantalla(2, "                 ");
                PonTextoCentradoPantalla(2, "listar");
                clearportion(2, 4, 81, 19);

                gotoxy(2, 4);
                printf(" # |");
                printf(" Matricula | ");
                printf(" Nombre  | ");
                printf("Ape Paterno | ");
                printf("Ape Materno | ");
                printf("Edad | ");
                printf("  Carrera    |");
                printf("Act");

                // read all records from file (until eof)
                while (!feof(cfPtr))
                {
                    // create clientData with default information
                    Alumno student = {"", "", "", "", "", "", ""};

                    int result = fread(&student, sizeof(struct Alumno), 1, cfPtr);
                    // display record
                    if (result != 0 && strcasecmp(tempchar, student.Matricula) == 0)
                    {
                        gotoxy(2, 5 + i);
                        printf(" %d \n ", i + 1);
                        gotoxy(5, 5 + i);
                        printf("|\n");
                        CortarTexto(student.Matricula, 7, 5 + i, 6);
                        gotoxy(17, 5 + i);
                        printf("|");

                        CortarTexto(student.Nombre, 18, 5 + i, 10);
                        gotoxy(28, 5 + i);
                        printf("|");

                        CortarTexto(student.ApellidoP, 29, 5 + i, 13);
                        gotoxy(42, 5 + i);
                        printf("|");

                        CortarTexto(student.ApellidoM, 43, 5 + i, 13);
                        gotoxy(56, 5 + i);
                        printf("|");

                        CortarTexto(student.Edad, 57, 5 + i, 3);
                        gotoxy(63, 5 + i);
                        printf("|");

                        CortarTexto(student.Carrera, 64, 5 + i, 14);
                        gotoxy(78, 5 + i);
                        printf("|");
                        CortarTexto(student.Status, 79, 5 + i, 1);
                        i++;
                    }
                }

                fclose(cfPtr); // fclose closes the file
            }

            do
            {

                mensajes("Presione 0 para salir ", 32);
                opc = getch();
            } while (opc != 48);
        }
        if (opc == 54)
        {
            struct Alumno swap;
            char tempchar[25];
            FILE *cfPtr; // accounts.dat file pointer
            // memset(tempchar, 0, 25);
            PonTextoCentradoPantalla(9, "Ingrese Matricula: ");
            fgets(tempchar, 25, stdin);
            clearportion(2, 4, 79, 19);

            gotoxy(2, 4);
            printf(" # |");
            printf(" Matricula | ");
            printf(" Nombre  | ");
            printf("Ape Paterno | ");
            printf("Ape Materno | ");
            printf("Edad | ");
            printf("  Carrera    |");
            printf("Act\n");

            int cont = 0;
            int i = 0;
            int length = countFile();

            if ((cfPtr = fopen("c2.txt", "rb")) == NULL)
            {
                puts("File could not be opened.");
            }
            else
            {

                PonTextoCentradoPantalla(2, "                 ");
                PonTextoCentradoPantalla(2, "listar");
                clearportion(2, 4, 81, 19);

                gotoxy(2, 4);
                printf(" # |");
                printf(" Matricula | ");
                printf(" Nombre  | ");
                printf("Ape Paterno | ");
                printf("Ape Materno | ");
                printf("Edad | ");
                printf("  Carrera    |");
                printf("Act");

                // read all records from file (until eof)
                while (!feof(cfPtr))
                {
                    // create clientData with default information
                    Alumno student = {"", "", "", "", "", "", ""};

                    int result = fread(&student, sizeof(struct Alumno), 1, cfPtr);
                    // display record
                    if (result != 0 && strcasecmp(tempchar, student.Matricula) == 0)
                    {
                        gotoxy(2, 5 + i);
                        printf(" %d \n ", i + 1);
                        gotoxy(5, 5 + i);
                        printf("|\n");
                        CortarTexto(student.Matricula, 7, 5 + i, 6);
                        gotoxy(17, 5 + i);
                        printf("|");

                        CortarTexto(student.Nombre, 18, 5 + i, 10);
                        gotoxy(28, 5 + i);
                        printf("|");

                        CortarTexto(student.ApellidoP, 29, 5 + i, 13);
                        gotoxy(42, 5 + i);
                        printf("|");

                        CortarTexto(student.ApellidoM, 43, 5 + i, 13);
                        gotoxy(56, 5 + i);
                        printf("|");

                        CortarTexto(student.Edad, 57, 5 + i, 3);
                        gotoxy(63, 5 + i);
                        printf("|");

                        CortarTexto(student.Carrera, 64, 5 + i, 14);
                        gotoxy(78, 5 + i);
                        printf("|");
                        CortarTexto(student.Status, 79, 5 + i, 1);
                        i++;
                    }
                }

                fclose(cfPtr); // fclose closes the file
            }

            do
            {

                mensajes("Presione 0 para salir ", 32);
                opc = getch();
            } while (opc != 48);
        }

        opc = menumodificar();
    }
}
