#ifndef PRESTAMO_H
#define PRESTAMO_H

#include <string>

class prestamo {
private:
    std::string codigoUsuario;
    std::string codigoMaterial;

public:
    prestamo(const std::string& codigoUsuario, const std::string& codigoMaterial);

    std::string getCodigoUsuario() const;
    std::string getCodigoMaterial() const;
    std::string aTexto() const;
};

#endif