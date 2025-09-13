#include <iostream>
#include <string>
using namespace std;

struct mahasiswa {
    string nama, nim;
    double ipk;
};

int main() {
    mahasiswa mahasigma[5];
    for (int i = 0; i < 5; ++i) {
        cout << "Nama : "; getline(cin, mahasigma[i].nama);
        cout << "NIM : "; getline(cin, mahasigma[i].nim);
        cout << "IPK : "; cin >> mahasigma[i].ipk; cin.ignore();
    }
    int idm = 0;
    for (int i = 1; i < 5; ++i)
        if (mahasigma[i].ipk > mahasigma[idm].ipk) idm = i;
    cout << "\nIPK Tertinggi :\nNama : " << mahasigma[idm].nama
         << "\nNIM : " << mahasigma[idm].nim << "\nIPK : " << mahasigma[idm].ipk << endl;
    return 0;
}