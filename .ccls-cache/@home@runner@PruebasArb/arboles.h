#ifndef ARBOLES_H
#define ARBOLES_H

#include <algorithm>
#include <deque>
#include <iostream>
#include <list>
#include <vector>

template <class T> class NodoAVL {
protected:
  T dato;
  NodoAVL<T> *hijoIzq;
  NodoAVL<T> *hijoDer;
  int altura; // Añadir atributo de altura

public:
NodoAVL() {
  this->hijoIzq = NULL;
  this->hijoDer = NULL;
}
NodoAVL(T dato) {
  this->dato = dato;
  this->hijoIzq = NULL;
  this->hijoDer = NULL;
}
~NodoAVL() {
  delete this->hijoDer;
  delete this->hijoIzq;
}
T getDato() { 
  return this->dato; 
}
void actualizarAltura() {
  altura = 1 + std::max(hijoIzq ? hijoIzq->altura : 0,
                        hijoDer ? hijoDer->altura : 0);
}
int factorEquilibrio() {
  return (hijoIzq ? hijoIzq->altura : 0) - (hijoDer ? hijoDer->altura : 0);
}
void preOrden() {
  std::cout << this->dato << " ";
  if (this->hijoIzq != NULL) {
    this->hijoIzq->preOrden();
  }
  if (this->hijoDer != NULL) {
    this->hijoDer->preOrden();
  }
}
int altura() {
  int alturaIzq = -1, alturaDer = -1;
  if (this->hijoIzq != NULL) {
    alturaIzq = this->hijoIzq->altura();
  }
  if (this->hijoDer != NULL) {
    alturaDer = this->hijoDer->altura();
  }
  return (alturaIzq > alturaDer ? alturaIzq : alturaDer) + 1;
}
bool esHoja() { 
  return this->hijoIzq == NULL && this->hijoDer == NULL; 
}
void inOrden() {
  if (this->hijoIzq != NULL) {
    this->hijoIzq->inOrden();
  }
  std::cout << this->dato << " ";
  if (this->hijoDer != NULL) {
    this->hijoDer->inOrden();
  }
}
int factorEquilibrio() {
  int alturaIzq = this->hijoIzq ? this->hijoIzq->altura() : -1;
  int alturaDer = this->hijoDer ? this->hijoDer->altura() : -1;
  return alturaIzq - alturaDer;
}
NodoAVL<T> *rotarDerecha(NodoAVL<T> * y) {
  NodoAVL<T> *x = y->hijoIzq;
  NodoAVL<T> *T2 = x->hijoDer;

  // Realiza la rotación
  x->hijoDer = y;
  y->hijoIzq = T2;

  // Actualiza alturas aquí si almacenas la altura en cada nodo

  return x; // Nueva raíz
}
NodoAVL<T> *rotarIzquierda(NodoAVL<T> * x) {
  NodoAVL<T> *y = x->hijoDer;
  NodoAVL<T> *T2 = y->hijoIzq;

  // Realiza la rotación
  y->hijoIzq = x;
  x->hijoDer = T2;

  // Actualiza alturas aquí si almacenas la altura en cada nodo

  return y; // Nueva raíz
}
};
template <class T> class ArbolAVL {
protected:
  NodoAVL<T> *raiz;
  NodoAVL<T> *eliminarNodo(NodoAVL<T> *nodo, T dato) {
    if (nodo == NULL) {
      return nodo; // El dato no se encontró en el árbol.
    }

    // Navega por el árbol
    if (dato < nodo->getDato()) {
      nodo->hijoIzq = eliminarNodo(nodo->hijoIzq, dato);
    } else if (dato > nodo->getDato()) {
      nodo->hijoDer = eliminarNodo(nodo->hijoDer, dato);
    } else {
      // Encontramos el nodo a eliminar
      // Caso 1: No tiene hijos o tiene un solo hijo
      if (nodo->hijoIzq == NULL || nodo->hijoDer == NULL) {
        NodoAVL<T> *temp = nodo->hijoIzq ? nodo->hijoIzq : nodo->hijoDer;

        // No tiene hijos
        if (temp == NULL) {
          temp = nodo;
          nodo = NULL;
        } else {
          // Tiene un hijo
          *nodo = *temp; // Copia el contenido del hijo no NULL
        }
        delete temp;
      } else {
        // Caso 2: Tiene dos hijos
        // Busca el sucesor inorden (el menor en el subárbol derecho)
        NodoAVL<T> *temp = valorMinimoNodo(nodo->hijoDer);

        // Copia el sucesor inorden al nodo actual
        nodo->dato = temp->dato;

        // Elimina el sucesor inorden
        nodo->hijoDer = eliminarNodo(nodo->hijoDer, temp->dato);
      }
    }

    if (nodo == NULL) {
      return nodo;
    }

    // Aquí debes implementar el balanceo del árbol después de la eliminación

    return nodo;
  }

  NodoAVL<T> *valorMinimoNodo(NodoAVL<T> *nodo) {
    NodoAVL<T> *actual = nodo;

    // Busca la hoja más a la izquierda
    while (actual && actual->hijoIzq != NULL) {
      actual = actual->hijoIzq;
    }

    return actual;
  }

public:
  void inOrden() {
    if (this->hijoIzq != NULL) {
      this->hijoIzq->inOrden();
    }
    std::cout << this->dato << " ";
    if (this->hijoDer != NULL) {
      this->hijoDer->inOrden();
    }
  }

  ArbolAVL() { this->raiz = NULL; }
  ArbolAVL(T dato) { this->raiz = new NodoAVL<T>(dato); }
  ~ArbolAVL() {
    delete this->raiz;
    this->raiz = NULL;
  }
  void eliminarDato(T dato) { this->raiz = eliminarNodo(this->raiz, dato); }
  NodoAVL<T> *getRaiz() { return this->raiz; }
  void insertarDato(T dato) {
    if (this->raiz == NULL) {
      this->raiz = new NodoAVL<T>(dato);
    } else {
      this->raiz->agregarHijo(dato);
    }
  }

  void preOrden() {
    if (raiz == NULL)
      return;
    raiz->preOrden();
  }
  void inOrden() {
    if (raiz == NULL)
      return;
    raiz->inOrden();
  }
  int altura() {
    if (this->raiz == NULL) {
      return -1; // Altura de un árbol vacío
    } else {
      return this->raiz->altura(); // Llama al método altura del nodo raíz
    }
  }
};

