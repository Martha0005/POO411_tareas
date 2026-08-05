// usuario.h
#ifndef USUARIO_H
#define USUARIO_H
#include <string>

class usuario {
private:
    std::string codigo;
    std::string nombre;

public:
    usuario(const std::string& codigo, const std::string& nombre);
    std::string getCodigo() const;
};
#endif