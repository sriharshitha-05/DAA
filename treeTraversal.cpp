#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int graph[10][10],visited[10];
int n;

void DFS(int v)
{
    cout<<v<<" ";
    visited[v]=1;
    for(int i=0;i<n;i++)
    {
        if(graph[v][i]==1&&visited[i]==0){
            DFS(i);
        }
    }
}

void BFS(int start)
{
    int queue[10];
    int front=0,rear=0;
    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    queue[rear++]=start;
    visited[start]=1;
    while(front<rear){
        int v=queue[front++];
        cout<<v<<" ";
        for(int i=0;i<n;i++)
        {
            if(graph[v][i]==1&&visited[i]==0){
            queue[rear++]=i;
            visited[i]=1;
        }
        }
    }
}

int main()
{
    int n;
    cout<<"Enter number of vertices: ";
    cin>>n;
    cout<<"Enter adjacent matrix:";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>graph[i][j];
        }
    }
    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    cout<<"DFS: ";
    DFS(0);

    cout<<"BFS: ";
    BFS(0);
    return 0;
}