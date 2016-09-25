#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

#define MAX_VERTEX 10000



typedef struct G_t{
	int n;
	int m;
	List vertex[MAX_VERTEX];
}G;

typedef G* Graph;

Graph graphCreate(int n);
void graphDestroy(Graph graph);
void graphAddEdge(Graph graph, int v1, int v2);
int graphVertexCount(Graph graph);
int graphEdgeCount(Graph graph);
int graphDegree(Graph graph, int v);
int graphHasEdge(Graph graph, int v1, int v2);

int main(){
	int choice=-1; Graph graph;
	int n;
	int v1,v2;
	while(choice!=0){
		printf("1. Create Graph\n2. Add Edge\n3. Count vertex\n4. Count edges\n5. Degree\n6. Test Edge\n0. Exit\n");
		printf("Choose a number:");scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Import number of vertex:");scanf("%d",&n);
				graph = graphCreate(n);
			break;
			case 2:
				//printf("Import v1, v2:");scanf("%d %d",&v1, &v2);
				graphAddEdge(graph, 10, 20);
				graphAddEdge(graph,100,30);
				graphAddEdge(graph,100,50);
				graphAddEdge(graph,50,50);
				graphAddEdge(graph,100,50);
				printf("%d\n",graphDegree(graph, 100));
				printf("%d\n", graphHasEdge(graph, 10, 20));
				printf("%d\n", graphHasEdge(graph, 100, 9));
			break;
		}
	}
	graphDestroy(graph);
}

Graph graphCreate(int n){
	int i;
	Graph graph = (Graph)malloc(sizeof(G));
	for(i=0;i<n;i++) graph->vertex[i]=initial_List();
	graph->n = n;
	graph->m = 0;
	return graph;
}

void graphDestroy(Graph graph){
	free(graph);
}

int graphVertexCount(Graph graph){
	return graph->n;
}

int graphEdgeCount(Graph graph){
	return graph->m;
}

void graphAddEdge(Graph graph, int v1, int v2){
	if(graphHasEdge(graph, v1, v2) || v1==v2){
		printf("Exist edge (%d, %d)\n", v1, v2);
	}else{
		List_add_element(graph->vertex[v1], v2);
		List_add_element(graph->vertex[v2], v1);
		graph->m++;
	}
}

int graphDegree(Graph graph, int v){
	int count=0; Node node;
	traverse(node, graph->vertex[v]) count++;
	return count;
}

int graphHasEdge(Graph graph, int v1, int v2){
	if(List_search_element(graph->vertex[v1],v2)!=NULL && List_search_element(graph->vertex[v2],v1)!=NULL){
		return 1;
	}
	return 0;
}
