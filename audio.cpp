#include <iostream>
#include <string>
#include <vector>
#include <memory>

class Audio {
protected:
    std::string titulo;
    std::string autor;

public:
    Audio(const std::string &titulo, const std::string &autor)
        : titulo(titulo), autor(autor) {}

    virtual ~Audio() = default; 
    virtual void mostrar() const = 0;
};

class Cancion : public Audio {
public:
    Cancion(const std::string &titulo, const std::string &artista)
        : Audio(titulo, artista) {}

    void mostrar() const override {
        std::cout << "Cancion: " << titulo << " - Artista: " << autor << '\n';
    }
};

class Podcast : public Audio {
public:
    Podcast(const std::string &titulo, const std::string &presentador)
        : Audio(titulo, presentador) {}

    void mostrar() const override {
        std::cout << "Podcast: " << titulo << " - Presentador: " << autor << '\n';
    }
};


void registrarCancion(std::vector<std::unique_ptr<Audio>> &lista) {
    std::string titulo, artista;

    std::cout << "Titulo de la cancion: ";
    std::getline(std::cin, titulo);

    std::cout << "Artista: ";
    std::getline(std::cin, artista);

    lista.push_back(std::make_unique<Cancion>(titulo, artista));
    std::cout << "Cancion registrada.\n";
}

void registrarPodcast(std::vector<std::unique_ptr<Audio>> &lista) {
    std::string titulo, presentador;

    std::cout << "Titulo del podcast: ";
    std::getline(std::cin, titulo);

    std::cout << "Presentador: ";
    std::getline(std::cin, presentador);

    lista.push_back(std::make_unique<Podcast>(titulo, presentador));
    std::cout << "Podcast registrado.\n";
}

void mostrarAudios(const std::vector<std::unique_ptr<Audio>> &lista) {
    if (lista.empty()) {
        std::cout << "No hay audios registrados.\n";
        return;
    }

    std::cout << "\n--- Lista de audios ---\n";
    for (const auto &audio : lista) {
        audio->mostrar(); 
    }
}

int main() {
    std::vector<std::unique_ptr<Audio>> lista;
    int opcion = -1;

    while (opcion != 0) {
        std::cout << "\n=== Registro de audios ===\n";
        std::cout << "1. Registrar cancion\n";
        std::cout << "2. Registrar podcast\n";
        std::cout << "3. Mostrar audios\n";
        std::cout << "0. Salir\n";
        std::cout << "Opcion: ";

        std::cin >> opcion;
        std::cin.ignore(); 
        if (opcion == 1) {
            registrarCancion(lista);
        } else if (opcion == 2) {
            registrarPodcast(lista);
        } else if (opcion == 3) {
            mostrarAudios(lista);
        } else if (opcion != 0) {
            std::cout << "Opcion no valida.\n";
        }
    }

    return 0;
}