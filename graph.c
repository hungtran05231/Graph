#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "graph.h"

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
