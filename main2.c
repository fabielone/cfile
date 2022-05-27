#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linux.h"
#include "getch.h"

typedef struct _alumno
{
    char Carrera[25];
    char Nombre[25];
    char APaterno[50];
    char AMaterno[50];
    char Edad[5];
    char Matricula[10];
    char estatus[2];
} Talumnos;

void InsertarAlumno();
void crearArchi();
void continuar();
void CuadroInterfaz();
void ListarDatos();
void BuscarDatos();
void CuadroTabla();
void InterfazInicio();
void BorrarDatos();
void OrdernarDatos();
void Goodbye();

void main()
{
    system("clear");
    int op;

    CuadroInterfaz();
    PonTextoCentradoPantallaAnimadoVERT(1, 10, "[Menu de opciones]");
    PonTextoCentradoPantalla(20, "[MENSAJES]");
    Recuadro(24, 9, 56, 14, 2);
    RecuadroTextoCentrado(24, 9, 56, 14, 2, "[MENU]");
    PonTextoCentradoPantalla(10, "NUEVO ARCHIVO----[1]");
    PonTextoCentradoPantalla(11, "MENU DE OPC------[2]");
    PonTextoCentradoPantalla(12, "Selecciona-------[ ]");
    do
    {
        gotoxy(48, 12);

        scanf("%d", &op);
        if (op < 1 || op > 2)
        {
            PonTextoCentradoPantalla(21, "OPCION NO VALIDA");
        }
        else
        {
            switch (op)
            {
            case 1:
                crearArchi();
                break;
            case 2:
                InterfazInicio();
                break;
            }
        }
    } while (op < 1 || op > 2);
}

/////////////////
/////////////////////////
/////////////////

void crearArchi()
{
    FILE *arch;
    arch = fopen("alumnos.dat", "wb");
    if (arch == NULL)
    {
        exit(1);
    }
    fclose(arch);
    continuar();
    return main();
}

/////////////////
/////////////////////////
/////////////////

void continuar()
{
    printf("Presione una tecla para continuar...\n");
    getch();
}

/////////////////
/////////////////////////
/////////////////

void InsertarAlumno()
{
    system("clear");

    int opc;

    FILE *arch;
    arch = fopen("alumnos.dat", "a");
    if (arch == NULL)
    {
        exit(1);
    }
    Talumnos base;
    CuadroInterfaz();

    ////////   ACHIVOOOOS   //////////
    PonTextoCentradoPantallaAnimadoVERT(1, 10, "¨[Captura de datos]");
    gotoxy(1, 7);
    printf("\t Carrera:  ");
    fgets(base.Carrera, 25, stdin);

    gotoxy(1, 9);
    printf("\t Nombre: ");
    fgets(base.Nombre, 25, stdin);

    gotoxy(1, 11);
    printf("\t Apellido Paterno: ");
    fgets(base.APaterno, 50, stdin);

    gotoxy(1, 13);
    printf("\t Apellido Materno: ");
    fgets(base.AMaterno, 50, stdin);

    gotoxy(1, 15);
    printf("\t Edad: ");
    fgets(base.Edad, 5, stdin);

    gotoxy(1, 17);
    printf("\t Matricula: ");
    fgets(base.Matricula, 10, stdin);
    strcpy(base.estatus, "1");

    // se escribe el archivo y lo cierra
    fwrite(&base, sizeof(Talumnos), 1, arch); // ESCRIBE LOS REGISTROS AL ARCHIVO
    fclose(arch);                             // CIERRA EL ARCHIVO

    PonTextoCentradoPantalla(21, "Quieres ingresar otro Alumno? 1.SI / 2.NO :) \n");
    opc = getch();
    if (opc == 49)
    {
        InsertarAlumno();
    }
    else
    {
        InterfazInicio();
        PonTextoCentradoPantalla(21, " Que desea hacer ? \n");
    }
}

/////////////////
/////////////////////////
/////////////////

