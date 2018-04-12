#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

void main() {

	char opcion, numeroDeMatricula[8][2], numeroDeMatriculaIntroducido[8], estadoDeLaPlaza[6][2];
	int i, numeroDePlazasLibres = 2, plaza[2] = { 0,0 };

	while (1) {

		printf("Seleccione una de estas opciones:\n");
		printf("\nR - Reservar plaza");
		printf("\nA - Abandonar plaza");
		printf("\nE - Estado del aparcamiento\n\n");
		scanf_s("%c", &opcion);

		switch (opcion) {

		case 'r':
		case 'R':

			if (numeroDePlazasLibres > 0) {

				numeroDePlazasLibres = numeroDePlazasLibres - 1;

				for (i = 1; i <= 2; i++) {

					if (plaza[i] == 0) {

						plaza[i] = 1;
						estadoDeLaPlaza[i][6] = "Libre";
						printf("\nIndique su n�mero de matr�cula: ");
						scanf_s("%s", numeroDeMatricula[i]);
						getchar();
						break;

					}

					else

						i = i + 1;

				}

				

			}

			else

				printf("\nNo hay plazas libres.");

			break;

		case 'a':
		case 'A':

			printf("\nIndique su matr�cula: ");
			scanf_s("%s", numeroDeMatriculaIntroducido);

			for (i = 0; i <= 2; i++) {

				if (numeroDeMatriculaIntroducido == numeroDeMatricula[i]) {

					numeroDePlazasLibres = numeroDePlazasLibres + 1;
					printf("\nHa abandonado su plaza.\n");

					for (i = 1; i <= 2; i++) {

						plaza[i] = 0;
						estadoDeLaPlaza[i][6] = "Vac�a";
						break;

					}

				}

			}

			break;

		case 'e':
		case 'E':

			printf("\n");

			for (i = 1; i <= 2; i++) {

				if (plaza[i] == 1) {

					printf("Plaza %d - %s - %s\n", i, estadoDeLaPlaza[i], numeroDeMatricula[i]);

				}

				else

					printf("Plaza %d - %s\n", i, estadoDeLaPlaza[i]);

			}

			break;

		default:

			printf("\nLa opci�n introducida no es v�lida.\n");

			break;
		}

	}

}
