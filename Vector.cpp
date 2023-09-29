#include "../include/Vector.hpp"

Vector::Vector() {
    cantidadDatos = 0;
    tamanioMaximo = 1;
    datos = new Item*[tamanioMaximo];
}

void Vector::alta(Item* dato) {
    if (cantidadDatos == tamanioMaximo) {
        tamanioMaximo *= 2;
        Item** nuevoArray = new Item*[tamanioMaximo];

        for (size_t i = 0; i < cantidadDatos; i++) {
            nuevoArray[i] = datos[i];
        }

        delete[] datos;
        nuevoArray[cantidadDatos] = dato; // Corregir el índice aquí
        datos = nuevoArray;
    }
    cantidadDatos++;
}

void Vector::alta(Item* dato, size_t indice) {
    if (indice > cantidadDatos) {
        throw VectorException();
    }

    if (cantidadDatos == tamanioMaximo) {
        tamanioMaximo *= 2;
        Item** nuevoArray = new Item*[tamanioMaximo];

        for (size_t i = 0; i < cantidadDatos; ++i) {
            nuevoArray[i] = datos[i];
        }

        delete[] datos;
        datos = nuevoArray;
    }

    for (size_t i = cantidadDatos; i > indice; --i) {
        datos[i] = datos[i - 1];
    }

    datos[indice] = dato;
    cantidadDatos++;
}

Item* Vector::baja() {
    if (cantidadDatos == 0) {
        throw VectorException();
    }

    return baja(cantidadDatos - 1);
}

Item* Vector::baja(size_t indice) {
    if (cantidadDatos == 0 || indice >= cantidadDatos) {
        throw VectorException();
    }

    Item* dato = datos[indice];

    for (size_t i = indice; i < cantidadDatos - 1; i++) {
        datos[i] = datos[i + 1];
    }

    datos[cantidadDatos - 1] = nullptr; // Establecer el puntero al último elemento eliminado a nullptr
    cantidadDatos--;
    return dato;
}

bool Vector::vacio() {
    return cantidadDatos == 0;
}

size_t Vector::tamanio() {
    return cantidadDatos;
}

Item*& Vector::operator[](size_t indice) {
    if (indice >= cantidadDatos) {
        throw VectorException();
    }
    return datos[indice];
}

Vector::~Vector() {
    for (size_t i = 0;i < cantidadDatos;i++){
        delete datos[i];
    }
    delete[] datos;
}
