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
  while(true){
    std::cout << "Numero a eliminar: ";
    std::cin >> a;
    arbol.erase(a);
    arbol.imprimirArbol();
  }
  return 0;
}