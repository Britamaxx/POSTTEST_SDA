#include <iostream>
using namespace std;

int main() {
    int matriks[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    int utama = 0, sekunder = 0;

    cout << "Matriks 3x3 :\n";
    for (int i = 0; i < 3; ++i, cout << endl)
        for (int j = 0; j < 3; ++j)
            cout << matriks[i][j] << " ";

    for (int i = 0; i < 3; ++i) {
        utama += matriks[i][i];
        sekunder += matriks[i][2-i];
    }

    cout << "\nJumlah diagonal utama : " << utama
         << "\nJumlah diagonal sekunder : " << sekunder
         << "\nJumlah total kedua diagonal : " << utama + sekunder << endl;
    return 0;
}