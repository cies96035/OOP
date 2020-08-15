#include <iostream>
using namespace std;
class A 
{
	public:
     	A( ) {  cout<<"A()"<<endl; x = 1; y = 2; }
        A(int a): x(a), y(a+1) { cout<<"A(int)"<<endl;  }
		int x, y;
};
class B : public A 
{
	public:
     	B( ): A( 2 ) { cout<<"B()"<<endl; x = y+1; }
        B( int a )  { cout<<"B(int)"<<endl; x = ++a; }
};

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    A a;//A()
    //a.x=1 a.y=2
    cout<<endl;

    B x(1);//A()->B(int)
    //x.x=1 x.y=2
    //x.x=2 x.y=2
    cout<<endl;

    B y;//A(int)->B()
    //y.x=2 y.y=3
    //y.x=4 y.y=3
    cout<<endl;

	y.x = --(x.x) + ++(a.y); 	// L1
    //x.x=1 a.y=3
    //y.x=4

    cout<<a.x<<endl;//1
    cout<<a.y<<endl;//3
    cout<<x.x<<endl;//1
    cout<<x.y<<endl;//2
    cout<<y.x<<endl;//4
    cout<<y.y<<endl;//3
    return 0;
}
/*
ans:
3
1
4
3
*/