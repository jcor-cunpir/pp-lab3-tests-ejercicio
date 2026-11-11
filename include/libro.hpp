// include/libro.hpp — un libro de la biblioteca. Es la clase BASE: Novedad hereda de ella.
#pragma once
#include <string>

class Libro {
public:
    // Lanza std::invalid_argument si el código no es positivo o el título está vacío.
    Libro(int codigo, const std::string& titulo);
    virtual ~Libro() = default;                   // clase base: destructor virtual

    bool prestar();                               // false si ya estaba prestado
    void devolver();

    int getCodigo() const;
    std::string getTitulo() const;
    bool estaPrestado() const;

    // Multa por devolver el libro tarde: 0,50 EUR por cada día de retraso.
    // 0 días de retraso -> 0 EUR. Lanza std::invalid_argument si dias < 0.
    virtual double multa(int dias) const;
    virtual std::string tipo() const;             // "Libro"

private:
    int codigo_;
    std::string titulo_;
    bool prestado_;
};
