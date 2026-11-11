// tests/test_libro.cpp — PRUEBAS UNITARIAS de Libro (CAJA NEGRA).
// De momento solo hay UN test de ejemplo. Vuestro trabajo: escribir el resto copiando
// y adaptando los de tests/test_habitacion.cpp del repositorio de REFERENCIA (pp-lab3-tests-referencia).
//
// Cada test sigue tres pasos: PREPARAR (crear objetos), ACTUAR (llamar al método)
// y COMPROBAR (EXPECT_...).
#include <gtest/gtest.h>
#include <stdexcept>
#include "libro.hpp"

TEST(LibroTest, ConstructorGuardaLosDatos) {
    Libro l(1, "El Quijote");                     // PREPARAR
    EXPECT_EQ(l.getCodigo(), 1);                  // COMPROBAR
    EXPECT_EQ(l.getTitulo(), "El Quijote");
    EXPECT_FALSE(l.estaPrestado());               // un libro nuevo está disponible
}

// >>> AQUÍ <<<  Vuestros tests de Libro (guía, paso 4).
