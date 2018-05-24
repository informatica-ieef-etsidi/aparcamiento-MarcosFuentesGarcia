#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NPLAZAS 100

struct plaza
{
	int estado; // 0 Libre 1 Ocupada
	char tipo; // M Moto C Coche
	char matricula[8]; // Formato NNNNLLL
};
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct usuario 
{
	char username[20];
	char password[20];
};

char menu(void);
int esDigitoValido(char);
int esLetraValida(char);
int esMatriculaValida(char[]);
int existeUsuario(struct usuario , char [], char []);
void recuento(struct plaza [], int , int *,int *);
void inicializar(struct plaza [], int);
int buscarPlazaLibre(struct plaza [], int, char);
int buscarVehiculo(struct plaza [], int , char []);
void leerFichero (char [],struct plaza [], int *);
void salvarFichero (char [],struct plaza [], int );

int main(int argc, char *argv[]) 
{
	struct usuario miUsuario = {"admin", "1234"};
	char usuario1[20],password1[20];
	struct plaza aparcamiento[NPLAZAS];
    int nplazas=0; 
	int intentos=0,accesoOK=0,i,resultado,plaza_liberar;
	char opcion,tipo;
	char matricula_b[8];
	int nLC,nLM;

    //inicializar(aparcamiento,NPLAZAS);
    leerFichero ("aparcamiento.txt",aparcamiento,&nplazas);
    

do
{
	system("color F5");
	printf ("Introduzca usuario:");
	scanf ("%s",usuario1);
	printf ("Introduzca password:");
	scanf("%s",password1);
	
	accesoOK=existeUsuario(miUsuario,usuario1,password1);
	if (accesoOK==0)
	{
	   printf ("Usuario/Password incorrectas\n");
	   intentos++;
	}
} while (accesoOK==0 && intentos<3);
	   
  if (accesoOK==0)
   	printf ("Accesso prohibido\n");
  else
  {
  	do
  	{
	  	opcion=menu();
		switch (opcion)
		{
			case 'B':
			case 'b':	printf ("Matricula a buscar: ");
						scanf ("%s",matricula_b);
						resultado=buscarVehiculo(aparcamiento, nplazas,matricula_b);

						if (resultado==-1)
						  printf ("La matricula no se encuentra en el aparcamiento\n");
						else
						  printf ("La matricula esta en la plaza %d\n",resultado+1);
						break;
			case 'R':
			case 'r': 	
						printf ("Coche o Moto (C|M):");
					  	fflush(stdin);
					  	scanf ("%c",&tipo);
					  	fflush(stdin);
					  	resultado= buscarPlazaLibre(aparcamiento,nplazas,tipo);

						if (resultado==-1)
						  printf ("No hay plazas disponibles de ese tipo\n");
						else
						{
							printf ("Introduzca matricula");
					  		scanf ("%s",aparcamiento[resultado].matricula);
					  		if (esMatriculaValida(aparcamiento[resultado].matricula)==1)
					  		{
							 	aparcamiento[resultado].estado=1;
							 	salvarFichero ("aparcamiento.txt",aparcamiento,nplazas);
							}
					  		else
					  		  printf ("La matricula no es valida\n");
						}

						break;	
			case 'E':
			case 'e':	printf ("\nEstado del aparcamiento\n");
						printf ("========================\n");
						printf ("Resumen de plazas Libres\n");
						recuento(aparcamiento,nplazas,&nLC,&nLM);
						printf ("Plazas Libres de Coches %d\n",nLC);
						printf ("Plazas Libres de Motos %d\n",nLM);
						
						for (i=0;i<nplazas;i++)
						{
							printf ("Plaza %d ",i+1);
							printf ("Tipo %c ",aparcamiento[i].tipo);
							if (aparcamiento[i].estado==1)
							  printf ("Ocupada - Matricula %s\n",aparcamiento[i].matricula);
							else
							  printf ("Libre\n");
						}
					   break;
			case 'A':
			case 'a':	printf ("Introduzca plaza a liberar:");
						scanf ("%d",&plaza_liberar);
						if (plaza_liberar>0 && plaza_liberar<=nplazas)
						{
							if (aparcamiento[plaza_liberar-1].estado==0)
							 printf ("La plaza esta libre\n");
							else
							{
								aparcamiento[plaza_liberar-1].estado=0;
								printf ("El vehiculo %s abandona la plaza\n",aparcamiento[plaza_liberar-1].matricula);
								strcpy(aparcamiento[plaza_liberar-1].matricula,"-------");
								salvarFichero ("aparcamiento.txt",aparcamiento,nplazas);
							}
						}
						else
							printf ("Plaza inexistente\n");
					
						break;
		}
	} while (opcion!='S' && opcion!='s');
	salvarFichero ("aparcamiento.txt",aparcamiento,nplazas);

  }
	return 0;
}


