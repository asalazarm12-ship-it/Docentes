#include <iostream>
#include <fstream>
#include "docente.h"

using namespace std;

// Graba los N docentes de DOC en DOCENTES.DAT.
bool GUARDAR_ARCHIVO(DOCENTE DOC[], int N) {
    int I;
    bool ABIERTO;
    bool GRABADO;
    bool EXITO;
    ofstream DAT;

    DAT.open("DOCENTES.DAT", ios::out | ios::binary);
    ABIERTO = DAT.is_open();

    // El archivo se pudo abrir para escritura.
    if (ABIERTO == true) {
        EXITO = true;
        I = 1;

        // Recorre los docentes del arreglo, del 1 al N.
        while (I <= N) {
            DAT.write(reinterpret_cast<char *>(&DOC[I]), sizeof(DOCENTE));
            GRABADO = DAT.good();

            // Esta escritura no quedó en el archivo.
            if (GRABADO == false) {
                cout << "ERROR AL GRABAR EL DOCENTE " << DOC[I].CODIGO << endl;
                EXITO = false;
            }

            I = I + 1;
        }

        DAT.close();
    } else {
        EXITO = false;
    }

    // Regresa verdadero solo si los N registros quedaron grabados.
    return EXITO;
}
