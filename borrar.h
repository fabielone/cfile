
void borrarFile()
{
    short opc;
    PonTextoCentradoPantalla(2, "                                 ");
    PonTextoCentradoPantalla(2, "Borrar");

    do
    {

        char tempchar[25];
        int length = countFile();
        FILE *cfPtr;

        PonTextoCentradoPantalla(9, "Ingrese Matricula: ");
        fgets(tempchar, 25, stdin);
        clearportion(2, 4, 79, 19);

        if ((cfPtr = fopen("c2.txt", "r+")) == NULL)
        {
            puts("File could not be opened.");
        }
        else
        {
            int i;
            Alumno swap = {"", "", "", "", "", "", ""};
            int location;

            while (!feof(cfPtr))
            {
                // create clientData with default information
                Alumno student = {"", "", "", "", "", "", ""};

                int result = fread(&student, sizeof(struct Alumno), 1, cfPtr);
                // display record
                if (result != 0 && strcmp(tempchar, student.Matricula) == 0)

                {
                    strcpy(student.Status, "0");
                    fseek(cfPtr, i * sizeof(struct Alumno), SEEK_SET);
                    fwrite(&student, sizeof(struct Alumno), 1, cfPtr);
                    fseek(cfPtr, (i + 1) * sizeof(struct Alumno), SEEK_SET);
                }
                i++;
            }
            // strcpy(swap.Status, "0");
            // fseek(cfPtr, location * sizeof(struct Alumno), SEEK_SET);
            // fwrite(&swap, sizeof(struct Alumno), 1, cfPtr);

            fclose(cfPtr); // fclose closes the file
        }

        listarFile();

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