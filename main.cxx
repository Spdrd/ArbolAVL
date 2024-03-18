  #include "arboles.h"
  #include <chrono>
  int main() {
    auto start = std::chrono::high_resolution_clock::now();

      ArbolAVL<int> *arbol = new ArbolAVL<int>(10);
      int a = 1;
      while(true) {
          std::cout << "Ingrese un numero (0 para terminar): ";
          std::cin >> a;
          if(a == 0) break; // Sale del bucle si el usuario ingresa 0
          arbol->insertarDato(a);
      }
      std::cout << "PreOrden: ";
      arbol->preOrden();
      std::cout << std::endl << "Altura: ";
      a = arbol->altura();
      std::cout << a << std::endl;
  
      delete arbol; // No olvides liberar la memoria del árbol al final
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Tiempo de carga: " << duration.count() << " segundos\n";

    return 0;
  }
  