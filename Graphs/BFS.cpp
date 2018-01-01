#include "bits/stdc++.h"
using namespace std;

struct node{
     vector<int> nodes;
};

// root starts from 0 it is based on code

void BFS(int root,node AdjList[] , vector<int> &visit){

     for(int i =0;i< AdjList[root].nodes.size();i++){
          if (visit[AdjList[root].nodes[i]]==0){
               visit[AdjList[root].nodes[i]] = 1;
               cout << AdjList[root].nodes[i] + 1 <<"-"<<endl;
          }
          // DFS(AdjList[root].nodes[i], AdjList, visit);
     }

     for(int i =0;i< AdjList[root].nodes.size();i++){
          BFS(AdjList[root].nodes[i], AdjList, visit);
     }

}

int main(int argc, char const *argv[]) {

     //taking input
     int no_nodes , no_edges;
     cout << "no of nodes" << '\n';
     cin >> no_nodes;
     cout << "no of edges" << '\n';
     cin >> no_edges;
     cout << "add edges a -> b" << '\n';

     node AdjList[no_nodes];

     //pruning nodes into adjacency list
     for(int i =0 ;i<no_edges;i++){
          int a ,b;
          cin >> a >> b;
          /*
               input might be in any form but we will convert it into 0 to n form
          */
          AdjList[a-1].nodes.push_back(b-1);
     }

     // printing adjacency list
     cout << "adjacency list is " << '\n';
     for(int i =0 ;i<no_nodes;i++){
          cout << i+1<<" -> " ;
          for(int j=0 ;j<AdjList[i].nodes.size();j++ ){
               cout << AdjList[i].nodes[j] + 1  ;
          }
          cout << '\n';
     }

     vector<int> visit(no_nodes,0);

     std::cout << "BFS result is" << '\n';
     BFS(0,AdjList,visit);

     return 0;
}
