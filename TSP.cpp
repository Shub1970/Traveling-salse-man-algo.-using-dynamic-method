/* traveling salse man problem using bruite force method */
#include<iostream>
using namespace std;
#define INF 9999
#define N 4
int graph[4][4]={{0,20,42,25},
                 {20,0,30,34},
                 {42,30,0,10},
                 {25,34,10,0}};
int dynamictable[(1<<N)][N];
int visited_all=(1<<N)-1;
int min(int a,int b){return(a<b)?a:b;}
int TSP(int visited,int position){
    if(visited==visited_all){return graph[position][0];}
    if(!dynamictable[visited][position]==-1){return dynamictable[visited][position];}
    int ans=INF;
    for(int city=0;city<N;city++){
        if(!(visited&(1<<city))){
              int newans=graph[position][city]+TSP(visited|(1<<city),city);
              ans=min(ans,newans);
        }
    }
    return dynamictable[visited][position]=ans;
}
int main(){
    for(int i=0;i<(1<<N);i++){
        for(int j=0;j<N;j++){
            dynamictable[i][j]=-1;
        }
    }

    cout<<"min distance the salse man has to travel to reach every node "<<TSP(1,0);
    return 0;
}