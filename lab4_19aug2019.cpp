#include <bits/stdc++.h>
#define lli long long int
#define pb push_back
#define vt vector
//#define f(x, y, z) for (lli x = y; x < z; x++)
using namespace std;
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
vector<string> formvector(string s)

{
    int n = s.size();
    vector<string> st;
    for(int i = 0; i<n;i++)
        { string temp="";
        if((s[i] >= '0' && s[i] <= '9')) 
        { int j = i;
                       for(;(s[j] >= '0' && s[j] <= '9');j++){
                                                  temp+=s[j];}
            i = j-1;
        }
        else 
        {temp+=s[i];
          }
        st.push_back(temp);
        }
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
int convert(string s)   //function for converting an string into
{  
    int num = 0;
                                     // Check if the integral value is  negative or not      If it is not negative, generate the number normally 
    if(s[0]!='-') 
        for (int i=0; i<s.length(); i++)  
            num = num*10 + (int(s[i])-48);  
                                           // If it is negative, calculate the +ve number first ignoring the sign and invert the sign at the end 
    else
        for (int i=1; i<s.length(); i++)  
        { 
            num = num*10 + (int(s[i])-48);  
            num = num*-1; 
        } 
      
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
                            // for an operand 
         if(!((s[i][0]=='*')||(s[i][0]=='+')||(s[i][0]=='-')||(s[i][0]=='/')||(s[i][0]=='^')))
          { ns.push_back(s[i]);}
         else             //for operation
          { if(st.empty()) { st.push(s[i]); continue;}        //if stack is empty then push directly
            if(prec(s[i][0])>prec((st.top())[0])) { st.push(s[i]);    continue ;}
          /*  if((s[i][0]!='^'))  
              {  if((prec(s[i][0])<prec((st.top())[0])))
                 { while(prec(s[i][0])<=prec((st.top())[0])&&(!st.empty()))//untill the element with same precedence and empty                          
                     {  ns.push_back(st.top());
                        st.pop();     
                     }
                st.push(s[i]); }
              }     
            else  { if(prec(s[i][0])==prec((st.top())[0])) { st.push(s[i]); continue ;} 
                  }*/
           if(prec(s[i][0])==prec((st.top())[0]))
              {  if((s[i][0]!='^')) { ns.push_back(st.top()); st.push(s[i]); continue ;}  
                 else{ st.push(s[i]); continue ;}
              }
           if(prec(s[i][0])<prec((st.top())[0]))
           { while((!st.empty()))//check if work with empty
              { ns.push_back(st.top());
                  st.pop(); 
              }
             st.push(s[i]); 
            }
          }
    }
    while(!st.empty()) 
    { 
        string c = st.top(); 
        st.pop(); 
        ns.push_back(c);
    } 
return ns;
}
         //for making of tree


tree* buildtree(vector<string> postfix) 
{ 
    stack<tree *> st; 
    tree *t, *t1, *t2; 
                            // Traverse through every character of input expression 
    for (int i=0; i<postfix.size(); i++) 
    { 
        // If operand, simply push into stack 
        if (!((postfix[i][0]=='*')||(postfix[i][0]=='+')||(postfix[i][0]=='-')||(postfix[i][0]=='/')||(postfix[i][0]=='^'))) 
        { 
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
        return convert(root->data);
  
    // Evaluate left subtree  
    int l_val = eval(root->left);  
  
    // Evaluate right subtree  
    int r_val = eval(root->right);  
  
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
      {  string s;
          cin>>s;
          vector<string> postfix=formvector(s);
          postfix=conversion(postfix);    //changes infix to postfix
          tree* root=buildtree(postfix);
          if(root!=NULL)
          {
          cout<<eval(root)<<"\n";
          }
          else{cout<<"CAN'T BE EVALUATED\n";}
      }
  }
return 0;
}







