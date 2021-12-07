#include <string.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct {

    char nombre[40];
    char pais[25];

}DatosPersonales;

typedef struct{
    DatosPersonales datos;
    char deporte[30];
    int numMedallas;

}Deportista;

void calc(Deportista depo[],char deporte[6][30], int len)
{

    int medallas[6]={0,0,0,0,0,0};

  for(int x =0; x<len; x++)
    {
       for(int y=0; y<6; y++)
       {
           if(depo[x].deporte[0]=='N')
           {
               medallas[0]+=depo[x].numMedallas;
               break;
           }
            else if(depo[x].deporte[0]=='E' && depo[x].deporte[1]=='q')
            {
                 medallas[4]+=depo[x].numMedallas;
                 break;
            }
          else if(strcmp(depo[x].deporte,deporte[y])==0)
          {

              medallas[y]+=depo[x].numMedallas;
              break;
          }
        }
    }

for(int x =0; x< 6; x++)
    printf("%s : %d\n",deporte[x],medallas[x]);
}
int leer(char c[], Deportista depo[])
{
    FILE *fp;
    fp= fopen(c,"r");
    char nom[40];
    char pais[25];
    char deporte[30];
    int medallas;

    int index=0;

    while(fscanf(fp,"%s %s %s %d",nom,pais,deporte,&medallas)!=EOF)
    {
        Deportista dp;
        strcpy(dp.datos.nombre,nom);
        strcpy(dp.datos.pais,pais);
        strcpy(dp.deporte,deporte);
        dp.numMedallas=medallas;

        depo[index]= dp;

        index++;
    }
    fclose(fp);
    return index;
}
int main()
{
    Deportista deportistas[100];
    char deporte[6][30] = {"Natación", "Atletismo", "Ciclismo", "Gimnasia", "Equitacion", "Esgrima"};
    int len=leer("deportistas.txt", deportistas);
    //printf("%s",deportistas[0].deporte);
    calc(deportistas, deporte, len);

    return 0;
}
