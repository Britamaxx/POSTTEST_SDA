#include <iostream>
using namespace std;

void sebelum(int* arr, int size) {
    for (int* p = arr; p < arr + size; ++p) cout << *p << " ";
    cout << endl;
}

void sesudah(int* arr, int size) {
    int *awal = arr, *akhir = arr + size - 1;
    while (awal < akhir) {
        int t = *awal;
        *awal++ = *akhir;
        *akhir-- = t;
    }
}

int main() {
    int data[7];
    for (int i = 0; i < 7; ++i) data[i] = (i + 1) * 3;

    cout << "Sebelum: "; sebelum(data, 7);
    sesudah(data, 7);
    cout << "Sesudah: "; sebelum(data, 7);
}