template <class T> std::list<T> inOrden(ArbolAVL<T> &arbol) {
  std::list<T> lista;
  inOrdenAux(arbol.getRaiz(), lista);
  return lista;
}


template <class T>
class Heap {
private:
    std::vector<T> heap;

    void heapifyUp(int index) {
        while (index > 0 && heap[(index-1)/2] > heap[index]) {
            std::swap(heap[(index-1)/2], heap[index]);
            index = (index-1)/2;
        }
    }

    void heapifyDown(int index) {
        int size = heap.size();
        int smallest = index;

        int left = 2*index + 1;
        int right = 2*index + 2;

        if (left < size && heap[left] < heap[smallest]) {
            smallest = left;
        }

        if (right < size && heap[right] < heap[smallest]) {
            smallest = right;
        }

        if (smallest != index) {
            std::swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    Heap() {}

    void insert(T element) {
        heap.push_back(element);
        int index = heap.size() - 1;
        heapifyUp(index);
    }

    T extractMin() {
        if (heap.size() == 0) {
            throw std::out_of_range("Heap is empty");
        }
        T min = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return min;
    }

    bool isEmpty() const {
        return heap.empty();
    }

    void printHeap() {
        for (auto &elem : heap) {
            std::cout << elem << " ";
        }
        std::cout << "\n";
    }
};


#endif
