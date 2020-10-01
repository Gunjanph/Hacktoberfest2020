#include<iostream>
#include<vector>

using namespace std;
vector<int>vertex[100007];

int visted[100007];
void dfs(int n)
{
    cout<<n<<" ";
    visted[n]=1;

    for(int i=0;i<vertex[n].size();i++)
    {
        int child=vertex[n][i];

        if(!visted[child])
       {
            dfs(child);
            cout<<n<<" ";
       }
    }
}
int main()
{
    int v,e,j,k;

    cin>>v>>e;

    for(int i=0;i<e;i++)
    {
        cin>>k>>j;
        vertex[k].push_back(j);
        vertex[j].push_back(k);
    }

    dfs(1);
    return 0;
}