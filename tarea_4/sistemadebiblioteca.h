#ifndef SISTEMA_BIBLIOTECA_H
#define SISTEMA_BIBLIOTECA_H

#include <vector>
#include <memory>
#include <string>
#include "materialBiblioteca.h"
#include "usuario.h"
#include "prestamo.h"

class sistemaBiblioteca {
private:
    std::vector<usuario> usuarios;
    std::vector<prestamo> prestamos;
    std::vector<std::unique_ptr<materialBiblioteca>> materiales; // <- Punteros inteligentes

    // Métodos auxiliares privados
    bool existeCodigoMaterial(const std::string& codigo) const;
    bool existeCodigoUsuario(const std::string& codigo) const;
    int contarPrestamosUsuario(const std::string& codigoUsuario) const;
    materialBiblioteca* buscarMaterial(const std::string& codigo);

    void guardarDatos() const;
    void cargarDatos();

public:
    sistemaBiblioteca();
    ~sistemaBiblioteca();

    void iniciar();
    void registrarLibro();
    void registrarRevista();
    void registrarUsuario();
    void prestarMaterial();
    void devolverMaterial();
    void mostrarMateriales() const;
};

#endif