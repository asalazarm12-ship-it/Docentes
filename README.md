# Control de docentes

Programa de la práctica de Algoritmos (Universidad Mariano Gálvez). Un solo ejecutable, `docentes`, con el menú del diagrama: Agregar, Eliminar, Modificar, Buscar, Manejo de Docente, Reportes y Salir.

El seudocódigo completo de cada módulo está en [`pseudocodigo/pseudocodigo.txt`](pseudocodigo/pseudocodigo.txt).

## Registro y arreglos

```
DOCENTE = REGISTRO
    CODIGO:   entero
    NOMBRE:   cadena [50]
    TELEFONO: cadena [10]
    EDAD:     entero
    PUESTO:   entero
    SALARIO:  real
    ESTADO:   entero

DOC     = ARREGLO [1..100] DE DOCENTE
PUESTOS = ARREGLO [1..7]   DE cadena

DOCENTES.DAT        : archivo de DOCENTE
REPORTE_GENERAL.TXT : archivo de texto
REPORTE_PUESTOS.TXT : archivo de texto
REPORTE_DOCENTE.TXT : archivo de texto

ESTADO = 1   docente activo
ESTADO = 0   docente de baja

El usuario no escribe ESTADO.
Al agregar, el programa lo pone en 1.
Al eliminar, el programa lo pone en 0 (baja lógica: el registro sigue en el arreglo).

PUESTOS[1] = PASANTE        PUESTOS[5] = NIVEL 3
PUESTOS[2] = TEMPORAL       PUESTOS[6] = COORDINADOR
PUESTOS[3] = NIVEL 1        PUESTOS[7] = DIRECTOR
PUESTOS[4] = NIVEL 2
```

`DOCENTES.DAT` se lee al abrir y se graba al salir si hubo cambios.

---

## 1. Cada vez que cambias el código

El programa que se ejecuta es el archivo `docentes`, no los `.cpp`. Si cambias un fuente y no vuelves a compilar, sigues corriendo la versión anterior.

Entra a la carpeta del proyecto y ejecuta:

```bash
g++ -std=c++11 -Wall -Iinclude -o docentes src/*.cpp
./docentes
```

El primer comando junta todos los `.cpp` y crea (o reemplaza) el ejecutable `docentes`. El segundo lo abre.

Si no hubo cambios en el código y el ejecutable ya existe, no hace falta volver a compilar.

---

## 2. Cómo ejecutarlo

Con el ejecutable ya compilado, dentro de esta carpeta:

```bash
./docentes
```

El menú pide un número del 1 al 6. Cualquier otro número (por ejemplo `0`) sale. Si hubo altas, bajas, cambios, promociones o salarios, al salir se guarda `DOCENTES.DAT`.

---

## 3. Qué hay que instalar para ejecutarlo

Hace falta un compilador de C++. En Linux es `g++`.

**Ubuntu / Debian / WSL:**

```bash
sudo apt update
sudo apt install g++
```

**Fedora:**

```bash
sudo dnf install gcc-c++
```

**Arch:**

```bash
sudo pacman -S gcc
```

Comprueba que quedó instalado:

```bash
g++ --version
```

En Windows no se usa `g++` de esta forma: se abre `docentes.dev` con Dev-C++ 5.11 o superior y se compila. El resultado es `docentes.exe` en esta misma carpeta.

---

## 4. Dónde están los reportes y el diagrama

**Reportes de texto.** Cuando en Reportes respondes `S` a “DESEA GENERAR EL ARCHIVO DE TEXTO?”, el programa escribe en la carpeta `report/`. Si esa carpeta no existe, la crea. Los archivos son:

- `report/REPORTE_GENERAL.TXT`
- `report/REPORTE_PUESTOS.TXT`
- `report/REPORTE_DOCENTE.TXT`

Si respondes `N`, solo se muestran en pantalla.

**Diagrama.** El diagrama de flujo está en:

- `diagramas/Diagrama-Docentes.pdf`

**Seudocódigo.** El registro, los arreglos y todos los módulos están en:

- `pseudocodigo/pseudocodigo.txt`

---

## 5. Qué es el Makefile y cómo funciona

El `Makefile` es un archivo de texto con la receta de compilación. No es el programa de docentes: le dice a `make` cómo llamar a `g++`.

En este proyecto hace esto:

- Usa `g++` con C++11, avisos (`-Wall`) y la carpeta `include`.
- Lista todos los `.cpp` en `SRCS`.
- La regla `docentes` produce el ejecutable `docentes`.
- `make clean` borra `docentes` y `docentes.exe`.

Si tienes `make` instalado, dentro de esta carpeta basta:

```bash
make
./docentes
```

Eso equivale al comando largo de `g++` de la sección 1. Se creó para no escribir esa línea cada vez y para que en Linux se compile igual.

---

## 6. Qué instalar para usar el Makefile en otra distro Linux

`make` es un programa aparte de `g++`. En algunas máquinas está `g++` y no está `make`.

**Ubuntu / Debian / WSL:**

```bash
sudo apt install make
```

O los dos juntos:

```bash
sudo apt install build-essential
```

`build-essential` instala `g++`, `make` y herramientas de compilación.

**Fedora:**

```bash
sudo dnf install make gcc-c++
```

**Arch:**

```bash
sudo pacman -S make gcc
```

Comprueba:

```bash
make --version
g++ --version
```

Luego, en la carpeta del proyecto:

```bash
make
./docentes
```

Si no puedes instalar `make`, usa el comando de `g++` de la sección 1. El resultado es el mismo.

---

## 7. Estructura de carpetas

```
ProyectoFinalAlgoritmos/
├── include/                 Encabezado compartido
│   └── docente.h            Struct DOCENTE y prototipos de las funciones
├── src/                     Un .cpp por módulo
│   ├── principal.cpp        Menú principal
│   ├── inicia_puestos.cpp   Nombres de los 7 puestos
│   ├── cargar_archivo.cpp   Lee DOCENTES.DAT al iniciar
│   ├── guardar_archivo.cpp  Graba DOCENTES.DAT al salir
│   ├── agregar.cpp          Alta
│   ├── eliminar.cpp         Baja lógica (ESTADO = 0)
│   ├── modificar.cpp        Nombre, teléfono y edad
│   ├── buscar.cpp           Consulta por código o nombre
│   ├── busca_codigo.cpp     Búsqueda secuencial por código
│   ├── busca_nombre.cpp     Búsqueda secuencial por nombre
│   ├── manejo_docente.cpp   Submenú de promoción y salario
│   ├── promocion.cpp        Sube un puesto (tope: Director)
│   ├── incrementar_salario.cpp
│   ├── reportes.cpp         Submenú de reportes
│   ├── reporte_general.cpp
│   ├── reporte_por_puesto.cpp
│   └── reporte_docente.cpp
├── diagramas/               Diagrama de flujo
│   └── Diagrama-Docentes.pdf
├── pseudocodigo/            Seudocódigo del registro y de cada módulo
│   └── pseudocodigo.txt
├── report/                  TXT de reportes (se crea al pedir S)
├── Makefile                 Receta para `make` en Linux
├── docentes.dev             Proyecto para Dev-C++ en Windows
├── README.md                Estas instrucciones
├── docentes                 Ejecutable (se crea al compilar en Linux)
└── DOCENTES.DAT             Datos guardados (se crea al salir con cambios)
```

`include/` tiene las declaraciones. `src/` tiene las implementaciones. El menú no hace todo: cada archivo hace una tarea y `principal.cpp` las llama.
