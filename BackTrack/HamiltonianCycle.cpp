#include <bits/stdc++.h>
using namespace std;

bool ham_cyc(int n, vector <vector<int>> &adj, int ind, vector<int> &seq, vector<int> &vis){
    if(seq.size()==n && find(adj[ind].begin(), adj[ind].end(), seq[0])!=adj[ind].end()) return true;
    for(int v: adj[ind]){
        if(!vis[v]){
            seq.push_back(v);
            vis[v]=1;
            if(ham_cyc(n,adj,v,seq,vis))return true;
            seq.pop_back();
            vis[v]=0;
        }
    }
    return false;
}

int main() {
    int n;
    int m;
    cin>>n>>m;
    vector <vector<int>> adj(n);
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> seq;
    vector<int> vis(n,0);
    seq.push_back(0);
    vis[0]=1;
    bool poss= ham_cyc(n,adj,0,seq,vis);
    if(poss){
        for(int i=0; i<n; i++) cout<<seq[i]<<" ";
        cout<<0<<" ";
        cout<<"\n";
    }
    else cout<<"Not Possible!\n";
    return 0;
}
