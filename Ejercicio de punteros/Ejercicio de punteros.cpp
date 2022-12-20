#include <iostream>
using namespace std;

const int NUM_SUBJECTS = 4; // Número de materias
const int NUM_QUARTERS = 3; // Número de trimestres

int main() {
    // Crear matriz dinámica
    int** grades = new int* [NUM_SUBJECTS];
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        grades[i] = new int[NUM_QUARTERS];
    }

    // Leer datos de la pantalla
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        for (int j = 0; j < NUM_QUARTERS; j++) {
            cout << "Ingrese la nota del trimestre " << j + 1 << " para la materia " << i + 1 << ": ";
            cin >> grades[i][j];
        }
    }

    // Calcular promedios anuales para cada materia
    float* averages = new float[NUM_SUBJECTS];
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        float sum = 0;
        for (int j = 0; j < NUM_QUARTERS; j++) {
            sum += grades[i][j];
        }
        averages[i] = sum / NUM_QUARTERS;
    }

    // Imprimir promedios anuales
    cout << "Promedios anuales:" << endl;
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        cout << "Materia " << i + 1 << ": " << averages[i] << endl;
    }

    // Liberar memoria
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        delete[] grades[i];
    }
    delete[] grades;
    delete[] averages;

    return 0;
}
