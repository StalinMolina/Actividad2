#include <iostream>

class ListaDeNumeros {
    int numeros[10];                
    int cantidadNumeros = 0;        
public:
    void agregarNumero(int numero) {
        numeros[cantidadNumeros++] = numero;
    }

    int calcularSuma() {
        int suma = 0;
        for (int indice = 0; indice < cantidadNumeros; ++indice) {
            suma += numeros[indice];
        }
        return suma;
    }

    double calcularPromedio() {
        return cantidadNumeros == 0 ? 0.0 : static_cast<double>(calcularSuma()) / cantidadNumeros;
    }
};

int main() {
    ListaDeNumeros lista;                 
    int cantidadIngresos;                

    std::cout << "¿Cuántos números ingresará? ";
    std::cin  >> cantidadIngresos;

    for (int contador = 0; contador < cantidadIngresos; ++contador) {
        std::cout << "Número: ";
        int numeroIngresado;
        std::cin >> numeroIngresado;
        lista.agregarNumero(numeroIngresado);
    }

    std::cout << "Suma = " << lista.calcularSuma() << '\n';
    std::cout << "Promedio = " << lista.calcularPromedio() << '\n';
    return 0;
}
