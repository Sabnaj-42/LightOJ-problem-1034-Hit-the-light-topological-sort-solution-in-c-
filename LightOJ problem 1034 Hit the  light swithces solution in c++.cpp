#include<bits/stdc++.h>
using namespace std;
bool visit[10005];
vector<int>graph[100005];
vector<int>topo;
void dfs(int src)
{
    visit[src]=1;
    for(int i=0;i<graph[src].size();i++)
    {
        int child=graph[src][i];
        if(visit[child]==0)dfs(child);
    }
    topo.push_back(src);
}
void dfs2(int src)
{
    visit[src]=1;
    for(int i=0;i<graph[src].size();i++)
    {
        int child=graph[src][i];
        if(visit[child]==0)dfs(child);
    }
}
int main()
{
    int t;cin>>t;
    for(int k=1;k<=t;k++)
    {

        int n,m,ans=0;cin>>n>>m;
        topo.clear();
        for(int i=1;i<=10005;i++){graph[i].clear();visit[i]=0;}
        while(m--)
        {
            int a,b;cin>>a>>b;
            graph[a].push_back(b);
        }
    for(int i=1;i<=n;i++)
    {
       if(visit[i]==0)dfs(i);
    }
     for(int i=1;i<=10005;i++){visit[i]=0;}
     reverse(topo.begin(),topo.end());
     for(int i=0;i<topo.size();i++)
     {
         if(visit[topo[i]]==0)
         {
             ans++;
             dfs2(topo[i]);
         }
     }
    printf("Case %d: ",k);
    cout<<ans<<endl;
    }


}
