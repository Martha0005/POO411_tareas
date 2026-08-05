#include "sistemadebiblioteca.h"
#include "libro.h"
#include "revista.h"
#include <iostream>
#include <fstream>
#include <sstream>

sistemadebiblioteca::sistemadebiblioteca() {
    cargarDatos();
}

sistemadebiblioteca::~sistemadebiblioteca() {
    guardarDatos();
}

bool sistemadebiblioteca::existeCodigoMaterial(const std::string& codigo) const {
    for (const auto& mat : materiales) {
        if (mat->getCodigo() == codigo) return true;
    }
    return false;
}

bool sistemadebiblioteca::existeCodigoUsuario(const std::string& codigo) const {
    for (const auto& usr : usuarios) {
        if (usr.getCodigo() == codigo) return true;
    }
    return false;
}

int sistemadebiblioteca::contarPrestamosUsuario(const std::string& codigoUsuario) const {
    int contador = 0;
    for (const auto& p : prestamos) {
        if (p.getCodigoUsuario() == codigoUsuario) contador++;
    }
    return contador;
}

materialBiblioteca* sistemadebiblioteca::buscarMaterial(const std::string& codigo) {
    for (auto& mat : materiales) {
        if (mat->getCodigo() == codigo) return mat.get();
    }
    return nullptr;
}

void sistemadebiblioteca::registrarLibro() {
    std::string codigo, titulo, autor;
    std::cout << "Codigo del libro: ";
    std::getline(std::cin, codigo);

    if (existeCodigoMaterial(codigo)) {
        std::cout << "Error: Ya existe un material registrado con ese codigo.\n";
        return;
    }

    std::cout << "Titulo: ";
    std::getline(std::cin, titulo);
    std::cout << "Autor: ";
    std::getline(std::cin, autor);

    materiales.push_back(std::make_unique<libro>(codigo, titulo, autor));
    std::cout << "Libro registrado exitosamente.\n";
}

void sistemadebiblioteca::registrarRevista() {
    std::string codigo, titulo, editorial;
    std::cout << "Codigo de la revista: ";
    std::getline(std::cin, codigo);

    if (existeCodigoMaterial(codigo)) {
        std::cout << "Error: Ya existe un material registrado con ese codigo.\n";
        return;
    }

    std::cout << "Titulo: ";
    std::getline(std::cin, titulo);
    std::cout << "Editorial: ";
    std::getline(std::cin, editorial);

    materiales.push_back(std::make_unique<revista>(codigo, titulo, editorial));
    std::cout << "Revista registrada exitosamente.\n";
}

void sistemadebiblioteca::registrarUsuario() {
    std::string codigo, nombre;
    std::cout << "Codigo del usuario: ";
    std::getline(std::cin, codigo);

    if (existeCodigoUsuario(codigo)) {
        std::cout << "Error: Ya existe un usuario registrado con ese codigo.\n";
        return;
    }

    std::cout << "Nombre completo: ";
    std::getline(std::cin, nombre);

    usuarios.emplace_back(codigo, nombre);
    std::cout << "Usuario registrado exitosamente.\n";
}

void sistemadebiblioteca::prestarMaterial() {
    std::string codigoUsuario, codigoMaterial;
    std::cout << "Codigo del usuario: ";
    std::getline(std::cin, codigoUsuario);

    if (!existeCodigoUsuario(codigoUsuario)) {
        std::cout << "Error: Usuario no encontrado.\n";
        return;
    }

    if (contarPrestamosUsuario(codigoUsuario) >= 3) {
        std::cout << "Error: El usuario ya tiene el limite maximo de 3 prestamos activos.\n";
        return;
    }

    std::cout << "Codigo del material: ";
    std::getline(std::cin, codigoMaterial);

    materialBiblioteca* mat = buscarMaterial(codigoMaterial);
    if (!mat) {
        std::cout << "Error: Material no encontrado.\n";
        return;
    }

    if (!mat->isDisponible()) {
        std::cout << "Error: El material no esta disponible actualmente.\n";
        return;
    }

    mat->setDisponible(false);
    prestamos.emplace_back(codigoUsuario, codigoMaterial);
    std::cout << "Prestamo registrado exitosamente.\n";
}

