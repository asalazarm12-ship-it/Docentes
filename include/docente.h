#ifndef DOCENTE_H
#define DOCENTE_H

// Registro de un docente. ESTADO 1 es activo y 0 es baja.
struct DOCENTE {
    int CODIGO;
    char NOMBRE[51];
    char TELEFONO[11];
    int EDAD;
    int PUESTO;
    float SALARIO;
    int ESTADO;
};

void INICIA_PUESTOS(char PUESTOS[][12]);
int CARGAR_ARCHIVO(DOCENTE DOC[]);
bool GUARDAR_ARCHIVO(DOCENTE DOC[], int N);
int BUSCA_CODIGO(DOCENTE DOC[], int N, int COD);
int BUSCA_NOMBRE(DOCENTE DOC[], int N, char NOM[]);
bool AGREGAR(DOCENTE DOC[], int &N, char PUESTOS[][12]);
bool ELIMINAR(DOCENTE DOC[], int N);
bool MODIFICAR(DOCENTE DOC[], int N);
void BUSCAR(DOCENTE DOC[], int N, char PUESTOS[][12]);
bool MANEJO_DOCENTE(DOCENTE DOC[], int N, char PUESTOS[][12]);
bool PROMOCION(DOCENTE DOC[], int N, char PUESTOS[][12]);
bool INCREMENTAR_SALARIO(DOCENTE DOC[], int N, char PUESTOS[][12]);
void REPORTES(DOCENTE DOC[], int N, char PUESTOS[][12]);
void REPORTE_GENERAL(DOCENTE DOC[], int N, char PUESTOS[][12]);
void REPORTE_POR_PUESTO(DOCENTE DOC[], int N, char PUESTOS[][12]);
void REPORTE_DOCENTE(DOCENTE DOC[], int N, char PUESTOS[][12]);

#endif
