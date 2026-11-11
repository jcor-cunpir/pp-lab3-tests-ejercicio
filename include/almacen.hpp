// include/almacen.hpp — guardar y cargar la biblioteca en un fichero de texto.
// Formato: un libro por línea, con los campos separados por ';'
//     tipo;codigo;titulo;prestado          por ejemplo:   Novedad;3;Dune;1
#pragma once
#include <stdexcept>
#include <string>
#include "biblioteca.hpp"

// Error al leer o escribir el fichero: no se puede abrir, una línea mal escrita...
class FicheroException : public std::runtime_error {
public:
    explicit FicheroException(const std::string& msg) : std::runtime_error(msg) {}
};

void guardarBiblioteca(const Biblioteca& biblioteca, const std::string& ruta);   // lanza FicheroException
Biblioteca cargarBiblioteca(const std::string& ruta);                             // lanza FicheroException