void InterfazInicio()
{
    system("clear");
    int op;

    CuadroInterfaz();
    PonTextoCentradoPantallaAnimadoVERT(1, 10, "[Menu de opciones]");
    PonTextoCentradoPantalla(20, "[MENSAJES]");
    Recuadro(24, 7, 56, 15, 2);
    RecuadroTextoCentrado(24, 7, 56, 15, 2, "[MENU]");
    PonTextoCentradoPantalla(8, "INSERTAR---------[1]");
    PonTextoCentradoPantalla(9, "BORRAR ----------[2]");
    PonTextoCentradoPantalla(10, "BUSCAR-----------[3]");
    PonTextoCentradoPantalla(11, "MODIFICAR--------[4]");
    PonTextoCentradoPantalla(12, "LISTA------------[5]");
    PonTextoCentradoPantalla(13, "SALIR------------[6]");
    PonTextoCentradoPantalla(14, "Selecciona-------[ ]");
    do
    {
        gotoxy(48, 14);
        op = getch();

        if (op < 49 || op > 54)
        {
            PonTextoCentradoPantalla(21, "OPCION NO VALIDA");
        }
        else
        {
            switch (op)
            {
            case 49:
                op = 1;
                InsertarAlumno();
                break;
            case 50:
                op = 2;
                BorrarDatos();
                break;
            case 51:
                op = 3;
                BuscarDatos();
                break;
            case 52:
                op = 4;
                ModificarDatos();
                break;
            case 53:
                op = 5;
                ListarDatos();
                break;
            case 54:
                op = 6;
                Goodbye();
                break;
            }
        }
    } while (op < 1 || op > 6);
}

/////////////////
/////////////////////////
/////////////////

void CuadroInterfaz()
{
    Recuadro(1, 1, 82, 22, 2);
    LineaHorizontal(1, 82, 3, 1);
    LineaHorizontal(1, 82, 20, 1);
    PonTextoCentradoPantalla(20, "[MENSAJES]");
}

/////////////////
/////////////////////////
/////////////////

void ListarDatos()
{
    int i = 0, op;

    // Abre el archivio
    FILE *arch;
    arch = fopen("alumnos.dat", "r+");
    if (arch == NULL)
    {
        exit(1);
    }

    // LEE LOS DATOS QUE CONTIENE EL ARCHIVO
    CuadroTabla(); // Imprime la tabla donde se acomodaran los datos
    while (!feof(arch))
    {
        Talumnos base = {"", "", "", "", "", "", ""};
        int holadiegomilena = fread(&base, sizeof(Talumnos), 1, arch);

        if (holadiegomilena != 0 && strcmp("1", base.estatus) == 0)
        {
            gotoxy(5, 6 + i);
            printf("%s", base.Matricula);
            gotoxy(18, 6 + i);
            printf("%s", base.Nombre);
            gotoxy(30, 6 + i);
            printf("%s", base.APaterno);
            gotoxy(44, 6 + i);
            printf("%s", base.AMaterno);
            gotoxy(58, 6 + i);
            printf("%s", base.Edad);
            gotoxy(66, 6 + i);
            printf("%s", base.Carrera);
            i++;
        }
    }
    // Cuenta cuantos archivos cargo
    gotoxy(5, 19);
    printf("%i", i);
    fclose(arch);

    // PREGUNTA SI QUIERE REGRESAR AL MENU PRINCIPAL
    PonTextoCentradoPantalla(19, "Quieres al menu de ordenaciones? 1.SI / 2.NO :) \n");
    gotoxy(60, 19);
    op = getch();
    if (op == 49)
    {
        InsertarAlumno();
    }
    else
    {
        if (op == 50)
        {
            exit(1);
        }
    }
}

/////////////////
/////////////////////////
/////////////////
void BuscarDatos()
{
    FILE *arch;
    arch = fopen("alumnos.dat", "r+");
    if (arch == NULL)
    {
        exit(1);
    }
    system("clear");
    CuadroInterfaz();

    // PIDE LA MATRICULLA QUE SE REQUIERE BUSCAR
    PonTextoCentradoPantalla(6, "Ingrese la matricula ");
    char matri[10];
    gotoxy(45, 7);
    fgets(matri, 25, stdin);
    Talumnos base;
    int existe = 0;

    fread(&base, sizeof(Talumnos), 1, arch);
    while (!feof(arch))
    {
        if (strcmp(matri, base.Matricula) == 0)
        {
            printf("%s %s %s %s %s %s \n", base.Carrera, base.Nombre, base.APaterno, base.AMaterno, base.Edad, base.Matricula);
            gotoxy(5, 6);
            printf("%s", base.Matricula);
            gotoxy(18, 6);
            printf("%s", base.Nombre);
            gotoxy(30, 6);
            printf("%s", base.APaterno);
            gotoxy(44, 6);
            printf("%s", base.AMaterno);
            gotoxy(58, 6);
            printf("%s", base.Edad);
            gotoxy(66, 6);
            printf("%s", base.Carrera);
            existe = 1;
            break;
        }
        fread(&base, sizeof(Talumnos), 1, arch);
    }
    if (existe == 0)
    {
        PonTextoCentradoPantalla(21, "No existe un Alumno con esa Matricula \n");
    }
    fclose(arch);
}

/////////////////
/////////////////////////
/////////////////

