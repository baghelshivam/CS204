#include <bits/stdc++.h>
#define f(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<string> a, b;
	string s;
	f(i, 0, n)
	{
		cin >> s;
		string ar = s;
		reverse(ar.begin(), ar.end());
		if(s != ar)
		{
			a.pb(s);
			b.pb(ar);
		}
	}
	sort(a.begin(), a.end());
	f(i, 0, b.size())
	{
		if (binary_search(a.begin(), a.end(), b[i]))
		{
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}