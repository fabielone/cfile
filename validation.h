//fabiel ramirez validation functions



int validateInt(){



int num;
char term;
if(scanf("%d%c", &num, &term) != 2 || term != '\n')
    return -1;
else
   return num;



}


void validarLetras(char string[], int a, char *ask)
{

    int i = 0, tecla, b = 0, c;
   // printf("\n %s ",ask);
   
    do
    {
		 tecla = getch();
        
        if (tecla > 64 && tecla < 91 || tecla > 96 && tecla < 123)
        {
            printf("%c", tecla);
			string[i]=tecla;

            i++;
            b = 1;
        }

		else{

			

			

		}
		

		if(tecla==10){

			string[i]='\0';

			return ;
		}

		

    } while (i < a);
}

void validarNumeros(char string[],int a, char *ask)
{

    int i = 0, tecla, b = 0, c;
  
   
    do
    {
		 tecla = getch();
        
        if (tecla > 47 && tecla < 58)
        {
            printf("%c", tecla);
			string[i]=tecla;

            i++;
            b = 1;
        }
		else{

			

			

		}
		

		if(tecla==10){

			string[i]='\0';

			return ;
		}

		

    } while (i < a);
}


int rInt(int min,int max){


  int num ; 
   
   scanf("%d", &num);


   if(num>=min&&num<=max){

    return num;
   }
   else{

    return -1;
   }


}

int searchArray(int arr[],int num){






    for(int i=0;i<10;i++){


            if(arr[i]==num){

                return 1;
            }


    }
    

        return 0;
}