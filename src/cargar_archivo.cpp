#include <fstream>
#include "docente.h"

using namespace std;

// Lee DOCENTES.DAT hacia DOC y devuelve cuántos docentes cargó.
int CARGAR_ARCHIVO(DOCENTE DOC[]) {
    int I;
    int CANT;
    bool ABIERTO;
    bool LEIDO;
    ifstream DAT;

    CANT = 0;
    DAT.open("DOCENTES.DAT", ios::in | ios::binary);
    ABIERTO = DAT.is_open();

    // El archivo existe y se pudo abrir.
    if (ABIERTO == true) {
        I = 1;
        DAT.read(reinterpret_cast<char *>(&DOC[I]), sizeof(DOCENTE));
        LEIDO = DAT.gcount() == static_cast<streamsize>(sizeof(DOCENTE));

        // Avanza por el archivo mientras la lectura sirva y el índice no llegue a 100.
        while (LEIDO == true && I < 100) {
            I = I + 1;
            DAT.read(reinterpret_cast<char *>(&DOC[I]), sizeof(DOCENTE));
            LEIDO = DAT.gcount() == static_cast<streamsize>(sizeof(DOCENTE));
        }

        // La última lectura sí dejó un docente: el arreglo llegó lleno a 100.
        if (LEIDO == true) {
            CANT = I;
        } else {
            CANT = I - 1;
        }

        DAT.close();
    }

    // Regresa la cantidad de docentes que quedaron en DOC. Si no abrió, es 0.
    return CANT;
}
