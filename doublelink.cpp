#include <iostream>
using namespace std;

//deklarasi
struct DataUser
{
    string nama, username, email, password;
    DataUser *prev;
    DataUser *next;
};

DataUser *kepala, *bt, *ini, *nodeBaru, *del, *after;

void buatDobel(string data[4]) {

    kepala = new DataUser();
    kepala ->nama = data[0];
    kepala ->username = data[1];
    kepala ->email = data[2];
    kepala ->password = data[3];
    kepala ->prev = NULL;
    kepala ->next = NULL;
    bt = kepala;
}

int hitung() {
    if (kepala == NULL)
    {
        cout << "Double Linkedlist belum dibuat";
    }else
    {
        ini = kepala;
        int jumlah=0;
    while (ini != NULL)
    {
        jumlah++;
        ini = ini->next;
    }
    return jumlah;
    }
}

void tambahAwal (string data[4]){
    if (kepala == NULL)
    {
        cout << "Double Linkedlist belum dibuat";
    }else
    {
        nodeBaru = new DataUser();
        nodeBaru ->nama = data[0];
        nodeBaru ->username = data[1];
        nodeBaru ->email = data[2];
        nodeBaru ->password = data[3];
        nodeBaru ->prev = NULL;
        nodeBaru ->next = kepala;
        kepala->prev = nodeBaru;
        kepala = nodeBaru;
    }
}

void tambahLast (string data[4]){
    if (kepala == NULL)
    {
        cout << "Double Linkedlist belum dibuat";
    }else
    {
        nodeBaru = new DataUser();
        nodeBaru ->nama = data[0];
        nodeBaru ->username = data[1];
        nodeBaru ->email = data[2];
        nodeBaru ->password = data[3];
        nodeBaru ->prev = bt;
        nodeBaru ->next = NULL;
        bt->next = nodeBaru;
        bt = nodeBaru;
    }
}

void tambahTengah(string data [4], int posisi){
    if (kepala == NULL)
    {
        cout << "Double Linkedlist belum dibuat";
    }else{
        if (posisi == 1)
        {
            cout << "posisi awal bukan posisi tengah" << endl;
        }else if (posisi < 1 || posisi > hitung())
        {
            cout << "posisi ngawur" << endl;
        }else
        {
        nodeBaru = new DataUser();
        nodeBaru ->nama = data[0];
        nodeBaru ->username = data[1];
        nodeBaru ->email = data[2];
        nodeBaru ->password = data[3];

        //transfersing
        ini = kepala;
        int nomor = 1;
        while (nomor < posisi-1)
        {
            ini = ini ->next;
            nomor++;
        }
            after = ini->next;
            nodeBaru->prev = ini;
            nodeBaru->next = after;
            ini->next = nodeBaru;
            after->prev = nodeBaru;
        }
    }
}

void hapusAwal(){
    if (kepala == NULL)
    {
        cout << "Double Linkedlist belum dibuat";
    }else
    { del = kepala;
    kepala = kepala->next;
    kepala->prev = NULL;
    delete del;
    }
}

void hapusLast () {
    if (kepala == NULL)
    {
        cout << "Double Linkedlist belum dibuat";
    }else
    {
        del = bt;
        bt = bt->prev;
        bt->next = NULL;
        delete del;
    }
}

void hapusTengah (int posisi) {
    if (kepala == NULL)
    {
        cout << "Double Linkedlist belum dibuat";
    }else
    {
        if ( posisi == 1 || posisi == hitung()) {
            cout << "posisi bukan posisi tengah" << endl;
        } else if (posisi < 1 || posisi > hitung())
        {
            cout << "posisi diluar jangkauan" << endl;
        }else
        {
            int nomor = 1;
            ini = kepala;
            while (nomor < posisi - 1)
            {
                ini = ini -> next;
                nomor++;
            }
            del = ini -> next;
            after = del->next;
            ini ->next = after;
            after ->prev = ini;
            delete del;
        }
    }
}
void soalNomor4(string data[4]) {
    ini = kepala;
    while (ini != NULL)
    {
        if (ini->nama == data[0] && ini->username == data[1] && ini->email == data[2] && ini->password == data[3])
        {
            if (ini == kepala)
            {
                hapusAwal();
                return;
            }
            else if (ini == bt)
            {
                hapusLast();
                return;
            }
            else
            {
            ini->prev->next = ini->next;
            ini->next->prev = ini->prev;
            del = ini;
            delete del;
            return;
            }
        }ini = ini->next;
    }
     cout << "data tidak ditemukan!" << endl;
}

void cetak() {
    if (kepala == NULL)
    {
        cout << "Double Linkedlist belum dibuat";
    }else
    {
        cout << "jumlah datanya : " << hitung() << endl;
        cout << "Isi data : " << endl;
        ini = kepala;
    while (ini != NULL)
    {
        cout << "nama user : " << ini->nama << endl;
        cout << "username user : " << ini->username << endl;
        cout << "email user : " << ini->email << endl;
        cout << "password user : " << ini->password << "\n" << endl;

        ini = ini->next;
    }
    }
}

int main () {

string newData[4] = {"Bagus eko", "bagusganteng", "bagus26@gmail.com", "password123"};
buatDobel(newData);
// cetak();

string data2[4] = {"eko Bagus", "eko123", "eko@gmail.com", "1234556"};
 tambahAwal(data2);
// // cetak();

 string data3[4] = {"wijayanto", "yanto", "yanto@gmail.com", "yanto556"};
 tambahLast(data3);
// // cetak();

 string data4[4] = {"den bagus", "denbaguse", "denba@gmail.com", "katasandi"};
 tambahTengah(data4, 2);
// cetak();

string datax[4] = {"Bagus eko", "bagusganteng", "bagus26@gmail.com", "password123"};
soalNomor4(datax);

cetak();

return 0;

}
