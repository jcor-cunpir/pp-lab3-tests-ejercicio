// src/libro.cpp
#include "libro.hpp"
#include <stdexcept>

Libro::Libro(int codigo, const std::string& titulo)
    : codigo_(codigo), titulo_(titulo), prestado_(false) {
    if (codigo <= 0) throw std::invalid_argument("El codigo del libro debe ser positivo");
    if (titulo.empty()) throw std::invalid_argument("El titulo no puede estar vacio");
}

bool Libro::prestar() {
    prestado_ = true;
    return true;
}

void Libro::devolver() { prestado_ = false; }

int Libro::getCodigo() const { return codigo_; }
std::string Libro::getTitulo() const { return titulo_; }
bool Libro::estaPrestado() const { return prestado_; }

double Libro::multa(int dias) const {
    if (dias < 0) throw std::invalid_argument("Los dias de retraso no pueden ser negativos");
    return dias * 0.5;
}

std::string Libro::tipo() const { return "Libro"; }
