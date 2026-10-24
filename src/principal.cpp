#include <iostream>
#include "docente.h"

using namespace std;

// Muestra el menú y llama al módulo que el usuario elige.
int main() {
    DOCENTE DOC[101];
    char PUESTOS[8][12];
    int N;
    int OPC;
    bool HECHO;
    bool CAMBIOS;
    bool EXITO;

    INICIA_PUESTOS(PUESTOS);
    N = CARGAR_ARCHIVO(DOC);
    CAMBIOS = false;
    OPC = 1;

    // El do-while mantiene el menú; el switch elige el módulo.
    do {
        cout << "BIENVENIDO AL GESTOR DE DOCENTES" << endl;
        cout << "1.) Agregar" << endl;
        cout << "2.) Eliminar" << endl;
        cout << "3.) Modificar" << endl;
        cout << "4.) Buscar" << endl;
        cout << "5.) Manejo de Docente" << endl;
        cout << "6.) Reportes" << endl;
        cout << "Otro.) Salir" << endl;
        cin >> OPC;

        // cin falló: si no se limpia, OPC se queda en 1 y Agregar se repite solo.
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            OPC = 1;
            continue;
        }

        HECHO = false;

        switch (OPC) {
            case 1:
                HECHO = AGREGAR(DOC, N, PUESTOS);
                break;
            case 2:
                HECHO = ELIMINAR(DOC, N);
                break;
            case 3:
                HECHO = MODIFICAR(DOC, N);
                break;
            case 4:
                BUSCAR(DOC, N, PUESTOS);
                break;
            case 5:
                HECHO = MANEJO_DOCENTE(DOC, N, PUESTOS);
                break;
            case 6:
                REPORTES(DOC, N, PUESTOS);
                break;
            default:
                break;
        }

        CAMBIOS = CAMBIOS || HECHO;
    } while (OPC >= 1 && OPC <= 6);

    // Hubo algún cambio en el arreglo.
    if (CAMBIOS == true) {
        EXITO = GUARDAR_ARCHIVO(DOC, N);

        // El archivo binario quedó grabado.
        if (EXITO == true) {
            cout << "DATOS GUARDADOS CORRECTAMENTE" << endl;
        } else {
            cout << "ATENCION: LOS DATOS NO SE PUDIERON GUARDAR" << endl;
        }
    } else {
        cout << "NO HUBO CAMBIOS QUE GUARDAR" << endl;
    }

    // Regresa 0 al sistema al terminar.
    return 0;
}
