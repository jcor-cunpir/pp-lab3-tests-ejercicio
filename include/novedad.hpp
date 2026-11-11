// include/novedad.hpp — una novedad es un libro recién llegado: su multa es más alta.
#pragma once
#include "libro.hpp"

class Novedad : public Libro {
public:
    Novedad(int codigo, const std::string& titulo);

    // 1 EUR por cada día de retraso y, si el retraso es de 7 días o más (7 incluido),
    // un recargo fijo de 5 EUR. Lanza std::invalid_argument si dias < 0.
    double multa(int dias) const override;
    std::string tipo() const override;            // "Novedad"
};
