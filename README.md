# Recorridos de Árboles Binarios - Estructura de Datos

**Universidad Técnica de Ambato**  
**Carrera:** Ingeniería de Software  
**Asignatura:** Estructura de Datos  
**Curso:** Tercero B  
**Autor:** Snaider Alexander Toainga Toapanta

**Tema:** Recorridos de árboles binarios: Inorden, Preorden, Postorden y BFS

## Objetivo general
Implementar y analizar los principales recorridos de árboles binarios utilizando C++ y Java, aplicando estructuras de datos dinámicas, recursividad y colas.

## Resultados de aprendizaje
Al finalizar la práctica, el estudiante será capaz de:

1. Explicar la diferencia entre recorridos DFS y BFS.
2. Implementar recorridos Inorden, Preorden y Postorden con recursividad.
3. Implementar BFS usando una cola.
4. Comparar la implementación en C++ y Java.
5. Aplicar recorridos de árboles a un caso real del proyecto final.

## Desarrollo
En este repositorio se encuentra la solución a los ejercicios propuestos en clase:
1. **Ejercicios 1 y 2:** Construcción de un Árbol Binario de Búsqueda (BST) base y posterior inserción de nuevos nodos (1, 3, 18, 25), validando el correcto funcionamiento de los algoritmos DFS y BFS.
2. **Ejercicios 3 y 4:** Implementación de algoritmos recursivos para contabilizar la cantidad total de nodos (11) y la cantidad de nodos hoja (6).
3. **Ejercicio 5 (Caso Real):** Aplicación de los recorridos a un modelo de jerarquía de un Sistema Web utilizando cadenas de texto (`string`).

## Explicación del Caso Real (Sistema Web)
En el desarrollo de software profesional, representamos la arquitectura de un sistema web como un árbol binario donde la raíz es el "Sistema Web" y las ramas son sus módulos. 

* **Menú Principal (Preorden):** Es el orden lógico para renderizar un menú (Raíz -> Izquierda -> Derecha). Mostramos el sistema y navegamos hacia adentro de sus categorías.
* **Módulos Internos / Dependencias (Postorden):** Útil para tareas técnicas de limpieza o carga de dependencias. Se procesan primero las funciones hijas antes de procesar el módulo padre.
* **Niveles de Acceso (BFS):** Sirve para cargar el sistema capa por capa de importancia o validar permisos horizontales.

## Contenido

| Carpeta | Descripción |
|---|---|
| `docs/` | Guía práctica para la clase |
| `src/cpp/` | Implementación completa en C++ |
| `src/java/` | Implementación completa en Java |
| `exercises/` | Ejercicios para trabajo grupal |
| `moodle/` | Banco de preguntas tipo Moodle |
| `assets/` | Recursos de apoyo |

## Reglas de recorrido

| Recorrido | Orden |
|---|---|
| Inorden | Izquierda → Raíz → Derecha |
| Preorden | Raíz → Izquierda → Derecha |
| Postorden | Izquierda → Derecha → Raíz |
| BFS | Nivel por nivel usando cola |

## Ejecución en C++

```bash
cd src/cpp
g++ main.cpp -o recorridos
./recorridos
```

## Ejecución en Java

```bash
cd src/java
javac Main.java
java Main
```

## Actividad  sugerida:

1. Clonar el repositorio.
2. Ejecutar el código base.
3. Agregar mínimo 5 nodos nuevos.
4. Mostrar los cuatro recorridos.
5. Modificar el caso de aplicación al proyecto final.
6. Subir evidencias al repositorio GitHub del grupo.

## Entregables

- Captura de ejecución en consola.
- Código fuente comentado.
- README del grupo.
- Explicación del caso real.
- Link del repositorio GitHub.

## Rúbrica breve sobre 10 puntos

| Criterio | Puntaje |
|---|---:|
| Implementación correcta de recorridos | 3 |
| Uso correcto de recursividad y cola | 2 |
| Código comentado y organizado | 1.5 |
| Aplicación al proyecto final | 2 |
| Uso de GitHub e IA documentada | 1.5 |

