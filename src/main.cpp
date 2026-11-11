// src/main.cpp — prueba rápida de la clase Libro.
#include <iostream>
#include "libro.hpp"

int main() {
    Libro l(1, "El Quijote");
    l.prestar();
    std::cout << l.tipo() << " " << l.getCodigo() << " \"" << l.getTitulo() << "\""
              << (l.estaPrestado() ? " (prestado)" : " (disponible)")
              << " - multa por 4 dias: " << l.multa(4) << " EUR\n";
}
