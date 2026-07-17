#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class Estudiante {
public:
    string nombre, matricula, sesion;

    Estudiante(string n, string m, string s) : nombre(n), matricula(m), sesion(s) {}
    
    Estudiante(const Estudiante& e) : nombre(e.nombre), matricula(e.matricula), sesion(e.sesion) {}
};

class Profesor {
public:
    string nombre, codigo;

    Profesor(string n, string c) : nombre(n), codigo(c) {}
    
    Profesor(const Profesor& p) : nombre(p.nombre), codigo(p.codigo) {}
};

class Materia {
public:
    string nombre, codigo;
    int creditos;

    Materia(string n, string c, int cr) : nombre(n), codigo(c), creditos(cr) {}
    
    Materia(const Materia& m) : nombre(m.nombre), codigo(m.codigo), creditos(m.creditos) {}
};

class Calificacion {
public:
    shared_ptr<Estudiante> est;
    shared_ptr<Profesor> prof;
    shared_ptr<Materia> mat;
    double nota;

    Calificacion(shared_ptr<Estudiante> e, shared_ptr<Profesor> p, shared_ptr<Materia> m, double n)
        : est(e), prof(p), mat(m), nota(n) {}
};

class SistemaRegistro {
public:
    vector<shared_ptr<Estudiante>> estudiantes;
    vector<shared_ptr<Profesor>> profesores;
    vector<shared_ptr<Materia>> materias;
    vector<Calificacion> calificaciones;

    void registrarCalificacion(int eIdx, int pIdx, int mIdx, double nota) {
        calificaciones.push_back(Calificacion(estudiantes[eIdx], profesores[pIdx], materias[mIdx], nota));
    }

    void mostrarReporte() {
        cout << "\n--- REPORTE GENERAL DE NOTAS ---\n";
        if (calificaciones.empty()) {
            cout << "No hay calificaciones registradas.\n";
            return;
        }
        for (const auto& c : calificaciones) {
            cout << "Estudiante: " << c.est->nombre << " (" << c.est->matricula << ")\n"
                 << "Materia:    " << c.mat->nombre << "\n"
                 << "Profesor:   " << c.prof->nombre << "\n"
                 << "Nota:       " << c.nota << "\n--------------------------------\n";
        }
    }
};


int main() {
    SistemaRegistro sistema;
    
    sistema.estudiantes.push_back(make_shared<Estudiante>("Martha Alvarez", "2026-0001", "POO411"));
    sistema.profesores.push_back(make_shared<Profesor>("Dr. Kirino", "PROF099"));
    sistema.materias.push_back(make_shared<Materia>("Programacion Orientada a Objetos", "POO411", 4));

    int opcion;
    do {
        cout << "\n=== MENU REGISTRO ===\n"
             << "1. Registrar Estudiante\n"
             << "2. Registrar Profesor\n"
             << "3. Registrar Materia\n"
             << "4. Registrar Calificacion\n"
             << "5. Mostrar Reporte\n"
             << "6. Salir\n"
             << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore(); 

        if (opcion == 1) {
            string n, m, s;
            cout << "Nombre: "; getline(cin, n);
            cout << "Matricula: "; getline(cin, m);
            cout << "Sesion: "; getline(cin, s);
            sistema.estudiantes.push_back(make_shared<Estudiante>(n, m, s));
        } 
        else if (opcion == 2) {
            string n, c;
            cout << "Nombre: "; getline(cin, n);
            cout << "Codigo: "; getline(cin, c);
            sistema.profesores.push_back(make_shared<Profesor>(n, c));
        }
        else if (opcion == 3) {
            string n, c; int cr;
            cout << "Nombre Materia: "; getline(cin, n);
            cout << "Codigo Materia: "; getline(cin, c);
            cout << "Creditos: "; cin >> cr;
            sistema.materias.push_back(make_shared<Materia>(n, c, cr));
        }
        else if (opcion == 4) {
            if (sistema.estudiantes.empty() || sistema.profesores.empty() || sistema.materias.empty()) {
                cout << "Error: Debe registrar primero estudiante, profesor y materia.\n";
                continue;
            }
            
            for (size_t i = 0; i < sistema.estudiantes.size(); i++) 
                cout << i + 1 << ". " << sistema.estudiantes[i]->nombre << "\n";
            int e; cout << "Seleccione Estudiante (numero): "; cin >> e;

            for (size_t i = 0; i < sistema.profesores.size(); i++) 
                cout << i + 1 << ". " << sistema.profesores[i]->nombre << "\n";
            int p; cout << "Seleccione Profesor (numero): "; cin >> p;

            for (size_t i = 0; i < sistema.materias.size(); i++) 
                cout << i + 1 << ". " << sistema.materias[i]->nombre << "\n";
            int m; cout << "Seleccione Materia (numero): "; cin >> m;

            double nota; 
            cout << "Calificacion: "; cin >> nota;
            
            sistema.registrarCalificacion(e - 1, p - 1, m - 1, nota);
        }
        else if (opcion == 5) {
            sistema.mostrarReporte();
        }
    } while (opcion != 6);

    cout << "Saliendo del sistema...\n";
    return 0;
}