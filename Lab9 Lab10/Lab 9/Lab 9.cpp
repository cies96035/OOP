#include <iostream>
#include <fstream>
using namespace std;

ifstream input("input.txt");
int num;
class Heap
{
    public:
        //create a Heap with required arrsize
        Heap(const int &size)
        {
            arr=new int[size+1];
            lastindex=0;
        }
        //destructor
        ~Heap()
        {
            delete [] arr; 
        }

        //return Left child index
        int LC(const int &root)
        {
            return root*2;
        }
        //return Right child index
        int RC(const int &root)
        {
            return root*2+1;
        }
        //return Parent index
        int Parent(const int &child)
        {
            return child/2;
        }

        //push a new element with value
        void push(int value)
        {
            lastindex++;
            int id=lastindex;
            int P=Parent(id);
            arr[id]=value;
            
            //heapify
            while(P)
            {
                if(arr[P]>arr[id])
                {
                    swap(arr[P],arr[id]);
                    id=P;
                    P=Parent(P);
                }
                else
                    return;
            }
            return;
        }

        //pop the minimum element,and return it
        int pop()
        {
            //no element left
            if(lastindex<=0)
            {
                cout<<"no left element can pop\n";
                return 0;
            }
            int min=arr[1];
            int id=1;
            arr[id]=arr[lastindex];

            //heapify
            while(true)
            {
                if(RC(id)<lastindex)
                {
                    if(arr[LC(id)]<arr[RC(id)])
                    {
                        if(arr[LC(id)]<arr[id])
                        {
                            swap(arr[id],arr[LC(id)]);
                            id=LC(id);   
                        }
                    }
                    else
                    {
                        if(arr[RC(id)]<arr[id])
                        {
                            swap(arr[id],arr[RC(id)]);
                            id=RC(id);   
                        }
                    }
                }
                else if(LC(id)<lastindex&&arr[LC(id)]<arr[id])
                {
                    swap(arr[id],arr[LC(id)]);
                    id=LC(id);   
                }
                else
                    break;
            }
            lastindex--;
            return min;
        }

        //for test
        void Print_test()
        {
            cout<<"last index : "<<lastindex<<endl<<"array number:"<<endl;
            for(int i=1;i<lastindex;i++)
                cout<<arr[i]<<' ';
            cout<<arr[lastindex]<<endl;;
            return;
        }

        //input operatror
        friend void operator >> (istream &in , Heap &h)
        {
            int x;
            in >> x;
            h.push(x);
        }

    protected:

        //member
        int* arr;
        int lastindex;

};
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    //cannot find the file
    if(!input)
    {
        cout<<"cannot open input.txt\n";
        return 1;
    }

    //Heap size
    input >> num;
    Heap heap(num);

    //input Heap elements
    for(int i=0;i<num;i++)
        input >> heap;

    //output Heap element with sort
    for(int i=1;i<num;i++)
        cout << heap.pop() << ' ';
    cout << heap.pop() << '\n';

	system("pause");
    return 0;
}