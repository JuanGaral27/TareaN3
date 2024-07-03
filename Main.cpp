#include <iostream>
#include <cmath>

using namespace std;

// Definición de la estructura Dot
struct Dot {
    float x;
    float y;
    float z;

    // Constructor para inicializar las coordenadas
    Dot(float x, float y, float z) : x(x), y(y), z(z) {}

    // Función para calcular la distancia entre dos puntos en 2 o 3 dimensiones
    float calcularDistancia(const Dot& otro) const {
        float dx = otro.x - x;
        float dy = otro.y - y;
        float dz = otro.z - z;
        return sqrt(dx*dx + dy*dy + dz*dz);
    }

    // Función para calcular el vector resultante de la suma de dos vectores en 2 o 3 dimensiones
    Dot sumarVector(const Dot& otro) const {
        return Dot(x + otro.x, y + otro.y, z + otro.z);
    }

    // Función para calcular el vector resultante de un arreglo de N vectores en 2 o 3 dimensiones
    static Dot sumarVectores(const Dot* vectores, int N) {
        float sumX = 0.0f, sumY = 0.0f, sumZ = 0.0f;
        for (int i = 0; i < N; ++i) {
            sumX += vectores[i].x;
            sumY += vectores[i].y;
            sumZ += vectores[i].z;
        }
        return Dot(sumX, sumY, sumZ);
    }

    // Función para calcular el producto escalar de dos vectores en 2 o 3 dimensiones
    float productoEscalar(const Dot& otro) const {
        return x * otro.x + y * otro.y + z * otro.z;
    }

    // Función para calcular el producto cruz de dos vectores en 3 dimensiones
    Dot productoCruz(const Dot& otro) const {
        float cx = y * otro.z - z * otro.y;
        float cy = z * otro.x - x * otro.z;
        float cz = x * otro.y - y * otro.x;
        return Dot(cx, cy, cz);
    }

    // Función para imprimir el vector y determinar en qué plano se encuentra
    void imprimirVector() const {
        cout << "v = " << x << "i + " << y << "j + " << z << "k (vector)\n";

        if (x == 0 && y == 0 && z == 0) {
            cout << "El vector es el vector nulo.\n";
        } else if (x == 0 && y == 0) {
            cout << "El vector esta en el plano Z.\n";
        } else if (x == 0 && z == 0) {
            cout << "El vector esta en el plano Y.\n";
        } else if (y == 0 && z == 0) {
            cout << "El vector esta en el plano X.\n";
        } else if (x == 0) {
            cout << "El vector esta en el plano YZ.\n";
        } else if (y == 0) {
            cout << "El vector esta en el plano XZ.\n";
        } else if (z == 0) {
            cout << "El vector esta en el plano XY.\n";
        } else {
            cout << "El vector no esta en ninguno de los planos principales.\n";
        }
    }
};

// Función para resolver un sistema de fuerzas
Dot resolverSistemaFuerzas(const Dot* fuerzas, int N) {
    return Dot::sumarVectores(fuerzas, N);
}

int main() {
    // Ejemplo de uso
    Dot punto1(1.0, 2.0, 3.0);
    Dot punto2(4.0, 5.0, 6.0);

    // Calcular distancia entre dos puntos
    float distancia = punto1.calcularDistancia(punto2);
    cout << "Distancia entre los puntos: " << distancia << endl;

    // Sumar dos vectores
    Dot resultadoSuma = punto1.sumarVector(punto2);
    resultadoSuma.imprimirVector();

    // Producto escalar
    float escalar = punto1.productoEscalar(punto2);
    cout << "Producto escalar: " << escalar << endl;

    // Producto cruz (solo para vectores en 3D)
    Dot productoCruz = punto1.productoCruz(punto2);
    cout << "Producto cruz: ";
    productoCruz.imprimirVector();

    // Resolver un sistema de fuerzas
    Dot fuerzas[] = {Dot(1.0, 2.0, 3.0), Dot(4.0, 5.0, 6.0)};
    Dot resultadoFuerzas = resolverSistemaFuerzas(fuerzas, 2);
    cout << "Resultado del sistema de fuerzas: ";
    resultadoFuerzas.imprimirVector();

    return 0;
}
