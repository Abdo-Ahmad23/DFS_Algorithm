#include <bits/stdc++.h>
using namespace std;
#define pb push_back
// Statics
const int N=1e5+1;
int n,m;// nodes , edges
vector<vector<int>>g;// Your graph container
vector<int>tmp;// This tmp is used for fetch nodes that you have visited
bool visited[N];
void dfs(int node){
    // You will iterate on all childs of this node
    for(int i=0,child;i<g[node].size();++i){
        child=g[node][i];
        if(!visited[child]){
            visited[child]=true;
            dfs(child);
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
    while(scanf("%d",&n)==1 && n)
    {
        g.clear();
        g.resize(n);
        int a,b,c,q;
        while(scanf("%d",&a)==1 && a){
            --a;
            while(scanf("%d",&b)==1 && b){
                g[a].pb(b);
            }
        }
        scanf("%d",&q);
        while(q--){
            memset(visited,false,sizeof visited);
            tmp.clear();
            scanf("%d",&c);
            dfs(--c);
            for(int i=0;i<n;i++){
                if(!visited[i])
                    tmp.pb(i+1);
            }
            printf("%d",(int)tmp.size());
            for(int i=0;i<(int)tmp.size();i++){
                printf(" %d",tmp[i]+1);
            }
            puts("");
        }
    }

    return 0;
}