#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>
#define COUNT 400000
char matrix[3][3];  /* la matriz */
int combinaciones[8][3][2];
void estilo1(void); 
void estilo2(void);	
char condiciones_victoria(void);
void inicializadores_matriz(void);
void cordenadas_jugador(void);
void cordenadas_jugador2(void);
void inteligencia_neo_artificial(void);
void interfaz_matriz(void);
void cargando (void);
int score1=0,score2=0;
int opcion=0;
int main(void)
{
	int turno=0;
	char respawn;
	char fin;
	char flag;
	do{
		fflush (stdin);
		system ("cls");
		system ("COLOR A");
		regresar:
			printf("\n\t\t\t  Bienvenido al menu de GATO \n\n\n");
		/*printf("Menu Jugar\n");*/
		printf("\t\t\t    1.  Jugador1 VS CPU\n\t\t\t    2.  Jugador1 VS Jugador2\n\t\t\t    3.  Salir del programa\n");
		scanf ("%d",&opcion);
	}while (opcion!=1 && opcion!=2 && opcion!=3);
	switch (opcion) {
		/*P1 VS AI*/
	case 1:
		cargando();
		do {
			fin =  ' ';
			inicializadores_matriz();
			do {
				system ("cls");
				system ("COLOR A");
				estilo1();
				interfaz_matriz();
				turno++;
				cordenadas_jugador();
				fin = condiciones_victoria(); /* checa si hubo victoria del jugador 1*/
				if(turno==9) break;
				if(fin!= ' ') break; /* Condicion de victoria*/
				estilo1();
				inteligencia_neo_artificial();
				interfaz_matriz();
				turno++;
				fin = condiciones_victoria(); /* checa si hubo vitoria CPU*/
			} while(fin== ' ');
			if(fin=='X'){
				score1++;
				system ("cls");
				estilo1();
				printf("\t  %c   %c              %c%c%c%c                       %c\n",95,95,95,95,95,95,95);     
				printf("\t %c %c %c %c %c%c %c %c%c%c   %c %c%c%c%c %c%c %c %c %c%c   %c%c %c  %c%c%c %c %c%c%c\n",124,124,124,124,95,95,95,95,95,95,47,95,95,95,124,95,95,95,95,95,95,95,95,95,95,95,124,124,95,95,95);  
				printf("\t %c %c%c%c %c%c %c%c %c  %c%c %c %c  %c %c %c %c%c %c %c%c%c  %c%c %c%c %c%c %c%c %c %c %c\n",124,124,95,124,124,47,95,96,124,95,124,124,124,95,47,95,96,124,96,95,92,47,95,96,124,47,95,96,124,47,95,92); 
				printf("\t %c  %c  %c %c%c%c %c%c%c %c %c %c%c%c %c %c%c%c %c %c %c %c %c%c%c %c %c%c%c %c %c%c%c %c\n",124,95,124,40,95,124,124,95,95,41,124,124,95,124,124,40,95,124,124,124,124,124,40,95,124,124,40,95,124,124,40,95,41,124);
				printf("\t %c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c  %c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c  %c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",124,95,124,124,95,124,92,95,95,44,95,124,95,95,95,47,92,95,95,95,95,124,92,95,95,44,95,124,95,124,124,95,124,92,95,9544,95,124,92,95,95,44,95,124,92,95,95,95);
				interfaz_matriz(); /* muestra posisiones finales */
			}
			if (fin=='O') { 	
				score2++;
				system ("cls");
				estilo1();
				printf("\t     %c   %c             %c%c%c%c              %c %c     %c\n",95,95,95,95,95,95,95,95,95);       
				printf("\t    %c %c %c %c %c%c %c %c%c%c  %c  %c %c %c%c%c %c %c%c %c%c%c %c%c%c %c%c%c %c %c%c%c\n",124,124,124,124,95,95,95,95,95,95,124,95,92,95,95,95,95,95,95,95,95,124,40,95,41,95,95,124,124,95,95,95);  
				printf("\t    %c %c%c%c %c%c %c%c %c %c%c%c %c %c%c%c %c %c %c %c%c%c%c %c%c %c %c%c %c%c %c%c   %c%c\n",124,124,95,124,124,47,95,96,47,95,95,124,124,124,95,41,47,95,92,96,95,95,47,96,124,124,47,95,96,124,47,95,92); 
				printf("\t    %c  %c  %c %c%c%c %c%c%c %c %c  %c%c%c  %c%c%c %c %c %c%c%c %c %c %c%c%c %c %c%c%c %c\n",124,95,124,40,95,124,92,95,95,92,124,95,95,47,95,95,47,124,124,40,95,124,124,40,95,41,124);
				printf("\t    %c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c   %c%c%c%c%c%c%c  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",124,95,124,124,95,124,92,95,95,44,95,124,95,95,95,47,124,95,124,92,95,95,95,124,95,124,92,95,95,44,95,124,95,124,92,95,95,44,95,124,92,95,95,95,47);
				interfaz_matriz(); /* muestra posisiones finales */
			}
			if (fin==' ' && turno==9)
				if (opcion ==1) 
				{
					estilo1();
					printf("\t\t  %c%c%c%c%c                       %c       %c %c\n",95,95,95,95,95,95,95,95);
					printf("\t\t %c %c%c%c%c%c%c %c%c %c%c%c  %c %c%c   %c%c %c%c %c%c %c%c%c%c %c %c\n",124,95,95,95,95,124,95,95,95,95,95,95,95,95,95,95,95,95,124,124,95,95,95,95,124,124,124);
					printf("\t\t %c  %c%c %c %c%c %c %c %c%c %c%c %c %c %c%c %c %c%c%c %c %c %c %c\n",124,95,124,124,96,95,96,95,92,124,96,95,92,47,95,96,124,95,95,47,95,92,124,124);
					printf("\t\t %c %c%c%c%c%c %c %c %c %c %c %c%c%c %c %c%c%c %c %c%c  %c%c%c%c%c%c%c\n",124,124,95,95,95,124,124,124,124,124,124,124,95,41,124,40,95,124,124,124,124,95,95,47,95,124,95,124);
					printf("\t\t %c%c%c%c%c%c%c%c%c %c%c%c %c%c%c %c%c%c%c %c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c\n",124,95,95,95,95,95,124,95,124,124,95,124,124,95,124,46,95,95,47,92,95,95,44,95,124,92,95,95,95,40,95,124,95,41);
					printf("\t\t                 %c%c%c\n",124,95,124); 
					interfaz_matriz(); /* muestra posisiones finales */
				}
			    if (fin==' ' && turno==9)
			    if (opcion ==2) 
				{
				    estilo2();
				    printf("\t\t\t\t  %c%c%c%c%c                       %c       %c %c\n",95,95,95,95,95,95,95,95);
				    printf("\t\t\t\t %c %c%c%c%c%c%c %c%c %c%c%c  %c %c%c   %c%c %c%c %c%c %c%c%c%c %c %c\n",124,95,95,95,95,124,95,95,95,95,95,95,95,95,95,95,95,95,124,124,95,95,95,95,124,124,124);
				    printf("\t\t\t\t %c  %c%c %c %c%c %c %c %c%c %c%c %c %c %c%c %c %c%c%c %c %c %c %c\n",124,95,124,124,96,95,96,95,92,124,96,95,92,47,95,96,124,95,95,47,95,92,124,124);
				    printf("\t\t\t\t %c %c%c%c%c%c %c %c %c %c %c %c%c%c %c %c%c%c %c %c%c  %c%c%c%c%c%c%c\n",124,124,95,95,95,124,124,124,124,124,124,124,95,41,124,40,95,124,124,124,124,95,95,47,95,124,95,124);
				    printf("\t\t\t\t %c%c%c%c%c%c%c%c%c %c%c%c %c%c%c %c%c%c%c %c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c\n",124,95,95,95,95,95,124,95,124,124,95,124,124,95,124,46,95,95,47,92,95,95,44,95,124,92,95,95,95,40,95,124,95,41);
				    printf("\t\t\t\t                 %c%c%c\n",124,95,124);
				    interfaz_matriz(); /* muestra posisiones finales */
			    }
			printf("\t%c  Presione S/s Para jugar denuevo.\n\t%c  Presione cualquier tecla para regresar al menu principal.",16,16);
			
			turno=0;
			fflush(stdin);
			flag=getchar();
			if (flag=='S' || flag=='s') {
				scanf ("%c",&respawn);
				
			}
			else if (flag!='S' || flag!= 's'){
				printf ("\n\t\t\tPuntuaje jugador:%d \t\t\t Puntuaje maquina:%d",score1,score2);
				system ("cls");
				score1=0;
				score2=0;
				goto regresar;
				break;
			}
		}while(respawn=='\n');
		break;
		/*P1 VS P2*/
	case 2:
		cargando();
		do {
			fin =  ' ';
			inicializadores_matriz();
			do {
				system ("cls");
				estilo2();
				interfaz_matriz();
				turno++;
				cordenadas_jugador();
				fin = condiciones_victoria(); /* checa si hubo victoria de jugador 1 */
				if(fin!= ' ') break; /* condicion que declara victora*/
				if (turno==9)break;
				estilo2();
				interfaz_matriz();
				turno++;
				cordenadas_jugador2();
				fin = condiciones_victoria(); /* checka si hubo victoria de jugador2 */
			} while(fin== ' ');
			if(fin=='X'){ 
				score1++;
				system("cls");
				estilo2();
				printf("\t\t       %c                       %c              %c\n",95,95,95);
                printf("\t\t      %c %c%c   %c  %c%c %c  %c%c %c  %c%c%c %c %c%c%c  %c %c%c  %c %c\n",124,124,95,95,95,95,95,95,95,95,95,95,124,124,95,95,95,95,95,95,47,124);
                printf("\t\t   %c  %c %c %c %c %c%c %c%c %c%c %c%c %c%c %c%c %c%c %c %c%c %c%c%c%c %c %c\n",95,124,124,124,124,124,47,95,96,124,47,95,96,124,47,95,96,124,47,95,92,124,96,95,95,124,124,124);
                printf("\t\t  %c %c%c%c %c %c%c%c %c %c%c%c %c %c%c%c %c %c%c%c %c %c%c%c %c %c    %c %c\n",124,124,95,124,124,124,95,124,124,40,95,124,124,40,95,124,124,40,95,124,124,40,95,124,124,40,95,41,124,124,124,124);
                printf("\t\t   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c    %c%c%c\n",92,95,95,95,47,95,92,95,95,44,95,124,92,95,95,44,124,92,95,95,44,95,124,92,95,95,44,95,124,92,95,95,95,47,124,95,124,124,95,124);
                printf("\t\t       %c %c%c%c%c %c%c%c%c%c%c %c%c   %c%c%c\n",47,95,95,95,124,95,124,95,95,95,47,95,95,95,95,95);                   
                printf("\t\t      %c %c  %c %c %c%c %c %c%c %c %c %c %c\n",124,124,95,47,95,96,124,39,95,92,47,95,92);                  
                printf("\t\t      %c %c%c%c %c %c%c%c %c %c %c %c %c%c%c %c\n",124,124,95,124,124,40,95,124,124,124,124,124,40,95,41,124);                 
                printf("\t\t       %c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c\n",92,95,95,95,95,124,92,95,95,44,95,124,95,124,124,95,124,92,95,95,95,47); 
				interfaz_matriz();
			}
			if (fin=='O') { 
				score2++;
				system ("cls");
				estilo2();
				printf("\t\t       %c                       %c           %c%c%c%c\n",95,95,95,95,95,95 );
                printf("\t\t      %c %c%c   %c  %c%c %c  %c%c %c  %c%c%c %c %c%c%c  %c%c%c%c%c%c%c %c\n",124,124,95,95,95,95,95,95,95,95,95,95,124,124,95,95,95,95,95,95,124,95,95,95,92);
                printf("\t\t   %c  %c %c %c %c %c%c %c%c %c%c %c%c %c%c %c%c %c%c %c %c%c %c%c%c%c%c%c%c %c\n",95,124,124,124,124,124,47,95,96,124,47,95,96,124,47,95,96,124,47,95,92,124,96,95,95,124,95,95,41,124);
                printf("\t\t  %c %c%c%c %c %c%c%c %c %c%c%c %c %c%c%c %c %c%c%c %c %c%c%c %c %c  %c %c%c%c\n",124,124,95,124,124,124,95,124,124,40,95,124,124,40,95,124,124,40,95,124,124,40,95,124,124,40,47,95,95,47);
                printf("\t\t   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c\n",92,95,95,95,47,95,92,95,95,44,95,124,92,95,95,44,124,92,95,95,44,95,124,92,95,95,44,95,124,92,95,95,95,47,124,95,124,124,95,95,95,95,95,124);
                printf("\t\t       %c %c%c%c%c %c%c%c%c%c%c %c%c   %c%c%c\n",47,95,95,95,124,95,124,95,95,95,47,95,95,95,95,95);                   
                printf("\t\t      %c %c  %c %c %c%c %c %c%c %c %c %c %c\n",124,124,95,47,95,96,124,39,95,92,47,95,92);                  
                printf("\t\t      %c %c%c%c %c %c%c%c %c %c %c %c %c%c%c %c\n",124,124,95,124,124,40,95,124,124,124,124,124,40,95,41,124);                 
                printf("\t\t       %c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c\n",92,95,95,95,95,124,92,95,95,44,95,124,95,124,124,95,124,92,95,95,95,47);  
				interfaz_matriz();
			}
			if (fin==' ' && turno==9)
			{	system ("cls");
			estilo2();
			printf("\t\t  %c%c%c%c%c                       %c       %c %c\n",95,95,95,95,95,95,95,95);
			printf("\t\t %c %c%c%c%c%c%c %c%c %c%c%c  %c %c%c   %c%c %c%c %c%c %c%c%c%c %c %c\n",124,95,95,95,95,124,95,95,95,95,95,95,95,95,95,95,95,95,124,124,95,95,95,95,124,124,124);
			printf("\t\t %c  %c%c %c %c%c %c %c %c%c %c%c %c %c %c%c %c %c%c%c %c %c %c %c\n",124,95,124,124,96,95,96,95,92,124,96,95,92,47,95,96,124,95,95,47,95,92,124,124);
			printf("\t\t %c %c%c%c%c%c %c %c %c %c %c %c%c%c %c %c%c%c %c %c%c  %c%c%c%c%c%c%c\n",124,124,95,95,95,124,124,124,124,124,124,124,95,41,124,40,95,124,124,124,124,95,95,47,95,124,95,124);
			printf("\t\t %c%c%c%c%c%c%c%c%c %c%c%c %c%c%c %c%c%c%c %c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c\n",124,95,95,95,95,95,124,95,124,124,95,124,124,95,124,46,95,95,47,92,95,95,44,95,124,92,95,95,95,40,95,124,95,41);
			printf("\t\t                 %c%c%c\n",124,95,124);
			interfaz_matriz(); /* muestra posisiones finales */
			}
			printf("\t%c  Presione S/s Para jugar de nuevo.\n\t%c  Presione cualquier tecla para regresar al menu principal.",16,16);
			
			turno=0;
			fflush(stdin);
			flag=getchar();
			if (flag=='S' || flag=='s') {
				scanf ("%c",&respawn);
				
			}
			else if (flag!='S' || flag!= 's'){
				printf ("\n\t\t\tPuntuaje jugador1:%d \t\t\t Puntuaje jugador2:%d",score1,score2);
				system ("cls");
				score1=0;
				score2=0;
				goto regresar;
				break;
			}
		}while (respawn=='\n');
	}
	return 0;
}

