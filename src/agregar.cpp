#include <iostream>
#include "docente.h"

using namespace std;

// Da de alta un docente al final de DOC.
bool AGREGAR(DOCENTE DOC[], int &N, char PUESTOS[][12]) {
    int COD;
    int POS;
    int J;
    bool HECHO;

    HECHO = false;

    // Todavía cabe un docente: el tope es 100.
    if (N < 100) {
        cout << "CODIGO: ";
        cin >> COD;

        // No llegó un número: se limpia cin para que el menú no se cicle.
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "CODIGO INVALIDO" << endl;
        } else {
            cin.ignore();
            POS = BUSCA_CODIGO(DOC, N, COD);

            // Ese código ya está en alguna posición de 1 a N.
            if (POS > 0) {
                cout << "EL CODIGO YA EXISTE" << endl;
            } else {
                N = N + 1;

                cout << "NOMBRE: ";
                cin.getline(DOC[N].NOMBRE, 51);
                cout << "TELEFONO: ";
                cin.getline(DOC[N].TELEFONO, 11);
                cout << "EDAD: ";
                cin >> DOC[N].EDAD;

                cout << "PUESTOS DISPONIBLES:" << endl;
                J = 1;

                // Lista los siete puestos para que el usuario elija el número.
                while (J <= 7) {
                    cout << J << ".) " << PUESTOS[J] << endl;
                    J = J + 1;
                }

                cout << "PUESTO: ";
                cin >> DOC[N].PUESTO;

                // El puesto debe estar entre 1 y 7.
                if (cin.fail() || DOC[N].PUESTO < 1 || DOC[N].PUESTO > 7) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    N = N - 1;
                    cout << "PUESTO INVALIDO" << endl;
                } else {
                    cout << "SALARIO: ";
                    cin >> DOC[N].SALARIO;

                    DOC[N].CODIGO = COD;
                    DOC[N].ESTADO = 1;
                    HECHO = true;

                    cout << "DOCENTE AGREGADO" << endl;
                }
            }
        }
    } else {
        cout << "NO HAY ESPACIO EN EL ARREGLO PARA NUEVOS DOCENTES" << endl;
    }

    // Regresa verdadero solo si el arreglo recibió un docente nuevo.
    return HECHO;
}
