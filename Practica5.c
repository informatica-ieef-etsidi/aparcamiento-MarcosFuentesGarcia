#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define NPLAZAS 4

char menu(char opcion);
int existeUsuario(struct usuario usuarioValido, char username[], char password[]);
int esDigitoValido(char caracter);
int esLetraValida(char caracter);
int esMatriculaValida(char matricula[]);


struct estructuraDePlaza {
	int estado; // 0 - Libre / 1 - Ocupada
	char tipoDeVehiculo;
	char matricula[8]; // Formato de la matrícula: NNNNLLL
};

struct usuario {
	char username[20];
	char password[20];
};

void main() {

	char opcion = '0', matriculaIntroducida[8], usernameIntroducido[20], passwordIntroducida[20];
	int i, numeroDePlazasLibres = NPLAZAS;
	struct estructuraDePlaza plaza[NPLAZAS];
	struct usuario miUsuario = { "admin", "1234" };

	for (i = 0; i < NPLAZAS; i++) {

		plaza[i].estado = 0;

	}

	if (existeUsuario(miUsuario, usernameIntroducido, passwordIntroducida) == 1) {

		while (1) {

			int aux1 = 0;
			int aux2 = 0;

			opcion = menu(opcion);

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

								printf("\nIndique su matrícula: ");
								scanf("%s", matriculaIntroducida);
								getchar();

								if (esMatriculaValida(matriculaIntroducida) == 1) {

									strcpy(plaza[i].matricula, matriculaIntroducida);
									numeroDePlazasLibres = numeroDePlazasLibres - 1;
									plaza[i].estado = 1;
									printf("\nSu vehículo ocupa la plaza %d", i);
									break;

								}

								else {

									printf("\nLa matrícula introducida no es válida.");
									break;

								}

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

				}

				printf("\n\n");
				system("pause");
				system("cls");
				break;

			case 'a':
			case 'A':

				printf("\nIndique su matrícula: ");
				scanf("%s", matriculaIntroducida);
				getchar();

				for (i = 0; i < NPLAZAS; i++) {

					if (strcmp(matriculaIntroducida, plaza[i].matricula) == 0) {

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
				scanf("%s", matriculaIntroducida);
				getchar();

				for (i = 0; i < NPLAZAS; i++) {

					if (strcmp(matriculaIntroducida, plaza[i].matricula) == 0) {

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

				printf("\n");
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

		printf("\nEl usuario o la contraseña introducidos no son válidos.\n\n");

	}

		system("pause");
		return 0;

}

char menu(char opcion) {

	printf("\nSeleccione una de estas opciones:\n");
	printf("\n  R - Reservar plaza");
	printf("\n  A - Abandonar plaza");
	printf("\n  E - Estado del aparcamiento");
	printf("\n  B - Buscar vehículo por matrícula");
	printf("\n  S - Salir\n\n");
	scanf("%c", &opcion);
	getchar();

	return opcion;

}

int existeUsuario(struct usuario usuarioValido, char username[], char password[]) {

	printf("\nIntroduzca su usuario: ");
	scanf("%s", username);
	printf("\nIntroduzca su contraseña: ");
	scanf("%s", password);
	getchar();

	if ((strcmp(password, usuarioValido.password) == 0) && (strcmp(username, usuarioValido.username) == 0)) {

		return 1;

	}

	else {

		return 0;

	}

}

int esDigitoValido(char caracter) {

	if (caracter >= '0' && caracter <= '9') {

		return 1;

	}

	else {

		return 0;

	}

}

int esLetraValida(char caracter) {

	if ((caracter >= 'a' && caracter <= 'z' && caracter != 'a' && caracter != 'e' && caracter != 'i' && caracter != 'o' && caracter != 'u') || (caracter >= 'A' && caracter <= 'Z' && caracter != 'A' && caracter != 'E' && caracter != 'I' && caracter != 'O' && caracter != 'U')) {

		return 1;

	}

	else {

		return 0;

	}

}

int esMatriculaValida(char matricula[]) {

	int aux1 = 1, aux2 = 1, i;

	for (i = 0; i <= 3; i++) {

		if ((esDigitoValido(matricula[i]) == 1) && (aux1 == 1)) {

			aux1 = 1;

		}

		else {

			aux1 = 0;

		}

	}

	for (i = 4; i <= 6; i++) {

		if ((esLetraValida(matricula[i]) == 1) && (aux2 == 1)) {

			aux2 = 1;

		}

		else {

			aux2 = 0;

		}

	}

	if (aux1 == 1 && aux2 == 1) {
		
		return 1;

	}

	else {

		return 0;

	}

}
