#include<bits/stdc++.h>
using namespace std;
int partition(float arr[], int l, int r, int k); 

float findMedian(float arr[], int n) 
{ 
	sort(arr, arr+n);  
	return arr[n/2]; 
} 


float halfsmallest(float arr[], int l, int r, int k) 
{ 
	
	if (k > 0 && k <= r - l + 1) 
	{ 
		int n = r-l+1; 

		
		int i;
                float median[(n+4)/5];
		for (i=0; i<n/5; i++) 
			median[i] = findMedian(arr+l+i*5, 5); 
		if (i*5 < n) 
		{ 
			median[i] = findMedian(arr+l+i*5, n%5); 
			i++; 
		}	 

		
		int medOfMed = (i == 1)? median[i-1]: 
								halfsmallest(median, 0, i-1, i/2); 

		
		int pos = partition(arr, l, r, medOfMed); 

		
		if (pos-l == k-1) 
			return arr[pos]; 
		if (pos-l > k-1) 
			return halfsmallest(arr, l, pos-1, k); 

		
		return halfsmallest(arr, pos+1, r, k-pos+l-1); 
	} 

	
	return INT_MAX; 
} 

void swap(float *a, float *b) 
{ 
	float temp = *a; 
	*a = *b; 
	*b = temp; 
} 


int partition(float arr[], int l, int r, int x) 
{ 
	
	int i; 
	for (i=l; i<r; i++) 
		if (arr[i] == x) 
		break; 
	swap(&arr[i], &arr[r]); 

	
	i = l; 
	for (int j = l; j <= r - 1; j++) 
	{ 
		if (arr[j] <= x) 
		{ 
			swap(&arr[i], &arr[j]); 
			i++; 
		} 
	} 
	swap(&arr[i], &arr[r]); 
	return i; 
}
int main()
{
int t;
cin>>t;
while(t--)
{ int n,x,y;
  cin>>n;
  float a[n];
  for(int i=0;i<n;i++)
     { 
       cin>>x;
       cin>>y;
       a[i]=pow((x*x+y*y),0.5);
      }
 if(n%2==0) cout<<halfsmallest(a,0,n-1,n/2);
 else cout<<halfsmallest(a,0,n-1,(n+1)/2);
}
return 0;
}


