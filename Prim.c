#include<stdio.h>
#include<limits.h>
#include<stdbool.h>

#define V 5

int minKey(int key[], bool mstSet[]){
	
	int min = INT_MAX, min_index;
	int v;
	for(v = 0; v<V; v++)
		if(mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;
	return min_index;
	}
int printMST(int parent[], int n, int graph[V][V]){
	printf("Edge        Weight\n");
	int i;
	for(i=1;i<V;i++)
		printf("%d - %d          %d \n",parent[i],i,graph[i][parent[i]]);
	}

void primMST(int graph[V][V]){
	int parent[V];
	int key[V];
	bool mstSet[V];
	
	int i;
	for(i=0; i<V; i++)
		key[i] = INT_MAX, mstSet[i] = false;
	
	key[0] = 0;
	parent[0] = -1;
	
	int count;
	for(count = 0; count < V-1; count++){
		
		int u = minKey(key,mstSet);
		mstSet[u] = true;
		
		int v;
		for(v=0; v<V; v++)
			if(graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
				parent[v] = u, key[v] = graph[u][v];
		}
	
	printMST(parent, V, graph);
	}

int main(){
	
	int graph[V][V] = {{0,2,0,5,0},{2,0,3,7,5},{0,3,0,0,7},{6,8,0,0,7},{0,5,6,9,0}};
	
	primMST(graph);
	
	return 0;
	}