void sistemadebiblioteca::devolverMaterial() {
    std::string codigoMaterial;
    std::cout << "Codigo del material a devolver: ";
    std::getline(std::cin, codigoMaterial);

    for (auto it = prestamos.begin(); it != prestamos.end(); ++it) {
        if (it->getCodigoMaterial() == codigoMaterial) {
            materialBiblioteca* mat = buscarMaterial(codigoMaterial);
            if (mat) {
                mat->setDisponible(true);
            }
            prestamos.erase(it);
            std::cout << "Material devuelto exitosamente.\n";
            return;
        }
    }

    std::cout << "Error: No existe un prestamo activo para ese material.\n";
}

void sistemadebiblioteca::mostrarMateriales() const {
    if (materiales.empty()) {
        std::cout << "No hay materiales registrados.\n";
        return;
    }

    std::cout << "\n--- Materiales ---\n";
    for (const auto& mat : materiales) {
        mat->mostrarInfo();
    }
}

void sistemadebiblioteca::guardarDatos() const {
    std::ofstream fileMat("materiales.txt");
    for (const auto& mat : materiales) {
        fileMat << mat->aTexto() << "\n";
    }

    std::ofstream fileUsr("usuarios.txt");
    for (const auto& usr : usuarios) {
        fileUsr << usr.aTexto() << "\n";
    }

    std::ofstream filePrest("prestamos.txt");
    for (const auto& p : prestamos) {
        filePrest << p.aTexto() << "\n";
    }
}

void sistemadebiblioteca::cargarDatos() {
    std::ifstream fileMat("materiales.txt");
    std::string linea;
    while (std::getline(fileMat, linea)) {
        if (linea.empty()) continue;
        std::stringstream ss(linea);
        std::string tipo, codigo, titulo, resp, dispStr;
        std::getline(ss, tipo, '|');
        std::getline(ss, codigo, '|');
        std::getline(ss, titulo, '|');
        std::getline(ss, resp, '|');
        std::getline(ss, dispStr, '|');

        bool disp = (dispStr == "1");

        if (tipo == "LIBRO") {
            materiales.push_back(std::make_unique<libro>(codigo, titulo, resp, disp));
        } else if (tipo == "REVISTA") {
            materiales.push_back(std::make_unique<revista>(codigo, titulo, resp, disp));
        }
    }

    std::ifstream fileUsr("usuarios.txt");
    while (std::getline(fileUsr, linea)) {
        if (linea.empty()) continue;
        std::stringstream ss(linea);
        std::string codigo, nombre;
        std::getline(ss, codigo, '|');
        std::getline(ss, nombre, '|');
        usuarios.emplace_back(codigo, nombre);
    }

    std::ifstream filePrest("prestamos.txt");
    while (std::getline(filePrest, linea)) {
        if (linea.empty()) continue;
        std::stringstream ss(linea);
        std::string codUsr, codMat;
        std::getline(ss, codUsr, '|');
        std::getline(ss, codMat, '|');
        prestamos.emplace_back(codUsr, codMat);
    }
}

void sistemadebiblioteca::iniciar() {
    int opcion = -1;
    while (opcion != 0) {
        std::cout << "\n=== Biblioteca ===\n";
        std::cout << "1. Registrar libro\n";
        std::cout << "2. Registrar revista\n";
        std::cout << "3. Registrar usuario\n";
        std::cout << "4. Prestar material\n";
        std::cout << "5. Devolver material\n";
        std::cout << "6. Mostrar materiales\n";
        std::cout << "0. Salir\n";
        std::cout << "Opcion: ";

        if (!(std::cin >> opcion)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Opcion no valida.\n";
            continue;
        }
        std::cin.ignore();

        switch (opcion) {
            case 1: registrarLibro(); break;
            case 2: registrarRevista(); break;
            case 3: registrarUsuario(); break;
            case 4: prestarMaterial(); break;
            case 5: devolverMaterial(); break;
            case 6: mostrarMateriales(); break;
            case 0: std::cout << "Guardando datos y saliendo del sistema...\n"; break;
            default: std::cout << "Opcion no valida.\n"; break;
        }
    }
}