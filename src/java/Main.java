import java.util.LinkedList;
import java.util.Queue;

class Nodo {
    int dato;
    Nodo izquierda;
    Nodo derecha;

    public Nodo(int dato) {
        this.dato = dato;
        this.izquierda = null;
        this.derecha = null;
    }
}

//Clase Ejercicio 5
class NodoWeb {
    String nombre;
    NodoWeb izquierda;
    NodoWeb derecha;

    public NodoWeb(String nombre) {
        this.nombre = nombre;
        this.izquierda = null;
        this.derecha = null;
    }
}

public class Main {

    //Metodos ejercicio 5
    public static void preordenWeb(NodoWeb raiz) {
        if (raiz == null) return;
        System.out.println("- " + raiz.nombre);
        preordenWeb(raiz.izquierda);
        preordenWeb(raiz.derecha);
    }

    public static void postordenWeb(NodoWeb raiz) {
        if (raiz == null) return;
        postordenWeb(raiz.izquierda);
        postordenWeb(raiz.derecha);
        System.out.println("- " + raiz.nombre);
    }

    public static void bfsWeb(NodoWeb raiz) {
        if (raiz == null) return;
        Queue<NodoWeb> cola = new LinkedList<>();
        cola.add(raiz);

        while (!cola.isEmpty()) {
            NodoWeb actual = cola.poll();
            System.out.println("- " + actual.nombre);
            if (actual.izquierda != null) cola.add(actual.izquierda);
            if (actual.derecha != null) cola.add(actual.derecha);
        }
    }

    public static void preorden(Nodo raiz) {
        if (raiz == null) return;
        System.out.print(raiz.dato + " ");
        preorden(raiz.izquierda);
        preorden(raiz.derecha);
    }

    public static void inorden(Nodo raiz) {
        if (raiz == null) return;
        inorden(raiz.izquierda);
        System.out.print(raiz.dato + " ");
        inorden(raiz.derecha);
    }

    public static void postorden(Nodo raiz) {
        if (raiz == null) return;
        postorden(raiz.izquierda);
        postorden(raiz.derecha);
        System.out.print(raiz.dato + " ");
    }

    public static void bfs(Nodo raiz) {
        if (raiz == null) return;

        Queue<Nodo> cola = new LinkedList<>();
        cola.add(raiz);

        while (!cola.isEmpty()) {
            Nodo actual = cola.poll();
            System.out.print(actual.dato + " ");

            if (actual.izquierda != null) cola.add(actual.izquierda);
            if (actual.derecha != null) cola.add(actual.derecha);
        }
    }
    // ==========================================
    // EJERCICIO 3
    // ==========================================
    public static int contarNodos(Nodo raiz) {
        if (raiz == null) {
            return 0; // Caso base: si no hay nodo, suma 0
        }
        // Suma 1 (el nodo actual) + los nodos de la izquierda + los de la derecha
        return 1 + contarNodos(raiz.izquierda) + contarNodos(raiz.derecha);
    }

    // ==========================================
    // EJERCICIO 4
    // ==========================================
    public static int contarHojas(Nodo raiz) {
        if (raiz == null) {
            return 0; 
        }
        // Si no tiene hijo izquierdo ni derecho, es una hoja
        if (raiz.izquierda == null && raiz.derecha == null) {
            return 1; 
        }
        // Si no es hoja, sigue buscando
        return contarHojas(raiz.izquierda) + contarHojas(raiz.derecha);
    }
    

    public static void main(String[] args) {
        Nodo raiz = new Nodo(10);
        raiz.izquierda = new Nodo(5);
        raiz.derecha = new Nodo(15);
        raiz.izquierda.izquierda = new Nodo(2);
        raiz.izquierda.derecha = new Nodo(7);
        raiz.derecha.izquierda = new Nodo(12);
        raiz.derecha.derecha = new Nodo(20);

        System.out.println("RECORRIDOS DE ARBOLES BINARIOS - UTA");

        System.out.print("Preorden: ");
        preorden(raiz);

        System.out.print("\nInorden: ");
        inorden(raiz);

        System.out.print("\nPostorden: ");
        postorden(raiz);

        System.out.print("\nBFS: ");
        bfs(raiz);

        System.out.println();
        // ==========================================
        // EJERCICIO 2
        // ==========================================
        System.out.println("\n--- Ejercicio 2 ---");
        // Agregamos 1 y 3 como hijos del nodo 2
        raiz.izquierda.izquierda.izquierda = new Nodo(1);
        raiz.izquierda.izquierda.derecha = new Nodo(3);
        
        // Agregamos 18 y 25 como hijos del nodo 20
        raiz.derecha.derecha.izquierda = new Nodo(18);
        raiz.derecha.derecha.derecha = new Nodo(25);

        System.out.print("Preorden actualizado: ");
        preorden(raiz);
        System.out.print("\nInorden actualizado: ");
        inorden(raiz);
        System.out.print("\nPostorden actualizado: ");
        postorden(raiz);
        System.out.print("\nBFS actualizado: ");
        bfs(raiz);
        System.out.println();

        // ==========================================
        // EJERCICIO 3
        // ==========================================
        System.out.println("\n--- Ejercicio 3 ---");
        int totalNodos = contarNodos(raiz);
        System.out.println("La cantidad total de nodos en el arbol es: " + totalNodos);

        // ==========================================
        // EJERCICIO 4
        // ==========================================
        System.out.println("\n--- Ejercicio 4 ---");
        int totalHojas = contarHojas(raiz);
        System.out.println("La cantidad total de hojas en el arbol es: " + totalHojas);

        // ==========================================
        // EJERCICIO 5
        // ==========================================
        System.out.println("\n--- Ejercicio 5: Sistema Web ---");
        
        NodoWeb raizWeb = new NodoWeb("Sistema Web");
        raizWeb.izquierda = new NodoWeb("Usuarios");
        raizWeb.derecha = new NodoWeb("Inventario");
        
        raizWeb.izquierda.izquierda = new NodoWeb("Registrar");
        raizWeb.izquierda.derecha = new NodoWeb("Buscar");
        
        raizWeb.derecha.izquierda = new NodoWeb("Productos");
        raizWeb.derecha.derecha = new NodoWeb("Reportes");

        System.out.println("\n1. Mostrar el menu principal (Preorden):");
        preordenWeb(raizWeb);

        System.out.println("\n2. Procesar primero los modulos internos (Postorden):");
        postordenWeb(raizWeb);

        System.out.println("\n3. Mostrar modulos nivel por nivel (BFS):");
        bfsWeb(raizWeb);
        
        System.out.println();
    }
}
