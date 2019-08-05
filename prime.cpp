#include <iostream>
#include <math.h>
using namespace std;  
void check(long n)
{ double sq=sqrt(n);
    for(int i=2;i<=sq;i++)
    {
        if(n%i==0)
        {
            cout<<"\nnot prime\n";
            return ;
        }
    }
  cout<<"\nprime\n";
  return; 
}
int main() 
{    int t;          //for no of tests
     cin>>t;
     long num[t];
    for(int i=0;i<t;i++)
    {cin>>num[i];
    }
    for(int i=0;i<t;i++)
    { check(num[i]);
    }
    return 0; 
   } 
