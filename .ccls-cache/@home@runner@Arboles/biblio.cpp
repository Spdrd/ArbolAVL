#include "biblio.h"
#include <iostream>
#include <deque>

template <typename T>
NodoGeneral<T>::NodoGeneral(){
  this->desc.clear();
}

template <typename T>
NodoGeneral<T>::~NodoGeneral(){
  typename std::deque<NodoGeneral<T>*>::iterator it;
  for(it = this->desc.begin(); it != this->desc.end(); it++){
    delete *it;
  }
  this->desc.clear();
}

template <typename T>
T& NodoGeneral<T>::getDato(){
  return this->dato;
}

template <typename T>
void NodoGeneral<T>::setDato(T& val){
  this->dato = val;
}

template <typename T>
void NodoGeneral<T>::limpiarLista(){
  this->desc.clear();
}

template <typename T>
void NodoGeneral<T>::adicionarDesc(T& nval) {
  NodoGeneral<T> *nodo = new NodoGeneral<T>;
  nodo->fijarDato(nval);
  this->desc.push_back(nodo);
}

template <typename T>
bool NodoGeneral<T>::eliminarDesc(T& val){
  //Buscar el Nodo con el valor dado
  typename std::deque<NodoGeneral<T>*>::iterator it;
  NodoGeneral<T> *aux;
  for(it = this->beguin(); it != this->end(); it++){
    aux = *it;
    if(aux->obtenerDato() == val){
      break;
    }
  }

  //Eliminar hijo
  bool r = false;
  if(aux == *it){
    delete *it;
    this->desc.erase(it);
    r = true;
  }
  return r;
}

template<typename T>
 int NodoGeneral<T>::altura(){
  if(this->esVacio()){
    return 0;
  }
  typename std::deque<NodoGeneral<T>*>::iterator it;
  int altMax = -1;
  for(it = this->desc.begining; it != this->desc.end(); it++){
    int aux = it->altura();
    if(aux > altMax)
      altMax = aux;
  }
  return altMax + 1;
} 

template<typename T>
bool NodoGeneral<T>::esHoja(){
  return this->desc.size() == 0;
}

template<typename T>
NodoGeneral<T>* NodoGeneral<T>::buscarDesc(T n){
  if(this->getDato() == n)
    return this;
  typename std::deque<T>::iteraror it;
  for(it = this->desc.begin(); it != this->desc.end(); it++)
    it->buscarDesc(n);
  return NULL;
}

template<typename T>
ArbolGeneral<T>::ArbolGeneral(){
  this->raiz = NULL;
}

template<typename T>
ArbolGeneral<T>::ArbolGeneral(T val){
  NodoGeneral<T>* nodo;
  nodo->setDato(val);
  this->setRaiz(nodo);
}

template<typename T>
ArbolGeneral<T>::~ArbolGeneral(){
  delete this->raiz;
  this-> raiz = NULL;
}
/*
template<typename T>
bool ArbolGeneral<T>::esVacio(){
  return this->raiz == NULL;
}

template<typename T>
NodoGeneral<T>* ArbolGeneral<T>::getRaiz(){
  return this->raiz;  
}

template<typename T>
void ArbolGeneral<T>::setRaiz(NodoGeneral<T>* nRaiz){
  this->raiz = nRaiz;
}

template<typename T>
bool ArbolGeneral<T>::insertarNodo(T padre, T n){
  if(esVacio()){
    NodoGeneral<T> *nodo = NodoGeneral<T>(n);
    setRaiz(nodo);
    return true;
  }
  NodoGeneral<T> *nodoAux = this->buscar(padre);
  if(nodoAux != NULL){
    nodoAux->adicionarDesc(n);
    return true;
  }
  return false;
}

template<typename T>
bool ArbolGeneral<T>::eliminarNodo(T n){
  return true;
}

template<typename T>
NodoGeneral<T>* ArbolGeneral<T>::buscar(T n){
  return  this->getRaiz()->buscarDesc(n);
}

template<typename T>
int ArbolGeneral<T>::altura(){
  if(this->esVacio()){
    return -1;
  }
  return raiz->altura();
}

template<typename T>
unsigned int ArbolGeneral<T>::tamanio(){
  return 0;
}

template<typename T>
void ArbolGeneral<T>::preOrden(){
  if(this->esVacio())
    return;
  this->preOrden(this->raiz);
}

template<typename T>
void NodoGeneral<T>::preOrden(NodoGeneral<T>* nodo){
  std::cout << this->dato << " ";
  typename std::deque<NodoGeneral<T>*>::iterator it;
  for(it = this->desc.begin(); it != this->desc.end(); it++){
    this->preOrden(*it);
  }
}

template<typename T>
void ArbolGeneral<T>::postOrden(){
  
}

template<typename T>
void ArbolGeneral<T>::nivelOrden(){
  
}
*/