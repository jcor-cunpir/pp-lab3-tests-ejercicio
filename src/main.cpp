// src/main.cpp — carga la biblioteca (o crea una de ejemplo), presta el primer libro disponible y guarda.
#include <iostream>
#include "almacen.hpp"
#include "novedad.hpp"

int main() {
    const std::string ruta = "biblioteca.txt";
    Biblioteca biblioteca;
    try {
        biblioteca = cargarBiblioteca(ruta);
        std::cout << "Cargados " << biblioteca.total() << " libros de " << ruta << "\n";
    } catch (const FicheroException& e) {
        std::cout << "Aviso: " << e.what() << ". Empiezo con una biblioteca de ejemplo.\n";
        biblioteca.anadir(std::make_unique<Libro>(1, "El Quijote"));
        biblioteca.anadir(std::make_unique<Libro>(2, "La Regenta"));
        biblioteca.anadir(std::make_unique<Novedad>(3, "Dune"));
    }

    for (const auto& l : biblioteca.libros()) {
        std::cout << "  " << l->tipo() << " " << l->getCodigo() << " \"" << l->getTitulo() << "\""
                  << (l->estaPrestado() ? " (prestado)" : " (disponible)")
                  << " - multa por 7 dias: " << l->multa(7) << " EUR\n";
    }

    bool prestado = false;
    for (const auto& l : biblioteca.libros()) {
        if (!l->estaPrestado()) {
            biblioteca.prestar(l->getCodigo());
            std::cout << "Prestado el " << l->getCodigo() << "\n";
            prestado = true;
            break;
        }
    }
    if (!prestado) std::cout << "No quedan libros disponibles\n";

    guardarBiblioteca(biblioteca, ruta);
    std::cout << "Disponibles: " << biblioteca.disponibles() << " de " << biblioteca.total() << "\n";
}
