#include <stdio.h>
#include <string.h>

void cargaInicial(const char *nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "w+");
    if (archivo == NULL) {
        printf("Error al abrir el archivo");
        return;
    }

    char nombreProducto[10][50] = {"Queso", "Tomates", "Papas", "Pollo", "Yogurt", "Carnes", "Leche", "Huevos", "Aguacate"};
    int cantidadProducto[10] = {10, 5, 5, 5, 5, 5, 5, 5, 5};

    for (int i = 0; i < 9; i++) {
        fprintf(archivo, "%s\n%d\n", nombreProducto[i], cantidadProducto[i]);
    }

    fclose(archivo);
}

void buscarProducto(const char *nombreArchivo, const char *productoBuscar) {
    FILE *archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo");
        return;
    }

    int cant;
    char producto[50];

    while (fscanf(archivo, "%s\n%d\n", producto, &cant) != EOF) {
        if (strcmp(producto, productoBuscar) == 0) {
            printf("La cantidad de %s es: %d\n", productoBuscar, cant);
            break;
        }
    }

    fclose(archivo);
}

void agregarDatos(const char *nombreArchivo, const char *nombreProducto, int cantidadProducto) {
    FILE *archivo = fopen(nombreArchivo, "a");
    if (archivo == NULL) {
        printf("Error al abrir el archivo");
        return;
    }

    fprintf(archivo, "%s\n%d\n", nombreProducto, cantidadProducto);

    fclose(archivo);
}

void borrarRegistro(const char *nombreArchivo, const char *productoBorrar) {
    FILE *archivoEntrada = fopen(nombreArchivo, "r");
    FILE *archivoSalida = fopen("temp.txt", "w");

    if (archivoEntrada == NULL || archivoSalida == NULL) {
        printf("Error al abrir el archivo");
        return;
    }

    int cant;
    char producto[100]; // aumenta la capacidad de palabras que puedo meter

    while (fscanf(archivoEntrada, "%[^\n]\n%d\n", producto, &cant) != EOF) {
        if (strcmp(producto, productoBorrar) != 0) {
            fprintf(archivoSalida, "%s\n%d\n", producto, cant);
        }
    }

    fclose(archivoEntrada);
    fclose(archivoSalida);

    remove(nombreArchivo);
    rename("temp.txt", nombreArchivo);
}
