#include "libro.h"

libro::libro(const std::string& codigo, const std::string& titulo, const std::string& autor, bool disponible)
    : materialBiblioteca(codigo, titulo, disponible), autor(autor) {}

std::string libro::getTipo() const { return "Libro"; }
std::string libro::getResponsable() const { return autor; }
std::string libro::aTexto() const {
    return "LIBRO|" + getCodigo() + "|" + getTitulo() + "|" + autor + "|" + (isDisponible() ? "1" : "0");
}