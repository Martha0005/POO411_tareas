#ifndef MATERIAL_BIBLIOTECA_H
#define MATERIAL_BIBLIOTECA_H

#include <string>

class materialBiblioteca {
private:
    std::string codigo;
    std::string titulo;
    bool disponible;

public:
    materialBiblioteca(const std::string& codigo, const std::string& titulo, bool disponible = true);
    virtual ~materialBiblioteca() = default;

    std::string getCodigo() const;
    std::string getTitulo() const;
    bool isDisponible() const;
    void setDisponible(bool valor);

    // Métodos virtuales puros -> Hacen que la clase sea abstracta
    virtual std::string getTipo() const = 0;
    virtual std::string getResponsable() const = 0;
    virtual std::string aTexto() const = 0;
    virtual void mostrarInfo() const;
};

#endif