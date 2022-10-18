#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct TNode{
    int nilai_x;
    int nilai_y;
    TNode * next;
};

TNode * head, * tail;

void init(){
    head = NULL;
    tail = NULL;
}

int isEmpty(){
    if(head == NULL)
        return 1;
    else
        return 0;
}

void masuk_depan(int x, int y)
{
    TNode * baru;
    baru = new TNode;
    baru -> nilai_x = x;
    baru -> nilai_y = y;
    baru -> next = NULL;
    if(isEmpty()==1){
        head = tail = baru;
        tail -> next= NULL;
    }
    else{
        baru -> next = head;
        head = baru;
    }
    cout << "Data masuk\n";
}

void masuk_tengah(int x, int y){
    system("cls");
    int pilih;
    cout << "Pilih menu masukkan data!" << endl;
    cout << "1 - Masukkan sebelum" << endl;
    cout << "2 - Masukkan setelah" << endl;
        cin >> pilih;
    switch(pilih){
        case 1: system("cls");{
            TNode * baru;
            TNode * bantu;
            TNode * sebelum_bantu;
            baru = new TNode;
            if(head == NULL){
                head = baru;
                tail = baru;
            }
            else{
                int before;
                cout << "Memasukkan sebelum data : ";
                    cin >> before;
                bantu = head;
                sebelum_bantu = bantu;
                baru -> nilai_x = x;
                baru -> nilai_y = y;
                bool find = false;
                do{
                    if(before == bantu -> nilai_x){
                        baru -> next = sebelum_bantu -> next;
                        sebelum_bantu -> next = baru;
                        find = true;
                        cout << "Data berhasil dimasukkan!\n";
                    }
                    sebelum_bantu = bantu;
                    bantu = bantu -> next;
                }
            while(bantu != NULL);
                if(find == false){
                    cout << "Data yang anda cari tidak ada!";
                }
            }
            break;
        }
        case 2: system("cls");{
            TNode * baru;
            TNode * bantu;
            baru = new TNode;
            baru -> nilai_x = x;
            baru -> nilai_y = y;
            baru -> next = NULL;
            if(head == NULL){
                head = baru;
                tail = baru;
            }
            else{
                int after;
                cout << "Memasukkan setelah data : ";
                    cin >> after;
                bantu = head;
                bool find = false;
                do{
                    if(after == bantu -> nilai_y){
                        baru -> next = bantu -> next;
                        bantu -> next = baru;
                        find = true;
                        cout << "Data berhasil dimasukkan!\n";
                    }
                    bantu = bantu -> next;
                }
                while(bantu != NULL);
                if(find == false){
                    cout << "Data yang anda cari tidak ada!";
                }
            }
            break;
        }
        default: system("cls");{
            cout << "\nMenu pilihan tidak ada!";
            break;
        }
    }
}

void masuk_belakang(int x, int y){
    TNode * baru;
    baru = new TNode;
    baru -> nilai_x = x;
    baru -> nilai_y = y;
    baru -> next = NULL;
    if(head == NULL){
        head = baru;
        tail = baru;
    }
    else{
        tail -> next = baru;
        tail = baru;
    }
    cout << "Data berhasil dimasukkan!\n";
}

void tampil(){
    TNode * bantu;
    bantu = head;
        if(isEmpty()==0)
        {
            while(bantu!=NULL)
            {
                cout << bantu -> nilai_x << " ";
                cout << bantu -> nilai_y << " \n";
                bantu = bantu -> next;
            }
        }
        else{
            cout <<"Data kosong / tidak ditemukan!\n";
        }
}

void cariData(){
    if(head == NULL){
        cout << "Data Kosong";
    }
    else{
        TNode * bantu;
        int cari;
        cout << "Masukkan isi data : ";
            cin >> cari;
        bool find = false;
        bantu = head;
        do{
            if(cari == bantu -> nilai_x){
                cout << "Data " << bantu -> nilai_x << " " << bantu -> nilai_y << " Data sudah ketemu!";
                find = true;
            }
            if(cari == bantu -> nilai_y){
                cout << "Data " << bantu -> nilai_x << " " << bantu -> nilai_y << " Data sudah ketemu!";
                find = true;
            }
            bantu = bantu -> next;
        }
        while(bantu != NULL);
        if(find == false){
            cout << "Data kosong / tidak ditemukan!";
        }
    }
}

