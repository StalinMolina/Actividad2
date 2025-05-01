#include <iostream>

class Acumulador {
    int numeros[10];
    int cantidad = 0;

public:
    void agregarNumero(int valor) {
        if (cantidad < 10) {
            numeros[cantidad++] = valor;
        } else {
            std::cerr << "Se alcanzó el límite de 10 números.\n";
        }
    }

    int obtenerSuma() {
        int suma = 0;
        for (int indice = 0; indice < cantidad; ++indice) {
            suma += numeros[indice];
        }
        return suma;
    }

    double obtenerPromedio() {
        return cantidad == 0 ? 0.0 : static_cast<double>(obtenerSuma()) / cantidad;
    }
};

int main() {
    Acumulador acumulador;
    int cantidadNumeros;

    std::cout << "¿Cuántos números ingresará? ";
    std::cin >> cantidadNumeros;

    for (int contador = 0; contador < cantidadNumeros; ++contador) {
        int numero;
        std::cout << "Número: ";
        std::cin >> numero;
        acumulador.agregarNumero(numero);
    }

    std::cout << "Suma = " << acumulador.obtenerSuma() << '\n';
    std::cout << "Promedio = " << acumulador.obtenerPromedio() << '\n';

    return 0;
}
