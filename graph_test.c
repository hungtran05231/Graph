#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "graph.h"

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
	return 0;
}
