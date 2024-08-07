#include <iostream>
#include <string.h>
using namespace std;

int main()
{

    cout<<"Enter the message:";
    char msg[100];
    cin.getline(msg,100);
    int key,i,j,length;
    cout<<"Enter key value:";
    cin>>key;
    char ch;
    length=strlen(msg);
    for(i=0;i<length;i++)
    {
    	ch =msg[i];
    	if(ch>='a' && ch<='z')
    	{
    		ch=ch+key;
    		
    		if (ch > 'z') 
			{
               ch = ch - 'z' + 'a' - 1;
            }  
            msg[i] = ch;
		}
		
		else if(ch>='A' && ch<='Z')
    	{
    		ch=ch+key;
    		
    		if (ch > 'Z') 
			{
               ch = ch - 'Z' + 'A' - 1;
            }  
            msg[i] = ch;
		}
	}
	
	cout<<"Encripted msg:"<<msg;
}