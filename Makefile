# Un solo ejecutable, docentes, con g++ en C++11. Sin carpeta de compilados.
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Iinclude

SRCS = \
	src/principal.cpp \
	src/inicia_puestos.cpp \
	src/cargar_archivo.cpp \
	src/guardar_archivo.cpp \
	src/agregar.cpp \
	src/eliminar.cpp \
	src/modificar.cpp \
	src/buscar.cpp \
	src/busca_codigo.cpp \
	src/busca_nombre.cpp \
	src/manejo_docente.cpp \
	src/promocion.cpp \
	src/incrementar_salario.cpp \
	src/reportes.cpp \
	src/reporte_general.cpp \
	src/reporte_por_puesto.cpp \
	src/reporte_docente.cpp

.PHONY: all clean

all: docentes

docentes: $(SRCS) include/docente.h
	$(CXX) $(CXXFLAGS) -o docentes $(SRCS)

clean:
	rm -f docentes docentes.exe
