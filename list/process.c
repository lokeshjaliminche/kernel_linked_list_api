#include <stdio.h>
#include <stdlib.h>

#include "list.h"


struct process{
	int number;
	char name[10];
	struct list_head existing;
	struct list_head waiting;
	struct list_head using;
	struct list_head available;
	};

int main(int argc, char **argv){

	struct process *tmp;
	struct process *tmp1;
	struct list_head *pos, *q;
	unsigned int i;
	unsigned int choice;

	struct process my_process;
	
	INIT_LIST_HEAD(&my_process.using);
	INIT_LIST_HEAD(&my_process.available);
	INIT_LIST_HEAD(&my_process.waiting);
	INIT_LIST_HEAD(&my_process.existing);
	/* INIT_LIST_HEAD(&tmp->list); 
	 *
	 * this initializes a dynamically allocated list_head. we
	 * you can omit this if subsequent call is add_list() or 
	 * anything along that line because the next, prev
	 * fields get initialized in those functions.
	 * or you could have declared this with the following macro
	 * LIST_HEAD(mylist); which declares and initializes the list
	 */
	/* adding elements to mylist */
	for(i=5; i!=0; --i){
		tmp= (struct process *)malloc(sizeof(struct process));
		
		printf("enter process details\n");
		scanf("%d %s", &tmp->number, &tmp->name);

		/* add the new item 'tmp' to the list of items in mylist */
		list_add(&(tmp->existing), &(my_process.existing));
		/* you can also use list_add_tail() which adds new items to
		 * the tail end of the list
		 */
	}
	printf("\n");

	/* now you have a circularly linked list of items of type struct kool_list.
	 * now let us go through the items and print them out
 * 	 	 */


	/* list_for_each() is a macro for a for loop. 
	 * first parameter is used as the counter in for loop. in other words, inside the
	 * loop it points to the current item's list_head.
	 * second parameter is the pointer to the list. it is not manipulated by the macro.
	 */
	printf("traversing the list using list_for_each()\n");
	list_for_each(pos, &my_process.existing){

	/* at this point: pos->next points to the next item's 'existing' variable and 
	 * pos->prev points to the previous item's 'existing' variable. Here item is 
	 * of type struct process. But we need to access the item itself not the 
	 * variable 'existing' in the item! macro list_entry() does just that. See "How
	 * does this work?" below for an explanation of how this is done.
	 */
		 tmp= list_entry(pos, struct process, existing);

	 /* given a pointer to struct list_head, type of data structure it is part of,
	  * and it's name (struct list_head's name in the data structure) it returns a
	  * pointer to the data structure in which the pointer is part of.
	  * For example, in the above line list_entry() will return a pointer to the
	  * struct kool_list item it is embedded in!
	  */

		 printf("number= %d name= %s\n", tmp->number, tmp->name);
		 printf("can we use this process?\n1.yes\n2.no\n3.not_sure\nEnter your choice.\n");
		 scanf("%d",&choice);
		if (choice == 1) {
			printf("adding process to using state\n ");
		list_add(&(tmp->using), &(my_process.using));
		} else if (choice == 2) {
			printf("adding process to waiting state\n ");
		list_add(&(tmp->waiting), &(my_process.waiting));
		} else {
			printf("adding process to available  state\n ");
		list_add(&(tmp->available), &(my_process.available));
		}

	}
	printf("\n");
		 printf("traversing waiting process list\n");
		 list_for_each(pos, &my_process.waiting){
	/* at this point: pos->next points to the next item's 'waiting' variable and 
	 * pos->prev points to the previous item's 'waiting' variable. Here item is 
	 * of type struct process. But we need to access the item itself not the 
	 * variable 'waiting' in the item! macro list_entry() does just that. See "How
	 * does this work?" below for an explanation of how this is done.
	 */
			tmp= list_entry(pos, struct process, waiting);
			printf("number= %d name= %s\n", tmp->number, tmp->name);
		 }
		 printf("traversing using process list\n");
		 list_for_each(pos, &my_process.using){
	/* at this point: pos->next points to the next item's 'waiting' variable and 
	 * pos->prev points to the previous item's 'waiting' variable. Here item is 
	 * of type struct process. But we need to access the item itself not the 
	 * variable 'waiting' in the item! macro list_entry() does just that. See "How
	 * does this work?" below for an explanation of how this is done.
	 */
			tmp= list_entry(pos, struct process, using);
			printf("number= %d name= %s\n", tmp->number, tmp->name);
		 }
		 printf("tracersing  available process list\n");
			 list_for_each(pos, &my_process.available){
	/* at this point: pos->next points to the next item's 'waiting' variable and 
	 * pos->prev points to the previous item's 'waiting' variable. Here item is 
	 * of type struct process. But we need to access the item itself not the 
	 * variable 'waiting' in the item! macro list_entry() does just that. See "How
	 * does this work?" below for an explanation of how this is done.
	 */
			tmp= list_entry(pos, struct process, available);
			printf("number= %d name= %s\n", tmp->number, tmp->name);
		 }
		 printf("tracersing  available process list\n");
			 list_for_each(pos, &my_process.existing){
	/* at this point: pos->next points to the next item's 'waiting' variable and 
	 * pos->prev points to the previous item's 'waiting' variable. Here item is 
	 * of type struct process. But we need to access the item itself not the 
	 * variable 'waiting' in the item! macro list_entry() does just that. See "How
	 * does this work?" below for an explanation of how this is done.
	 */
			tmp= list_entry(pos, struct process, existing);
			printf("number= %d name= %s\n", tmp->number, tmp->name);
		 }

}

