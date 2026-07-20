# Ejercicio 3 - Evaluador de Expresiones Aritméticas

Este ejercicio implementa un **Autómata Finito Determinístico (AFD)** para validar expresiones aritméticas y un módulo evaluador capaz de calcular el resultado respetando la precedencia de los operadores.

## Objetivo

Implementar un programa que:

- Verifique que una expresión aritmética pertenezca al lenguaje definido mediante un AFD.
- Evalúe correctamente expresiones compuestas por números enteros y los operadores `+`, `-` y `*`.
- Respete la precedencia de los operadores, resolviendo primero las multiplicaciones y posteriormente las sumas y restas.

---

## Expresión regular

```regex
[0-9]+([+\-*][0-9]+)*
```

---

## Funcionamiento

El programa recibe una expresión aritmética definida en `main.c`.

Ejemplo:

```text
3+4*7+3-5
```

En primer lugar, la expresión es validada por el AFD para comprobar que cumpla la sintaxis definida por el lenguaje.

Si la validación es correcta, la expresión es enviada al módulo evaluador, encargado de:

- Leer los números completos.
- Resolver primero las multiplicaciones.
- Aplicar posteriormente las operaciones de suma y resta.
- Mostrar el resultado final de la expresión.

Si la expresión no pertenece al lenguaje definido, el programa informa un error sintáctico y no realiza la evaluación.

---

## Organización del código

```
ejercicio3/
│
├── include/
│   ├── automata.h
│   └── evaluador.h
│
├── src/
│   ├── main.c
│   ├── automata.c
│   └── evaluador.c
│
└── Makefile
```

### Módulos

- **main.c**

  Coordina el funcionamiento del programa, validando primero la expresión y, si esta pertenece al lenguaje, obteniendo e imprimiendo el resultado final.

- **automata.c**

  Implementa el AFD encargado de verificar que la expresión sea sintácticamente válida.

- **evaluador.c**

  Contiene las funciones responsables de leer números, resolver operaciones y evaluar completamente la expresión respetando la precedencia de los operadores.

---

## Compilación

Desde la carpeta `ejercicio3`:

```bash
make
```

o directamente:

```bash
make run
```

También es posible compilar manualmente:

```bash
gcc src/main.c src/automata.c src/evaluador.c -Iinclude -o ejercicio3
```

---

## Ejemplo de salida

```text
Expresión: 3+4*7+3-5

Resultado: 29
```

En caso de ingresar una expresión inválida:

```text
Expresión inválida.
```

---

## Documentación

La documentación asociada al proyecto puede consultarse en la carpeta:

```
documentacion/
```

donde se incluyen:

- Informe técnico.
- Diagrama del AFD.
- Capturas de ejecución.

---

## Alumno

**Kevin Bernabe**

Trabajo Práctico N.º 1 - Sintaxis y Semántica de los Lenguajes.

---

## Recursos adicionales

Para una descripción más detallada del desarrollo del ejercicio pueden consultarse los siguientes recursos:

- [Informe técnico](../documentacion/SSL%20TP1_%20Informe%20-%20Kevin%20Bernabe.pdf)
- [Diagrama del AFD](../documentacion/automatas/)