void hapus_depan()
{
    TNode * hapus;
    int d;
    if(isEmpty()==0)
    {
        if(head != tail)
        {
            hapus = head;
            d = hapus -> nilai_x;
            head = head -> next;
            delete hapus;
        }
        else{
            d = tail -> nilai_x;
            head = tail = NULL;
        }
    cout << d << "Data berhasil dihapus";
    }
    else
        cout << "Masih kosong\n";
}

void hapus_tengah(int x){
    TNode * hapus;
    TNode * sebelum_hapus;
    TNode * temp;
    hapus = head;
    sebelum_hapus = hapus;
    bool success = false;
    do{
        if(hapus -> nilai_x == x || hapus -> nilai_y == x){
            sebelum_hapus -> next = hapus -> next;
            temp = hapus;
            temp -> next = NULL;
            success = true;
            cout << "Data " << temp -> nilai_x << " " << temp -> nilai_y << " Data berhasil dihapus!\n";
            free(temp);
        }
        sebelum_hapus = hapus;
        hapus = hapus -> next;
    }
    while(hapus != NULL);
    if(success == false){
        cout << "Data tidak ditemukan!";
    }
}

void hapus_belakang(){
    TNode * hapus;
    TNode * temp;
    hapus = head;

while(hapus -> next != NULL){
        temp = hapus;
        hapus = hapus -> next;
    }
    temp -> next = NULL;
    cout << "Data " << hapus -> nilai_x << " " << hapus -> nilai_y << " Data berhasil dihapus!";
    free(hapus);
}

void clear()
{
    TNode * bantu, * hapus;
    bantu = head;
    do{
        hapus = bantu;
        bantu = bantu -> next;
        delete hapus;
    }
    while(bantu != NULL);
    head = NULL;
    cout << "Semua data berhasil dihapus\n";
}

main()
{
    int no_menu, data_x, data_y;
    do{
        system("cls");
        cout << endl;
        cout << "Silahkan Pilih Menu Berikut" << endl;
        // menu data depan
        cout << "1 - Insert data didepan" << endl;
        cout << "2 - Delete data didepan" << endl;
        // menu data tengah
        cout << "3 - Insert data ditengah" << endl;
        cout << "4 - Delete data ditengah" << endl;
        // menu data belakang
        cout << "5 - Insert data dibelakang" << endl;
        cout << "6 - Delete data dibelakang" << endl;
        // menu cari tampil hapus data
        cout << "7 - Cari Data" << endl;
        cout << "8 - Tampil Data" << endl;
        cout << "9 - Hapus data" << endl;
        // keluar
        cout << "10 - Keluar" << endl;
        cout << " Masukkan nomor menu = ";
            cin >> no_menu;
        switch(no_menu)
        {
            // menu data depan
            case 1: system("cls");{
                cout << "Masukan Data X = ";
                    cin >> data_x;
                cout << "Masukan Data Y = ";
                    cin >> data_y;
                masuk_depan(data_x, data_y);
                break;
            }
            case 2: system("cls");{
                hapus_depan();
                break;
            }
            // menu data tengah
            case 3: system("cls");{
                cout << "Masukan Data X = ";
                    cin >> data_x;
                cout << "Masukan Data Y = ";
                    cin >> data_y;
                masuk_tengah(data_x, data_y);
                break;
            }
            case 4: system("cls");{
                cout << "Masukkan Data : ";
                    cin >> data_x;
                hapus_tengah(data_x);
                break;
            }
            // menu data belakang
            case 5: system("cls");{
                cout << "Masukan Data X = ";
                    cin >> data_x;
                cout << "Masukan Data Y = ";
                    cin >> data_y;
                masuk_belakang(data_x, data_y);
                break;
            }
            case 6: system("cls");{
                hapus_belakang();
                break;
            }
            // menu cari tampil hapus data
            case 7: system("cls");{
                cariData();
                break;
            }
            case 8: system("cls");{
                tampil();
                break;
            }
            case 9: system("cls");{
                clear();
                break;
            }
            //keluar
            case 10: system("cls");{
                return 0;
                break;
            }
            default : system("cls");
            {
                cout << "\n Menu yang anda pilih tidak dikenali!";
            }
        }
        getch();
    }
    while(no_menu != 10);
}
