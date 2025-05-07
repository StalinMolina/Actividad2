#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Material {
private:
    string nombre;
    string tipo;
    string estado;

public:
    Material(string nombre, string tipo) : nombre(nombre), tipo(tipo), estado("Disponible") {}

    void utilizar() {
        estado = "En uso";
        cout << "Usando el material: " << nombre << endl;
    }

    string toString() const {
        return "Material: " + nombre + ", Tipo: " + tipo + ", Estado: " + estado;
    }
};

class Borrador {
private:
    vector<string> contenido;
    bool revisado = false;

public:
    void agregarIdea(const string& idea) {
        contenido.push_back(idea);
    }

    void ajustarContenido(int index, const string& nuevoContenido) {
        if (index >= 0 && index < contenido.size()) {
            contenido[index] = nuevoContenido;
        }
    }

    void estructurar() {
        revisado = true;
        cout << "Contenido estructurado y listo para pasar en limpio." << endl;
    }

    string toString() const {
        string result = "Borrador: [";
        for (size_t i = 0; i < contenido.size(); ++i) {
            result += contenido[i];
            if (i < contenido.size() - 1) result += ", ";
        }
        result += "] Revisado: " + string(revisado ? "true" : "false");
        return result;
    }
};

class Actividad {
private:
    string nombre;
    string tipo;
    string contenido;
    string estado;

public:
    Actividad(string nombre, string tipo, string contenido)
        : nombre(nombre), tipo(tipo), contenido(contenido), estado("Pendiente") {}

    void obtenerInstrucciones() const {
        cout << "Instrucciones para " << nombre << " (" << tipo << "): " << contenido << endl;
    }

    void completar() {
        estado = "Completada";
    }

    string getNombre() const {
        return nombre;
    }

    string toString() const {
        return "Actividad: " + nombre + ", Tipo: " + tipo + ", Estado: " + estado;
    }
};

class Plataforma {
private:
    string nombre;
    string url;

public:
    Plataforma(string nombre, string url) : nombre(nombre), url(url) {}

    void consultarActividad(const Actividad& actividad) const {
        cout << "Consultando actividad en " << nombre << " (" << url << ")" << endl;
    }

    void subirTarea(const Actividad& actividad) const {
        cout << "Subiendo actividad " << actividad.getNombre() << " a " << nombre << endl;
    }
};

class Estudiante {
private:
    string nombre;
    string tipoActividad;
    vector<Material> materiales;
    vector<Actividad> actividades;
    Plataforma plataforma;

public:
    Estudiante(string nombre, string tipoActividad, Plataforma plataforma)
        : nombre(nombre), tipoActividad(tipoActividad), plataforma(plataforma) {}

    void reunirMateriales(const vector<Material>& nuevosMateriales) {
        materiales.insert(materiales.end(), nuevosMateriales.begin(), nuevosMateriales.end());
    }

    void colocarseEnLaMesa() const {
        cout << nombre << " se ha sentado a estudiar." << endl;
    }

    void revisarActividad(Actividad& actividad) {
        actividades.push_back(actividad);
        actividad.obtenerInstrucciones();
    }

    void identificarParametro() const {
        cout << "Tipo de actividad: " << tipoActividad << endl;
    }

    void subirActividad(Actividad& actividad) {
        actividad.completar();
        plataforma.subirTarea(actividad);
    }

    string toString() const {
        return "Estudiante: " + nombre + ", Tipo Actividad: " + tipoActividad;
    }
};

int main() {
    Material lapiz("Lápiz", "Escritura");
    Material cuaderno("Cuaderno", "Papel");

    Borrador borrador;
    borrador.agregarIdea("Idea principal");
    borrador.agregarIdea("Detalles secundarios");
    borrador.ajustarContenido(1, "Detalles desarrollados");
    borrador.estructurar();

    Actividad actividad("Ensayo de Historia", "Escrita", "Redactar un ensayo sobre la independencia");
    Plataforma moodle("Moodle", "https://moodle.instituto.edu");
    Estudiante estudiante("Ana", "Escrita", moodle);

    vector<Material> materiales = {lapiz, cuaderno};
    estudiante.reunirMateriales(materiales);
    estudiante.colocarseEnLaMesa();
    estudiante.revisarActividad(actividad);
    estudiante.identificarParametro();
    estudiante.subirActividad(actividad);

    cout << "\nResumen:" << endl;
    cout << estudiante.toString() << endl;
    cout << actividad.toString() << endl;
    cout << borrador.toString() << endl;
    cout << lapiz.toString() << endl;
    cout << cuaderno.toString() << endl;

    return 0;
}
