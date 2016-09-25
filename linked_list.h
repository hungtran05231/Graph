typedef struct element_t{
	int key;
	struct element_t* next;
}element;

typedef struct L_t{
	element*head;
}L;

typedef L* List;
typedef element* Node;

List initial_List();
Node initial_Node(int key);
Node List_add_element(List list, int key);
Node List_push_element(List list, int key);
Node List_insert_element(List list, int key, Node node);
Node List_delete_element(List list, Node node);
Node List_delete_next(List list, Node node);
Node List_search_element(List list, int key);
void free_list(List list);
void free_node(Node node);

#define List_print(node, list) for(node = list->head; node != NULL; node = node->next) printf("%d\t",node->key);
#define get_tail(node, list) for(node = list->head; node->next != NULL; node =  node->next);
#define traverse(node, list) for(node = list->head; node != NULL; node = node->next)
