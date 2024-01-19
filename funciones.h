#ifndef FUNCIONES_H
#define FUNCIONES_H

void cargaInicial(const char *nombreArchivo);
void buscarProducto(const char *nombreArchivo, const char *productoBuscar);
void agregarDatos(const char *nombreArchivo, const char *nombreProducto, int cantidadProducto);
void borrarRegistro(const char *nombreArchivo, const char *productoBorrar);

#endif