void CuadroTabla()
{
    system("clear");
    Recuadro(1, 1, 82, 21, 1);
    LineaHorizontal(1, 82, 3, 1);
    PonTextoCentradoPantallaAnimadoVERT(1, 10, "[Lista de Alumnos]");

    ///////////// - Tabla - ////////////
    LineaHorizontal(1, 82, 5, 1);

    ///////// - datos table - ////////
    PonTextoXY(5, 4, "Matricula");
    PonTextoXY(18, 4, "Nombre");
    PonTextoXY(30, 4, "ApellidoP");
    PonTextoXY(44, 4, "ApellidoM");
    PonTextoXY(58, 4, "Edad");
    PonTextoXY(66, 4, "Carrera");
}

/////////////////
/////////////////////////
/////////////////

void ModificarDatos()
{
    FILE *arch;
    arch = fopen("alumnos.dat", "r+");
    if (arch == NULL)
    {
        exit(1);
    }
    system("clear");
    CuadroInterfaz();

    // PIDE LA MATRICULLA QUE SE REQUIERE BUSCAR
    PonTextoCentradoPantalla(6, "Ingrese la matricula ");
    char matri[10];
    gotoxy(45, 7);
    fgets(matri, 25, stdin);
    Talumnos base;
    int existe = 0;
    int contador = 0;

    fread(&base, sizeof(Talumnos), 1, arch);
    while (!feof(arch))
    {

        if (strcmp(matri, base.Matricula) == 0)
        {
            PonTextoCentradoPantallaAnimadoVERT(1, 10, "¨[Captura de datos]");
            gotoxy(1, 7);
            printf("\t Carrera:  ");
            fgets(base.Carrera, 25, stdin);

            gotoxy(1, 9);
            printf("\t Nombre: ");
            fgets(base.Nombre, 25, stdin);

            gotoxy(1, 11);
            printf("\t Apellido Paterno: ");
            fgets(base.APaterno, 50, stdin);

            gotoxy(1, 13);
            printf("\t Apellido Materno: ");
            fgets(base.AMaterno, 50, stdin);

            gotoxy(1, 15);
            printf("\t Edad: ");
            fgets(base.Edad, 5, stdin);

            gotoxy(1, 17);
            printf("\t Matricula: ");
            fgets(base.Matricula, 10, stdin);

            // se escribe el archivo y lo cierra
            fseek(arch, contador * sizeof(Talumnos), SEEK_SET);
            fwrite(&base, sizeof(Talumnos), 1, arch); // ESCRIBE LOS REGISTROS AL ARCHIVO
            fseek(arch, (contador + 1) * sizeof(Talumnos), SEEK_SET);

            existe = 1;
            break;
        }
        contador++;
        fread(&base, sizeof(Talumnos), 1, arch);
    }
    if (existe == 0)
    {
        PonTextoCentradoPantalla(21, "No existe un Alumno con esa Matricula \n");
    }
    fclose(arch);
}

/////////////////
/////////////////////////
/////////////////

void OrdernarDatos()
{
}

void BorrarDatos()
{

    FILE *arch;
    arch = fopen("alumnos.dat", "r+");
    if (arch == NULL)
    {
        exit(1);
    }
    system("clear");
    CuadroInterfaz();

    // PIDE LA MATRICULLA QUE SE REQUIERE BUSCAR
    PonTextoCentradoPantalla(6, "Ingrese la matricula ");
    char matri[10];
    gotoxy(45, 7);
    fgets(matri, 25, stdin);
    Talumnos base;
    int existe = 0;
    int contador = 0;

    fread(&base, sizeof(Talumnos), 1, arch);
    while (!feof(arch))
    {
        if (strcmp(matri, base.Matricula) == 0)
        {
            strcpy(base.estatus, "0");
            fseek(arch, contador * sizeof(Talumnos), SEEK_SET);
            fwrite(&base, sizeof(Talumnos), 1, arch);
            fseek(arch, (contador + 1) * sizeof(Talumnos), SEEK_SET);
            existe = 1;
            break;
        }
        fread(&base, sizeof(Talumnos), 1, arch);
        contador++;
    }
    if (existe == 0)
    {
        PonTextoCentradoPantalla(21, "No existe un Alumno con esa Matricula \n");
    }
    fclose(arch);
}

void Goodbye()
{
    system("clear");
    CuadroInterfaz();
    PonTextoCentradoPantallaAnimadoVERT(1, 10, "[Despedida]");
    PonTextoCentradoPantalla(11, "Gracias por utilizar nuestro programa");
    PonTextoCentradoPantalla(12, "Nos vemos :) \n");
    getch();
}