#include <iostream>
#include "interface.h"

using namespace std;

void sift(int v[], int i, int n) {
    int maior = i; 
    int esq = 2 * i + 1;  
    int dir = 2 * i + 2;  

    if (esq < n && v[esq] > v[maior])
        maior = esq;

    if (dir < n && v[dir] > v[maior])
        maior = dir;

    if (maior != i) {
        swap(v[i], v[maior]);
        sift(v, maior, n);
    }
}

void buildHeap(int v[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        sift(v, i, n);
    }
}

void printHeap(int v[], int n) {
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    int v[MAX] = {56, 34, 22, 18, 92, 11, 78, 63, 44, 55, 9, 4, 99, 7, 45, 66, 27, 81, 30, 19, 
                  35, 90, 21, 5, 16, 62, 48, 59, 87, 60, 32, 51, 13, 23, 10, 1, 39, 49, 83, 36, 
                  68, 53, 3, 40, 28, 75, 6, 29, 8, 2};

    int n = MAX;

    cout << "Vetor Original:\n";
    printHeap(v, n);

    buildHeap(v, n);

    cout << "\nHeap Construído:\n";
    printHeap(v, n);

    return 0;
}
