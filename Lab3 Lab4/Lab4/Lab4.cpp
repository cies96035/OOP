#include <iostream>
#include <algorithm>
using namespace std;

string str;

void f1(string S,int i)
{
    if(i==str.size()-1)
    {
        cout<<S<<'\n';
        return;
    }
    for(int j=i;j<str.size();j++)
    {
        string tmp=S;
        swap(tmp[i],tmp[j]);
        f1(tmp,i+1);
    }
    return;
}

void f2(string de,int n)
{
    if(n==1)
    {
        cout<<de<<'\n';
        return;
    }
    for(int i=0;i<str.size();i++)
    {
        int j=0;
        for(;j<de.size();j++)
            if(de[j]==str[i])
                j=str.size()-1;
        if(j!=str.size())
        {
            f2(de+str[i],n-1);
        }
    }
    return;
}

bool my_next_permutation(string &s)
{
    int i=s.size()-2,j=s.size()-1,k=s.size()-1;

    //(j,end]
    for(;i>=0;i--,j--)
        if(s[i]<s[j])
            break;
    
    //can't find pair(i,j) s[i]<s[j]
    if(i<0)
        return false;

    //find k which after j and s[k]>s[i]
    for(;j<=k&&s[i]>=s[k];k--);
    swap(s[i],s[k]);//swap

    //s.reverse(j,k)
    for(k=s.size()-1;j<k;j++,k--)
        swap(s[j],s[k]);

    //success find next_permutation
    return true;
}

void f3(string &S)
{
    do
    {
        cout<<S<<'\n';
    }while(my_next_permutation(S));//until there's no next_permutation
    return;
}


void choose_method(int k)
{
    switch(k)
    {
        case 1:
            f1(str,0);
            break;
        case 2:
            for(int i=0;i<str.size();i++)
                f2(str.substr(i,1),str.size());
            break;
        case 3:
            f3(str);
            break;
    }
    return;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    while(cin>>str)
    {
        sort(str.begin(),str.end());

        choose_method(1);
        cout<<flush;
    }
    return 0;
}
