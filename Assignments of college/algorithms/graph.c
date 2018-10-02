#include<stdio.h>
#include<stdlib.h>
//adjacency list node
struct AdjListNode{
  int dest;
  struct AdjListNode *next;
};

//adjacency list head
struct AdjList{
  struct AdjListNode *head;
};

struct Graph
{
    int V;//no of vertices
    struct AdjList* array;
};

struct AdjListNode * newAdjListNode(int dest){
  struct AdjListNode* newNode =
     (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int v){
  struct Graph* graph=(struct Graph *)malloc(sizeof(struct Graph));
  graph->V=v;
  graph->array =
      (struct AdjList*) malloc(v * sizeof(struct AdjList));
  for(int i=0;i<v;i++){
    graph->array[i].head = NULL;
  }

 return graph;
}

//add edge
void addEdge(struct Graph* graph,int src,int dest ){
  //add edge from source to destination
  struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
  //add edge from destination to source
  newNode = newAdjListNode(src);
     newNode->next = graph->array[dest].head;
     graph->array[dest].head = newNode;
   }

   void printGraph(struct Graph* graph)
{
    int v;
    for (v = 0; v < graph->V; ++v)
    {
        struct AdjListNode* pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl)
        {
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

int main()
{
    // create the graph given in above fugure
    int V = 4;
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 1, 3);
  

    // print the adjacency list representation of the above graph
    printGraph(graph);

    return 0;
}
