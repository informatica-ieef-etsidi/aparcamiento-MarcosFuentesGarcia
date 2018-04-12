#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {

	char opcion;
	char matricula1[8], matricula2[8], matricula3[8], matricula4[8], matricula_comparar[8];
	int plaza1 = 0, plaza2 = 0, plaza3 = 0, plaza4 = 0, aux, c1, c2, c3, c4;
	char tipo_vehiculo;

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
				if (plaza1 == 1 && plaza2 == 1) {
					printf("No quedan huecos libres para coches en el aparcamiento.\n");
				}
				if (plaza1 == 0 || plaza2 == 0) {
					printf("Introduzca su numero de matricula: ");
					gets(matricula_comparar);

					c1 = strcmp(matricula1, matricula_comparar);
					c2 = strcmp(matricula2, matricula_comparar);

					if (c1 == 0 || c2 == 0) {
						if (c1 == 0) {
							printf("El vehiculo con la matricula introducida ya esta aparcado en la plaza 1.\n");
						}
						if (c2 == 0) {
							printf("El vehiculo con la matricula introducida ya esta aparcado en la plaza 2.\n");
						}
					}
					else {
						if (plaza1 == 0) {
							printf("Usted ha reservado la plaza 1.\n");
							plaza1 = 1;
							strcpy(matricula1, matricula_comparar);
						}
						else if (plaza2 == 0) {
							printf("Usted ha reservado la plaza 2.\n");
							plaza2 = 1;
							strcpy(matricula2, matricula_comparar);
						}
					}
				}
				break;
			case 'M':
			case 'm':
				if (plaza3 == 1 && plaza4 == 1) {
					printf("No quedan huecos libres para motos en el aparcamiento.\n");
				}
				if (plaza3 == 0 || plaza4 == 0) {
					printf("Introduzca su numero de matricula: ");
					gets(matricula_comparar);

					c3 = strcmp(matricula3, matricula_comparar);
					c4 = strcmp(matricula4, matricula_comparar);

					if (c3 == 0 || c4 == 0) {
						if (c3 == 0) {
							printf("El vehiculo con la matricula introducida ya esta aparcado en la plaza 3.\n");
						}
						if (c4 == 0) {
							printf("El vehiculo con la matricula introducida ya esta aparcado en la plaza 4.\n");
						}
					}
					else {
						if (plaza3 == 0) {
							printf("Usted ha reservado la plaza 3.\n");
							plaza3 = 1;
							strcpy(matricula3, matricula_comparar);
						}
						else if (plaza4 == 0) {
							printf("Usted ha reservado la plaza 4.\n");
							plaza4 = 1;
							strcpy(matricula4, matricula_comparar);
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

			c1 = strcmp(matricula1, matricula_comparar);
			c2 = strcmp(matricula2, matricula_comparar);
			c3 = strcmp(matricula3, matricula_comparar);
			c4 = strcmp(matricula4, matricula_comparar);

			switch (opcion) {
			case 'C':
			case 'c':
				if (c1 == 0 || c2 == 0) {
					if (c1 == 0) {
						printf("Ha abandonado la plaza 1.\n");
						plaza1 = 0;
						strcpy(matricula1, " ");
					}
					if (c2 == 0) {
						printf("Ha abandonado la plaza 2.\n");
						plaza2 = 0;
						strcpy(matricula2, " ");
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
						plaza3 = 0;
						strcpy(matricula3, " ");
					}
					if (c4 == 0) {
						printf("Ha abandonado la plaza 4.\n");
						plaza4 = 0;
						strcpy(matricula4, " ");
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
			if (plaza1 == 1) {
				printf("Ocupada - %s\n", matricula1);
			}
			if (plaza1 == 0) {
				printf("Libre\n");
			}
			printf("Plaza 2 - Coche - ");
			if (plaza2 == 1) {
				printf("Ocupada - %s\n", matricula2);
			}
			if (plaza2 == 0) {
				printf("Libre\n");
			}
			printf("Plaza 3 - Moto - ");
			if (plaza3 == 1) {
				printf("Ocupada - %s\n", matricula3);
			}
			if (plaza3 == 0) {
				printf("Libre\n");
			}
			printf("Plaza 4 - Moto - ");
			if (plaza4 == 1) {
				printf("Ocupada - %s\n", matricula4);
			}
			if (plaza4 == 0) {
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

			c1 = strcmp(matricula1, matricula_comparar);
			c2 = strcmp(matricula2, matricula_comparar);
			c3 = strcmp(matricula3, matricula_comparar);
			c4 = strcmp(matricula4, matricula_comparar);

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
