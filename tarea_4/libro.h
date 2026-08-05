#ifndef LIBRO_H
#define LIBRO_H

#include "materialBiblioteca.h"

class libro : public materialBiblioteca {
private:
    std::string autor;

public:
    libro(const std::string& codigo, const std::string& titulo, const std::string& autor, bool disponible = true);

    std::string getTipo() const override;
    std::string getResponsable() const override;
    std::string aTexto() const override;
};

#endif