#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<cmath>
#include<windows.h>

using namespace std;

const int kichthuoc = 8;  // Kích thu?c bàn c? 8x8
int KhungCo[kichthuoc+1][kichthuoc+1];
int x[8] = {2, 1, -1, -2, -2, -1, 1, 2};  // Di theo chi?u kim d?ng h?
int y[8] = {1, 2, 2, 1, -1, -2, -2, -1};
bool thang = FALSE;

void gotoxy(int x, int y) {
    static HANDLE h = NULL;  
    if (!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = {x, y};  
    SetConsoleCursorPosition(h, c);
}

void HienThiBanCo() {
    gotoxy(4, 4);
    for (int i = 0; i < kichthuoc; i++) {
        cout << "\t+---+---+---+---+---+---+---+---+ \n";
        cout << "\t|   |   |   |   |   |   |   |   | \n";
    }
    cout << "\t+---+---+---+---+---+---+---+---+ \n";
}

void Di(int x_m, int y_m, int n) {
    int x_t, y_t;
    for (int i = 0; i < 8; i++) {
        x_t = x_m + x[i];
        y_t = y_m + y[i];
        if (0 < x_t && x_t <= kichthuoc && 0 < y_t && y_t <= kichthuoc && KhungCo[x_t][y_t] == 0) {  // N?u ô c? h?p l? và chua di
            KhungCo[x_t][y_t] = n;
            gotoxy(5 + x_t * 4, 3 + y_t * 2);
            Sleep(200);
            cout << n;
            gotoxy(0, 10 + kichthuoc * 2);
            cout << "Buoc di: " << n;

            if (n == kichthuoc * kichthuoc) {  // Ðã di d? nu?c
                thang = TRUE;
                putchar(7);  // Phát âm báo thành công
            }

            if (!thang) {
                Di(x_t, y_t, n + 1);
            }

            if (thang) {
                return;
            }

            KhungCo[x_t][y_t] = 0;  // Quay lui
            gotoxy(5 + x_t * 4, 3 + y_t * 2);
            Sleep(100);
            cout << "   ";
        }
    }
}

int main() {
    int x_chon, y_chon;

    // Kh?i t?o bàn c? tr?ng
    for (int i = 0; i <= kichthuoc; i++) {
        for (int j = 0; j <= kichthuoc; j++) {
            KhungCo[i][j] = 0;
        }
    }

    cout << "Thuat toan quay lui: Ma di tuan \n";
    cout << "\nMoi ban nhap vi tri xuat phat (x, y): ";
    cin >> x_chon >> y_chon;

    if (x_chon < 1 || x_chon > kichthuoc) {
        x_chon = 1;
    }
    if (y_chon < 1 || y_chon > kichthuoc) {
        y_chon = 1;
    }

    HienThiBanCo();  // Hi?n th? bàn c? tr?ng ban d?u

    KhungCo[x_chon][y_chon] = 1;  // Ðánh d?u v? trí kh?i d?u
    gotoxy(5 + x_chon * 4, 3 + y_chon * 2);  // Ð?t v? trí d?u tiên
    cout << "1";

    Di(x_chon, y_chon, 2);  // B?t d?u t? bu?c th? 2 (bu?c d?u tiên là v? trí kh?i d?u)

    gotoxy(0, 10 + kichthuoc * 2);
    if (thang) {
        cout << "\nThanh cong!";
    } else {
        cout << "\nKhong co loi giai.";
    }

    return 0;
}

