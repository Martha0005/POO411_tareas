#include "revista.h"

revista::revista(const std::string& codigo, const std::string& titulo, const std::string& editorial, bool disponible)
    : materialBiblioteca(codigo, titulo, disponible), editorial(editorial) {}

std::string revista::getTipo() const { return "Revista"; }
std::string revista::getResponsable() const { return editorial; }
std::string revista::aTexto() const {
    return "REVISTA|" + getCodigo() + "|" + getTitulo() + "|" + editorial + "|" + (isDisponible() ? "1" : "0");
}