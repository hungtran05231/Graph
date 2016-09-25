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
