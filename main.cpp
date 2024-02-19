#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <climits>
#define lmax 100

using namespace std;

int count_mines(char M[lmax][lmax], int row, int col, int n, int m) {
    int count = 0;
    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = col - 1; j <= col + 1; j++) {
            if (i >= 0 && i < n && j >= 0 && j < m && M[i][j] == '*') {
                count++;
            }
        }
    }
    return count;
}

void output_matr(char A[][lmax], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << setw(2) << left << *(*(A + i) + j);
        cout << '\n';
    }
}




int main(void) {
    int n, m, k, n_M, m_M;
    char M[lmax][lmax];

    cout << "Write n, m: " << endl;
    cin >> n;
    cin >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            M[i][j] = '0';
        }
    }


    
    cout << "Write k: " << endl;
    cin >> k;
    for (int i = 0; i < k; i++) {
        cout << "Write mine coords(n+1,m+1)" << endl;
        cin >> n_M;
        cin >> m_M;
        M[n_M - 1][m_M - 1] = '*';

    }
    cout << "Matrix before: " << endl;
    output_matr(M, n, m);

    cout << "Matrix after: " << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (M[i][j] != '*') {
                int count = count_mines(M, i, j, n, m);
                M[i][j] = count + '0';
            }

        }
    }
    output_matr(M, n, m);

    return 0;
}




































