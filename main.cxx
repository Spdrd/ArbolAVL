#include "arboles.hxx"
int main() {
  ArbolAVL<int> arbol = ArbolAVL<int>(0);
  int a;
  while(true) {
    std::cout << "Ingrese un Numero: ";
    std::cin >> a;
    if(a == 0) 
      break; // Sale del bucle si el usuario ingresa 0
    arbol.insert(a);
    arbol.imprimirArbol();
  }
  NodoAVL<int> *aux = arbol.buscar(11);
  if(aux != NULL){
    std::cout << "Nodo no encontrado \n";
  }
  else{
    aux->imprimirArbol();
  }
  
  return 0;
}