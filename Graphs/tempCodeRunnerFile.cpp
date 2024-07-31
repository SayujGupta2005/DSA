//LuvBabbar_lec-85

// Undirected Graph
//  Two vertices have an edge without a specific direction

// Directed Graph
//  Two vertices have an edge that is in a specific direction
//  eg- an edge b/w A and B either points from A to B or from B to A

// Vertices(Nodes)
//  Entity to store data

// Edge
//  For connection of nodes

// Degree of a vertice
//  Undirected Graph
//      Number of edges connected to a vertice 
//  Directed Graph
//      Indegree- No of edges coming in the vertex
//      Outdegree- No of the edges going out of the vertex

// Weights
//  Values assigned to edges
//  Incase there is a graph with no weights but we need to use an algorithm for weights graphs,
//      we can assign weights as 1 to all edges

// Cyclic Graph
//  When we return to a node that we have already travelled, we call it a cyclic graph
//  eg- 1->2->3->4->1

// Acyclic Graph
//  When we don't return to a node that we have already travelled, we call it an acyclic graph

// Graph Representation
//  Adjacency Matrix (Space complexity = O(V**2))
//      2D array of size VxV
//      V- Number of vertices
//      Undirected Graph
//          A[i][j] = 1 if there is an edge b/w i and j (=n if n edges b/w i and j)
//          A[i][j] = 0 if there is no edge b/w i and j
//      Directed Graph
//          A[i][j] = 1 if there is an edge from i to j (=n if n edges from i to j)
//          A[i][j] = 0 if there is no edge from i to j or from j to i
//  Adjacency List
//      List of vertices connected to a vertex
//      We use it like map<int,vector<int>> m;
//      Undirected Graph
//          m[i]= list of edges connected to vertex i
//      Directed Graph
//          m[i]= list of edges going out of vertex i
//          eg- m[0]={1,2} ==  (0->1),(0->2)

#include<bits/stdc++.h>
using namespace std;

class graph{
    public:
    unordered_map<int,list<int>>adj;
    void addEdge(int u,int v,bool direction){
        //Direction 0 - undirected
        //Direction 1 - directed
        adj[u].push_back(v);
        if(!direction){
            adj[v].push_back(u);
        }
    }
    void print(){
        for(auto i:adj){
            cout<<i.first<<"-> ";
            for(auto k:i.second){
                cout<<k<<" ";
            }
            cout<<endl;
        }
    }
};

int main(){
    int n;//No of nodes
    cin>>n;
    int e;//No of edges
    cin>>e;
    graph g;
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v,0);
    }
    g.print();
}