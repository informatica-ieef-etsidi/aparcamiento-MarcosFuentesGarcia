#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define NPLAZAS 4

struct estructuraDePlaza {
	int estado; // 0 - Libre / 1 - Ocupada
	char tipoDeVehiculo;
	char matricula[8]; // Formato de la matrícula: NNNNLLL
};


void main() {

	char opcion, numeroDeMatriculaIntroducido[8], usuario[7] = "marcos", usuarioIntroducido[7], password[7] = "marcos", passwordIntroducida[7];
	int i, numeroDePlazasLibres = NPLAZAS;
	struct estructuraDePlaza plaza[NPLAZAS];

	for (i = 0; i < NPLAZAS; i++) {

		plaza[i].estado = 0;

	}

	printf("\nIntroduzca su usuario: ");
	scanf("%s", usuarioIntroducido);
	printf("\nIntroduzca su contraseña: ");
	scanf("%s", passwordIntroducida);
	getchar();

	if ((strcmp(password, passwordIntroducida) == 0) && (strcmp(usuario, usuarioIntroducido) == 0)) {


		while (1) {

			int aux1 = 0;
			int aux2 = 0;

			printf("\nSeleccione una de estas opciones:\n");
			printf("\n  R - Reservar plaza");
			printf("\n  A - Abandonar plaza");
			printf("\n  E - Estado del aparcamiento");
			printf("\n  B - Buscar vehículo por matrícula");
			printf("\n  S - Salir\n\n");
			scanf("%c", &opcion);
			getchar();

			switch (opcion) {

			case 'r':
			case 'R':

				if (numeroDePlazasLibres > 0) {

					for (i = 0; i < NPLAZAS; i++) {

						if (plaza[i].estado == 0) {

							printf("\nIndique su tipo de vehículo 'M' (moto) o 'C' (coche): ");
							scanf("%c", &plaza[i].tipoDeVehiculo);
							getchar();

							if (plaza[i].tipoDeVehiculo == 'c' || plaza[i].tipoDeVehiculo == 'C' || plaza[i].tipoDeVehiculo == 'm' || plaza[i].tipoDeVehiculo == 'M') {

								numeroDePlazasLibres = numeroDePlazasLibres - 1;
								plaza[i].estado = 1;
								printf("\nIndique su número de matrícula: ");
								scanf("%s", plaza[i].matricula);
								getchar();
								printf("\nSu vehículo ocupa la plaza %d", i);
								break;

							}

							else if (plaza[i].tipoDeVehiculo != 'c' && plaza[i].tipoDeVehiculo != 'C' && plaza[i].tipoDeVehiculo != 'm' && plaza[i].tipoDeVehiculo != 'M') {

								printf("\nLa opción introducida no es válida.");
								break;

							}

						}

					}

				}

				else {

					printf("\nNo hay plazas libres.");
					break;

				}

				printf("\n\n");
				system("pause");
				system("cls");
				break;

			case 'a':
			case 'A':

				printf("\nIndique su matrícula: ");
				scanf("%s", numeroDeMatriculaIntroducido);
				getchar();

				for (i = 0; i < NPLAZAS; i++) {

					if (strcmp(numeroDeMatriculaIntroducido, plaza[i].matricula) == 0) {

						aux1 = 1;
						plaza[i].estado = 0;
						plaza[i].matricula;
						break;

					}

				}

				if (aux1 == 1) {

					numeroDePlazasLibres = numeroDePlazasLibres + 1;
					printf("\nHa abandonado su plaza.\n");
					aux1 = 0;

				}

				else {

					printf("\nEl número de matrícula introducido no coincide.");

				}

				printf("\n\n");
				system("pause");
				system("cls");
				break;

			case 'e':
			case 'E':

				printf("\n");

				for (i = 0; i < NPLAZAS; i++) {

					if (plaza[i].estado == 1) {

						if (plaza[i].tipoDeVehiculo == 'c' || plaza[i].tipoDeVehiculo == 'C') {

							printf("Plaza %d - Ocupada - %s - Coche\n", i, plaza[i].matricula);

						}

						else

							printf("Plaza %d - Ocupada - %s - Moto\n", i, plaza[i].matricula);

					}

					else

						printf("Plaza %d - Libre\n", i);

				}

				printf("\n\n");
				system("pause");
				system("cls");
				break;

			case 'b':
			case 'B':

				printf("\nIntroduzca la matrícula: ");
				scanf("%s", numeroDeMatriculaIntroducido);
				getchar();

				for (i = 0; i < NPLAZAS; i++) {

					if (strcmp(numeroDeMatriculaIntroducido, plaza[i].matricula) == 0) {

						aux2 = 1;
						break;

					}

				}

				if (aux2 == 1) {

					printf("\nEl número de matrícula coincide con la de un vehículo del aparcamiento que ocupa la plaza %d.", i);
					aux2 = 0;

				}

				else {

					printf("\nEl número de matrícula no coincide con la de un vehículo del aparcamiento.");

				}

				printf("\n\n");
				system("pause");
				system("cls");
				break;

			case 's':
			case 'S':

				system("pause");
				return 0;

			default:

				printf("\nLa opción introducida no es válida.\n");

				printf("\n\n");
				system("pause");
				system("cls");
				opcion;
				getchar();
				break;
			}

		}

	}

	else {

		printf("\nEl usuario o la contraseña no son correctos.\n\n");

	}

	system("pause");
	return 0;

}
