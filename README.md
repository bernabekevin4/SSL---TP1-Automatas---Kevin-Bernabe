# Trabajo Práctico N.º 1 - Sintaxis y Semántica de los Lenguajes

Implementación de distintos **Autómatas Finitos Determinísticos (AFD)** en lenguaje **C**, desarrollados para resolver las consignas del Trabajo Práctico N.º 1 de la materia **Sintaxis y Semántica de los Lenguajes**.

El proyecto aborda el reconocimiento de constantes numéricas, la conversión de caracteres a enteros y la validación y evaluación de expresiones aritméticas mediante autómatas y módulos independientes.

---

## Contenido del repositorio

```
.
├── documentacion/
│   ├── automatas/
│   └── informe
│
├── ejercicio1/
│   ├── src/
│   ├── include/
│   ├── Makefile
│   └── README.md
│
├── ejercicio2/
│   ├── src/
│   ├── include/
│   ├── Makefile
│   └── README.md
│
├── ejercicio3/
│   ├── src/
│   ├── include/
│   ├── Makefile
│   └── README.md
│
└── README.md
```

---

## Ejercicios

### Ejercicio 1

Implementación de autómatas finitos determinísticos para el reconocimiento de:

- Constantes decimales.
- Constantes octales.
- Constantes hexadecimales.

Cada constante es analizada de manera independiente y clasificada según el lenguaje al que pertenece.

📄 Más información: **ejercicio1/README.md**

---

### Ejercicio 2

Implementación de una función encargada de convertir un carácter numérico (`'0'`–`'9'`) en su correspondiente valor entero mediante la codificación ASCII.

📄 Más información: **ejercicio2/README.md**

---

### Ejercicio 3

Implementación de un AFD para validar expresiones aritméticas simples y de un módulo evaluador que calcula el resultado respetando la precedencia de los operadores.

Operadores soportados:

- `+`
- `-`
- `*`

📄 Más información: **ejercicio3/README.md**

---

## Documentación

La carpeta **documentacion/** contiene el material utilizado durante el desarrollo del proyecto:

- Informe técnico.
- Diagramas de los autómatas.
- Capturas de ejecución.

---

## Requisitos

Para compilar los ejercicios se recomienda disponer de:

- GCC
- GNU Make
- MSYS2 (Windows)

---

## Compilación

Cada ejercicio puede compilarse de forma independiente.

Ejemplo:

```bash
cd ejercicio1
make
```

o directamente:

```bash
make run
```

---

## Autor

**Kevin Ricardo Bernabe Carnero**

Trabajo Práctico desarrollado para la materia **Sintaxis y Semántica de los Lenguajes**.