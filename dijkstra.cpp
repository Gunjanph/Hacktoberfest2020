#include<iostream>
#include<queue>
using namespace std;
priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
vector<pair<int, int> >edge[100000];
vector<bool> visited;
vector<int> distance_source;
void addedge(int u,int v,int w)
{
	edge[u].push_back(make_pair(w,v));
	edge[v].push_back(make_pair(w,u));
}
void print_distance(int source){
	cout << "Source is " << source << endl;
	for(int i = 0; i <=distance_source.size(); i++){
		cout << i << ":" << distance_source[i] << " ";
	}
	cout << endl;
}
void dijkstra(int source)
{
	// pq.clear();
	pq = priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>();
	pq.push(make_pair(0,source));
	while(pq.size()!=0)
	{
		pair<int, int> temp = pq.top();
		pq.pop();
		if(!visited[temp.second])
		{
			visited[temp.second] = true;
			distance_source[temp.second] = temp.first;
			for(int i=0; i < edge[temp.second].size(); i++)
			{
				if(visited[edge[temp.second][i].second]==0)
					pq.push(make_pair(edge[temp.second][i].first + temp.first, edge[temp.second][i].second));
			}
		}
	}
	print_distance(source);
}

int main()
{
	int u,v,w,n,m;
	cin>>n>>m;
	//edge.resize(n+1);
	//cout<<"in"<<endl;
	for(int i=0;i<m;i++)
	{
		cin>>u>>v>>w;
		//cout<<"in2"<<endl;
		addedge(u,v,w);
		//cout<<"in"<<endl;
	}
	//cout<<"out"<<endl;
	int test_cases, source = 0;
	//Assuming 0 is the source, otherwise input source from the user
	cin >> test_cases;
	while(test_cases--){
		visited.clear();
		distance_source.clear();
		visited.resize(n, false);
		distance_source.resize(n,1000000000);
		cin >> source;
		dijkstra(source);
	}
}
