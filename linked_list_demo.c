#include <stdio.h>
#include <stdlib.h>

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

int main(int argc, char const *argv[]){
	int choice=-1;
	List list=initial_List();
	Node node;//node for traverse...
	while(choice!=0){
		printf("1. Add element\n2. Push element\n3. Insert element\n4. Delete element\n5. Delete next element\n6. Search\n0. Exit\n");
		printf("import choice:");scanf("%d",&choice);
		switch(choice){
			case 1:
				List_add_element(list, 1);
				List_add_element(list, 2);
				List_add_element(list, 3);
				List_add_element(list, 4);
				List_print(node, list)
				printf("\n");
			break;
			case 2:
				List_push_element(list, 5);
				List_print(node, list)
				printf("\n");
			break;
			case 3:
				List_insert_element(list, 10, list->head->next);
				List_print(node, list)
				printf("\n");
			break;
			case 4:
				List_delete_element(list, list->head);
				List_print(node, list)
				printf("\n");
			break;
			case 5:
				List_delete_next(list, list->head->next);
				List_print(node, list)
				printf("\n");
			break;
			case 6:
				if(List_search_element(list,1)!=NULL) printf("Yes!\n");
				else printf("No!\n");
			break;
			default:
			break;
		}
	}
	free_list(list);
	return 0;
}

List initial_List(){
	List list = (List)malloc(sizeof(List));
	list->head = NULL;
	return list;
}

Node initial_Node(int key){
	Node node = (Node)malloc(sizeof(Node));
	node->key =  key;
	node->next = NULL;
	return node;	
}

Node List_add_element(List list, int key){
	Node node;
	if(list->head == NULL){
		list->head = initial_Node(key);
	}else{
		get_tail(node, list)
		node->next = initial_Node(key);
	}
	return list->head;
}

Node List_push_element(List list, int key){
	Node node;
	if(list->head == NULL){
		list->head = initial_Node(key);
	}else{
		node = initial_Node(key);
		node->next = list->head;
		list->head = node;
	}
	return list->head;
}

Node List_insert_element(List list, int key, Node node){
	Node new_node =  initial_Node(key);
	new_node->next =  node->next;
	node->next=new_node;
	return list->head;
}

Node List_delete_next(List list, Node node){
	Node deleted_node =  node->next;
	node->next = node->next->next;
	free_node(deleted_node);
	return list->head;
}

Node List_delete_element(List list, Node node){
	Node walk;
	if(node == list->head){
		list->head = list->head->next;
		free(node);
	}else{
		for(walk = list->head; walk->next!=NULL && walk->next!=node; walk = walk->next);
		List_delete_next(list, walk);
	}
	return list->head;
}

void free_list(List list){
	Node node;
	traverse(node, list) free(node);
}

void free_node(Node node){
	free(node);
}

Node List_search_element(List list, int key){
	Node node;
	traverse(node, list) if(node->key ==  key) return node;
	return NULL;
}