typedef struct {
	char nombre[20];
	char apellido[20];
	int edad;
	int grado;
	int registro;
	double promedio;
	double calificaciones[10];
}VariableAlumno;

void ingresarNumeroAlumnosMaterias(int* nAlumnos, int* nMaterias) {
	char comprobante[5];

	do {
		printf("Ingresa el numero de alumnos(<=10): \n");
		fgets(comprobante, sizeof(comprobante), stdin);
	} while (!(sscanf_s(comprobante, "%d", nAlumnos)) || strcspn(comprobante, "\n") == 0);

	do {
		printf("Ingresa el numero de materias(<10): \n");
		fgets(comprobante, sizeof(comprobante), stdin);
	} while (!(sscanf_s(comprobante, "%d", nMaterias) || strcspn(comprobante, "\n") == 0));

}
void ingresarNombre(VariableAlumno* alumno) {
	do {
		printf("Ingresa el Nombre: \n");
		fgets(alumno->nombre, sizeof(alumno->nombre), stdin);
	} while (strcspn(alumno->nombre, "\n") == 0);
	do {
		printf("Ingresa el Apellido: \n");
		fgets(alumno->apellido, sizeof(alumno->apellido), stdin);
	} while (strcspn(alumno->apellido, "\n") == 0);

}
void ingresarEdad(VariableAlumno* alumno) {
	char comprobante[5];
	do {
		printf("Ingresa la edad: \n");
		fgets(comprobante, sizeof(comprobante), stdin);
	} while (!(sscanf_s(comprobante, "%d", &alumno->edad)) || strcspn(comprobante, "\n") == 0);
}
void ingresarGrado(VariableAlumno* alumno) {
	char comprobante[5];

	do {
		printf("Ingresa el grado: \n");
		fgets(comprobante, sizeof(comprobante), stdin);
	} while (!(sscanf_s(comprobante, "%d", &alumno->grado)) || strcspn(comprobante, "\n") == 0);
}
void ingresarRegistro(VariableAlumno* alumno) {
	char comprobante[9];
	do {
		printf("Ingresa el registro: \n");
		fgets(comprobante, sizeof(comprobante), stdin);
	} while (!(sscanf_s(comprobante, "%d", &alumno->registro)) || strcspn(comprobante, "\n") == 0);
}
int evaluarNombre(VariableAlumno* alumno) {
	if (strlen(alumno->nombre) < 20) {
		if (strlen(alumno->apellido) < 20) {
			return 0;
		}
	}
	return 1;
}
int evaluarEdad(VariableAlumno* alumno) {
	if ((alumno->edad) < 40) {
		return 0;
	}return 1;
}
int evaluarGrado(VariableAlumno* alumno) {
	if ((alumno->grado) <= 8) {
		return 0;
	}return 1;
}
int evaluarRegistro(VariableAlumno* alumno) {
	if ((alumno->registro) > 9999999 && (alumno->registro) < 100000000) {
		return 0;
	}return 1;
}

void ingresarCalificaciones(VariableAlumno* alumno, int* nMaterias, char* materias[]) {
	char comprobante[20];
	int c;
	while ((c = getchar()) != '\n' && c != EOF) {}
	for (int i = 0; i <= *nMaterias - 1; i++) {
		do {
			printf("Ingresa la calificacion de %s (0-100):\n", materias[i]);
			fgets(comprobante, sizeof(comprobante), stdin);
		} while (!(sscanf_s(comprobante, "%lf", &alumno->calificaciones[i])) || strcspn(comprobante, "\n") == 0);
	}
}
void calcularPromedio(VariableAlumno* alumno, int* nMaterias) {
	alumno->promedio = 0;
	for (int i = 0; i < *nMaterias; i++) {
		alumno->promedio += alumno->calificaciones[i];
	}


	alumno->promedio /= *nMaterias;


}


void imprimirDatos(VariableAlumno* alumno, int* nMaterias, char* materias[]) {
	printf("**********************************************\n");
	printf("Nombre: %s\nApellido: %s\n", alumno->nombre, alumno->apellido);
	printf("Edad: %d\nGrado: %d", alumno->edad, alumno->grado);
	printf("\nRegistro: %d \n\n", alumno->registro);
	for (int i = 0; i <= *nMaterias - 1; i++) {
		printf("%s: %0.2lf\n", (materias[i]), alumno->calificaciones[i]);
	}
	printf("\nPromedio: %0.2lf\n", alumno->promedio);
	printf("**********************************************");
}
void limpiarbuffer() {
	int c;
	while ((c = getchar()) != '\n' && c != EOF) {}
}
int sacarMejorPromedio(VariableAlumno* alumno, int* nAlumnos) {
	int i = 0, max = 0;
	for (; i < *nAlumnos; i++) {
		if (alumno[max].promedio < alumno[i].promedio) {
			max = i;
		}
	}
	return max;
}
int sacarPeorPromedio(VariableAlumno* alumno, int* nAlumnos) {

	int i = 0, min = 0;
	for (; i < *nAlumnos; i++) {
		if (alumno[min].promedio >  alumno[i].promedio) {
			min = i;
		}
	}
	return min;
}
int sacarMejorCalificacion(VariableAlumno* alumno, int* nAlumnos, int* opcion) {
	int i = 0, max = 0;
	for (; i < *nAlumnos; i++) {
		if (alumno[max].calificaciones[*opcion] < alumno[i].calificaciones[*opcion]) {
			max = i;
		}
	}
	return max;
}
int sacarPeorCalificacion(VariableAlumno* alumno, int* nAlumnos, int* opcion) {
	int i = 0, min = 0;
	for (; i < *nAlumnos; i++) {
		if (alumno[min].calificaciones[*opcion] >  alumno[i].calificaciones[*opcion]) {
			min = i;
		}
	}
	return min;
}

