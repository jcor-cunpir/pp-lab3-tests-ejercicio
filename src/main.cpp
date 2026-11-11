// src/main.cpp — prueba rápida de Libro y Novedad, a través de punteros a la base.
#include <iostream>
#include <memory>
#include <vector>
#include "novedad.hpp"

int main() {
    std::vector<std::unique_ptr<Libro>> libros;
    libros.push_back(std::make_unique<Libro>(1, "El Quijote"));
    libros.push_back(std::make_unique<Novedad>(3, "Dune"));
    for (const auto& l : libros) {
        std::cout << l->tipo() << " " << l->getCodigo() << " \"" << l->getTitulo() << "\""
                  << " - multa por 7 dias: " << l->multa(7) << " EUR\n";
    }
}
