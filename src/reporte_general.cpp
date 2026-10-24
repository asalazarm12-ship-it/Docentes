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

// Lista los docentes activos y, si se pide, los escribe en el TXT.
void REPORTE_GENERAL(DOCENTE DOC[], int N, char PUESTOS[][12]) {
    int I;
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
        DAT.open("report/REPORTE_GENERAL.TXT");
        ABIERTO = DAT.is_open();

        // No se pudo crear el TXT.
        if (ABIERTO == false) {
            cout << "NO SE PUDO CREAR EL ARCHIVO DE TEXTO" << endl;
            ARCH = 'N';
        }
    }

    cout << left
         << setw(8) << "CODIGO"
         << setw(22) << "NOMBRE"
         << setw(12) << "TELEFONO"
         << setw(6) << "EDAD"
         << setw(13) << "PUESTO"
         << right << setw(10) << "SALARIO" << endl;
    I = 1;

    // Recorre los docentes del arreglo, del 1 al N.
    while (I <= N) {
        // El docente sigue activo.
        if (DOC[I].ESTADO == 1) {
            cout << left
                 << setw(8) << DOC[I].CODIGO
                 << setw(22) << DOC[I].NOMBRE
                 << setw(12) << DOC[I].TELEFONO
                 << setw(6) << DOC[I].EDAD;
            if (DOC[I].PUESTO >= 1 && DOC[I].PUESTO <= 7) {
                cout << setw(13) << PUESTOS[DOC[I].PUESTO];
            } else {
                cout << setw(13) << "INVALIDO";
            }
            cout << right << setw(10) << fixed << setprecision(2)
                 << DOC[I].SALARIO << endl;

            // La misma línea va también al TXT.
            if (ARCH == 'S') {
                DAT << left
                    << setw(8) << DOC[I].CODIGO
                    << setw(22) << DOC[I].NOMBRE
                    << setw(12) << DOC[I].TELEFONO
                    << setw(6) << DOC[I].EDAD;
                if (DOC[I].PUESTO >= 1 && DOC[I].PUESTO <= 7) {
                    DAT << setw(13) << PUESTOS[DOC[I].PUESTO];
                } else {
                    DAT << setw(13) << "INVALIDO";
                }
                DAT << right << setw(10) << fixed << setprecision(2)
                    << DOC[I].SALARIO << endl;
            }
        }

        I = I + 1;
    }

    // El TXT quedó abierto.
    if (ARCH == 'S') {
        DAT.close();
    }

    // No devuelve nada: solo vuelve al menú de reportes.
}
