#include <cstring>
#include "docente.h"

// Devuelve la posición del nombre NOM, o 0 si no está.
int BUSCA_NOMBRE(DOCENTE DOC[], int N, char NOM[]) {
    int I;
    int POS;

    I = 1;

    // Recorre DOC del 1 al N hasta hallar el nombre o acabar.
    while (I <= N && strcmp(DOC[I].NOMBRE, NOM) != 0) {
        I = I + 1;
    }

    // I se pasó de N: el nombre no está en el arreglo.
    if (I > N) {
        POS = 0;
    } else {
        POS = I;
    }

    // Regresa la posición hallada, o 0 si no existe.
    return POS;
}
