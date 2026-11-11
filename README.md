# LAB 3 · Pruebas con GoogleTest — repositorio de EJERCICIO (Biblioteca)

Un proyecto pequeño de una **biblioteca**, con la misma estructura que el del hotel del repositorio de referencia
**[pp-lab3-tests-referencia](https://github.com/jcor-cunpir/pp-lab3-tests-referencia)**, pero **casi sin tests**:
solo hay uno de ejemplo. Vuestro trabajo, por parejas, es **escribir las pruebas copiando y adaptando las del hotel**.

> **El código tiene 4 errores escondidos.** No los busquéis leyendo el código: si vuestros tests están bien hechos,
> **ellos los encontrarán** (se pondrán en rojo). Primero el test en rojo; después, el arreglo.

La guía paso a paso está en **`Practica Tests - 2026.11.16.pdf`**, en este mismo repositorio.

## 1. Crear vuestro repositorio (UNA persona de la pareja)

1. Botón verde **Use this template** → **Create a new repository**.
2. Nombre: `lab3-biblioteca`. Da igual **Public** o **Private**. **Create repository**.
3. Opcional: **Settings → Collaborators → Add people** para añadir a vuestra pareja.
4. Pestaña **Actions**: al cabo de un par de minutos, la primera ejecución sale en **verde**.

## 2. Descargar, compilar y pasar los tests

| | Windows (PowerShell) | Mac (Terminal) |
| --- | --- | --- |
| Descargar | `git clone https://github.com/vuestro-usuario/lab3-biblioteca.git` | igual |
| Entrar | `cd lab3-biblioteca` | igual |
| Configurar (1.ª vez; descarga GoogleTest) | `cmake -S . -B build -G Ninja` | `cmake -S . -B build` |
| Compilar | `cmake --build build` | `cmake --build build` |
| Pasar los tests | `cd build`, `ctest --output-on-failure`, `cd ..` | igual |
| Ver cada test | `.\build\tests_gestor.exe` | `./build/tests_gestor` |

## 3. Qué tenéis que escribir

| Del hotel (referencia)… | …a la biblioteca (ejercicio) | Tipo de prueba | Paso de la guía |
| --- | --- | --- | --- |
| `tests/test_habitacion.cpp` | `tests/test_libro.cpp` (ya existe, con 1 test) | Unitaria, caja negra | 4 |
| `tests/test_suite.cpp` | `tests/test_novedad.cpp` (nuevo) | Unitaria, caja blanca | 5 |
| `tests/test_hotel.cpp` | `tests/test_biblioteca.cpp` (nuevo) | Unitaria con fixture | 6 |
| `tests/test_almacen.cpp` | `tests/test_almacen.cpp` (nuevo) | Integración | 7 |

Las equivalencias: `Habitacion` → `Libro`, `Suite` → `Novedad`, `Hotel` → `Biblioteca`, `reservar` → `prestar`,
`liberar` → `devolver`, `precioEstancia(noches)` → `multa(dias)`, `libres` → `disponibles`.
**Ojo: no todo es igual.** Leed los comentarios de cada `.hpp` en `include/`: dicen exactamente qué promete cada método.

Cada fichero de tests **nuevo** hay que añadirlo a `add_executable(tests_gestor ...)` en el `CMakeLists.txt`.

## 4. Cómo trabajar

1. Escribid un test (o varios) → `cmake --build build` → `ctest --output-on-failure`.
2. Si un test sale en rojo, **¿está mal el test o está mal la clase?** Leed el comentario del `.hpp`: es lo que manda.
3. Si está mal la clase: haced **primero el commit del test** (`test(libro): ...`) y `git push` → el CI de *Actions* sale en **rojo**.
4. Arreglad la clase, comprobad que todo sale en verde y haced el commit del arreglo (`fix(libro): ...`) y `git push` → **verde**.

Si lleváis más de 10 minutos atascados con un rojo, al final de la guía están las **Pistas**: qué está mal en cada error, por qué y cómo se arregla.
