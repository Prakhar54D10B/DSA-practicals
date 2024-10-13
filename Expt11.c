#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 5

void bfs(int graph[MAX_VERTICES][MAX_VERTICES],int start){
    bool visited[MAX_VERTICES] = {false};
    int queue[MAX_VERTICES],front = -1, rear = -1;
    
    visited[start] = true;
    queue[++rear] = start;
    
    while(front < rear){
        int vertex = queue[++front];
        printf("%d ",vertex);
        
        for(int i = 0; i<MAX_VERTICES;i++){
            if(graph[vertex][i]==1 && !visited[i]){
                visited[i] = true;
                queue[++rear] = i;
            }
        }
    }
}

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES] = {
        {0, 1, 1, 0, 0}, // Connections for vertex 0
        {1, 0, 0, 1, 1}, // Connections for vertex 1
        {1, 0, 0, 0, 0}, // Connections for vertex 2
        {0, 1, 0, 0, 0}, // Connections for vertex 3
        {0, 1, 0, 0, 0}  // Connections for vertex 4
    };

    printf("BFS starting from vertex 0:\n");
    bfs(graph, 0);

    return 0;
}
