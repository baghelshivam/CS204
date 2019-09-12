#include<bits/stdc++.h>
using namespace std;

bool compare(string a,string b)
  {
    string x=a+b;  //two possible number
    string y=b+a;
    int t = x.length();
    for(int i=0;i<t;i++){
        if(x[i]-'0' > y[i]-'0'){
                                 return true;
                               }
        else if(x[i]-'0' < y[i]-'0'){
                                    return false;
                                    }
                        }
    
    return true;
}
void merge(vector<string> &arr, int l, int m, int r) //for merging
{ 
    int i, j, k; 
    int n1=m-l+1; 
    int n2=r-m;
    vector<string> L, R; 
    for (i=0;i<n1;i++) 
        L.push_back(arr[l+i]); 
    for (j=0;j<n2;j++) 
        R.push_back(arr[m+1+j]); 
    i=0; 
    j=0; 
    k=l; 
    while (i<n1&&j<n2) 
    { 
        if (compare(L[i],R[j])) 
        { 
            arr[k]=L[i]; 
            i++; 
        } 
        else
        { 
            arr[k]=R[j]; 
            j++; 
        } 
        k++; 
    } 
    while (i<n1) 
    { 
        arr[k]=L[i]; 
        i++; 
        k++; 
    } 
    while (j<n2) 
    { 
        arr[k]=R[j]; 
        j++; 
        k++; 
    } 
} 
  
void mergeSort(vector<string> &arr, int l, int r) 
{ 
    if (l< r) 
    { 
        int m=l+(r-l)/2; 
        mergeSort(arr,l,m); 
        mergeSort(arr,m+1,r); 
        merge(arr, l, m, r); 
    } 
} 

int main()
{
    int t;
    cin>>t;
    for(int j=0;j<t;j++)
    {
        int n;
        cin>>n;
        vector<string> arr;
        string temp;
        for(int i=0;i<n;i++){
            cin>>temp;
            arr.push_back(temp);
        }
        mergeSort(arr,0,arr.size() - 1);
        string result = "";
        for(string x:arr){
            result+=x;
        }
        cout<<result<<'\n';
    }
    
    
    return 0;
}
