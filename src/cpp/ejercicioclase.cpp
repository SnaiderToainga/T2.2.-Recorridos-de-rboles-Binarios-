#include <iostream>
#include <queue>

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
    
    return 0;
}