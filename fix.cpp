#include <iostream>
using namespace std;

struct Identitas {
    string nama, umur, pekerjaan;

    Identitas *next;
};

Identitas *kepala, *bt, *baru, *ini, *del;

void buatList (string data[3]) {
    kepala = new Identitas();
    kepala->nama = data[0];
    kepala->umur = data[1];
    kepala->pekerjaan = data[2];
    bt = kepala;
    bt ->next = kepala;
}

void tambahAwal (string data[3]) {
    baru = new Identitas();
    baru->nama = data[0];
    baru->umur = data[1];
    baru->pekerjaan = data[2];
    
    baru->next = kepala;
    bt ->next = baru;
    kepala = baru;
}

void tambahTengah (string data[3], int posisi) {
        if (kepala == NULL)
    {
        cout << "Buat Linked List Dulu" << endl;
    }else {
        if (posisi == 1) {
            cout << "Posisi 1 bukan tengah" << endl;
        }
    else {
        baru = new Identitas();
        baru ->nama = data[0];
        baru ->umur = data[1];
        baru ->pekerjaan = data[2];

        int nomor = 1;
        ini = kepala;
        while (nomor < posisi -1 )
        {
            ini = ini->next;
            nomor++;
        }
        baru->next = ini ->next;
        ini->next = baru;
    }
}
}

void tambahLast (string data[3]) {
    baru = new Identitas();
    baru->nama = data[0];
    baru->umur = data[1];
    baru->pekerjaan = data[2];

    baru ->next = kepala;
    bt ->next = baru;
    bt = baru;
}

void cetak() {
    ini = kepala;
    while (ini->next != kepala)
    {
        cout << "| " << ini->nama << "\t\t| " << ini->umur << "\t\t| " << ini->pekerjaan << "\t\t|" << endl;
        ini = ini -> next;
    }
        cout << "| " << ini->nama << "\t\t| " << ini->umur << "\t\t| " << ini->pekerjaan << "\t\t|" << endl;
}

int main () {
    string dataBaru[3] = {"Sukarno", "20", "Manajer"};
    buatList(dataBaru);

    string data1[3] = {"Sunaryo", "21", "HRD"};
    tambahAwal(data1);

    string data2[3] = {"Sutrisno", "23", "Dosen"};
    tambahLast(data2);

    string data5[3] = {"Subali", "30", "CEO"};
    tambahTengah(data5, 2);

    cetak();
  

    return 0;
}