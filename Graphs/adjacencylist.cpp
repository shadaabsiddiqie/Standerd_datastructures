#include <bits/stdc++.h>

using namespace std;

struct node{
     vector<int> nodes;
};

int main(int argc, char const *argv[]) {
     //taking input
     int no_nodes , no_edges;
     cout << "no of nodes" << '\n';
     cin >> no_nodes;
     cout << "no of edges" << '\n';
     cin >> no_edges;
     cout << "add edges a -> b" << '\n';

     node graph[no_nodes];

     //pruning nodes into adjacency list
     for(int i =0 ;i<no_edges;i++){
          int a ,b;
          cin >> a >> b;
          graph[a-1].nodes.push_back(b-1);
     }

     // printing adjacency list
     cout << "adjacency list is " << '\n';
     for(int i =0 ;i<no_nodes;i++){
          cout << i+1<<" -> " ;
          for(int j=0 ;j<graph[i].nodes.size();j++ ){
               cout << graph[i].nodes[j] + 1  ;
          }
          cout << '\n';
     }
     return 0;
}
