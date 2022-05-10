
#include <stdio.h>

void listar(Alumno arrDatost[], short *length)
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

    for (int i = 0; i < *length; i++)
    {
        gotoxy(2, 5 + i);
        printf(" %d \n ", i + 1);
        gotoxy(5, 5 + i);
        printf("|\n");
        CortarTexto(arrDatost[i].Matricula, 7, 5 + i, 6);
        gotoxy(17, 5 + i);
        printf("|");

        CortarTexto(arrDatost[i].Nombre, 18, 5 + i, 10);
        gotoxy(28, 5 + i);
        printf("|");

        CortarTexto(arrDatost[i].ApellidoP, 29, 5 + i, 13);
        gotoxy(42, 5 + i);
        printf("|");

        CortarTexto(arrDatost[i].ApellidoM, 43, 5 + i, 13);
        gotoxy(56, 5 + i);
        printf("|");

        CortarTexto(arrDatost[i].Edad, 57, 5 + i, 3);
        gotoxy(63, 5 + i);
        printf("|");

        CortarTexto(arrDatost[i].Carrera, 64, 5 + i, 14);
        gotoxy(78, 5 + i);
        printf("|");
        CortarTexto(arrDatost[i].Status, 79, 5 + i, 14);
    }

    short opc;
    do
    {

        mensajes("Presione 0 para salir ", 32);
        opc = getch();
    } while (opc != 48);
    clearportion(2, 4, 81, 19);
};

void listarFile(){

    FILE *cfPtr; // accounts.dat file pointer

 // fopen opens the file; exits if file cannot be opened
 if ((cfPtr = fopen("c2.txt", "rb" )) == NULL ) {
 puts("File could not be opened.");
 }
 else {
 

 // read all records from file (until eof)
 while (!feof(cfPtr)) {
 // create clientData with default information
 Alumno student = {"","",""};

int result = fread(&student, sizeof(struct Alumno), 1, cfPtr);
 // display record
 if (result != 0 && student.Matricula != 0) {
 printf("%s %s %s %s\n",
 student.Matricula, student.ApellidoP,
 student.ApellidoM, student.Nombre);
 }
 }

 fclose(cfPtr); // fclose closes the file
 } 


};
