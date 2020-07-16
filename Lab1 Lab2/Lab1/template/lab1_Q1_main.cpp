#include<iostream>
#include "lab1_Q1.h"

using namespace std;

MATRIX matrix,matrix2;

// if f(flag) is 1 ,input matrix
//  else , input matrix2
void Input(bool f)
{
    int input[4];
    for(int i=0;i<4;i++)
        cin>>input[i];
    if(f)
        matrix=MATRIX(input[0],input[1],input[2],input[3]);
    else
        matrix2=MATRIX(input[0],input[1],input[2],input[3]);
}

int n;
char command;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin>>n;

    while(n--)
    {
        cin>>command;
        switch(command)
        {
            case '+':
                Input(1);
                Input(0);
                matrix.add(matrix2);
                break;
            case '*':
                Input(1);
                Input(0);
                matrix.multiple(matrix2);
                break;
            case 'p':
                Input(1);
                matrix.print();
                break;
            case 'd':
                Input(1);
                matrix.det();
                break;
            default:
                cout<<"wrong input\n";
                break;
        }
    }
    //system("PAUSE");
    return 0;
}
