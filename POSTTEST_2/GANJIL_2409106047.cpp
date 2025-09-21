#include <iostream>
using namespace std;

struct Item 
{
    string namaItem;
    int jumlah;
    string tipe;
};

struct Node 
{
    Item barang;
    Node* next;
};

const string NAMA = "Tama";
const string NIM  = "2409106047";
int defaultJumlah;
int posisiSisip;

void initNIM() 
{
    int duaDigit = stoi(NIM.substr(NIM.size() - 2));
    defaultJumlah = duaDigit;

    int digitTerakhir = (NIM[NIM.size() - 1] - '0');
    if (digitTerakhir == 0) posisiSisip = 2;
    else posisiSisip = digitTerakhir + 1;
}

void addFirst(Node** head, Node** tail, const string& namaItem, const string& tipe) 
{
    Node* newNode = new Node;
    newNode->barang.namaItem = namaItem;
    newNode->barang.jumlah = defaultJumlah;
    newNode->barang.tipe = tipe;
    newNode->next = *head;
    *head = newNode;
    if (*tail == nullptr) {
        *tail = newNode;
    }
}

void addLast(Node** head, Node** tail, const string& namaItem, const string& tipe) 
{
    Node* newNode = new Node;
    newNode->barang.namaItem = namaItem;
    newNode->barang.jumlah = defaultJumlah;
    newNode->barang.tipe = tipe;
    newNode->next = nullptr;

    if (*head == nullptr) 
    {
        *head = newNode;
        *tail = newNode;
    } 
    else 
    {
        (*tail)->next = newNode;
        *tail = newNode;
    }
}

void addSpecific(Node** head, Node** tail, const string& namaItem, const string& tipe) 
{
    if (posisiSisip <= 1) 
    {
        addFirst(head, tail, namaItem, tipe);
        return;
    }

    Node* temp = *head;
    for (int i = 1; i < posisiSisip - 1 && temp != nullptr; i++) 
    {
        temp = temp->next;
    }

    if (temp == nullptr) 
    {
        addLast(head, tail, namaItem, tipe);
    } 
    else 
    {
        Node* newNode = new Node;
        newNode->barang.namaItem = namaItem;
        newNode->barang.jumlah = defaultJumlah;
        newNode->barang.tipe = tipe;
        newNode->next = temp->next;
        temp->next = newNode;
        if (newNode->next == nullptr) 
        {
            *tail = newNode;
        }
    }
}

void deleteLast(Node** head, Node** tail) 
{
    if (*head == nullptr) {
        cout << "Inventory kosong, tidak ada yang dihapus.\n";
        return;
    }
    if ((*head)->next == nullptr) {
        cout << "Item \"" << (*head)->barang.namaItem << "\" dihapus.\n";
        delete *head;
        *head = nullptr;
        *tail = nullptr;
        return;
    }
    Node* temp = *head;
    while (temp->next != *tail) {
        temp = temp->next;
    }
    cout << "Item \"" << (*tail)->barang.namaItem << "\" dihapus.\n";
    delete *tail;
    temp->next = nullptr;
    *tail = temp;
}

void gunakanItem(Node** head, Node** tail, const string& namaItem) 
{
    if (*head == nullptr) {
        cout << "Inventory kosong.\n";
        return;
    }

    Node* temp = *head;
    Node* prev = nullptr;

    while (temp != nullptr && temp->barang.namaItem != namaItem) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Item \"" << namaItem << "\" tidak ditemukan.\n";
        return;
    }

    temp->barang.jumlah -= 1;
    cout << "Item \"" << namaItem << "\" digunakan. Sisa: " << temp->barang.jumlah << endl;

    if (temp->barang.jumlah <= 0) {
        cout << "Item \"" << namaItem << "\" habis dan dihapus dari inventory.\n";
        if (prev == nullptr) {
            *head = temp->next;
            if (*tail == temp) *tail = nullptr;
        } else {
            prev->next = temp->next;
            if (*tail == temp) *tail = prev;
        }
        delete temp;
    }
}

void tampilkan(Node* head) 
{
    if (head == nullptr) 
    {
        cout << "Inventory kosong.\n";
        return;
    }
    Node* temp = head;
    int i = 1;
    cout << "\n--- Daftar Inventory ---\n";
    while (temp != nullptr) 
    {
        cout << i++ << ". " << temp->barang.namaItem 
             << " (" << temp->barang.tipe 
             << ") - " << temp->barang.jumlah << endl;
        temp = temp->next;
    }
}

int main() 
{
    initNIM();
    Node *head = nullptr;
    Node *tail = nullptr;

    int pilih;
    do {
        cout << "\n============================\n";
        cout << " INVENTORY GAME\n";
        cout << " " << NAMA << " - " << NIM << "\n";
        cout << "============================\n";
        cout << "1. Tambah Item Baru\n";
        cout << "2. Sisipkan Item\n";
        cout << "3. Hapus Item Terakhir\n";
        cout << "4. Gunakan Item\n";
        cout << "5. Tampilkan Inventory\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilih;

        if (pilih == 1) {
            string nama, tipe;
            cout << "Nama item : "; cin >> nama;
            cout << "Tipe item : "; cin >> tipe;
            addLast(&head, &tail, nama, tipe);
        }
        else if (pilih == 2) {
            string nama, tipe;
            cout << "Nama item : "; cin >> nama;
            cout << "Tipe item : "; cin >> tipe;
            addSpecific(&head, &tail, nama, tipe);
        }
        else if (pilih == 3) {
            deleteLast(&head, &tail);
        }
        else if (pilih == 4) {
            string nama;
            cout << "Nama item yang dipakai : "; cin >> nama;
            gunakanItem(&head, &tail, nama);
        }
        else if (pilih == 5) {
            tampilkan(head);
        }
        else if (pilih == 0) {
            cout << "Keluar...\n";
        }
        else {
            cout << "Pilihan tidak ada.\n";
        }
    } while (pilih != 0);

    return 0;
}