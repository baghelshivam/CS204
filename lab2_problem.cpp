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
{                             //FOR STOP LOOP CLICK EITHER 0 OR ANY DIGIT GREATER THAN 6
cout<<"PLEASE INPUT AND AFTER INPUT ENTER  0 OR ANY DIGIT GREATER THAN 6 FOR DISPLAYING OUTPUT:\n";
for(int i=0;;i++)
{int a=0,y=0;
float x=0;
cin>>a;
if(a==0||a>6)
{break ; }                          
if(!(a==2||a==6||a==4))
{cin>>x;
cin>>y;
}
if(a==4)
{cin>>x;}
task(a,x,y);
}
cout<<out;
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
{struct node *temp;
temp=start;
start=temp->next;
delete temp;
}

void del(int a,int b)
{ struct node *temp,*prev;
 temp=start;
if (temp != NULL && (temp->x==a&&temp->y==b)) 
    { 
        start = temp->next;   // Changed start 
        delete temp;               // free old start
        return; 
    } 

while (temp != NULL && (temp->x==a&&temp->y==b)) 
    { 
        prev = temp;                //means this loop will end only when either we reached last element or we found our element 
        temp = temp->next; 
    }
   if (temp == NULL) return;
   prev->next = temp->next; 
   delete temp;
}

void search(float d)
{ int x,y;
  struct node *temp;
  temp=start;
  while(temp!=NULL)
  {
 float r=sqrt((temp->x)*(temp->x)+(temp->y)*(temp->y));
  if(r<=d)
 {       out=out+"(";
 out.push_back(temp->x+'0');
 out=out+",";                      //for storing (x,y) in out string for output
 out.push_back(temp->y+'0');
 out=out+")";}
  temp=temp->next;
 }
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
out=out+"length:";
out.push_back(n+'0');
return 0;
}

