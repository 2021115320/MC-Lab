#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Function to calculate the determinant of a 3x3 matrix
int determinant(int mat[3][3]) {
    return mat[0][0] * (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1]) -
           mat[0][1] * (mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0]) +
           mat[0][2] * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]);
}

// Function to calculate the inverse of a 3x3 matrix
bool inverse(int mat[3][3], int inv[3][3]) {
    int det = determinant(mat);
    if (det == 0) {
        cout << "The matrix is singular and cannot be inverted." << endl;
        return false;
    }

    int invDet = 1.0 / det;

    // Calculate the adjugate matrix
    inv[0][0] = (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1]) * invDet;
    inv[0][1] = (mat[0][2] * mat[2][1] - mat[0][1] * mat[2][2]) * invDet;
    inv[0][2] = (mat[0][1] * mat[1][2] - mat[0][2] * mat[1][1]) * invDet;
    inv[1][0] = (mat[1][2] * mat[2][0] - mat[1][0] * mat[2][2]) * invDet;
    inv[1][1] = (mat[0][0] * mat[2][2] - mat[0][2] * mat[2][0]) * invDet;
    inv[1][2] = (mat[0][2] * mat[1][0] - mat[0][0] * mat[1][2]) * invDet;
    inv[2][0] = (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]) * invDet;
    inv[2][1] = (mat[0][1] * mat[2][0] - mat[0][0] * mat[2][1]) * invDet;
    inv[2][2] = (mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0]) * invDet;

    return true;
}


int main() {
    string msg;
    cout<<"Enter the message (Upper case):";
    getline(cin,msg);
    int i,j;
    int k=0;
    //Msg text 
    int msgmat[3][1];
    for(i=0;i<3;i++)
    {
        for ( j = 0; j<1; j++)
        {
            msgmat[i][j]=(msg[k])%65;
            k++;
        }
    }   
    cout << "MSG MATRIX:\n";
    for(i=0;i<3;i++)
    {
        for ( j = 0; j<1; j++)
        {
            cout<<msgmat[i][j];
            cout<<"\n";
        }
    }   

   // key value
   string key;
    cout<<"\nEnter the key (Upper case):";
    getline(cin,key);
    k=0;
    int keymat[3][3];
    for(i=0;i<3;i++)
    {
        for ( j = 0; j<3; j++)
        {
            keymat[i][j]=(key[k])%65;
            k++;
        }
    }   
    cout << "KEY MATRIX:\n";
    for(i=0;i<3;i++)
    {
        for ( j = 0; j<3; j++)
        {
            cout<<keymat[i][j];
            cout<<"\n";
        }
    }
    
    int inv[3][3];
    if (inverse(keymat, inv)) {
        // Print the inverse matrix
        cout << "Inverse Matrix:" << endl;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << setw(10) << fixed << setprecision(4) << inv[i][j] << " ";
            }
            cout << endl;
        }
    }
  
    
    int resmat[3][1] = {0};  

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 1; j++) {
            resmat[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                resmat[i][j] += inv[i][k] * msgmat[k][j];
            }
            resmat[i][j] %= 26;  
        }
    }
    cout << "\nDECRIPTED MATRIX:\n";
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 1; j++) {
            cout << resmat[i][j] << "\n";
        }
    }
    //Convert to string
    string encmsg;
    for (i = 0; i < 3; i++) {
        encmsg += char(resmat[i][0] + 'A');  
    }
    cout << "\nDECRIPTED MSG:\n" << encmsg << "\n";

    return 0;

}
