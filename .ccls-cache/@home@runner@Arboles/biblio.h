#ifndef BIBLIO_H
#define BIBLIO_H

#include <iostream>
#include <deque>

template <typename T>
class NodoGeneral {
protected : 
T dato;
std::deque<NodoGeneral<T>*> desc;

public:
NodoGeneral();
~NodoGeneral();
T& getDato();
void setDato(T& val);
void limpiarLista();
void adicionarDesc(T& nval);
bool eliminarDesc(T& val);
int altura();
bool esHoja();
NodoGeneral<T>* buscarDesc(T n);
void preOrden(NodoGeneral<T>* nodo);
};

template <typename T>
class ArbolGeneral {
protected:
NodoGeneral<T> *raiz;
public:
ArbolGeneral();
ArbolGeneral(T val);
~ArbolGeneral();
bool esVacio();
NodoGeneral<T>* getRaiz();
void setRaiz(NodoGeneral<T>* nRaiz);
bool insertarNodo(T padre, T n);
bool eliminarNodo(T n);
NodoGeneral<T>* buscar(T n);
int altura();
unsigned int tamanio();
void preOrden();
void postOrden();
void nivelOrden();
};

#endif