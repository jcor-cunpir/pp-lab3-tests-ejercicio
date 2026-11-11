// src/novedad.cpp
#include "novedad.hpp"
#include <stdexcept>

Novedad::Novedad(int codigo, const std::string& titulo) : Libro(codigo, titulo) {}

double Novedad::multa(int dias) const {
    if (dias < 0) throw std::invalid_argument("Los dias de retraso no pueden ser negativos");
    double importe = dias * 1.0;
    if (dias > 7) {
        importe = importe + 5.0;                  // recargo
    }
    return importe;
}

std::string Novedad::tipo() const { return "Novedad"; }
