#include <bits/stdc++.h>
using namespace std;
#define pb push_back
// Statics
const int N=1e5+1;
int t,n,m;// nodes , edges
vector<vector<int>>g;// Your graph container
vector<char>tmp;// This tmp is used for fetch nodes that you have visited
vector<vector<char>>comps;
bool visited[N];
void dfs(int node){
    visited[node]=true;
    tmp.pb(node + 'a');
    // cout<<node<<endl;
    // You will iterate on all childs of this node
    for(int i=0,child;i<g[node].size();++i){
        child=g[node][i];
        if(!visited[child]){
            dfs(child);
        }
        // else{
        //     cout<<"#In Node "<<node<<endl;
        //     cout<<"Child "<<child << " is visited"<<endl;
        // }
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
    scanf("%d",&t);
    for(int test=0;test<t;test++){
        scanf("%d %d",&n,&m);
        g.clear();
        g.resize(n);
        char u,v;
        for(int i=0;i<n;++i){
            scanf("%c %c",&u,&v);
            // don't forget that this graph is not directed 
            g[u-'a'].pb(v-'a');
            g[v-'a'].pb(u-'a');
        }

        // For Reset visited array 
        memset(visited,false,sizeof visited);
        comps.clear();
        for(int i=0;i<n;i++){
            if(visited[i])
                continue;
            tmp.clear();
            dfs(i);
            comps.pb(tmp);

        }
        printf("Case #%d\n:",test+1);
        for(int i=0;i<comps.size();i++){
            sort(comps[i].begin(),comps[i].end());
            for(int j=0;j<comps[i].size();j++){
                printf("%c,",comps[i][j]);

            }
            puts("");
        }
        printf("%d connected components\n\n",(int)comps.size());
        // cout<<(int)comps.size();
    }
    return 0;
}