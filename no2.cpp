#include <iostream>
#include <string>
#include <sstream>

using namespace std;
struct Menu
{
    string namaMakanan;
    int harga;
};

struct Pesanan
{
    string nama;
    int jumlah;
    int total;
};

int main()
{
    // Array menu makanan
    Menu menuMakanan[5] = {
        {"Soto", 15000},
        {"Rawon", 20000},
        {"Pecel", 10000},
        {"Bakso", 12500},
        {"Siomay", 25000}};

    // max 5 karena hanya ada 5 menu makanan
    const int MAX_PESANAN = 5;

    // Array pesanan
    Pesanan pesanan[MAX_PESANAN];

    // Input pesanan
    cout << "Masukkan pesanan (format: Nama Jumlah Nama Jumlah ...): ";
    string input;
    getline(cin, input);

    // Menggunakan stringstream untuk memisahkan input berdasarkan spasi
    stringstream ss(input);
    string namaMakanan;
    int jumlah;
    int index = 0;

    // Membaca input sampai habis
    while (ss >> namaMakanan >> jumlah)
    {
        // Mencari harga berdasarkan nama makanan
        double harga = 0.0;
        for (int i = 0; i < 5; i++)
        {
            if (menuMakanan[i].namaMakanan == namaMakanan)
            {
                harga = menuMakanan[i].harga;
                break;
            }
        }

        // Mengisi data ke array pesanan
        pesanan[index].nama = namaMakanan;
        pesanan[index].jumlah = jumlah;
        pesanan[index].total = harga * jumlah;

        index++;
    }

    // Menampilkan pesanan yang telah disimpan
    int totalHarga = 0;
    for (int i = 0; i < index; i++)
    {
        cout << pesanan[i].nama << " @" << pesanan[i].total / pesanan[i].jumlah << " * " << pesanan[i].jumlah << " = " << pesanan[i].total << endl;
        totalHarga += pesanan[i].total;
    }

    cout << "Total = " << totalHarga << endl;

    return 0;
}