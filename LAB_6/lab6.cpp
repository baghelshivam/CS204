#include<iostream>
using namespace std;
int main()
{
int n,a,t=0;  //no of users
cout<<"ENTER THE NO OF USERS:";
cin>>n;
long long int x[n][2];
for(int i=0;i<2;i++)            //intialising whole array to zero
{ for(int j=0;j<n;j++)
    { x[j][i]=0;
    }  
}
int k=0,q;
cout<<"ENTER NO. OF QUERIES:";
cin>>q;  //for no of lines  (QUERIES)
while(k<q)
{
cin>>a;
	if(a==1)
	{ 
	   int b,c,count=0,index=0;
 	  cin>>b>>c;   //in this case it will take two inputs user id  and amount of recharge
 	     for(int i=0;i<n;i++)
	     {
 	        if(x[i][0]==b) 
                  {   count++;       // updating the recharge done by user 
                     x[i][1]+=c; 
                     break ;
                  }
                if(x[i][0]!=0) index=i;
 	     }
                if(count==0) { x[index+1][0]=b; x[index+1][1]=c; }
	}
	if(a==2)
	{ 
 	   int max=0;
 	     for(int i=0;i<n;i++)
 	     { if(x[i][1]>x[max][1]) { max=i; }
	      }
            if(x[max][0]==0) cout<<"No data available.\n";
 	    else cout<<"output:"<<x[max][0]<<endl;
	}
k++;
}


return 0;
}
