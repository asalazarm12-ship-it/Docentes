#include <cstring>
#include "docente.h"

// Deja en PUESTOS el nombre de cada uno de los siete puestos.
void INICIA_PUESTOS(char PUESTOS[][12]) {
    strcpy(PUESTOS[1], "PASANTE");
    strcpy(PUESTOS[2], "TEMPORAL");
    strcpy(PUESTOS[3], "NIVEL 1");
    strcpy(PUESTOS[4], "NIVEL 2");
    strcpy(PUESTOS[5], "NIVEL 3");
    strcpy(PUESTOS[6], "COORDINADOR");
    strcpy(PUESTOS[7], "DIRECTOR");

    // No devuelve nada: solo vuelve al llamador.
}
