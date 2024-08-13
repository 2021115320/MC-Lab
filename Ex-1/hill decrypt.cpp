#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Function to calculate the determinant of a 2x2 matrix
int determinant(int mat[2][2]) {
    return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
}

// Function to calculate the inverse of a 2x2 matrix
void inverse(int mat[2][2], int msgmat[2][1], int det) {
    double invDet = 1.0 / det; // Calculate the inverse of the determinant

    // Calculate the inverse matrix
    int inv[2][2];
    inv[0][0] = mat[1][1] * invDet;
    inv[0][1] = -mat[0][1] * invDet;
    inv[1][0] = -mat[1][0] * invDet;
    inv[1][1] = mat[0][0] * invDet;

    cout << "\nINVERSE MATRIX:\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << inv[i][j] << "\n";
        }
    }

     int resmat[2][1] = {0};

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 1; j++) {
            resmat[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                resmat[i][j] += inv[i][k] * msgmat[k][j];
            }
            resmat[i][j] %= 26;
        }
    }

    cout << "\nDECRYPTED MATRIX:\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 1; j++) {
            cout << resmat[i][j] << "\n";
        }
    }

    // Convert to string
    string decmsg;
    for (int i = 0; i < 2; i++) {
        decmsg += char(resmat[i][0] + 'A');
    }

    cout << "\nDECRYPTED MSG:\n" << decmsg << "\n";
}

int main() {
    string msg;
    cout << "Enter the message (Upper case): ";
    getline(cin, msg);

    if (msg.length() < 2) {
        cout << "Message too short! Padding with 'X'." << endl;
        msg += 'X'; // Padding if the message length is less than 2
    }

    int i, j;
    int k = 0;

    // Message matrix
    int msgmat[2][1];
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 1; j++) {
            msgmat[i][j] = (msg[k]) % 65;
            k++;
        }
    }

    cout << "MSG MATRIX:\n";
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 1; j++) {
            cout << msgmat[i][j] << "\n";
        }
    }

    // Key matrix
    string key;
    cout << "\nEnter the key (4 uppercase letters): ";
    getline(cin, key);

    if (key.length() < 4) {
        cout << "Key too short! Exiting." << endl;
        return -1;
    }

    k = 0;
    int keymat[2][2];
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            keymat[i][j] = (key[k]) % 65;
            k++;
        }
    }

    cout << "KEY MATRIX:\n";
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            cout << keymat[i][j] << "\n";
        }
    }

    int deter = determinant(keymat);
    cout << "Determinant of the KEY MATRIX: " << deter << "\n";
    inverse(keymat,msgmat,deter);
    return 0;
}
