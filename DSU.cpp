#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;

    int arr[n+1];
    int size[n+1];
    
    int i=1;
    for(int i=1;i<=n;i++)
    {
        arr[i]=i;
        size[i]=1;
    }

    int q,x,y;
    cin>>q;
    while(q--)
    {
        cin>>x>>y;

        if(size[y]<size[x])
        {
            arr[y]=x;

            size[x]+=size[y];
        }

        else
        {
            arr[x]=y;

            size[y]+=size[x];
        }
    }

    for(int i=1;i<=n;i++)
    cout<<arr[i]<<" ";

    cout<<endl;
}