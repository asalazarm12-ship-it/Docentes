#include "docente.h"

// Devuelve la posición del código COD, o 0 si no está.
int BUSCA_CODIGO(DOCENTE DOC[], int N, int COD) {
    int I;
    int POS;

    I = 1;

    // Recorre DOC del 1 al N hasta hallar el código o acabar.
    while (I <= N && DOC[I].CODIGO != COD) {
        I = I + 1;
    }

    // I se pasó de N: el código no está en el arreglo.
    if (I > N) {
        POS = 0;
    } else {
        POS = I;
    }

    // Regresa la posición hallada, o 0 si no existe.
    return POS;
}
