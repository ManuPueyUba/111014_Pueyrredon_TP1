#include <iostream>
#include "include/Inventario.h"
using namespace std;


const string SALIR = "SALIR";
const string ALTA = "ALTA";
const string BAJA = "BAJA";
const string CONSULTA = "CONSULTA";
const string CARGAR = "CARGAR";
const string GUARDAR = "GUARDAR";

int main() {
    bool salir = false;
     Inventario inventario = Inventario();
    do {
        cout << "Ingrese SALIR, para salir"<<endl;
        cout << "Ingrese ALTA, para dar de alta un item"<<endl;
        cout << "Ingrese BAJA, para bajar un item"<<endl;
        cout << "Ingrese CONSULTA, para consultar el inventario"<<endl;
        cout << "Ingrese CARGAR, para cargar un inventario"<<endl;
        cout << "Ingrese GUARDAR, para guardar un inventario"<<endl;

        string accion;
        getline(cin >> ws,accion);
        if (accion == SALIR){
            salir = true;
        } else if (accion == ALTA){
            cout << "Nombre del Item"<<endl;
            string nombre;
            getline(cin >> ws, nombre);
            string tipo;
            cout << "Nombre del tipo"<<endl;
            getline(cin >> ws, tipo);
            inventario.alta(nombre, tipo);

        } else if (accion == GUARDAR){
            string ruta;
            cout << "Ingrese la ruta del archivo a guardar." << endl;
            getline(cin >> ws, ruta);
            inventario.guardado(ruta);
        } else if (accion == CARGAR) {
            string ruta;
            cout << "Ingrese la ruta del archivo de su inventario." << endl;
            getline(cin >> ws, ruta);
            inventario.cargado(ruta);
        } else if (accion == BAJA){
            string nombre_del_item;
            cout << "Ingrese el nombre del archivo a dar de baja." << endl;
            getline(cin >> ws, nombre_del_item);
            inventario.baja(nombre_del_item);
        } else if (accion == CONSULTA) {
            inventario.consulta();
        } else
            cout << "Opcion no valida, intente de nuevo." << endl;
    } while (!salir);
    return 0;
}