char menu (void)
{
	char opcion;
	
	printf ("\nSeleccione una de estas opciones:\n");
	printf ("R - Reservar plaza\n");
	printf ("A - Abandonar plaza\n");
	printf ("E - Estado del aparcamiento\n");
	printf ("B - Buscar vehiculo por matricula\n");
	printf ("S - Salir del programa\n");
	printf ("Opcion: ");
	fflush (stdin);
	scanf ("%c",&opcion);
	fflush (stdin);
	return opcion;
}

int esDigitoValido(char caracter)
{
	int resultado=0;
	if (caracter>='0' && caracter<='9')
		resultado=1;
	return resultado;
}

int esLetraValida(char caracter)
{
	int resultado=0;
	if ((caracter>='A' && caracter<='Z') || (caracter>='a' && caracter<='z'))
		resultado=1;
	return resultado;
}

int esMatriculaValida(char matricula[])
{
	int resultado=1;
	int i;
	
	for (i=0;i<4;i++)
	  if (esDigitoValido(matricula[i])==0)
	     resultado=0;
	if (resultado==1)
	  for (i=4;i<7;i++)
	    if (esLetraValida(matricula[i]==0))
	      resultado=0;
	return resultado;
}

int existeUsuario(struct usuario usuarioValido, char username[], char password[])
{
	int resultado=0;
	if (strcmp(usuarioValido.username,username)==0 && strcmp(usuarioValido.password,password)==0)
	  resultado=1;
	return resultado;
}

void recuento(struct plaza aparcamiento[], int dim, int *nLibresCoches,int *nLibresMotos)
{
	int i;
	(*nLibresCoches) = 0;
	(*nLibresMotos) = 0;
	
	for (i=0;i<dim;i++)
	{
		if (aparcamiento[i].tipo=='M' && aparcamiento[i].estado==0)
			(*nLibresMotos)++;
		else
		  if (aparcamiento[i].tipo=='C' && aparcamiento[i].estado==0)
		    (*nLibresCoches)++;
	}
}

void inicializar(struct plaza aparcamiento[], int dim)
{
	int i;
	
	for (i=0;i<dim;i++)
    {
    	aparcamiento[i].estado=0; // Establezco libre cada plaza
    	if (i%2 == 0)
    	  aparcamiento[i].tipo='C';
    	else
    	  aparcamiento[i].tipo='M';
	}
}

int buscarPlazaLibre(struct plaza aparcamiento[], int dim, char tipo)
{
	int i,resultado = -1;
	
	for (i=0;i<dim && resultado==-1;i++)
	{
		if (aparcamiento[i].estado==0 && aparcamiento[i].tipo==tipo)
		   resultado=i;
	}
	return resultado;
}

int buscarVehiculo(struct plaza aparcamiento[], int dim, char matricula[])
{
	int i,resultado=-1;
	for (i=0;i<dim && resultado==-1;i++)
	{
		if (aparcamiento[i].estado==1)
		  if (strcmp(aparcamiento[i].matricula,matricula)==0)
			     resultado=i;
	}
	return resultado;
}


void leerFichero (char nombreFichero[],struct plaza aparcamiento[], int *pdim)
{
	FILE *f;
	int i=0;
	
	f = fopen (nombreFichero,"r");
	if (f==NULL)
		printf ("El fichero no ha podido ser abierto\n");
	else
	{
		for (i=0;!feof(f);i++)
		{
			fscanf (f,"%d ",&aparcamiento[i].estado);
			fscanf (f,"%c ",&aparcamiento[i].tipo);
			fscanf (f,"%s",aparcamiento[i].matricula);
		}
		fclose (f);
	}
	*pdim = i;
}

void salvarFichero (char nombreFichero[],struct plaza aparcamiento[], int dim)
{
	FILE *f;
	int i;
	
	f=fopen (nombreFichero,"w");
	if (f== NULL)
		printf ("El fichero no ha podido crearse\n");
	else
	{
		for (i=0;i<dim;i++)
		{
			fprintf (f,"%d ",aparcamiento[i].estado);
			fprintf (f,"%c ",aparcamiento[i].tipo);
			fprintf (f,"%s",aparcamiento[i].matricula);
			if (i<dim-1) fprintf (f,"\n");
		}
		fclose (f);
	}
}







