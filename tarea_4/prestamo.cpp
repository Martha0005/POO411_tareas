#include "prestamo.h"

prestamo::prestamo(const std::string& codigoUsuario, const std::string& codigoMaterial)
    : codigoUsuario(codigoUsuario), codigoMaterial(codigoMaterial) {}

std::string prestamo::getCodigoUsuario() const {
    return codigoUsuario;
}

std::string prestamo::getCodigoMaterial() const {
    return codigoMaterial;
}

std::string prestamo::aTexto() const {
    return codigoUsuario + "|" + codigoMaterial;
}