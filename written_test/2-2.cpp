#include <iostream>
using namespace std;
class A 
{
    public:
        int a;	 
        A( ) { a =11 ; }
        A( int a)  {  (*this).a = a; }
        void printf() const 
        { 
            cout << "A:" << "\t" << a << endl;
        }
};
class B: public A 
{
    public: 
        int b;
        B( ) { b = 12; }
        B (int b) 
        { 
            this->b = b + a; 
            cout << "B:" << b++ << endl; 
        }
        virtual void printf() const 
        { 
            cout << "B:" << "\t" << b << endl;
        }
};
class C: public A 
{
    public: 
        int a;
        C( ): A(13) 
        { 
            a = 10; 
            cout << "a:" << A::a << endl; 
        }
        C(int c): A( ) 
        { 
            this->a = c; 
            cout << "C:" << a << endl; 
        }
        virtual void printf() const 
        { 
            cout << "C:" << "\t" << C::a << "\t" << A::a << endl; 
        }
};

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    B a;
    a.printf( );	    // L1

	B b(1); 		    // L2

	C c(2); 		
    A *pa = &b;	        // L3

	pa->printf( );
    C *pc;        		// L4
    
	if ( pc = dynamic_cast<C*>(&b) )
     	pc->printf( );	// L5

    return 0;
}