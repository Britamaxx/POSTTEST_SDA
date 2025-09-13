#include <iostream>
using namespace std;

void tukar(int** a, int** b) {
    int temp = **a;
    **a = **b;
    **b = temp;
}

int main() {
    int nilai1, nilai2;

    cout << "Masukkan Nilai 1 : ";
    cin >> nilai1;
    cout << "Masukkan Nilai 2 : ";
    cin >> nilai2;

    int* ptrNilai1 = &nilai1;
    int* ptrNilai2 = &nilai2;

    cout << "\nSebelum pertukaran :" << endl;
    cout << "Nilai 1 = " << nilai1 << endl;
    cout << "Nilai 2 = " << nilai2 << endl;

    tukar(&ptrNilai1, &ptrNilai2);

    cout << "\nSetelah pertukaran :" << endl;
    cout << "Nilai 1 = " << nilai1 << endl;
    cout << "Nilai 2 = " << nilai2 << endl;

    return 0;
}