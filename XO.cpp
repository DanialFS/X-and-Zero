#include <iostream>
using namespace std;

const int N = 3;
const int M = 3;
char pole[N][M];

void Pole() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << pole[i][j] << " ";
        }
        cout << endl;
    }
}

// Функция для проверки выигрышных комбинаций
bool CheckWin(char x) {
        if (pole[0][0] == x && pole[0][1] == x && pole[0][2] == x) return true;
        if (pole[1][0] == x && pole[1][1] == x && pole[1][2] == x) return true;
        if (pole[2][0] == x && pole[2][1] == x && pole[2][2] == x) return true;
        if (pole[0][0] == x && pole[1][0] == x && pole[2][0] == x) return true;
        if (pole[0][1] == x && pole[1][1] == x && pole[2][1] == x) return true;
        if (pole[0][2] == x && pole[1][2] == x && pole[2][2] == x) return true;
        if (pole[0][0] == x && pole[1][1] == x && pole[2][2] == x) return true;
        if (pole[0][2] == x && pole[1][1] == x && pole[2][0] == x) return true;

    return false;
}

int main() {
    bool game = true;
    char step = 'X';

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            pole[i][j] = '*';
        }
    }

    cout << "Чтобы играть, вам нужно знать, что такое матрица!" << endl;

    while (game) {
        Pole();
        int n, m;
        cout << "Ход игрока " << step << ". Выберите точку, например [1][2 ]: ";
        cin >> n >> m;

        if (n >= 0 && n < N && m >= 0 && m < M && pole[n][m] == '*') {
            pole[n][m] = step;
            if (CheckWin(step) == true) {
                game = false;
                cout << "Игрок " << step << " победил!" << endl;
            } else {
                if (step == 'X') {
                    step = 'O';
                } else {
                    step = 'X';
                }
            }
        } else {
            cout << "Недопустимый ход. Попробуйте еще раз." << endl;
        }
    }

    Pole();
    return 0;
}
