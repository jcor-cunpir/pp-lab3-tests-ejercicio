// src/biblioteca.cpp
#include "biblioteca.hpp"
#include <stdexcept>
#include <string>

void Biblioteca::anadir(std::unique_ptr<Libro> libro) {
    libros_.push_back(std::move(libro));
}

Libro* Biblioteca::buscar(int codigo) const {
    for (const auto& l : libros_) {
        if (l->getCodigo() == codigo) return l.get();
    }
    return nullptr;
}

bool Biblioteca::prestar(int codigo) {
    Libro* l = buscar(codigo);
    if (l == nullptr) throw std::out_of_range("No existe el libro " + std::to_string(codigo));
    return l->prestar();
}

std::size_t Biblioteca::total() const { return libros_.size(); }

int Biblioteca::disponibles() const {
    int n = 0;
    for (const auto& l : libros_) {
        if (!l->estaPrestado()) n++;
    }
    return n;
}

const std::vector<std::unique_ptr<Libro>>& Biblioteca::libros() const { return libros_; }