void inicializadores_matriz(void){
	int i, j;
	
	for(i=1; i<=3; i++)
		for(j=1; j<=3; j++) matrix[i][j] =  ' ';
	
	/*filas primer arreglo type: "combo alpha" contiene[3 tipos de combinaciones para las 3 filas ] */
	combinaciones[1][1][1] = 1;
	combinaciones[1][1][2] = 1;
	combinaciones[1][2][1] = 1;
	combinaciones[1][2][2] = 2;
	combinaciones[1][3][1] = 1;
	combinaciones[1][3][2] = 3;
	
	combinaciones[2][1][1] = 2;
	combinaciones[2][1][2] = 1;
	combinaciones[2][2][1] = 2;
	combinaciones[2][2][2] = 2;
	combinaciones[2][3][1] = 2;
	combinaciones[2][3][2] = 3;
	
	combinaciones[3][1][1] = 3;
	combinaciones[3][1][2] = 1;
	combinaciones[3][2][1] = 3;
	combinaciones[3][2][2] = 2;
	combinaciones[3][3][1] = 3;
	combinaciones[3][3][2] = 3;
	/*columnas segundo arreglo type : "combo beta" contiene[3 tipos de combinaciones para las 3 columnas ] */
	combinaciones[4][1][1] = 1;
	combinaciones[4][1][2] = 1;
	combinaciones[4][2][1] = 2;
	combinaciones[4][2][2] = 1;
	combinaciones[4][3][1] = 3;
	combinaciones[4][3][2] = 1;
	
	combinaciones[5][1][1] = 1;
	combinaciones[5][1][2] = 2;
	combinaciones[5][2][1] = 2;
	combinaciones[5][2][2] = 2;
	combinaciones[5][3][1] = 3;
	combinaciones[5][3][2] = 2;
	
	combinaciones[6][1][1] = 1;
	combinaciones[6][1][2] = 3;
	combinaciones[6][2][1] = 2;
	combinaciones[6][2][2] = 3;
	combinaciones[6][3][1] = 3;
	combinaciones[6][3][2] = 3;
	/*diagonales segundo 3 areglo type: "combo gamma" contiene[2 tipos de combinaciones para las 2 diagonales ] */
	combinaciones[7][1][1] = 1;
	combinaciones[7][1][2] = 1;
	combinaciones[7][2][1] = 2;
	combinaciones[7][2][2] = 2;
	combinaciones[7][3][1] = 3;
	combinaciones[7][3][2] = 3;
	
	combinaciones[8][1][1] = 1;
	combinaciones[8][1][2] = 3;
	combinaciones[8][2][1] = 2;
	combinaciones[8][2][2] = 2;
	combinaciones[8][3][1] = 3;
	combinaciones[8][3][2] = 1;
	
}

