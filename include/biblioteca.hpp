// include/biblioteca.hpp — la biblioteca guarda sus libros (normales y novedades) con unique_ptr.
#pragma once
#include <cstddef>
#include <memory>
#include <vector>
#include "libro.hpp"

class Biblioteca {
public:
    // Lanza std::invalid_argument si ya hay un libro con ese código.
    void anadir(std::unique_ptr<Libro> libro);

    // Devuelve el libro con ese código, o nullptr si no existe.
    Libro* buscar(int codigo) const;

    // false si ya estaba prestado. Lanza std::out_of_range si no existe.
    bool prestar(int codigo);

    std::size_t total() const;
    int disponibles() const;                      // los que no están prestados
    const std::vector<std::unique_ptr<Libro>>& libros() const;

private:
    std::vector<std::unique_ptr<Libro>> libros_;
    // Regla del cero: no hace falta escribir destructor, copia ni movimiento.
};
