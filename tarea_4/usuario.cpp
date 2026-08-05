#include "usuario.h"

usuario::usuario(const std::string& codigo, const std::string& nombre)
    : codigo(codigo), nombre(nombre) {}

std::string usuario::getCodigo() const {
    return codigo;
}

std::string usuario::getNombre() const {
    return nombre;
}

std::string usuario::aTexto() const {
    return codigo + "|" + nombre;
}