/* jugador 1 */
void cordenadas_jugador(void){
	int x, y;
	
	do {
		fflush (stdin);
		printf("\n\t\t\tJugador 1 ingrese la fila:");
		scanf("%d*c", &x);
		if (x!=1 && x!=2 && x!=3) {
			system("cls");
			if (opcion==2)
			{
				estilo2();
			}
			else
				{
					estilo1();
				}
			puts ("\n\t\t   Movimiento Nulo! solo validos del 1-3");
			printf("\a");
			interfaz_matriz();
			
		}
		
	}while(x!=1 && x!=2 && x!=3);
	
	do {
		fflush (stdin);
		printf("\n\t\t\tJugador 1 ingrese la columna:");
		scanf ("%d", &y);
		if (y!=1 && y!=2 && y!=3) {
			system("cls");
			if (opcion==2)
			{
				estilo2();
			}
			else
				{
					estilo1();
				}
			puts ("\n\t\t  Movimiento Nulo! solo validos del 1-3");
			printf("\a");
			interfaz_matriz();
			
		}
		
	}while(y!=1 && y!=2 && y!=3);
	
	if(matrix[x][y]!= ' '){
		
		system("cls");
		if (opcion==2)
		{
			estilo2();
		}
		else
			{
				estilo1();
			}
		
		printf("\t\t\t CORDENADAS OCUPADAS!!! \n");
		printf("\a");
		interfaz_matriz ();
		cordenadas_jugador();
	}
	else matrix[x][y] = 'X';
}
void cordenadas_jugador2(void) {
	int x, y;
	
	do {
		fflush (stdin);
		printf("\n\t\t\tJugador 2 ingresa la fila:");
		scanf("%d*c", &x);
		if (x!=1 && x!=2 && x!=3) {
			
			system("cls");
			estilo2();
			puts ("\n\t\t   Movimiento Nulo! solo validos del 1-3");
			printf("\a");
			interfaz_matriz();
			
			
		}
		
	}while(x!=1 && x!=2 && x!=3);
	
	do {
		fflush (stdin);
		printf("\n\t\t\tJugador 2 ingresa la columna:");
		scanf ("%d", &y);
		if (y!=1 && y!=2 && y!=3) {
			system("cls");
			estilo2();
			puts ("\n\t\t   Movimiento Nulo! solo validos del 1-3"); /*validacion si el usuario pone valor fuera del rango*/
			printf("\a");
			interfaz_matriz();
			
		}
	}while(y!=1 && y!=2 && y!=3);
	
	if(matrix[x][y]!= ' '){
		
		system("cls");
		
		estilo2();
		printf("\t\t\t CORDENADAS OCUPADAS!!! \n");
		printf("\a");
		interfaz_matriz ();
		cordenadas_jugador2();
	}
	else matrix[x][y] = 'O';
}


