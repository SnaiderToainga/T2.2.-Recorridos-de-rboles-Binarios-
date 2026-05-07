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

    return 0;
}