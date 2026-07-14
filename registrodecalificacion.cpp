#include <iostream>
#include <string>
#include <vector>
#include <memory> 
#include <fstream>
#include <sstream>
#include <iomanip>

class Estudiante {
    std::string nombre, matricula, sesion;
public:
    Estudiante() { this->nombre = this->matricula = this->sesion = ""; }
    Estudiante(std::string n, std::string m, std::string s) { this->nombre = n; this->matricula = m; this->sesion = s; }
    std::string getNombre() const { return this->nombre; }
    std::string getMatricula() const { return this->matricula; }
    std::string getSesion() const { return this->sesion; }
};

class Profesor {
    std::string nombre, codigo;
public:
    Profesor() { this->nombre = this->codigo = ""; }
    Profesor(std::string n, std::string c) { this->nombre = n; this->codigo = c; }
    std::string getNombre() const { return this->nombre; }
    std::string getCodigo() const { return this->codigo; }
};

class Materia {
    std::string nombre, codigo;
    int creditos;
public:
    Materia() { this->nombre = this->codigo = ""; this->creditos = 0; }
    Materia(std::string n, std::string c, int cr) { this->nombre = n; this->codigo = c; this->creditos = cr; }
    std::string getNombre() const { return this->nombre; }
    std::string getCodigo() const { return this->codigo; }
    int getCreditos() const { return this->creditos; }
};

class Calificacion {
    std::shared_ptr<Estudiante> estudiante; 
    std::shared_ptr<Profesor> profesor;     
    std::shared_ptr<Materia> materia;       
    double nota;
public:
    Calificacion(std::shared_ptr<Estudiante> e, std::shared_ptr<Profesor> p, std::shared_ptr<Materia> m, double n) {
        this->estudiante = e; this->profesor = p; this->materia = m; this->nota = n;
    }
    std::shared_ptr<Estudiante> getEstudiante() const { return this->estudiante; }
    std::shared_ptr<Profesor> getProfesorCorrected() const { return this->profesor; } 
    std::shared_ptr<Materia> getMateria() const { return this->materia; }
    double getNota() const { return this->nota; }
};

class Sistema {
    std::vector<std::shared_ptr<Estudiante>> estudiantes;
    std::vector<std::shared_ptr<Profesor>> profesores;
    std::vector<std::shared_ptr<Materia>> materias;
    std::vector<std::shared_ptr<Calificacion>> calificaciones;

    std::string leerCadena(const std::string& msg) {
        std::string ent;
        while (std::cout << msg && std::getline(std::cin, ent)) {
            if (!ent.empty() && ent.find('~') == std::string::npos) return ent;
            std::cout << "Entrada invalida (No vacia ni con '~').\n";
        }
        return "";
    }

    double leerNumero(const std::string& msg, double min, double max) {
        double val;
        while (std::cout << msg) {
            if (std::cin >> val && val >= min && val <= max) { std::cin.ignore(10000, '\n'); return val; }
            std::cout << "Valor invalido. Reintente.\n";
            std::cin.clear(); std::cin.ignore(10000, '\n');
        }
        return min;
    }

    void registrarEstudiante() {
        this->estudiantes.push_back(std::make_shared<Estudiante>(leerCadena("Nombre: "), leerCadena("Matricula: "), leerCadena("Sesion: ")));
        std::cout << "Estudiante registrado con exito.\n";
    }
    void registrarProfesor() {
        this->profesores.push_back(std::make_shared<Profesor>(leerCadena("Nombre: "), leerCadena("Codigo: ")));
        std::cout << "Profesor registrado con exito.\n";
    }
    void registrarMateria() {
        this->materias.push_back(std::make_shared<Materia>(leerCadena("Nombre: "), leerCadena("Codigo: "), leerNumero("Creditos: ", 1, 100)));
        std::cout << "Materia registrada con exito.\n";
    }

    void registrarCalificacion() {
        if (this->estudiantes.empty() || this->profesores.empty() || this->materias.empty()) {
            std::cout << "Error: Debe registrar primero estudiante, profesor y materia.\n"; return;
        }
        std::cout << "\n--- Estudiantes ---\n";
        for (size_t i = 0; i < this->estudiantes.size(); ++i) std::cout << i+1 << ". [" << this->estudiantes[i]->getMatricula() << "] " << this->estudiantes[i]->getNombre() << "\n";
        int idxE = leerNumero("Seleccione: ", 1, this->estudiantes.size()) - 1;

        std::cout << "\n--- Profesores ---\n";
        for (size_t i = 0; i < this->profesores.size(); ++i) std::cout << i+1 << ". [" << this->profesores[i]->getCodigo() << "] " << this->profesores[i]->getNombre() << "\n";
        int idxP = leerNumero("Seleccione: ", 1, this->profesores.size()) - 1;

        std::cout << "\n--- Materias ---\n";
        for (size_t i = 0; i < this->materias.size(); ++i) std::cout << i+1 << ". [" << this->materias[i]->getCodigo() << "] " << this->materias[i]->getNombre() << "\n";
        int idxM = leerNumero("Seleccione: ", 1, this->materias.size()) - 1;

        this->calificaciones.push_back(std::make_shared<Calificacion>(this->estudiantes[idxE], this->profesores[idxP], this->materias[idxM], leerNumero("Nota (0-100): ", 0, 100)));
        std::cout << "Calificacion registrada con exito.\n";
    }