void inteligencia_neo_artificial(void){
	int i, j,k;
	
	
	for(i=1; i<=3; i++){
		for(j=1; j<=3; j++)
			
			if(matrix[i][j]==' ') break;
		if(matrix[i][j]==' ') break;
	}
	
	for (k=0;k<=8;k++){
		
		/*combo alpha combinacion offensiva*/
		if (matrix[combinaciones[k][1][1]][combinaciones[k][1][2]]=='O' &&
			matrix[combinaciones[k][2][1]][combinaciones[k][2][2]]=='O' &&
			matrix[combinaciones[k][3][1]][combinaciones[k][3][2]]==' '){
				i=combinaciones[k][3][1];
				j=combinaciones[k][3][2];
			}
		/*combo beta combinacion offensiva*/
		else if (matrix[combinaciones[k][1][1]][combinaciones[k][1][2]]=='O' &&
			matrix[combinaciones[k][2][1]][combinaciones[k][2][2]]==' ' &&
			matrix[combinaciones[k][3][1]][combinaciones[k][3][2]]=='O'){
				i=combinaciones[k][2][1];
				j=combinaciones[k][2][2];
			}
		/*combo gamma combinacion offensiva*/
		else if (matrix[combinaciones[k][1][1]][combinaciones[k][1][2]]==' ' &&
			matrix[combinaciones[k][2][1]][combinaciones[k][2][2]]=='O' &&
			matrix[combinaciones[k][3][1]][combinaciones[k][3][2]]=='O'){
				i=combinaciones[k][1][1];
				j=combinaciones[k][1][2];
			}
		/*combo alpha interpolacion defensiva*/
		else if (matrix[combinaciones[k][1][1]][combinaciones[k][1][2]]=='X' &&
			matrix[combinaciones[k][2][1]][combinaciones[k][2][2]]=='X' &&
			matrix[combinaciones[k][3][1]][combinaciones[k][3][2]]==' '){
				i=combinaciones[k][3][1];
				j=combinaciones[k][3][2];
			}
		/*combo beta interpolacion defensiva*/
		else if (matrix[combinaciones[k][1][1]][combinaciones[k][1][2]]=='X' &&
			matrix[combinaciones[k][2][1]][combinaciones[k][2][2]]==' ' &&
			matrix[combinaciones[k][3][1]][combinaciones[k][3][2]]=='X'){
				i=combinaciones[k][2][1];
				j=combinaciones[k][2][2];
			}
		/*combo gamma interpolacion defensiva*/
		else if (matrix[combinaciones[k][1][1]][combinaciones[k][1][2]]==' ' &&
			matrix[combinaciones[k][2][1]][combinaciones[k][2][2]]=='X' &&
			matrix[combinaciones[k][3][1]][combinaciones[k][3][2]]=='X'){
				i=combinaciones[k][1][1];
				j=combinaciones[k][1][2];
			}
		
	}
	
	if (matrix[2][2] == ' ') {
		matrix [2][2] = 'O';
	}
	
	
	
	
	else if (matrix[i][j] == 'X') {
		
	}
	
	else matrix[i][j] = 'O'; 
}

