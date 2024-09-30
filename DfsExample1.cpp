#include <bits/stdc++.h>
using namespace std;
#define pb push_back
// Statics
const int N=1e5;
int n,m;// nodes , edges
vector<vector<int>>g;// Your graph container
bool visited[N];
void dfs(int node){
    visited[node]=true;
    // cout<<node<<endl;
    // You will iterate on all childs of this node
    for(int i=0,child;i<g[node].size();++i){
        child=g[node][i];
        if(!visited[child]){
            dfs(child);
        }
        else{
            cout<<"#In Node "<<node<<endl;
            cout<<"Child "<<child << " is visited"<<endl;
        }
    }
}
/*
4 4
0 1
0 2
1 2
2 3
*/
int main(){
    cin>>n>>m;
    g.resize(n);
    for(int i=0,u,v;i<n;++i){
        cin>>u>>v;
        // don't forget that this graph is not directed 
        g[u].pb(v);
        g[v].pb(u);
    }
    // For Reset visited array 
    memset(visited,false,sizeof visited);
    dfs(0);
    return 0;
}