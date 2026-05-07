#include <iostream>
#include <queue>
#include <string>

using namespace std;

// Estructura del nodo
struct Nodo {
    int dato;
    Nodo* izquierda;
    Nodo* derecha;
    
    Nodo(int valor) {
        dato = valor;
        izquierda = NULL;
        derecha = NULL;
    }
};

// Función para insertar nodos respetando la regla del BST
Nodo* insertar(Nodo* raiz, int valor) {
    if (raiz == NULL) {
        return new Nodo(valor);
    }
    if (valor < raiz->dato) {
        raiz->izquierda = insertar(raiz->izquierda, valor);
    } else {
        raiz->derecha = insertar(raiz->derecha, valor);
    }
    return raiz;
}

// 1. Recorrido Preorden
void preorden(Nodo* raiz) {
    if (raiz == NULL) return;
    cout << raiz->dato << " ";
    preorden(raiz->izquierda);
    preorden(raiz->derecha);
}

// 2. Recorrido Inorden
void inorden(Nodo* raiz) {
    if (raiz == NULL) return;
    inorden(raiz->izquierda);
    cout << raiz->dato << " ";
    inorden(raiz->derecha);
}

// 3. Recorrido Postorden
void postorden(Nodo* raiz) {
    if (raiz == NULL) return;
    postorden(raiz->izquierda);
    postorden(raiz->derecha);
    cout << raiz->dato << " ";
}

// 4. Recorrido BFS (Por niveles)
void bfs(Nodo* raiz) {
    if (raiz == NULL) return;
    queue<Nodo*> cola;
    cola.push(raiz);

    while (!cola.empty()) {
        Nodo* actual = cola.front();
        cola.pop();
        cout << actual->dato << " ";

        if (actual->izquierda != NULL) cola.push(actual->izquierda);
        if (actual->derecha != NULL) cola.push(actual->derecha);
    }
}

// ==========================================
// EJERCICIO 3: Contar total de nodos
// ==========================================
int contarNodos(Nodo* raiz) {
    if (raiz == NULL) {
        return 0; // Caso base: si no hay nodo, no suma nada
    }
    // Suma 1 (el nodo actual) + los nodos de la izquierda + los de la derecha
    return 1 + contarNodos(raiz->izquierda) + contarNodos(raiz->derecha);
}
// ==========================================
// EJERCICIO 4: Contar las hojas del árbol
// ==========================================
int contarHojas(Nodo* raiz) {
    if (raiz == NULL) {
        return 0; // Si está vacío, no hay hojas
    }
    // Si no tiene hijo izquierdo ni derecho, es una hoja
    if (raiz->izquierda == NULL && raiz->derecha == NULL) {
        return 1; 
    }
    // Si no es hoja, sigue buscando en las ramas y suma los resultados
    return contarHojas(raiz->izquierda) + contarHojas(raiz->derecha);
}

// ==========================================
// EJERCICIO 5: Árbol de Sistema Web
// ==========================================
struct NodoWeb {
    string nombre;
    NodoWeb* izquierda;
    NodoWeb* derecha;
    
    NodoWeb(string n) {
        nombre = n;
        izquierda = NULL;
        derecha = NULL;
    }
};

void preordenWeb(NodoWeb* raiz) {
    if (raiz == NULL) return;
    cout << "- " << raiz->nombre << endl;
    preordenWeb(raiz->izquierda);
    preordenWeb(raiz->derecha);
}

void postordenWeb(NodoWeb* raiz) {
    if (raiz == NULL) return;
    postordenWeb(raiz->izquierda);
    postordenWeb(raiz->derecha);
    cout << "- " << raiz->nombre << endl;
}

void bfsWeb(NodoWeb* raiz) {
    if (raiz == NULL) return;
    queue<NodoWeb*> cola;
    cola.push(raiz);

    while (!cola.empty()) {
        NodoWeb* actual = cola.front();
        cola.pop();
        cout << "- " << actual->nombre << endl;

        if (actual->izquierda != NULL) cola.push(actual->izquierda);
        if (actual->derecha != NULL) cola.push(actual->derecha);
    }
}

int main() {
    Nodo* raiz = NULL;
    
    // Creando el árbol del Ejercicio 1
    int valores[] = {10, 5, 15, 2, 7, 12, 20};
    for(int i = 0; i < 7; i++) {
        raiz = insertar(raiz, valores[i]);
    }

    cout << "--- Ejercicio 1 ---" << endl;
    cout << "Preorden: "; preorden(raiz); cout << endl;
    cout << "Inorden: "; inorden(raiz); cout << endl;
    cout << "Postorden: "; postorden(raiz); cout << endl;
    cout << "BFS: "; bfs(raiz); cout << endl;

    // ==========================================
    // EJERCICIO 2
    // ==========================================
    cout << "\n--- Ejercicio 2 ---" << endl;
    
    // Agregamos los nuevos nodos al árbol existente
    int nuevosValores[] = {1, 3, 18, 25};
    for(int i = 0; i < 4; i++) {
        raiz = insertar(raiz, nuevosValores[i]); // Se insertan siguiendo la regla del BST
    }

    // Volvemos a ejecutar los recorridos para ver el cambio
    cout << "Preorden actualizado: "; preorden(raiz); cout << endl;
    cout << "Inorden actualizado:  "; inorden(raiz); cout << endl;
    cout << "Postorden actualizado: "; postorden(raiz); cout << endl;
    cout << "BFS actualizado:       "; bfs(raiz); cout << endl;

    // ==========================================
    //  EJERCICIO 3
    // ==========================================
    cout << "\n--- Ejercicio 3 ---" << endl;
    int totalNodos = contarNodos(raiz);
    cout << "La cantidad total de nodos en el arbol es: " << totalNodos << endl;

    // ==========================================
    // EJERCICIO 4
    // ==========================================
    cout << "\n--- Ejercicio 4 ---" << endl;
    int totalHojas = contarHojas(raiz);
    cout << "La cantidad total de hojas en el arbol es: " << totalHojas << endl;

    // ==========================================
    // AGREGAR ESTO PARA EL EJERCICIO 5
    // ==========================================
    cout << "\n--- Ejercicio 5: Sistema Web ---" << endl;
    
    // Armamos el árbol manualmente según el gráfico
    NodoWeb* raizWeb = new NodoWeb("Sistema Web");
    raizWeb->izquierda = new NodoWeb("Usuarios");
    raizWeb->derecha = new NodoWeb("Inventario");
    
    raizWeb->izquierda->izquierda = new NodoWeb("Registrar");
    raizWeb->izquierda->derecha = new NodoWeb("Buscar");
    
    raizWeb->derecha->izquierda = new NodoWeb("Productos");
    raizWeb->derecha->derecha = new NodoWeb("Reportes");

    cout << "\n1. Menu Principal (Preorden):" << endl;
    preordenWeb(raizWeb);

    cout << "\n2. Procesar modulos internos primero (Postorden):" << endl;
    postordenWeb(raizWeb);

    cout << "\n3. Modulos nivel por nivel (BFS):" << endl;
    bfsWeb(raizWeb);
    
    return 0;
}