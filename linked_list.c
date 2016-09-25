#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

List initial_List(){
	List list = (List)malloc(sizeof(L));
	list->head = NULL;
	return list;
}

Node initial_Node(int key){
	Node node = (Node)malloc(sizeof(element));
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
	traverse(node, list) if(node!=NULL) free(node);
}

void free_node(Node node){
	free(node);
}

Node List_search_element(List list, int key){
	Node node;
	traverse(node, list) if(node->key ==  key) return node;
	return NULL;
}
