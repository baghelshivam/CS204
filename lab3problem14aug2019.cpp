#include<bits/stdc++.h> 
using namespace std; 
int main()
{
     int n;
     string output="";
         cout<<"enter no of test cases:";
         cin>>n;
  for(int i=1;i<=n;i++)
   {
         string s1;
         stack<char> s;
         cin>>s1;
         int a=s1.length();
                for(int j=0;j<a;j++)
               {
                       if(s1[j]=='('||s1[j]=='{'||s1[j]=='['||s1[j]=='<')  s.push(s1[j]);
                       
                       if(s1[j]==')') 
                          {    if(s.empty())
                                   {  output=output+"NO\n"; goto j;
                                    }

                              else{   if(s.top()=='(') s.pop();  
                                        else {output=output+"NO\n"; goto j;}
                                  }
                          }

                       if(s1[j]=='}')
                          {    if(s.empty())
                                   {  output=output+"NO\n"; goto j;
                                    }

                              else{   if(s.top()=='{') s.pop();  
                                        else {output=output+"NO\n"; goto j;}
                                  }
                          }

                       if(s1[j]==']')
                          {    if(s.empty())
                                   {  output=output+"NO\n"; goto j;
                                    }

                              else{   if(s.top()=='[') s.pop();  
                                        else {output=output+"NO\n"; goto j;}
                                  }
                          }       
                           
                       if(s1[j]=='>')
                          {   if(s.empty())
                                   {  output=output+"NO\n"; goto j;
                                    }

                              else{   if(s.top()=='<') s.pop();  
                                        else {output=output+"NO\n"; goto j;}
                                  }
                          }
 
                       if(s1[j]=='|')
                         {    if(s.empty()) s.push(s1[j]);
                              else {   
                                        if(s.top()!='|') s.push(s1[j]);
                                        else{ s.pop(); } 
                                   } 
                         }
               }     
            if(s.empty()) output=output+"YES\n";
            else output=output+"NO\n";
    j: cout<<"";
}
cout<<"output:\n"<<output;
return 0;
}

