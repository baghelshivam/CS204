#include<iostream>
#include<vector>
using namespace std;
struct user
{
 long long int id;
 long long int rec;//for recharge
};
int main()
{
vector<user> v;  //defining vector of my new data type user
int k=0,q,a;
cout<<"ENTER NO. OF QUERIES:";
cin>>q;  //for no of lines  (QUERIES)
while(k<q)
{
cin>>a;
	if(a==1)
	{ 
	   int b,c,count=0,index=0;
 	  cin>>b>>c;   //in this case it will take two inputs user id  and amount of recharge
 	     for(auto it=v.begin();it!=v.end();it++)
	     {
 	        if((it->id)==b) 
                  {   count++;      // updating the recharge done by user 
                                                      // cout<<":::::: v[i].id  "<<it->id<<"   v[i].rec  "<<it->rec<<endl;
                      it->rec+=c; 
                                                      //cout<<"updated v[i].rec  "<<it->rec;
                     break ;
                  }
 	     }
                if(count==0) {   struct user s;
                                 (s.id)=b; (s.rec)=c;           //creating a new node and then pushing in v
                                 v.push_back(s);
                              }
	}
	if(a==2)
	{ 
               auto max=v.begin(); 	 
 	     for(auto it=v.begin();it!=v.end();it++)
 	     { if((it->rec)>(max->rec)) { max=it; }
	      }
            if(v.empty()) cout<<"No data available.\n";            //if no input is given then vector will be empty 
 	    else cout<<"output:"<<(max->id)<<endl;
	}
k++;
}
return 0;
}
