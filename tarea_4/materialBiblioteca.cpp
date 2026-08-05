#include "materialBiblioteca.h"
#include <iostream>

materialBiblioteca::materialBiblioteca(const std::string& codigo, const std::string& titulo, bool disponible)
    : codigo(codigo), titulo(titulo), disponible(disponible) {}

std::string materialBiblioteca::getCodigo() const { return codigo; }
std::string materialBiblioteca::getTitulo() const { return titulo; }
bool materialBiblioteca::isDisponible() const { return disponible; }
void materialBiblioteca::setDisponible(bool valor) { disponible = valor; }

void materialBiblioteca::mostrarInfo() const {
    std::cout << getTipo() << ": " << codigo << " - " << titulo 
              << " - " << getResponsable() << " - "
              << (disponible ? "Disponible" : "Prestado") << '\n';
}