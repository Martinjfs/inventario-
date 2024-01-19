#include <stdio.h>
#include <string.h>
#include "funciones.h"

int main() {
    const char *nombreArchivo = "archivo1";
    int opcion;

    cargaInicial(nombreArchivo);

    do {
        printf("\n=== inventario:3 ===\n");
        printf("1. Buscar producto\n");
        printf("2. Agregar producto\n");
        printf("3. Borrar producto\n");
        printf("4. Salir\n");
        printf("Ingrese la opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: {
                char productoBuscar[50];
                printf("Ingrese el nombre del producto a buscar: ");
                scanf("%s", productoBuscar);
                buscarProducto(nombreArchivo, productoBuscar);
                break;
            }
            case 2: {
                char nombreProducto[100];
                int cantidadProducto;
                printf("Ingrese el nombre del producto a agregar: ");
                scanf(" %[^\n]s", nombreProducto);
                printf("Ingrese la cantidad del producto a agregar: ");
                scanf("%d", &cantidadProducto);
                agregarDatos(nombreArchivo, nombreProducto, cantidadProducto);
                break;
            }
            case 3: {
                char productoBorrar[50];
                printf("Ingrese el nombre del producto a borrar: ");
                scanf("%s", productoBorrar);
                borrarRegistro(nombreArchivo, productoBorrar);
                break;
            }
            case 4:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
        }

    } while (opcion != 4);

    return 0;
}
