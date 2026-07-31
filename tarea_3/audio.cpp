#include <iostream>
#include <string>
#include <vector>

/*---------------------------------
Práctica: registro de audios

Convierta el programa entregado a programación orientada a objetos.

Debe utilizar herencia y polimorfismo para representar canciones y podcasts,
cada una en su propia clase. Todos los objetos deben guardarse en una sola
lista.

Cada clase debe estar separada en sus archivos `.h` y `.cpp`.

El programa final debe conservar el comportamiento del programa original.

--------------------------------------*/

struct Audio {
  int tipo;
  std::string titulo;
  std::string autor;
};

void registrarCancion(std::vector<Audio> &lista) {
  Audio audio;
  audio.tipo = 1;

  std::cout << "Titulo de la cancion: ";
  std::getline(std::cin, audio.titulo);

  std::cout << "Artista: ";
  std::getline(std::cin, audio.autor);

  lista.push_back(audio);
  std::cout << "Cancion registrada.\n";
}

void registrarPodcast(std::vector<Audio> &lista) {
  Audio audio;
  audio.tipo = 2;

  std::cout << "Titulo del podcast: ";
  std::getline(std::cin, audio.titulo);

  std::cout << "Presentador: ";
  std::getline(std::cin, audio.autor);

  lista.push_back(audio);
  std::cout << "Podcast registrado.\n";
}

void mostrarAudios(const std::vector<Audio> &lista) {
  if (lista.empty()) {
    std::cout << "No hay audios registrados.\n";
    return;
  }

  std::cout << "\n--- Lista de audios ---\n";

  for (const Audio &audio : lista) {
    if (audio.tipo == 1) {
      std::cout << "Cancion: " << audio.titulo << " - Artista: " << audio.autor
                << '\n';
    } else {
      std::cout << "Podcast: " << audio.titulo
                << " - Presentador: " << audio.autor << '\n';
    }
  }
}

int main() {
  std::vector<Audio> lista;
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
