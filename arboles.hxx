#ifndef ARBOLES_H
#define ARBOLES_H

#include <deque>
#include <cmath>
#include <iostream>

template <class T> class NodoAVL {
protected:
T dato;
NodoAVL<T> *hijoIzq;
NodoAVL<T> *hijoDer;

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

NodoAVL(T dato, NodoAVL<T> *izq, NodoAVL<T> *der){
  this->dato = dato;
  this->hijoIzq = izq;
  this->hijoDer = der;
}
~NodoAVL() {
  delete this->hijoDer;
  delete this->hijoIzq;
}
NodoAVL<T>* getHijoDer() {
  return this->hijoDer;

}
NodoAVL<T>* getHijoIzq(){
  return this->hijoIzq;
}
void setIzq(NodoAVL<T>* izq){
  this->hijoIzq = izq;
}
void setDer(NodoAVL<T>* der){
  this->hijoDer = der;
}
void agregarHijo(T dato){
  if(this->dato > dato){
    if(this->hijoIzq == NULL)
      this->hijoIzq = new NodoAVL<T>(dato);
    else
      this->hijoIzq->agregarHijo(dato);
  } else{
    if(this->hijoDer == NULL)
      this->hijoDer = new NodoAVL<T>(dato);
    else
      this->hijoDer->agregarHijo(dato);    
  }
  if(!this->equilibrado()){
    this->ordenar();
  }
}
void agregarHijo(NodoAVL<T>* nodo){
  if(this->dato > nodo->dato){
    if(this->hijoIzq == NULL){
      this->hijoIzq = nodo;
    }
    else
      this->hijoIzq->agregarHijo(nodo);
  } else{
    if(this->hijoDer == NULL)
      this->hijoDer = nodo;
    else
      this->hijoDer->agregarHijo(nodo);    
  }
  if(!this->equilibrado()){
    this->ordenar();
  }
}
NodoAVL<T>* eliminarNodo(T valor){
  NodoAVL<T> *aux;
  if(this->hijoIzq != NULL){
    if(this->hijoIzq->getDato() == valor){
      std::cout<<"Val Econtrado\n";
      aux = this->hijoIzq->getHijoIzq();
      aux->agregarHijo(this->hijoIzq->getHijoDer());
      return aux;
    }
  }
  if(this->hijoDer != NULL){
    if(this->hijoDer->getDato() == valor){
      std::cout<<"Val Econtrado\n";
      aux = this->hijoDer->getHijoIzq();
      aux->agregarHijo(this->hijoDer->getHijoDer());
      return aux;
    }
  }
  if(valor < this->dato){
    if(this->hijoIzq != NULL){
       aux = this->hijoIzq->eliminarNodo(valor);
      if(aux != NULL)
        return aux;
    }
  }
  if(valor > this->dato){
    std::cout << "Val mayor\n";
    if(this->hijoDer != NULL){
      aux = this->hijoDer->eliminarNodo(valor);
      if(aux != NULL)
        return aux;
    }
  }
  return NULL;
}
T getDato() { 
  return this->dato; 
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
void inOrden() {
  if (this->hijoIzq != NULL) {
    this->hijoIzq->inOrden();
  }
  std::cout << this->dato << " ";
  if (this->hijoDer != NULL) {
    this->hijoDer->inOrden();
  }
}
void postOrden(){
  if (this->esHoja())
    std::cout << this->dato << " ";
  else{
    if(this->hijoIzq != NULL)
      this->hijoIzq->postOrden();
    if(this->hijoDer != NULL)
      this->hijoDer->postOrden();
    std::cout << this->dato << " ";
  }
  
}
int altura(NodoAVL<T>* nodo) {
  if(nodo == NULL)
    return -1;
  int alturaIzq = -1, alturaDer = -1;
  alturaIzq = altura(nodo->getHijoIzq());
  alturaDer = altura(nodo->getHijoDer());
  if (alturaIzq > alturaDer){
    return alturaIzq + 1;
  }else{
    return alturaDer + 1;
  }
}
int alturaMin(NodoAVL<T>* nodo) {
  if(nodo == NULL)
    return -1;
  int alturaIzq = -1, alturaDer = -1;
  alturaIzq = alturaMin(nodo->getHijoIzq());
  alturaDer = alturaMin(nodo->getHijoDer());
  if (alturaIzq < alturaDer){
    return alturaIzq + 1;
  }else{
    return alturaDer + 1;
  }
}
bool esHoja() { 
  return this->hijoIzq == NULL && this->hijoDer == NULL; 
}
bool equilibrado(){
  int dif = this->difAlturas();
  bool nodoEq = dif <= 1 && dif >= -1;
  if(this->hijoDer != NULL)
    nodoEq = nodoEq && this->hijoDer->equilibrado();
  if(this->hijoIzq != NULL)
    nodoEq = nodoEq && this->hijoIzq->equilibrado();
  return nodoEq;
}
int difAlturas(){
  int altIzq = -1, altDer = -1;
  if(this->hijoIzq != NULL){
    altIzq = altura(this->hijoIzq);
  }
  if(this->hijoDer != NULL){
    altDer = altura(this->hijoDer);
  }
  // Menor a 0 izq más grande
  // Mayor a 0 der más grande

  
  return altDer - altIzq;
}
int ordenar(){
  int dif = this->difAlturas();
  if(dif > 0){
    if(this->hijoDer->difAlturas() > 0)
      this->rotarIzquierda();
    else
      this->rotarDerIzq();
  }
  if(dif < 0){
    if(this->hijoIzq->difAlturas() < 0){
      this->rotarDerecha();
    }
    else
      this->rotarIzqDer();
  }
  return 0;
}
void rotarDerecha() {
  NodoAVL<T> *auxHI = this->hijoIzq;
  this->hijoIzq = this->hijoIzq->getHijoDer();
  NodoAVL<T> *auxThis = new NodoAVL<T>(this->dato,this->hijoIzq, this->hijoDer);
  auxHI->setDer(auxThis);
  this->dato = auxHI->getDato();
  this->hijoIzq = auxHI->getHijoIzq();
  this->hijoDer = auxHI->getHijoDer();
}
void rotarIzquierda() {
  NodoAVL<T> *auxHD = this->hijoDer;
  this->hijoDer = this->hijoDer->getHijoIzq();
  NodoAVL<T> *auxThis = new NodoAVL<T>(this->dato, this->hijoIzq, this->hijoDer);
  auxHD->setIzq(auxThis);
  this->dato = auxHD->getDato();
  this->hijoIzq = auxHD->getHijoIzq();
  this->hijoDer = auxHD->getHijoDer();
}
void rotarIzqDer(){
  this->hijoIzq->rotarIzquierda();
  this->rotarDerecha();
}
void rotarDerIzq(){
  this->hijoDer->rotarDerecha();
  this->rotarIzquierda();
}
void imprimirArbol(){
  if(hijoIzq != NULL)
    std::cout << this->dato << "->" << this->hijoIzq->dato << "\n";
  if(hijoDer != NULL)
    std::cout << this->dato << "->" << this->hijoDer->dato << "\n";
  if(hijoIzq != NULL)
    this->hijoIzq->imprimirArbol();
  if(hijoDer != NULL)
    this->hijoDer->imprimirArbol();
}
NodoAVL<T>* buscar(T valor){
  if(this->dato == valor){
    return this;
  }
  if((valor < this->dato) && (this->hijoIzq != NULL)){
    return this->hijoIzq->buscar(valor);
  }
  if((this->dato < valor) && (hijoDer != NULL)){
    return this->hijoDer->buscar(valor);
  }
  return NULL;
}

};
template <class T> class ArbolAVL {
protected:
NodoAVL<T> *raiz;

public:
ArbolAVL() { 
  this->raiz = NULL; 
}
ArbolAVL(T dato) { 
  this->raiz = new NodoAVL<T>(dato); 
}
~ArbolAVL() {
  delete this->raiz;
  this->raiz = NULL;
}
NodoAVL<T> *getRaiz() { 
  return this->raiz; 
}
void insert(T dato) {
  if (this->raiz == NULL) {
    this->raiz = new NodoAVL<T>(dato);
  } else
    this->raiz->agregarHijo(dato);
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
void postOrden(){
  if(raiz == NULL)
    return;
  raiz->postOrden();
}
int altura() {
  if (this->raiz == NULL) {
    return -1; // Altura de un árbol vacío
  } else {
    return raiz->alturaMax(raiz); // Llama al método altura del nodo raíz
  }
}
bool equilibrado(){
  if (raiz == NULL)
    return true;
  return this->raiz->equilibrado();
}
void imprimirArbol(){
  if (raiz == NULL)
    return;
  this->raiz->imprimirArbol();
}

NodoAVL<T>* buscar(T valor){
return this->raiz->buscar(valor);
}
void erase(T valor){
  NodoAVL<T> *aux = this->raiz->eliminarNodo(valor);
  if(raiz == NULL)
    return;
  if(this->raiz->getDato() == valor){
    aux = this->raiz->getHijoIzq();
    aux->agregarHijo(this->raiz->getHijoDer());
    this->raiz = aux;
  }
  else if(aux != NULL){
    this->raiz = aux;
  }
}
};

#endif