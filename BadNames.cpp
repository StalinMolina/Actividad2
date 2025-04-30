#include <iostream>

class ColeccionNumeros {
    int numeros[10];
    int cantidad = 0;

public:
    void agregarNumero(int valor) {
        numeros[cantidad++] = valor;
    }

    int calcularSuma() {
        int suma = 0;
        for (int indice = 0; indice < cantidad; ++indice) {
            suma += numeros[indice];
        }
        return suma;
    }

    double calcularPromedio() {
        return cantidad == 0 ? 0.0 : static_cast<double>(calcularSuma()) / cantidad;
    }
};

int main() {
    ColeccionNumeros coleccion;
    int cantidadIngresos;

    std::cout << "¿Cuántos números ingresará? ";
    std::cin >> cantidadIngresos;

    for (int indiceIngreso = 0; indiceIngreso < cantidadIngresos; ++indiceIngreso) {
        std::cout << "Número: ";
        int valorIngresado;
        std::cin >> valorIngresado;
        coleccion.agregarNumero(valorIngresado);
    }

    std::cout << "Suma = " << coleccion.calcularSuma() << '\n';
    std::cout << "Promedio = " << coleccion.calcularPromedio() << '\n';

    return 0;
}
