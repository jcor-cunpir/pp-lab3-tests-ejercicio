// src/main.cpp — una biblioteca de ejemplo: presta el primer libro.
#include <iostream>
#include "biblioteca.hpp"
#include "novedad.hpp"

int main() {
    Biblioteca biblioteca;
    biblioteca.anadir(std::make_unique<Libro>(1, "El Quijote"));
    biblioteca.anadir(std::make_unique<Libro>(2, "La Regenta"));
    biblioteca.anadir(std::make_unique<Novedad>(3, "Dune"));

    for (const auto& l : biblioteca.libros()) {
        std::cout << "  " << l->tipo() << " " << l->getCodigo() << " \"" << l->getTitulo() << "\"\n";
    }
    biblioteca.prestar(1);
    std::cout << "Disponibles: " << biblioteca.disponibles() << " de " << biblioteca.total() << "\n";
}
