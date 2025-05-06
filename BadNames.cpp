#include <iostream>
using namespace std;

class ProcesadorNumeros {
    int numeros[10];
    int totalIngresados = 0;

public:
    void ejecutar() {
        int cantidad = solicitarCantidadDeNumeros();
        leerNumeros(cantidad);
        mostrarSumaYPromedio();
    }

private:
    int solicitarCantidadDeNumeros() {
        int cantidad;
        cout << "¿Cuántos números ingresará? ";
        cin >> cantidad;
        return cantidad;
    }

    void leerNumeros(int cantidad) {
        for (int i = 0; i < cantidad; ++i) {
            numeros[totalIngresados++] = solicitarNumero();
        }
    }

    int solicitarNumero() {
        int numero;
        cout << "Número: ";
        cin >> numero;
        return numero;
    }

    void mostrarSumaYPromedio() {
        int suma = calcularSuma();
        double promedio = calcularPromedio(suma);
        mostrarResultado("Suma", suma);
        mostrarResultado("Promedio", promedio);
    }

    int calcularSuma() {
        int suma = 0;
        for (int i = 0; i < totalIngresados; ++i) {
            suma += numeros[i];
        }
        return suma;
    }

    double calcularPromedio(int suma) {
        return totalIngresados == 0 ? 0.0 : static_cast<double>(suma) / totalIngresados;
    }

    void mostrarResultado(const string& etiqueta, double valor) {
        cout << etiqueta << " = " << valor << endl;
    }
};

int main() {
    ProcesadorNumeros procesador;
    procesador.ejecutar();
    return 0;
}
