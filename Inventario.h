//
// Created by Usuario on 9/26/2023.
//

#ifndef AYP2_PLANTILLA_TP1_2C2023_INVENTARIO_H
#define AYP2_PLANTILLA_TP1_2C2023_INVENTARIO_H
#include "Item.hpp"
#include "Vector.hpp"
#include <string>
class Inventario {
private:
    size_t cantidad_de_elementos;
    size_t limite_de_items;
    Vector elementos_del_inventario;

public:
    //Pre: -
    //Post: Crea una instancia de la clase inventario con los atributos:
    //      cantidad_de_elementos = 0
    //      limite_de_items = 15
    //      items =
    Inventario();

    //Pre: Recibe un objeto de clase Item por parametro.
    //Post: Agrega un item a la lista de items.
    void alta(std::string nombre, std::string tipo);

    //Pre: Recibe un objeto de clase Item por parametro.
    //Post: Saca un item de la lista de items.
    void baja(const std::string& item_a_eliminar);

    //Pre: -
    //Post: Imprime por pantalla los items.
    void consulta();

    //Pre: Recibe una ruta de tipo string por parametro.
    //Post: Carga los items de un archivo al inventario.
    void cargado(const std::string& ruta);

    //Pre: Recibe una ruta de tipo string por parametro.
    //Post: Guarda los items del inventario en un archivo.
    //      <nombre>,<tipo>\n
    void guardado(const std::string& ruta);

    ~Inventario();
};

#endif //AYP2_PLANTILLA_TP1_2C2023_INVENTARIO_H
