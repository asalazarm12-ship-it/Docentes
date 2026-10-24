#include <iostream>
#include <iomanip>
#include <fstream>
#ifdef _WIN32
#include <direct.h>
#else
#include <sys/stat.h>
#include <sys/types.h>
#endif
#include "docente.h"

using namespace std;

// Cuenta los activos por puesto y escribe la tabla, en pantalla y si se pide en el TXT.
void REPORTE_POR_PUESTO(DOCENTE DOC[], int N, char PUESTOS[][12]) {
    int I;
    int J;
    int CONT[8];
    char ARCH;
    bool ABIERTO;
    ofstream DAT;

    cout << "DESEA GENERAR EL ARCHIVO DE TEXTO? (S/N): ";
    cin >> ARCH;

    // El usuario pidió el archivo de texto.
    if (ARCH == 'S') {
        // Crea report si falta, para poder escribir el TXT.
#ifdef _WIN32
        if (_mkdir("report") != 0) {
            ABIERTO = false;
        }
#else
        if (mkdir("report", 0755) != 0) {
            ABIERTO = false;
        }
#endif
        DAT.open("report/REPORTE_PUESTOS.TXT");
        ABIERTO = DAT.is_open();

        // No se pudo crear el TXT.
        if (ABIERTO == false) {
            cout << "NO SE PUDO CREAR EL ARCHIVO DE TEXTO" << endl;
            ARCH = 'N';
        }
    }

    J = 1;

    // Recorre los siete puestos para poner cada contador en cero.
    while (J <= 7) {
        CONT[J] = 0;
        J = J + 1;
    }

    I = 1;

    // Recorre los docentes del arreglo, del 1 al N.
    while (I <= N) {
        // El docente sigue activo.
        if (DOC[I].ESTADO == 1 && DOC[I].PUESTO >= 1 && DOC[I].PUESTO <= 7) {
            CONT[DOC[I].PUESTO] = CONT[DOC[I].PUESTO] + 1;
        }

        I = I + 1;
    }

    cout << left << setw(13) << "PUESTO"
         << right << setw(10) << "CANTIDAD" << endl;
    J = 1;

    // Recorre los siete puestos para imprimir nombre y cantidad.
    while (J <= 7) {
        cout << left << setw(13) << PUESTOS[J]
             << right << setw(10) << CONT[J] << endl;

        // La misma línea va también al TXT.
        if (ARCH == 'S') {
            DAT << left << setw(13) << PUESTOS[J]
                << right << setw(10) << CONT[J] << endl;
        }

        J = J + 1;
    }

    // El TXT quedó abierto.
    if (ARCH == 'S') {
        DAT.close();
    }

    // No devuelve nada: solo vuelve al menú de reportes.
}
