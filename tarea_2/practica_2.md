# Práctica: Sistema de Registro de Calificaciones 2

Desarrolle una aplicación de consola para gestionar estudiantes, profesores, materias y calificaciones utilizando Programación Orientada a Objetos.

El sistema debe mostrar el siguiente menú:

1. Registrar estudiante.
2. Registrar profesor.
3. Registrar materia.
4. Registrar calificación.
5. Ver estudiantes.
6. Ver profesores.
7. Ver materias.
8. Ver calificaciones.
9. Salir.

---

## Registrar estudiante

Debe solicitar:

* Nombre completo.
* Matrícula.
* Sesión.

Con estos datos se debe crear un nuevo estudiante.

---

## Registrar profesor

Debe solicitar:

* Nombre completo.
* Código de profesor.

Con estos datos se debe crear un nuevo profesor.

---

## Registrar materia

Debe solicitar:

* Nombre de la materia.
* Código de materia.
* Cantidad de créditos.

Con estos datos se debe crear una nueva materia.

---

## Registrar calificación

Debe permitir seleccionar:

* Un estudiante registrado.
* Un profesor registrado.
* Una materia registrada.

Luego debe solicitar:

* Nota.

Con estos datos se debe crear una nueva calificación.

---

## Ver estudiantes

Debe mostrar todos los estudiantes registrados en formato de tabla.

---

## Ver profesores

Debe mostrar todos los profesores registrados en formato de tabla.

---

## Ver materias

Debe mostrar todas las materias registradas en formato de tabla.

---

## Ver calificaciones

Debe mostrar todas las calificaciones registradas en formato de tabla, incluyendo la información relacionada del estudiante, profesor y materia.

---

## Salir

Antes de finalizar el programa, toda la información debe guardarse en archivos de texto.

Al iniciar el programa nuevamente, todos los datos guardados deben cargarse automáticamente.

---

## Clases requeridas

### Estudiante

Debe representar un estudiante y contener sus datos personales.

Atributos mínimos:

* Nombre completo.
* Matrícula.
* Sesión.

---

### Profesor

Debe representar un profesor y contener sus datos personales.

Atributos mínimos:

* Nombre completo.
* Código de profesor.

---

### Materia

Debe representar una materia y contener su información académica.

Atributos mínimos:

* Nombre de la materia.
* Código de materia.
* Cantidad de créditos.

---

### Calificacion

Debe representar una calificación individual.

Debe contener:

* Un objeto de tipo `Estudiante`.
* Un objeto de tipo `Profesor`.
* Un objeto de tipo `Materia`.
* La nota obtenida.

---

### Sistema

Debe controlar toda la lógica del programa, incluyendo:

* Menús.
* Registro de datos.
* Consultas.
* Persistencia de información.
* Validaciones.

---

## Persistencia de datos

La información debe almacenarse utilizando archivos de texto.

Cada tipo de entidad debe guardarse en su propio archivo:

* Estudiantes.
* Profesores.
* Materias.
* Calificaciones.

Al iniciar el programa, todos los datos deben cargarse automáticamente desde los archivos correspondientes.

---

## Validaciones

Todos los datos ingresados por el usuario deben validarse utilizando bucles hasta que sean correctos.

Se deben validar, entre otros:

* Formato de matrícula.
* Formato de códigos.
* Formato de nombres.
* Rango válido de notas.
* Sesión.

No se permite aceptar datos inválidos.

---

## Requisitos

* Utilizar Programación Orientada a Objetos.
* Utilizar una colección para almacenar múltiples objetos.
* Implementar lectura y escritura en archivos de texto.
* El programa debe ejecutarse completamente en la terminal.
* Separar la definición e implementación de las clases.
* Cada clase debe tener su correspondiente archivo `.h` y `.cpp`.
* Los registros deben soportar espacios en los textos ingresados por el usuario.
* Mostrar la información en formato tabular cuando corresponda.

---

## Organización del proyecto

La implementación debe estar distribuida en múltiples archivos.

Ejemplo:

```text
Registro de calificaciones/
│
├── main.cpp
├── Sistema.h
├── Sistema.cpp
├── Estudiante.h
├── Estudiante.cpp
├── Profesor.h
├── Profesor.cpp
├── Materia.h
├── Materia.cpp
├── Calificacion.h
├── Calificacion.cpp
└── archivos de datos
```

La estructura exacta puede variar, pero cada clase debe tener su archivo de definición (`.h`) y su archivo de implementación (`.cpp`).

---

## Restricciones

* No se permite el uso de atributos públicos.
* Todos los atributos deben ser privados.
* No se permite utilizar variables globales para almacenar información.
* La lógica principal debe estar dentro de la clase `Sistema`.
* No se permite utilizar `using namespace std`.
* El uso de `using namespace std` en cualquier parte del proyecto invalida automáticamente la práctica.
* No se permite el uso de herramientas de Inteligencia Artificial para desarrollar la práctica.
* No se permiten modificaciones directamente desde la interfaz web de GitHub.
* Todo el trabajo debe realizarse localmente utilizando Git.
* El código debe compilar sin advertencias.

---

## Repositorio

Debe realizar un fork del siguiente repositorio:

https://github.com/YoelPilier/POO411_tareas

Luego debe:

1. Completar sus datos en el archivo `README.md`.
2. Crear una carpeta llamada:

```text
Registro de calificaciones
```

3. Desarrollar toda la práctica dentro de esa carpeta.
4. Utilizar Git durante todo el desarrollo para registrar el progreso realizado.
5. Realizar múltiples commits que reflejen avances reales del proyecto.
6. Subir los cambios mediante:

```bash
git push
```

7. No se permite desarrollar el proyecto completo y realizar un único commit al final.
8. No se permite editar archivos directamente desde la interfaz web de GitHub.

El historial de commits será utilizado como evidencia del proceso de desarrollo.

---

## Compilación

El proyecto será evaluado utilizando exactamente el siguiente comando:

```bash
clang++ -std=c++20 -Wall -Wextra -Wpedantic -Werror *.cpp -o outputs/salida
```

El proyecto debe compilar sin errores ni advertencias.

---

## Entrega

La entrega se realizará mediante el repositorio de GitHub generado a partir del fork, por lo tanto debe copiart el enlace  de su fork en el formulario de la tarea.

La carpeta `Registro de calificaciones` en el repositorio debe contener:

* Los archivos `.h` y `.cpp` correspondientes.
* Los archivos de texto utilizados para persistencia.
* El historial de commits realizado durante el desarrollo.


