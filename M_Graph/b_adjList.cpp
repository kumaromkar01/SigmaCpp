#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;
template<typename t>
class graph{
    public:
    unordered_map<t,list<t>> adj;
    void addEdge(t u, t v, bool direction){
        //direction 0 -> undirected
        //direction 1 -> directed
        adj[u].push_back(v);
        if(direction==0){
            adj[v].push_back(u);
        }
    }
    void print(){
        cout<<"adjacency list is \n";
        for(auto i: adj){
            cout<<i.first<<"=>";
            for(auto j: i.second){
                cout<<j<<"->";
            }
            cout<<"NULL \n";
        }
    }
};

int main(){
    int n;
    cout<<"enter number of nodes : ";
    cin>>n;
    int m;
    cout<<"enter number of edges : ";
    cin>>m;

    graph<int> g;
    for(int i =0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v,0);
    }
    g.print();
}
