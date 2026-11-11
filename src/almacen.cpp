// src/almacen.cpp — guardar y cargar con <fstream>.
#include "almacen.hpp"
#include <fstream>
#include <sstream>
#include "novedad.hpp"

void guardarBiblioteca(const Biblioteca& biblioteca, const std::string& ruta) {
    std::ofstream f(ruta);                                   // si ya existe, lo SOBRESCRIBE
    if (!f.is_open()) throw FicheroException("No se puede escribir en " + ruta);
    for (const auto& l : biblioteca.libros()) {
        f << l->tipo() << ';' << l->getCodigo() << ';' << l->getTitulo() << ';'
          << l->estaPrestado() << '\n';
    }
}

Biblioteca cargarBiblioteca(const std::string& ruta) {
    std::ifstream f(ruta);
    if (!f.is_open()) throw FicheroException("No se puede abrir " + ruta);

    Biblioteca biblioteca;
    std::string linea;
    int numLinea = 0;
    while (std::getline(f, linea)) {
        numLinea++;
        if (linea.empty()) continue;
        std::stringstream ss(linea);                         // trocear la línea por los ';'
        std::string tipo, codigo, titulo, prestado;
        std::getline(ss, tipo, ';');
        std::getline(ss, codigo, ';');
        std::getline(ss, titulo, ';');
        std::getline(ss, prestado, ';');
        try {
            std::unique_ptr<Libro> l;
            if (tipo == "novedad") {
                l = std::make_unique<Novedad>(std::stoi(codigo), titulo);
            } else {
                l = std::make_unique<Libro>(std::stoi(codigo), titulo);
            }
            if (prestado == "1") l->prestar();
            biblioteca.anadir(std::move(l));
        } catch (const std::invalid_argument&) {   // stoi sin número, código <= 0, título vacío...
            throw FicheroException(ruta + ", linea " + std::to_string(numLinea) + ": formato incorrecto");
        }
    }
    return biblioteca;
}
