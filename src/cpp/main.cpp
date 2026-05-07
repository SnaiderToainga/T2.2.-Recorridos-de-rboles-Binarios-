#include <iostream>
#include <queue>
using namespace std;

struct Nodo {
    int dato;
    Nodo* izquierda;
    Nodo* derecha;

    Nodo(int valor) {
        dato = valor;
        izquierda = nullptr;
        derecha = nullptr;
    }
};

void preorden(Nodo* raiz) {
    if (raiz == nullptr) return;
    cout << raiz->dato << " ";
    preorden(raiz->izquierda);
    preorden(raiz->derecha);
}

void inorden(Nodo* raiz) {
    if (raiz == nullptr) return;
    inorden(raiz->izquierda);
    cout << raiz->dato << " ";
    inorden(raiz->derecha);
}

void postorden(Nodo* raiz) {
    if (raiz == nullptr) return;
    postorden(raiz->izquierda);
    postorden(raiz->derecha);
    cout << raiz->dato << " ";
}

void bfs(Nodo* raiz) {
    if (raiz == nullptr) return;

    queue<Nodo*> cola;
    cola.push(raiz);

    while (!cola.empty()) {
        Nodo* actual = cola.front();
        cola.pop();

        cout << actual->dato << " ";

        if (actual->izquierda != nullptr) cola.push(actual->izquierda);
        if (actual->derecha != nullptr) cola.push(actual->derecha);
    }
}

// Ejercicio 3
int contarNodos(Nodo* raiz) {
    if (raiz == NULL) {
        return 0; // Caso base: si no hay nodo, suma 0
    }
    // Suma 1 (el nodo actual) + los nodos de la izquierda + los de la derecha
    return 1 + contarNodos(raiz->izquierda) + contarNodos(raiz->derecha);
}

int main() {
    Nodo* raiz = new Nodo(10);
    raiz->izquierda = new Nodo(5);
    raiz->derecha = new Nodo(15);
    raiz->izquierda->izquierda = new Nodo(2);
    raiz->izquierda->derecha = new Nodo(7);
    raiz->derecha->izquierda = new Nodo(12);
    raiz->derecha->derecha = new Nodo(20);

    cout << "RECORRIDOS DE ARBOLES BINARIOS - UTA" << endl;

    cout << "Preorden: ";
    preorden(raiz);

    cout << "\nInorden: ";
    inorden(raiz);

    cout << "\nPostorden: ";
    postorden(raiz);

    cout << "\nBFS: ";
    bfs(raiz);

    cout << endl;

    // ==========================================
    // EJERCICIO 2
    // ==========================================
    cout << "\n--- Ejercicio 2 ---" << endl;
    
    // Agregamos 1 y 3 como hijos del nodo 2
    raiz->izquierda->izquierda->izquierda = new Nodo(1);
    raiz->izquierda->izquierda->derecha = new Nodo(3);
    
    // Agregamos 18 y 25 como hijos del nodo 20
    raiz->derecha->derecha->izquierda = new Nodo(18);
    raiz->derecha->derecha->derecha = new Nodo(25);

    cout << "Preorden actualizado: "; preorden(raiz); cout << endl;
    cout << "Inorden actualizado:  "; inorden(raiz); cout << endl;
    cout << "Postorden actualizado: "; postorden(raiz); cout << endl;
    cout << "BFS actualizado:       "; bfs(raiz); cout << endl;
    
    // ==========================================
    // EJERCICIO 3
    // ==========================================
    cout << "\n--- Ejercicio 3 ---" << endl;
    int totalNodos = contarNodos(raiz);
    cout << "La cantidad total de nodos en el arbol es: " << totalNodos << endl;
    
    return 0;
}
