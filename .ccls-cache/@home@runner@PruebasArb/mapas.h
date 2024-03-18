#ifndef BIBLIO_H
#define BIBLIO_H

#include<deque>
#include <iostream>

template <class T>
class NodoGeneral{
protected:
T dato;
std::deque<NodoGeneral<T>*> desc;

public:
NodoGeneral(){
  std::cout<<"AA\n";
  this->desc.clear();
}
NodoGeneral(T dato){
  this->dato = dato;
}
T getDato();
};

#endif