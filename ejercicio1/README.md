# Ejercicio 1 - Reconocimiento de Constantes Numéricas

Este ejercicio implementa tres **Autómatas Finitos Determinísticos (AFD)** en lenguaje **C** para el reconocimiento de constantes numéricas pertenecientes a distintos lenguajes.

## Objetivo

Clasificar constantes numéricas como:

- Decimal
- Octal
- Hexadecimal

En caso de que una constante no pertenezca a ninguno de estos lenguajes, se informa un **error léxico**.

---

## Expresiones regulares

### Decimal

```regex
0 | [+-]?[1-9][0-9]*
```

### Octal

```regex
0[0-7]+
```

### Hexadecimal

```regex
0[xX][0-9A-Fa-f]+
```

---

## Funcionamiento

El programa recibe una cadena compuesta por constantes separadas mediante el carácter `@`.

Ejemplo:

```text
-123@056@0x1AF@08@0xG@0@+456
```

Cada constante es copiada a un buffer temporal y posteriormente analizada por los distintos autómatas para determinar a qué lenguaje pertenece.

Al finalizar la ejecución se informa:

- Cantidad de constantes decimales.
- Cantidad de constantes octales.
- Cantidad de constantes hexadecimales.
- Cantidad de errores léxicos.

---

## Organización del código

```
ejercicio1/
│
├── include/
│   ├── decimal.h
│   ├── octal.h
│   └── hexadecimal.h
│
├── src/
│   ├── main.c
│   ├── decimal.c
│   ├── octal.c
│   └── hexadecimal.c
│
└── Makefile
```

### Módulos

- **main.c**  
  Coordina el análisis de la entrada y contabiliza los resultados.

- **decimal.c**
  
  Implementa el AFD para constantes decimales.

- **octal.c**
  
  Implementa el AFD para constantes octales.

- **hexadecimal.c**
  
  Implementa el AFD para constantes hexadecimales.

---

## Compilación

Desde la carpeta raíz `ejercicio1`:

```bash
make
```

o directamente ejecutar el programa con:

```bash
make run
```

**Nota:** Los comandos `make` están preparados para ejecutarse desde el entorno **MSYS2**. Es necesario ubicarse previamente en la carpeta raíz del ejercicio correspondiente antes de ejecutar cualquier comando del `Makefile`.

También es posible compilar manualmente:


```bash
gcc src/main.c src/decimal.c src/octal.c src/hexadecimal.c -Iinclude -o ejercicio1
```

Y posteriormente ejecutar mediante:
```bash
./ejercicio1.exe
```

---

## Ejemplo de salida

```text
-123 -> Constante decimal
056 -> Constante octal
0x1AF -> Constante hexadecimal
08 -> Error léxico
0xG -> Error léxico
0 -> Constante decimal
+456 -> Constante decimal

Resumen:
Decimales: 3
Octales: 1
Hexadecimales: 1
Errores léxicos: 2
```

---

## Documentación

La documentación asociada al proyecto puede consultarse en la carpeta:

```
documentacion/
```

donde se incluyen:

- Informe técnico (con capturas de la ejecución).
- Diagramas de los autómatas.

---

## Recursos adicionales

Para una descripción más detallada del desarrollo del ejercicio pueden consultarse los siguientes recursos:

- [Informe técnico](../documentacion/SSL%20TP1_%20Informe%20-%20Kevin%20Bernabe.pdf)
- [Diagramas de los autómatas](../documentacion/automatas/)
