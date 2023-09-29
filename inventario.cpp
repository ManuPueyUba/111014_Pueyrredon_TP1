//
// Created by Usuario on 9/26/2023.
//

#include "Inventario.h"
#include "Item.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
using namespace std;
const size_t LIMITE_DE_ITEMS = 15;

Inventario::Inventario() {
    this -> limite_de_items = LIMITE_DE_ITEMS;
    this -> cantidad_de_elementos = 0;
}

void Inventario::alta(string nombre, string tipo) {
    if (cantidad_de_elementos == limite_de_items){
        cout << "El inventario esta lleno, da de baja un Item para poder agarrar otro." << endl;
    }
    Item* puntero_a_item = new Item(std::move(nombre), std::move(tipo));
    elementos_del_inventario.alta(puntero_a_item);
    cantidad_de_elementos++;
}

void Inventario::baja(const std::string& item_a_eliminar) {
    for (size_t i = 0; i < cantidad_de_elementos; i++){
        if (*elementos_del_inventario[i] == item_a_eliminar){
            elementos_del_inventario.baja(i);
            cantidad_de_elementos --;
        }
    }
}



void Inventario::consulta() {
    for (size_t i = 0; i < cantidad_de_elementos; ++i) {
        cout << to_string(i + 1)<<". ";
        elementos_del_inventario[i]->listarInformacion();
        cout << endl;
    }
}

void Inventario::cargado(const std::string& ruta) {
    ifstream archivo(ruta);
    string nombre;
    if (!archivo.is_open()) {
        cout << "El archivo no existe" << endl;
    } else{
        while (getline(archivo,nombre,',')) {
            string tipo;
            getline(archivo,tipo);
            Item* puntero_a_item = new Item(nombre, tipo);
            elementos_del_inventario.alta(puntero_a_item,cantidad_de_elementos);
            cantidad_de_elementos++;
        }
        archivo.close();
    }
}

void Inventario::guardado(const std::string& ruta) {
    ofstream archivo(ruta);
    for (size_t i = 0; i< cantidad_de_elementos; i++){
        archivo << *elementos_del_inventario[i] << endl;
    }
    archivo.close();
}

Inventario::~Inventario() {
    for (size_t i = 0; i < cantidad_de_elementos; ++i) {
        delete elementos_del_inventario[i];
    }
}
