#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct plaza {
	int estado;
	char matricula[8];
	char tipo;
};

void main() {

	struct plaza plaza1 = { 0, " ", 'C' }, plaza2 = { 0, " ", 'C' }, plaza3 = { 0, " ", 'M' }, plaza4 = { 0, " ", 'M' };
	char opcion, tipo_vehiculo;
	char matricula_comparar[8];
	int aux, c1, c2, c3, c4;


	system("color FC");

	printf("BIENVENIDO AL PARKING\n\n\n");

	while (1) {

		printf("Seleccione una opcion:\nR - Reservar una plaza\nA - Abandonar su plaza\nE - Ver estado del aparcamiento\nB - Buscar vehiculo por matricula\nS - Salir del programa\n");
		scanf("%c", &opcion);
		getchar();

		switch (opcion) {
		case 'R':
		case 'r':
			printf("Elija el tipo de plaza que desea reservar:\nC - Coche\nM - Moto\n");
			scanf("%c", &tipo_vehiculo);
			getchar();

			switch (tipo_vehiculo) {
			case 'C':
			case 'c':
				if (plaza1.estado == 1 && plaza2.estado == 1) {
					printf("No quedan huecos libres para coches en el aparcamiento.\n");
				}
				if (plaza1.estado == 0 || plaza2.estado == 0) {
					printf("Introduzca su numero de matricula: ");
					gets(matricula_comparar);

					c1 = strcmp(plaza1.matricula, matricula_comparar);
					c2 = strcmp(plaza2.matricula, matricula_comparar);

					if (c1 == 0 || c2 == 0) {
						if (c1 == 0) {
							printf("El vehiculo con la matricula introducida ya esta aparcado en la plaza 1.\n");
						}
						if (c2 == 0) {
							printf("El vehiculo con la matricula introducida ya esta aparcado en la plaza 2.\n");
						}
					}
					else {
						if (plaza1.estado == 0) {
							printf("Usted ha reservado la plaza 1.\n");
							plaza1.estado = 1;
							strcpy(plaza1.matricula, matricula_comparar);
						}
						else if (plaza2.estado == 0) {
							printf("Usted ha reservado la plaza 2.\n");
							plaza2.estado = 1;
							strcpy(plaza2.matricula, matricula_comparar);
						}
					}
				}
				break;
			case 'M':
			case 'm':
				if (plaza3.estado == 1 && plaza4.estado == 1) {
					printf("No quedan huecos libres para motos en el aparcamiento.\n");
				}
				if (plaza3.estado == 0 || plaza4.estado == 0) {
					printf("Introduzca su numero de matricula: ");
					gets(matricula_comparar);

					c3 = strcmp(plaza3.matricula, matricula_comparar);
					c4 = strcmp(plaza4.matricula, matricula_comparar);

					if (c3 == 0 || c4 == 0) {
						if (c3 == 0) {
							printf("El vehiculo con la matricula introducida ya esta aparcado en la plaza 3.\n");
						}
						if (c4 == 0) {
							printf("El vehiculo con la matricula introducida ya esta aparcado en la plaza 4.\n");
						}
					}
					else {
						if (plaza3.estado == 0) {
							printf("Usted ha reservado la plaza 3.\n");
							plaza3.estado = 1;
							strcpy(plaza3.matricula, matricula_comparar);
						}
						else if (plaza4.estado == 0) {
							printf("Usted ha reservado la plaza 4.\n");
							plaza4.estado = 1;
							strcpy(plaza4.matricula, matricula_comparar);
						}
					}
				}
				break;
			default:
				printf("OPCION INCORRECTA\n");
			}
			break;
		case 'A':
		case 'a':
			printf("Introduzca el tipo de vehiculo con el que ha reservado la plaza:\nC - Coche\nM - Moto\n");
			scanf("%c", &opcion);
			getchar();
			printf("Introduzca la matricula del vehiculo con el que ha reservado la plaza: ");
			gets(matricula_comparar);

			c1 = strcmp(plaza1.matricula, matricula_comparar);
			c2 = strcmp(plaza2.matricula, matricula_comparar);
			c3 = strcmp(plaza3.matricula, matricula_comparar);
			c4 = strcmp(plaza4.matricula, matricula_comparar);

			switch (opcion) {
			case 'C':
			case 'c':
				if (c1 == 0 || c2 == 0) {
					if (c1 == 0) {
						printf("Ha abandonado la plaza 1.\n");
						plaza1.estado = 0;
						strcpy(plaza1.matricula, " ");
					}
					if (c2 == 0) {
						printf("Ha abandonado la plaza 2.\n");
						plaza2.estado = 0;
						strcpy(plaza2.matricula, " ");
					}
				}
				else {
					printf("No hay ninguna plaza reservada por un vehiculo con la matricula %s.\n", matricula_comparar);
				}
				break;
			case 'M':
			case 'm':
				if (c3 == 0 || c4 == 0) {
					if (c3 == 0) {
						printf("Ha abandonado la plaza 3.\n");
						plaza3.estado = 0;
						strcpy(plaza3.matricula, " ");
					}
					if (c4 == 0) {
						printf("Ha abandonado la plaza 4.\n");
						plaza4.estado = 0;
						strcpy(plaza4.matricula, " ");
					}
				}
				else {
					printf("No hay ninguna plaza reservada por un vehiculo con la matricula %s.\n", matricula_comparar);
				}
				break;
			}
			break;
		case 'E':
		case 'e':
			printf("Plaza 1 - Coche - ");
			if (plaza1.estado == 1) {
				printf("Ocupada - %s\n", plaza1.matricula);
			}
			if (plaza1.estado == 0) {
				printf("Libre\n");
			}
			printf("Plaza 2 - Coche - ");
			if (plaza2.estado == 1) {
				printf("Ocupada - %s\n", plaza2.matricula);
			}
			if (plaza2.estado == 0) {
				printf("Libre\n");
			}
			printf("Plaza 3 - Moto - ");
			if (plaza3.estado == 1) {
				printf("Ocupada - %s\n", plaza3.matricula);
			}
			if (plaza3.estado == 0) {
				printf("Libre\n");
			}
			printf("Plaza 4 - Moto - ");
			if (plaza4.estado == 1) {
				printf("Ocupada - %s\n", plaza4.matricula);
			}
			if (plaza4.estado == 0) {
				printf("Libre\n");
			}
			break;
		case 'B':
		case 'b':
			printf("Introduzca el tipo de vehiculo con el que ha reservado la plaza:\nC - Coche\nM - Moto\n");
			scanf("%c", &opcion);
			getchar();
			printf("Introduzca la matricula del vehiculo que desea buscar: ");
			gets(matricula_comparar);

			c1 = strcmp(plaza1.matricula, matricula_comparar);
			c2 = strcmp(plaza2.matricula, matricula_comparar);
			c3 = strcmp(plaza3.matricula, matricula_comparar);
			c4 = strcmp(plaza4.matricula, matricula_comparar);

			switch (opcion) {
			case 'C':
			case'c':
				if (c1 == 0) {
					printf("El vehiculo que busca se encuentra estacionado en la plaza 1.\n");
				}
				if (c2 == 0) {
					printf("El vehiculo que busca se encuentra estacionado en la plaza 2.\n");
				}
				if (c1 != 0 && c2 != 0) {
					printf("El vehiculo que busca no se encuentra estacionado en el parking.\n");
				}
				break;
			case 'M':
			case 'm':
				if (c3 == 0) {
					printf("El vehiculo que busca se encuentra estacionado en la plaza 3.\n");
				}
				if (c4 == 0) {
					printf("El vehiculo que busca se encuentra estacionado en la plaza 4.\n");
				}
				if (c3 != 0 && c4 != 0) {
					printf("El vehiculo que busca no se encuentra estacionado en el parking.\n");
				}
				break;
			}
			break;
		case 'S':
		case 's':
			break;
		default:
			printf("OPCION INCORRECTA\n");
		}

		if (opcion == 'S' || opcion == 's') {
			break;
		}

		system("pause");
		system("cls");
		printf("BIENVENIDO AL PARKING\n\n\n");
	}
	//system("pause");
}