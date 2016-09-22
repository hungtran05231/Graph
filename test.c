#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

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
