#include <iostream>
#include <string>
#include <vector>
#include <memory>

class Estudiante {
private:
    std::string nombre;
    std::string matricula;
    std::string sesion;

public:
    Estudiante() : nombre(""), matricula(""), sesion("") {}
    
    Estudiante(const std::string& nombre, const std::string& matricula, const std::string& sesion)
        : nombre(nombre), matricula(matricula), sesion(sesion) {}

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

class Materia {
private:
    std::string nombre;
    std::string codigo;
    int creditos;

public:
    Materia() : nombre(""), codigo(""), creditos(0) {}
    
    Materia(const std::string& nombre, const std::string& codigo, int creditos)
        : nombre(nombre), codigo(codigo), creditos(creditos) {}

    Materia(const Materia& otro)
        : nombre(otro.nombre), codigo(otro.codigo), creditos(otro.creditos) {}

    std::string getNombre() const { return this->nombre; }
    std::string getCodigo() const { return this->codigo; }
    int getCreditos() const { return this->creditos; }
};

class Calificacion {
private:
    std::shared_ptr<Estudiante> estudiante;
    std::shared_ptr<Profesor> profesor;
    std::shared_ptr<Materia> materia;
    double nota;

public:
    Calificacion(std::shared_ptr<Estudiante> estudiante, std::shared_ptr<Profesor> profesor, std::shared_ptr<Materia> materia, double nota)
        : estudiante(estudiante), profesor(profesor), materia(materia), nota(nota) {}

    Calificacion(const Calificacion& otra)
        : estudiante(otra.estudiante), profesor(otra.profesor), materia(otra.materia), nota(otra.nota) {}

    std::shared_ptr<Estudiante> getEstudiante() const { return this->estudiante; }
    std::shared_ptr<Profesor> getProfesor() const { return this->profesor; }
    std::shared_ptr<Materia> getMateria() const { return this->materia; }
    double getNota() const { return this->nota; }
};

int main() {
    std::cout << "Paso 2: Agregadas Materias y Calificaciones.\n";
    return 0;
}