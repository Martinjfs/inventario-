#include <stdio.h>
#include <string.h>
#include "funciones.h"

int main() {
    const char *nombreArchivo = "archivo1";

    cargaInicial(nombreArchivo);

    char productoBuscar[50];
    printf("Ingrese el nombre del producto a buscar: ");
    scanf("%s", productoBuscar);

    buscarProducto(nombreArchivo, productoBuscar);

    char nombreProducto[100]; //Permite colocar mas palabras
    int cantidadProducto;
    printf("Ingrese el nombre del producto a agregar: ");
    scanf(" %[^\n]s", nombreProducto); // lee las lineas con espacios 
    printf("Ingrese la cantidad del producto a agregar: ");
    scanf("%d", &cantidadProducto);

    agregarDatos(nombreArchivo, nombreProducto, cantidadProducto);

    char productoBorrar[50];
    printf("Ingrese el nombre del producto a borrar: ");
    scanf("%s", productoBorrar);

    borrarRegistro(nombreArchivo, productoBorrar);

    return 0;
}
