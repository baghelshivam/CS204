#include <bits/stdc++.h>
#define ll long long int
#define M 1000000007
using namespace std;

class Edge
{
    public:
    ll src, dest, weight;
};

class Graph
{
    public:
    ll V, E;
    Edge* edge;
};

Graph* createGraph(ll V, ll E)
{
    Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
}

class subset
{
    public:
    ll parent;
    ll rank;
};

ll find(subset subsets[], ll i)
{
    if (subsets[i].parent != i) subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(subset subsets[], ll x, ll y)
{
    ll xroot = find(subsets, x);
    ll yroot = find(subsets, y);
    if (subsets[xroot].rank < subsets[yroot].rank) subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank) subsets[yroot].parent = xroot;
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int myComp(const void* a, const void* b)
{
    Edge* a1 = (Edge*)a;
    Edge* b1 = (Edge*)b;
    return a1->weight < b1->weight;
}

ll MaxWeight(Graph* graph)
{
	ll ans = 1;
    ll V = graph->V;
    Edge result[V];
    ll e = 0;
    ll i = 0;
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);
    subset *subsets = new subset[( V * sizeof(subset) )];
    for (ll v = 0; v < V; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    while (e < V - 1 && i < graph->E)
    {
        Edge next_edge = graph->edge[i++];
        ll x = find(subsets, next_edge.src);
        ll y = find(subsets, next_edge.dest);
        if (x != y)
        {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }
    for (i = 0; i < e; ++i) ans *= (result[i].weight%M);
    return ans%M;
}

int main()
{
	ll n, m;
	cin>>n>>m;
	ll x, y, w;

	Graph* graph = createGraph(n, m);

	for (ll i = 0; i < m; ++i)
	{
		cin>>x>>y>>w;
		graph->edge[i].src = x-1;
		graph->edge[i].dest = y-1;
		graph->edge[i].weight = w;
	}

	cout<<MaxWeight(graph);

	return 0;
}