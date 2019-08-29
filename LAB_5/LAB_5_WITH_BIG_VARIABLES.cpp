#include <bits/stdc++.h>

using namespace std;
map<string,int> v;   //globally declearing map
struct tree 
{                                //defining tree
    string data; 
    tree* left, *right; 
}; 

tree* newNode(string v) 
{                                //newnode function fortree
    tree *temp = new tree; 
    temp->left = temp->right = NULL; 
    temp->data = v;

    return temp; 
}; 

vector<string> formvector(string s)     //working fine
{
	int n = s.size();
	vector<string> st;
	for(int i = 0; i<n;i++)
	        { string temp="";
	         if(s[i]=='-'&&(i==0))
	           {	             temp=+s[0];
	                             int j = i+1;
	                             for(;(s[j] >= '0' && s[j] <= '9')||(s[j]>=97&&s[j]<=122);j++)
	                              {
	                             temp+=s[j];
	                               }
	               		       i=j-1;
	           }
	     else{           if(s[i]>=97&&s[i]<=122) //for variable storage
                             {   int k=i;
                                     for(;s[k]>=97&&s[k]<=122;k++)
                                        { temp+=s[k];  
                                        }
                                           i=k-1;                              
                                        }
                             else{
                                
	                                if((s[i] >= '0' && s[i] <= '9')) 
        	                           { int j = i;
	                                         for(;(s[j] >= '0' && s[j] <= '9');j++)
                                                    {
	                                              temp+=s[j];
                                                    }
	                                       i = j-1;
	                                    }
	                                else 
	                                    { 
                                      			if(s[i]=='-'&&!((s[i-1] >= '0' && s[i-1] <= '9')||(s[i-1]>=97&&s[i-1]<=122)))
                                       			{   temp=+s[i];
                                            			int j = i+1;
	                                        		for(;(s[j] >= '0' && s[j] <= '9')||(s[j]>=97&&s[j]<=122);j++) 
	                                        		{
	                                         			temp+=s[j];
	                                        		}
                                           			i=j-1;
                                      			}
                                      			else {temp+=s[i];} 
	                         	    }
                                 }
	        
	         }   st.push_back(temp);
	      }  cout<<"HELLO FORMVECTOR:";
	        return st;

	}
int prec(char c)   //precedence
{ 
    if(c == '^') 
    return 3; 
    else if(c == '*' || c == '/') 
    return 2; 
    else if(c == '+' || c == '-') 
    return 1; 
    else
    return -1; 
} 
                          //convert function is also working fine
int convert(string s)   //function for converting an string into
{  
    int num = 0;
                                     // Check if the integral value is  negative or not      If it is not negative, generate the number normally 
    if(s[0]!='-') 
        for (int i=0; i<s.length(); i++)  
            num = num*10 + (int(s[i])-48);  
                                           // If it is negative, calculate the +ve number first ignoring the sign and invert the sign at the end 
    else{
        for (int i=1; i<s.length(); i++)  
        { 
            num = num*10 + (int(s[i])-48);  
            
        } 
       num = num*-1;}
  return num;  
}  
                              
   //for infix to postfix 
vector<string> conversion(vector<string> s) 
{ 
    stack<string> st; 
     int l = s.size(); 
    vector<string> ns; 
    for(int i = 0; i < l; i++) 
    { 
                            // for an operand even take -number as operand
         if(!(((s[i][0]=='*')||(s[i][0]=='+')||s[i][0]=='-'||(s[i][0]=='/')||(s[i][0]=='^'))&&(s[i].size()==1)))
          {  
              ns.push_back(s[i]);
          }
         else             //for operation
          { if(st.empty()) { st.push(s[i]);}        //if stack is empty then push directly
            else{      if(prec(s[i][0])>prec((st.top())[0])) { st.push(s[i]); }
                       else{        if(prec(s[i][0])==prec((st.top())[0]))
                                      {  if((s[i][0]!='^')) { ns.push_back(st.top());
                                                              st.pop();
                                                              st.push(s[i]);}  
                                         else{ st.push(s[i]); }
                                      }

                                    else {if(prec(s[i][0])<prec((st.top())[0]))
                                              { while((!st.empty()))//check if work with empty
                                                  { ns.push_back(st.top());
                                                    st.pop(); 
                                                  }
                                                   st.push(s[i]); 
                                               }
                                          }
                           }
                }
          }
    }
    while(!st.empty()) 
    { 
        string c = st.top(); 
        st.pop(); 
        ns.push_back(c);
    } 
cout<<"\nDOING CONVERSION:";
return ns;
}       //for making of tree


