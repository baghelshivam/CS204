#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

lli arr[1000][1000];
lli visited[1000][1000];
lli m, n,col;
lli ct;

int check(int key,int i,int j )
{
	if(key==arr[i][j] && visited[i][j]==0)
		return 1;
	else 
		return 0;

}

void reset_visited(lli n, lli m) 
{ 
    for (lli i = 0; i < n; i++) 
        for (lli j = 0; j < m; j++) 
            visited[i][j] = 0; 
} 

lli dfs(lli i, lli j)
{

    visited[i][j] = 1;
    lli c=1;
   
    if(j+1<n && check(arr[i][j],i,j+1)  )
		{
			c+=dfs(i,j+1);
		}
	if(j-1>=0 && check(arr[i][j],i,j-1)  )
		{
			c+=dfs(i,j-1);
		}
	if(i+1<m && check(arr[i][j],i+1,j))
		{
			c+=dfs(i+1,j);
		}
	if(i-1>=0 && check(arr[i][j],i-1,j))
		{
			c+=dfs(i-1,j);
		}
    
    return c;
}

void ans(lli mx[]){

	reset_visited(m,n);
    for(lli i = 0; i < m; i++)
    {
        for(lli j = 0; j < n; j++)
        {
            if(visited[i][j] == 0)
            {
                lli d=dfs(i,j);
                if( d > mx[0])
                {
                    mx[0] = d;
                    mx[1] = arr[i][j];
                }
            }
        }
    }
}

int main()
{
    cin >> m >> n >> col ;
    lli mx[2];
    mx[0]=INT_MIN;
    for(lli i = 0; i < m; i++)
        for(lli j = 0; j < n; j++)
            cin >> arr[i][j];
    ans(mx);
    cout <<"Largest component of size : "<<mx[0] <<" , color : "<< mx[1]<<" "<<endl;

    return 0;
}