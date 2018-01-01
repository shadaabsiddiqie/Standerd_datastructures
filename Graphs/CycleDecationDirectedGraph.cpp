#include "bits/stdc++.h"
using namespace std;

struct node{
     vector<int> nodes;
};


// root starts from 0 it is based on code

int CycleDecationDirectedGraph(int root,node AdjList[] , vector<int> &visit, vector<int> &set_stack){
     if (visit[root]==0){
          visit[root] = 1;
          set_stack[root] = 1;

          for(int i =0;i< AdjList[root].nodes.size();i++){
               if(visit[AdjList[root].nodes[i]]==1 && set_stack[AdjList[root].nodes[i]]==1){
                    return 1;
               }
               else if (CycleDecationDirectedGraph(AdjList[root].nodes[i], AdjList, visit,set_stack)){
                    return 1;
               }
          }
          set_stack[root] = 0;
     }
     return 0;
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
          AdjList[a].nodes.push_back(b);
     }

     vector<int> set_stack(no_nodes,0);
     vector<int> visit(no_nodes,0);

     cout << "------------------CycleDecationDirectedGraph result is----------------" << '\n';

     for(int i =0;i<no_nodes;i++){
        if(CycleDecationDirectedGraph(i,AdjList,visit,set_stack)==1){
            cout << "Cycle present" << '\n';
            break;
        }
    }

     return 0;
}
