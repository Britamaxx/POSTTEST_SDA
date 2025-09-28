#include <iostream>
#include <string>
using namespace std;

int panjangList = 0;

struct Item {
    string namaItem;
    int jumlah;
    string tipe;
};

struct Node {
    Item barang;
    Node* prev = nullptr;
    Node* next = nullptr;
};

void getInputItem(Item& item) {
    cout << "Nama item : ";
    getline(cin, item.namaItem);

    cout << "Tipe item : ";
    getline(cin, item.tipe);

    item.jumlah = 47;
}

Node* createNewNode(const Item& item) {
    Node* newNode = new Node;
    newNode->barang = item;
    return newNode;
}

void addLast(Node*& head, Node*& tail) {
    Item newItem;
    getInputItem(newItem);
    Node* newNode = createNewNode(newItem);

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    panjangList++;
    cout << "Item \"" << newItem.namaItem << "\" ditambahkan di akhir.\n";
}

void addSpecific(Node*& head, Node*& tail) {
    const int posisiSisip = 8;
    int posisi = posisiSisip;

    if (posisiSisip > panjangList + 1) {
        posisi = panjangList + 1;
        cout << "Posisi ke-" << posisiSisip
             << " melebihi panjang list saat ini. "
             << "Item akan disisipkan di akhir (posisi ke-" << posisi << ").\n";
    } else {
        cout << "Item akan disisipkan pada posisi ke-8.\n";
    }

    if (posisi < 1) {
        cout << "Posisi sisip tidak valid.\n";
        return;
    }

    Item newItem;
    cout << "--- Input Item yang akan disisipkan ---\n";
    getInputItem(newItem);
    Node* newNode = createNewNode(newItem);

    if (posisi == 1) {
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
    } else if (posisi == panjangList + 1) {
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    } else {
        Node* temp = head;
        for (int i = 1; i < posisi - 1; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }

    panjangList++;
    cout << "Item \"" << newItem.namaItem
         << "\" disisipkan pada posisi " << posisi << ".\n";
}

void deleteLast(Node*& head, Node*& tail) {
    if (head == nullptr) {
        cout << "Inventory kosong, tidak ada yang dihapus.\n";
        return;
    }

    Node* temp = tail;
    cout << "Item \"" << temp->barang.namaItem << "\" dihapus.\n";

    if (head == tail) {
        delete temp;
        head = nullptr;
        tail = nullptr;
    } else {
        tail = temp->prev;
        tail->next = nullptr;
        delete temp;
    }

    panjangList--;
}

void gunakanItem(Node*& head, Node*& tail) {
    if (head == nullptr) {
        cout << "Inventory kosong.\n";
        return;
    }

    string namaItem;
    cout << "Nama item yang dipakai : ";
    getline(cin, namaItem);

    Node* temp = head;
    while (temp != nullptr && temp->barang.namaItem != namaItem) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Item \"" << namaItem << "\" tidak ditemukan.\n";
        return;
    }

    temp->barang.jumlah -= 1;
    cout << "Item \"" << namaItem << "\" digunakan. Sisa: "
         << temp->barang.jumlah << endl;

    if (temp->barang.jumlah <= 0) {
        cout << "Item \"" << namaItem << "\" habis dan dihapus dari inventory.\n";

        if (temp->prev == nullptr) {
            head = temp->next;
            if (head) head->prev = nullptr;
            if (tail == temp) tail = nullptr;
        } else if (temp->next == nullptr) {
            tail = temp->prev;
            if (tail) tail->next = nullptr;
        } else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }

        delete temp;
        panjangList--;
    }
}

void tampilkan(Node* head) {
    if (head == nullptr) {
        cout << "Inventory kosong.\n";
        return;
    }

    Node* temp = head;
    int i = 1;
    cout << "\n--- Daftar Inventory (Dari Depan) ("
         << panjangList << " Item) ---\n";

    while (temp != nullptr) {
        cout << i++ << ". " << temp->barang.namaItem
             << " (" << temp->barang.tipe
             << ") - Jumlah: " << temp->barang.jumlah << endl;
        temp = temp->next;
    }
}

void tampilkanDariBelakang(Node* tail) {
    if (tail == nullptr) {
        cout << "Inventory kosong.\n";
        return;
    }

    Node* temp = tail;
    int nomorUrut = 1; 
    
    cout << "\n--- Daftar Inventory (Dari Belakang) ---\n";

    while (temp != nullptr) {
        cout << nomorUrut++ << ". " << temp->barang.namaItem 
             << " (" << temp->barang.tipe 
             << ") - Jumlah: " << temp->barang.jumlah << endl;
        
        temp = temp->prev; 
    }
}

void tampilkanDetail(Node* head) {
    if (head == nullptr) {
        cout << "Inventory kosong.\n";
        return;
    }

    string namaItem;
    cout << "Nama item yang ingin dilihat detailnya : ";
    getline(cin, namaItem);

    Node* temp = head;
    while (temp != nullptr) {
        if (temp->barang.namaItem == namaItem) {
            cout << "\n--- Detail Item ---\n";
            cout << "Nama  : " << temp->barang.namaItem << endl;
            cout << "Tipe  : " << temp->barang.tipe << endl;
            cout << "Jumlah: " << temp->barang.jumlah << endl;
            return;
        }
        temp = temp->next;
    }

    cout << "Item \"" << namaItem << "\" tidak ditemukan.\n";
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    int pilih = -1;
    string namaUser = "Tama";
    string nimUser = "2409106047";

    do {
        cout << "\n============================\n";
        cout << " INVENTORY GAME\n";
        cout << " " << namaUser << " - " << nimUser << "\n";
        cout << "============================\n";
        cout << "1. Tambah Item Baru\n";
        cout << "2. Sisipkan Item\n";
        cout << "3. Hapus Item Terakhir\n";
        cout << "4. Gunakan Item\n";
        cout << "5. Tampilkan Inventory (Depan)\n";
        cout << "6. Tampilkan Inventory (Belakang)\n";
        cout << "7. Tampilkan Detail Item\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu : ";

        if (!(cin >> pilih)) {
            cout << "Input tidak valid. Masukkan angka.\n";
            continue;
        }

        cin.ignore();

        if (pilih == 1) {
            addLast(head, tail);
        } else if (pilih == 2) {
            addSpecific(head, tail);
        } else if (pilih == 3) {
            deleteLast(head, tail);
        } else if (pilih == 4) {
            gunakanItem(head, tail);
        } else if (pilih == 5) {
            tampilkan(head);
        } else if (pilih == 6) {
            tampilkanDariBelakang(tail);
        } else if (pilih == 7) {
            tampilkanDetail(head);
        } else if (pilih == 0) {
            cout << "Keluar...\n";
        } else {
            cout << "Pilihan tidak ada.\n";
        }
    } while (pilih != 0);

    return 0;
}