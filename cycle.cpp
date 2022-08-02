#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<climits>

using namespace std;
int n, m;
int edges[20][20];
int visited[20];
int parent[20];
int dist[20];

vector<vector<int>> allcycles;

void init(){
    for(int i=0;i<20;i++){
        visited[i]=0;
        dist[i]=-1;
        parent[i]=-1;
        for(int j=0;j<20;j++){
            edges[i][j]=0;
        }
    }
}

void dfs(int curr, int prev, int counter){
    visited[curr]=counter;
    parent[curr]=prev;
    if (prev!=-1)
        dist[curr]=dist[prev]+1;
    else 
        dist[curr]=0;
    for(int j=0;j<n;j++){
        if(edges[curr][j] && j!=prev ){
            if(!visited[j]){
                dfs(j,curr,counter);
            }
            else if (visited[j]==counter && dist[j]!=-1){
                vector<int> cycle;
                int node=curr;
                while(1){
                    cycle.push_back(node);
                    node=parent[node];
                    if(node==j){
                        cycle.push_back(j);
                        break;
                    }
                } 
                sort(cycle.begin(), cycle.end());
                allcycles.push_back(cycle);
                
            }
            else if (visited[j]==counter && dist[j]==-1){
                dfs(j, curr, counter);
            }
        }
    }
    parent[curr]=-1;
    dist[curr]=-1;
    
        
}
int main(){
  int t=1;
  while(t--){
      init();
      cin>>n>>m;
      for(int i=0;i<m;i++){
          int a;
          int b;
          cin>>a>>b;
          edges[a-1][b-1]=1;
          //edg
          
      }
      int counter=0;
      for(int i=0;i<n;i++){
        if(visited[i]==0){
            counter++;
            dfs(i, -1, counter);
        } 
      }
      sort(allcycles.begin(),allcycles.end());
      for(auto u:allcycles){
          for(auto v:u){
              cout<<v+1<<" ";
          }cout<<"\n";
      }
      
      
  }
  return 0;
}
