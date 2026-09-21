# Ejercicio 2 - Conversión de Carácter Numérico a Entero

Este ejercicio implementa una función en lenguaje **C** capaz de convertir un carácter numérico en su correspondiente valor entero.

## Objetivo

Implementar una función que:

- Reciba un carácter (`char`).
- Determine si representa un dígito decimal válido.
- Devuelva el valor entero correspondiente.
- Retorne `-1` cuando el carácter no pertenezca al conjunto de los dígitos decimales.

---

## Funcionamiento

El programa recibe un carácter definido en `main.c`.

Ejemplo:

```text
'5'
```

La función `caracterAEntero()` verifica si el carácter pertenece al rango `'0'`–`'9'`.

- Si es válido, devuelve el entero correspondiente.
- Si no es un carácter numérico, retorna `-1`.

---

## Organización del código

```
ejercicio2/
│
├── include/
│   └── conversion.h
│
├── src/
│   ├── main.c
│   └── conversion.c
│
└── Makefile
```

### Módulos

- **main.c**

  Programa de prueba encargado de enviar distintos caracteres a la función de conversión e imprimir el resultado obtenido.

- **conversion.c**

  Implementa la función `caracterAEntero()`, responsable de convertir un carácter numérico en su valor entero utilizando la codificación ASCII.

---

## Compilación

Desde la carpeta raíz `ejercicio2`:

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
gcc src/main.c src/conversion.c -Iinclude -o ejercicio2
```

Y posteriormente ejecutar mediante:
```bash
./ejercicio2.exe
```

---

## Ejemplo de salida

```text
'1' -> 1
'5' -> 5
'9' -> 9
'a' -> -1
'+' -> -1
```

---

## Documentación

La documentación asociada al proyecto puede consultarse en la carpeta:

```
documentacion/
```

donde se incluyen:

- Informe técnico (con capturas de ejecución).

---

## Recursos adicionales

Para una descripción más detallada del desarrollo del ejercicio pueden consultarse los siguientes recursos:

- [Informe técnico](../documentacion/SSL%20TP1_%20Informe%20-%20Kevin%20Bernabe.pdf)
