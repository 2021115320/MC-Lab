#include <iostream>
#include <string>
using namespace std;

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
    
    int resmat[3][1] = {0};  

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 1; j++) {
            resmat[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                resmat[i][j] += keymat[i][k] * msgmat[k][j];
            }
            resmat[i][j] %= 26;  
        }
    }
    cout << "\nENCRIPTED MATRIX:\n";
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 1; j++) {
            cout << resmat[i][j] << "\n";
        }
    }
    
    string encmsg;
    for (i = 0; i < 3; i++) {
        encmsg += char(resmat[i][0] + 'A');  
    }
    cout << "\nENCRIPTED MSG:\n" << encmsg << "\n";

    return 0;

}
