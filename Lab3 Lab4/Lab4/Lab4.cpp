#include <iostream>
#include <algorithm>
using namespace std;

string s;

void f1(string de,int n)
{
    if(n==1)
    {
        cout<<de<<'\n';
        return;
    }
    for(int i=0;i<s.size();i++)
    {
        int j=0;
        for(;j<de.size();j++)
            if(de[j]==s[i])
                j=s.size()-1;
        if(j!=s.size())
        {
            f1(de+s[i],n-1);
        }
    }
    return;
}

void f2(string S,int i)
{
    if(i==s.size()-1)
    {
        cout<<S<<'\n';
        return;
    }
    for(int j=i;j<s.size();j++)
    {
        string tmp=S;
        swap(tmp[i],tmp[j]);
        f2(tmp,i+1);
    }
    return;
}

void f3(string S)
{
    do
    {
        cout<<S<<'\n';
    }while(next_permutation(S.begin(),S.end()));
    return;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin>>s;
    sort(s.begin(),s.end());

    //for(int i=0;i<s.size();i++)
    //    f1(s.substr(i,1),s.size());

    f2(s,0);

    //f3(s);
    cout<<flush;

    return 0;
}