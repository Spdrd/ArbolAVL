

// Nodo

template<class T>
NodoAVL<T>::NodoAVL(){
  this->hijoIzq = NULL;
  this->hijoDer = NULL;
}

template<class T>
NodoAVL<T>::NodoAVL(T dato){
  this->dato = dato;
  this->hijoIzq = NULL;
  this->hijoDer = NULL;
}

template<class T>
T NodoAVL<T>::getDato(){
  return this->dato;
}


// Arbol

template<class T>
ArbolAVL<T>::ArbolAVL(){
  this->raiz = NULL;
}

template<class T>
ArbolAVL<T>::ArbolAVL(T dato){
  this->raiz = NodoAVL(dato);
}