#ifndef REVISTA_H
#define REVISTA_H

#include "materialBiblioteca.h"

class revista : public materialBiblioteca {
private:
    std::string editorial;

public:
    revista(const std::string& codigo, const std::string& titulo, const std::string& editorial, bool disponible = true);

    std::string getTipo() const override;
    std::string getResponsable() const override;
    std::string aTexto() const override;
};

#endif