#include <stdio.h>
#include <string.h>
#include "main.h"



int main(void) {
	
	int nAlumnos, nMaterias,opcionMenu,opcionMateria,opcionMateriaMenu,n=0;

	ingresarNumeroAlumnosMaterias(&nAlumnos, &nMaterias);
	
	VariableAlumno grupo[10];
	char *materias[] = { "Precalculo","Matematicas Discretas","IDS","Medio Ambiente","TCOE","Cultura Comparada","Redes","Programacion" };
	char comprobante[20];


	for (int i = 0; i <= nAlumnos-1; i++) {
		do {
			ingresarNombre(&grupo[i]);
		} while (evaluarNombre(&grupo[i]));
		do {
			ingresarEdad(&grupo[i]);
		} while (evaluarEdad(&grupo[i]));
		do {
			ingresarGrado(&grupo[i]);
		} while (evaluarGrado(&grupo[i]));
		
		do {
			limpiarbuffer();
			ingresarRegistro(&grupo[i]);
		} while (evaluarRegistro(&grupo[i]));

		ingresarCalificaciones(&grupo[i], &nMaterias, materias);
		
	}
	for (int i = 0; i <= nAlumnos-1; i++) {
		calcularPromedio(&grupo[i],&nMaterias);
	}
	printf("Que quieres ver? \n1. Alumno con mayor promedio\n2. Alumno con menor promedio\n3. Calificaciones por materia...");
	do {
		do {
			printf("Ingresa la opcion deseada:\n");
			fgets(comprobante, sizeof(comprobante), stdin);
		} while (!(sscanf_s(comprobante, "%d", &opcionMenu)) || strcspn(comprobante, "\n") == 0);
	} while (!(opcionMenu > 0 && opcionMenu < 4));

	switch (opcionMenu) {
		case 1:
			n = sacarMejorPromedio(&grupo,&nAlumnos);
			imprimirDatos(&grupo[n], &nMaterias, &materias);
			break;
		case 2:
			n = sacarPeorPromedio(&grupo, &nAlumnos);
			imprimirDatos(&grupo[n], &nMaterias, &materias);
			break;
		case 3:
			for (int i = 0; i <= nMaterias - 1; i++) {
				printf("\n%d. %s\n", i,materias[i]);		//imprime las materias
			}
			do {
				do {
					printf("Ingresa la opcion deseada:\n");
					fgets(comprobante, sizeof(comprobante), stdin);
				} while (!(sscanf_s(comprobante, "%d", &opcionMateria)) || strcspn(comprobante, "\n") == 0);
			} while (!(opcionMateria > 0 && opcionMateria <= nMaterias));

			printf("Que quieres ver? \n1. Alumno con mayor calificacion\n2. Alumno con menor calificacion\n3. Mayor y menor calificacion\n");
			do {
				do {
					printf("Ingresa la opcion deseada:\n");
					fgets(comprobante, sizeof(comprobante), stdin);
				} while (!(sscanf_s(comprobante, "%d", &opcionMateriaMenu)) || strcspn(comprobante, "\n") == 0);
			} while (!(opcionMateriaMenu > 0 && opcionMateriaMenu < 4));
			
			switch (opcionMateriaMenu) {
				case 1:
					n = sacarMejorCalificacion(grupo,&nAlumnos,&opcionMateriaMenu);
					imprimirDatos(&grupo[n], &nMaterias, &materias);
					break;
				case 2:
					n = sacarPeorCalificacion(grupo, &nAlumnos, &opcionMateriaMenu);
					imprimirDatos(&grupo[n], &nMaterias, &materias);
					break;
				case 3:
					n = sacarMejorCalificacion(grupo, &nAlumnos, &opcionMateriaMenu);
					imprimirDatos(&grupo[n], &nMaterias, &materias);
					n = sacarPeorCalificacion(grupo, &nAlumnos, &opcionMateriaMenu);
					imprimirDatos(&grupo[n], &nMaterias, &materias);
			}
				
}

	

	


	return 0;
}