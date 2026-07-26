#include <iostream>
#include <string>
#include <vector>
#include <memory>

// ============================================================================
// 1. CLASE ESTUDIANTE
// ============================================================================
class Estudiante {
private:
    std::string nombre;
    std::string matricula;
    std::string sesion;

public:
    Estudiante() : nombre(""), matricula(""), sesion("") {}
    
    Estudiante(const std::string& nombre, const std::string& matricula, const std::string& sesion)
        : nombre(nombre), matricula(matricula), sesion(sesion) {}

    // Constructor de copia explícito con lista de inicialización
    Estudiante(const Estudiante& otro)
        : nombre(otro.nombre), matricula(otro.matricula), sesion(otro.sesion) {}

    std::string getNombre() const { return this->nombre; }
    std::string getMatricula() const { return this->matricula; }
    std::string getSesion() const { return this->sesion; }

    friend std::ostream& operator<<(std::ostream& os, const Estudiante& e) {
        os << e.nombre << " (" << e.matricula << ")";
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Estudiante& e) {
        std::cout << "Nombre estudiante: ";
        std::getline(is, e.nombre);
        std::cout << "Matricula: ";
        std::getline(is, e.matricula);
        std::cout << "Sesion: ";
        std::getline(is, e.sesion);
        return is;
    }
};

class Profesor {
private:
    std::string nombre;
    std::string codigo;

public:
    Profesor() : nombre(""), codigo("") {}
    
    Profesor(const std::string& nombre, const std::string& codigo)
        : nombre(nombre), codigo(codigo) {}

    // Constructor de copia explícito con lista de inicialización
    Profesor(const Profesor& otro)
        : nombre(otro.nombre), codigo(otro.codigo) {}

    std::string getNombre() const { return this->nombre; }
    std::string getCodigo() const { return this->codigo; }

    friend std::ostream& operator<<(std::ostream& os, const Profesor& p) {
        os << p.nombre << " (Cod: " << p.codigo << ")";
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Profesor& p) {
        std::cout << "Nombre profesor: ";
        std::getline(is, p.nombre);
        std::cout << "Codigo profesor: ";
        std::getline(is, p.codigo);
        return is;
    }
};

int main() {
    std::cout << "Paso 1: Clases base listas.\n";
    return 0;
}