    void verEstudiantes() const {
        std::cout << "\n" << std::left << std::setw(25) << "Nombre Completo" << std::setw(18) << "Matricula" << std::setw(15) << "Sesion" << "\n---\n";
        for (const auto& e : this->estudiantes) std::cout << std::left << std::setw(25) << e->getNombre() << std::setw(18) << e->getMatricula() << std::setw(15) << e->getSesion() << "\n";
    }
    void verProfesores() const {
        std::cout << "\n" << std::left << std::setw(30) << "Nombre Completo" << std::setw(20) << "Codigo Profesor" << "\n---\n";
        for (const auto& p : this->profesores) std::cout << std::left << std::setw(30) << p->getNombre() << std::setw(20) << p->getCodigo() << "\n";
    }
    void verMaterias() const {
        std::cout << "\n" << std::left << std::setw(25) << "Materia" << std::setw(18) << "Codigo Materia" << std::setw(15) << "Creditos" << "\n---\n";
        for (const auto& m : this->materias) std::cout << std::left << std::setw(25) << m->getNombre() << std::setw(18) << m->getCodigo() << std::setw(15) << m->getCreditos() << "\n";
    }
    void verCalificaciones() const {
        std::cout << "\n" << std::left << std::setw(20) << "Estudiante" << std::setw(20) << "Profesor" << std::setw(20) << "Materia" << std::setw(10) << "Nota" << "\n---\n";
        for (const auto& c : this->calificaciones) std::cout << std::left << std::setw(20) << c->getEstudiante()->getNombre() << std::setw(20) << c->getProfesorCorrected()->getNombre() << std::setw(20) << c->getMateria()->getNombre() << std::setw(10) << c->getNota() << "\n";
    }

    void guardarDatos() const {
        std::ofstream fEst("estudiantes.txt"), fProf("profesores.txt"), fMat("materias.txt"), fCal("calificaciones.txt");
        for (const auto& e : this->estudiantes) fEst << e->getNombre() << "~" << e->getMatricula() << "~" << e->getSesion() << "\n";
        for (const auto& p : this->profesores) fProf << p->getNombre() << "~" << p->getCodigo() << "\n";
        for (const auto& m : this->materias) fMat << m->getNombre() << "~" << m->getCodigo() << "~" << m->getCreditos() << "\n";
        for (const auto& c : this->calificaciones) fCal << c->getEstudiante()->getMatricula() << "~" << c->getProfesorCorrected()->getCodigo() << "~" << c->getMateria()->getCodigo() << "~" << c->getNota() << "\n";
    }

    void cargarlosDatos() {
        std::ifstream fEst("estudiantes.txt"), fProf("profesores.txt"), fMat("materias.txt"), fCal("calificaciones.txt");
        std::string l, nom, mat, ses, cod, credStr, matEst, codProf, codMat, notaStr;
        while (std::getline(fEst, l)) if (!l.empty()) { std::stringstream ss(l); std::getline(ss, nom, '~'); std::getline(ss, mat, '~'); std::getline(ss, ses, '~'); this->estudiantes.push_back(std::make_shared<Estudiante>(nom, mat, ses)); }
        while (std::getline(fProf, l)) if (!l.empty()) { std::stringstream ss(l); std::getline(ss, nom, '~'); std::getline(ss, cod, '~'); this->profesores.push_back(std::make_shared<Profesor>(nom, cod)); }
        while (std::getline(fMat, l)) if (!l.empty()) { std::stringstream ss(l); std::getline(ss, nom, '~'); std::getline(ss, cod, '~'); std::getline(ss, credStr, '~'); this->materias.push_back(std::make_shared<Materia>(nom, cod, std::stoi(credStr))); }
        while (std::getline(fCal, l)) if (!l.empty()) {
            std::stringstream ss(l); std::getline(ss, matEst, '~'); std::getline(ss, codProf, '~'); std::getline(ss, codMat, '~'); std::getline(ss, notaStr, '~');
            std::shared_ptr<Estudiante> ePtr = nullptr; std::shared_ptr<Profesor> pPtr = nullptr; std::shared_ptr<Materia> mPtr = nullptr;
            for (const auto& e : this->estudiantes) if (e->getMatricula() == matEst) { ePtr = e; break; }
            for (const auto& p : this->profesores) if (p->getCodigo() == codProf) { pPtr = p; break; }
            for (const auto& m : this->materias) if (m->getCodigo() == codMat) { mPtr = m; break; }
            if (ePtr && pPtr && mPtr) this->calificaciones.push_back(std::make_shared<Calificacion>(ePtr, pPtr, mPtr, std::stod(notaStr)));
        }
    }

public:
    void ejecutar() {
        this->cargarlosDatos();
        int op = 0;
        do {
            std::cout << "\n=== SISTEMA DE REGISTRO ===\n1. Registrar estudiante\n2. Registrar profesor\n3. Registrar materia\n4. Registrar calificacion\n5. Ver estudiantes\n6. Ver profesores\n7. Ver materias\n8. Ver calificaciones\n9. Salir\nSeleccione: ";
            if (!(std::cin >> op)) { std::cout << "Invalido.\n"; std::cin.clear(); std::cin.ignore(10000, '\n'); continue; }
            std::cin.ignore(10000, '\n');
            switch (op) {
                case 1: this->registrarEstudiante(); break; case 2: this->registrarProfesor(); break; case 3: this->registrarMateria(); break; case 4: this->registrarCalificacion(); break;
                case 5: this->verEstudiantes(); break; case 6: this->verProfesores(); break; case 7: this->verMaterias(); break; case 8: this->verCalificaciones(); break;
                case 9: this->guardarDatos(); std::cout << "Datos guardados.\n"; break;
                default: std::cout << "Fuera de rango.\n";
            }
        } while (op != 9);
    }
};

int main() {
    Sistema sistema;
    sistema.ejecutar();
    return 0;
}