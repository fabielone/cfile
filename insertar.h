#include <string.h>

void insertar(Alumno arrData[], short *i)
{
    char buf[20];
    PonTextoCentradoPantalla(2, "                                 ");
    PonTextoCentradoPantalla(2, "insertar");
    clearportion(2, 4, 79, 19);
    // fgets(buf, 20, stdin);
    Alumno student;
    short opc;
    do
    {
        clearportion(2, 4, 79, 19);
        gotoxy(4, 4);

        printf("Estudiante #:%hu", *i);

        gotoxy(4, 5);
        printf("Matricula:");
        //fgets(arrData[*i].Matricula, 25, stdin);
        validarNumeros(arrData[*i].Matricula,25,"none");
        gotoxy(4, 6);
        printf("Nombre:");
        //fgets(arrData[*i].Nombre, 25, stdin);
        validarLetras(arrData[*i].Nombre,25,"none");
        gotoxy(4, 7);
        printf("Apellido Paterno:");
        //fgets(arrData[*i].ApellidoP, 25, stdin);
        validarLetras(arrData[*i].ApellidoP,25,"none");
        gotoxy(4, 8);
        printf("Apellido Materno:");
        //fgets(arrData[*i].ApellidoM, 25, stdin);
        validarLetras(arrData[*i].ApellidoM,25,"none");
        gotoxy(4, 9);
        printf("Edad:");
        //fgets(arrData[*i].Edad, 25, stdin);
        validarNumeros(arrData[*i].Edad,25,"none");
        gotoxy(4, 10);
        printf("Carrera:");
        //fgets(arrData[*i].Carrera, 25, stdin);
        validarLetras(arrData[*i].Carrera,25,"none");
        gotoxy(4, 11);
        strcpy(arrData[*i].Status, "1");
        *i = *i + 1;

        PonTextoCentradoPantalla(2, "listar");
        mensajes("Deseas agregar otro alumno? 0.NO / 1.SI. ", 32);

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
    clearportion(2, 4, 79, 19);
    // El salto para que no se coma el cuadro el mensaje de abajo
};

void insertarFile(short *i)
{
    FILE *of;
    of = fopen("c2.txt", "a");
    if (of == NULL)
    {
        fprintf(stderr, "\nError to open the file\n");
        exit(1);
    }

    char buf[20];
    PonTextoCentradoPantalla(2, "                                 ");
    PonTextoCentradoPantalla(2, "insertar");
    clearportion(2, 4, 79, 19);
    // fgets(buf, 20, stdin);
    Alumno student;
    short opc;
    do
    {
        clearportion(2, 4, 79, 19);
        gotoxy(4, 4);

        printf("Estudiante #:%hu", countFile() + 1);

        gotoxy(4, 5);
        printf("Matricula:");
        fgets(student.Matricula, 25, stdin);
        gotoxy(4, 6);
        printf("Nombre:");
        fgets(student.Nombre, 25, stdin);
        gotoxy(4, 7);
        printf("Apellido Paterno:");
        fgets(student.ApellidoP, 25, stdin);
        gotoxy(4, 8);
        printf("Apellido Materno:");
        fgets(student.ApellidoM, 25, stdin);
        gotoxy(4, 9);
        printf("Edad:");
        fgets(student.Edad, 25, stdin);
        gotoxy(4, 10);
        printf("Carrera:");
        fgets(student.Carrera, 25, stdin);
        gotoxy(4, 11);
        strcpy(student.Status, "1");
        *i = *i + 1;

        fwrite(&student, sizeof(struct Alumno), 1, of);
        fclose(of);

        PonTextoCentradoPantalla(2, "listar");
        mensajes("Deseas agregar otro alumno? 0.NO / 1.SI. ", 32);

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
    clearportion(2, 4, 79, 19);
    // El salto para que no se coma el cuadro el mensaje de abajo
}