/* la interfaz de la matriz */
void interfaz_matriz(void){
	int t;
	printf ("\n\n");
	for(t=1; t<=3; t++) {
		
		printf("\t\t\t\t %c | %c | %c ",matrix[t][1],
			matrix[t][2], matrix [t][3]);
		if(t!=3) printf("\n\t\t\t\t---|---|---\n");
	}
	printf("\n\n");
}

/* checa si hubo victoria */
char condiciones_victoria (void){
	int i;
	
	for(i=1; i<=3; i++)  /* checa las filas */
		if(matrix[i][1]==matrix[i][2] &&
			matrix[i][1]==matrix[i][3]) 
			
			return matrix[i][1];
	
	for(i=1; i<=3; i++)  /* checa columnas */
		if(matrix[1][i]==matrix[2][i] &&
			matrix[1][i]==matrix[3][i]) 
			
			return matrix[1][i];
	
	/* prueba diagonales */
	if(matrix[1][1]==matrix[2][2] &&
		matrix[2][2]==matrix[3][3])
		return matrix[1][1];
	
	if(matrix[1][3]==matrix[2][2] &&
		matrix[2][2]==matrix[3][1])
		return matrix[1][3];
	
	return ' ';
}

void estilo1(void) /* funcones para la permaencia de interfaz grafica */
{
	system ("cls");
	system ("COLOR A");
	printf("\n\t\t\t      Tic Tac Toe Gato\n\n");
	printf("\t\t\t  Modo de juego:Contra CPU\n\n");
	printf("\t\t\t\tPuntuaciones\n\t\t\t\t  \n\t\t\tJugador1:%d\t Maquina:%d\n\n",score1,score2);
}
void estilo2()
{
	system ("cls");
	system ("COLOR A");
	printf("\n\t\t\t      Tic Tac Toe Gato\n\n");
	printf("\t\t\t Modo de juego:Multijugador\n\n");
	printf("\t\t\t\tPuntuaciones\n\t\t\t\t  \n\t\t\tJugador1:%d\t Jugador2:%d\n\n",score1,score2);
}
void cargando(void){
	int c,t,h;
	system ("COLOR E");
	for(c=0;c<20;c++)
	{
		if(c<30)
		{
			Sleep(20);
			printf("\n");
			printf("\n");	
			printf("\n");
			printf("\n");
			printf("               %c\n",95);
			printf("            %c%c%c%c%c\n",124,92,47,40,95);
			printf("            %c   %c%c%c%c\n",47,45,250,96,46);
			printf("            %c  %c%c%c%c%c%c\n",124,61,95,95,45,47,61);
			printf("            %c   %c\n",47,40);
			printf("           %c     %c\n",59,92);
			printf("          %c      %c\n",47,124);
			printf("         %c    %c  %c\n",47,44,47);
			printf("       %c%c      %c %c\n",46,39,124,124);
			printf("      %c      %c%c%c %c\n",47,45,45,59,124);
			printf("      %c         %c%c\n",124,124,124);
			printf("      %c        %c%c%c%c%c %c%c%c%c\n",124,47,95,59,45,96,95,96,250,46);
			printf("      %c  %c%c%c%c%c%c %c%c%c%c %c%c%c%c\n",92,96,45,45,45,45,45,96,95,46,45,96,250,46,95,41);
			printf("       %c%c%c%c%c%c%c%c%c%c%c\n",96,248,45,45,45,45,45,45,45,96,34);
			
			printf("        Espere porfavor...");			
			printf("\n");	
			printf("\n");
			Sleep(20);
			printf("\n");
			for(t=0;t<c;t++)
				printf("%c%c%c",178,178,178);printf("   %c  %c%c%c%c\n",191,95,95,248,248);
				for(t=0;t<c;t++)
					printf("%c%c%c",178,178,178);printf("   %c%c%c%c%c%c%c%c\n",192,45,40,95,95,95,58,62);
					for(t=0;t<c;t++)
						printf("%c%c%c",178,178,178);printf("      %c %c\n",34,34);
						for(h=0;h<c;h++);
						system("cls");
						
		}
		
	}
}
