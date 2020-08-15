#include <iostream>
using namespace std;
class A 
{
    public: 
        A( ) { x = 1; }
        A &operator=(A a) { x = x + 2*a.x;} 
        int x;
};
void k( ) 
{
    A a;
    (a = (a = *(new A)));   			
    cout << a.x << endl;   				//L1
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    k();
    return 0;
}
/*
ans:
?
?
9
*/