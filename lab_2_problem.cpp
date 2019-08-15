#include<iostream>
#include<cmath>
#include<string>
using namespace std;
struct node{
int x;
int y;
struct node *next;
};
string out="";// declearing the string for output storage
void addfirst(int a,int b);
void delfirst();
void del(int a,int b);
void search(float d);
bool search(int x,int y);
int length();
void task(int a,int x,int y) //function declearation for calling each 
{
   switch(a)
 { case 1: addfirst(x,y); break;
   case 2: delfirst(); break;
   case 3: del(x,y); break;
   case 4: search(x); break;     // here x is d    
   case 5: if(search(x,y)) out=out+"true\n";
           else    out=out+"false\n";
            break;   //will print true and false
   case 6: length(); break;
 }
}
 
struct node *start=NULL;
int main()
{                             //FOR STOP LOOP CLICK EITHER 0 OR ANY DIGIT GREATER THAN PERFORMED
int n;
cout<<"PLEASE INPUT NUMBER 0F OPERATION TO BE PERFORMED:";
cin>>n;
for(int i=1;i<=n;i++)
{     int a=0,y=0;   float x=0;
       cin>>a;
       if(a==0||a>6)
        {   cout<<"function not available corresponding to given input:"<<a<<endl;  break ; }   
                         
       if(!(a==2||a==6||a==4))
        {   cin>>x;
            cin>>y;
        } 

       if(a==4)
        {cin>>x;}

       task(a,x,y);
}
  
cout<<"OUTPUT:"<<out;

return 0;

}//main close now function defination


void addfirst(int a,int b)
{
struct node *temp=new node;
//newnode=malloc(sizeof(struct node)); 
temp->x=a;
temp->y=b;
temp->next=NULL;
if(start==NULL)
{ start=temp;}
else{temp->next=start; //doubt
    start=temp;}
}

   
void delfirst()
{
struct node *temp;
temp=start;
if(temp==NULL)         //checking whether linked list is empty or not
{ out=out+"-1\n"; return ;
}
start=temp->next;
delete temp;
}


void del(int a,int b)
{ struct node *temp,*prev;
 temp=start;
      if(start == NULL) 
          { out=out+"-1\n";
                return ;
           }

      if (temp->x==a&&temp->y==b)  // checking for whether fir 
            { 
                start = temp->next;   // Changed start 
                delete temp;               // free old start
                return; 
             } 

       while (temp != NULL && !(temp->x==a&&temp->y==b)) 
            { 
              prev = temp;                //means this loop will end only when either we reached last element or we found our element 
             temp = temp->next; 
            }
 
        if (temp == NULL) 
          { out=out+"-1\n";     
            return ;}
 
   prev->next = temp->next; 
   delete temp;
}


void search(float d)
{ int x,y;
  struct node *temp;
  temp=start;
int count=0;
  while(temp!=NULL)
        {
                 float r=sqrt((temp->x)*(temp->x)+(temp->y)*(temp->y));
                     if(r<=d)
                         { count++;     
                          }
                 temp=temp->next;
        }
if(count!=0) out.push_back(count+'0');
else out=out+"-1"; 
 
out=out+"\n";
}//end of function search


bool search(int a,int b)
{ struct node *temp;
  temp=start;
    while (temp != NULL)  
    {  
        if (temp->x == a && temp->y == b)  
            return true;  
        temp = temp->next;  
    }  
    return false;

}


int length()
{struct node *temp;
 temp=start;
int n=0; // because when condition false n wiil not increase
 while(temp!=NULL)
  { n=n+1;
   temp=temp->next;
     }
out.push_back(n+'0');
out=out+"\n";
return 0;
}