tree* buildtree(vector<string> postfix) 
{ 
    stack<tree*> st; 
    tree *t, *t1, *t2; 
                            // Traverse through every character of input expression 
    for (int i=0; i<postfix.size(); i++) 
    { 
        // If operand, simply push into stack 
 if(!(((postfix[i][0]=='*')||(postfix[i][0]=='+')||postfix[i][0]=='-'||(postfix[i][0]=='/')||(postfix[i][0]=='^'))&&(postfix[i].size()==1)))
        {   cout<<"data is:"<<postfix[i];
            t = newNode(postfix[i]); 
            st.push(t); 
        } 
        else // operator 
        { 
            t = newNode(postfix[i]); 
  
            // Pop two top nodes 
            t1 = st.top(); // Store top 
            st.pop();      // Remove top 
            t2 = st.top(); 
            st.pop(); 
            
            //  make them children 
            t->right = t1; 
            t->left = t2; 
  
            // Add this subexpression to stack 
            st.push(t); 
        } 
    } 
  
    //  only element will be root of expression 
    // tree 
    t = st.top(); 
    st.pop(); 
  
    return t; 
} 
  



int eval(tree* root)  
{  
    // empty tree  
    if (!root)  
        return 0;  
  
    // leaf node i.e, an integer  
    if (!root->left && !root->right) 
     { if(((root->data)[0]=='-'&&((root->data)[1]>=97&&(root->data)[1]<=122))) //for the unary minus of variable
          { 			cout<<root->data<<endl; 
                                cout<<"data size:"<<root->data.size()<<endl; 
                               string c; int i=1; 
       			 while(i<(root->data.size())) 
        			 {                           //for erasing '-'
        			 c=c+root->data[i]; 
        			   i++; 
    				 } cout<<"data:\n"<<c;
                return -1*v[c];
          } 
          else { if((root->data)[0]>=97&&(root->data)[0]<=122) return v[root->data];    //for the  variable key,return the value of variable
              else  {
                     return convert(root->data);   // when data is simple no
                     }
            } 
     }
    // Evaluate left subtree  
    long int l_val = eval(root->left);
    
  
    // Evaluate right subtree  
    long int r_val = eval(root->right);


    // Check which operator to apply  
    if (root->data=="+")  
        return l_val+r_val;  
  
    if (root->data=="-")  
        return l_val-r_val;  
  
    if (root->data=="*")  
        return l_val*r_val;  
    if (root->data=="/")
       return l_val/r_val;
    if (root->data=="^")
       return pow(l_val,r_val);
    
}  
  
int main()
{ 
int t,n;
  cin>>t;        //for no of test cases
  cin>>n;      //for no of lines
  for(int i=0; i<t;i++)
  {   
      for(int j=0;j<n;j++)
      {  
          string s;        //c for storing right side expression
          cin>>s;
          vector<string> p=formvector(s);
         if(p[1]=="=")  //checking for assignment expression 
         {  
         string c=p[0];   //storing key for variable
         p.erase(p.begin(), p.begin() + 2);  //deleting key and =
         p=conversion(p);    //changes infix to postfix
         tree* r=buildtree(p);
         cout<<" CONFUSION:"<<c<<endl;
         v[c]=eval(r);  //storing value corresponding to variable key
        // cout<<"BIGGER:"<<v[c]<<endl;
         }
      else{                 //for not assignment operation
              cout<<"BIGGER:"<<v["xy"]<<endl;
              cout<<p[0];
              p=conversion(p);    //changes infix to postfix
              tree* root=buildtree(p);
              if(root!=NULL)
              {
              cout<<"\n"<<eval(root)<<"\n";
              }
              else{cout<<"CAN'T BE EVALUATED\n";}
          }
       }
  }
return 0;
}
