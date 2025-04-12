
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Representation of a product in an aisle 
typedef struct TInventory{
	int aisle;  // aisle number
	char* prod; // product name
	int len_s;  // length of the product name
}INVENTORY;

// Representation of an item in the shopping list
typedef struct TListItem{
	int which_aisle; 
	char* name;       
	int len_item;
	int num_of_found;
	int list_num;       // to what list does it belong to
	int pos_in_aisle;
}LIST_ITEM;

// Reads shopping list from standard input in this format
LIST_ITEM * read_list(int * len, int* num_of_lists){
	int max = 5;
	int quantity = 0;
	
	LIST_ITEM * List = (LIST_ITEM*) malloc (sizeof(LIST_ITEM)*max);
	
	char *temp = NULL;
	size_t size;
	
	// load list items if possible
	while(getline(&temp,&size,stdin)!=-1){
		if(temp[0]=='\n'){
			*num_of_lists += 1;
			continue;
		}
		List[quantity].len_item = strlen(temp);

		if(temp[List[quantity].len_item-1]=='\n'){
			temp[List[quantity].len_item-1]='\0';
			List[quantity].len_item--;
		}

		// prolong the array if needed
		if(quantity >= max-1){
			max*=2;
			List = (LIST_ITEM*) realloc (List, sizeof(LIST_ITEM)*max);
		}

		// load item name
		List[quantity].name = (char*) malloc (sizeof(char)*List[quantity].len_item+1);
		strcpy(List[quantity].name,temp);
		List[quantity].list_num = *num_of_lists;
		List[quantity].num_of_found = 0;
		quantity ++;
	}
	*len = quantity;
	free(temp);
	return List;
}

/* Reads inventory from standard input in this format

#0
Bananas
Apples
#1
Milk
Eggs

*/
INVENTORY * read_aisle(int * len, int* num_of_aisles){
	int max = 5;
	int num_of_struct = 0;
	int curr_aisle = -1;
	
	INVENTORY * Inventory = (INVENTORY*) malloc (sizeof(INVENTORY)*max);
	
	char *temp = NULL;
	size_t size;	
	int first_line = 1;
	// load lines while possible
	while(getline(&temp,&size,stdin)!=-1){
		Inventory[num_of_struct].len_s = strlen(temp);
		Inventory[num_of_struct].aisle = curr_aisle;
		
		// aisle listing ended
		if(temp[0]=='\n'){
			free(temp);
			*len = num_of_struct;
			return Inventory;
		}
		if(temp[Inventory[num_of_struct].len_s-1]=='\n'){
			temp[Inventory[num_of_struct].len_s-1]='\0';
			Inventory[num_of_struct].len_s--;
		}
		if(((temp[0]!='#' && first_line) || (temp[1] != '0' && first_line) || (temp[2] != '\0' && first_line))){
			free(Inventory);
			free(temp);
			return NULL;
		}
		first_line=0;
		// process aisle number
		if(temp[0]=='#'){
			curr_aisle++;
			if(curr_aisle != atoi(temp+1)){
				for(int i=0; i<num_of_struct;i++){
					free(Inventory[i].prod);
				}
				free(Inventory);
				free(temp);
				return NULL;
			}
			*num_of_aisles = curr_aisle+1;
			continue;
		}	

		// prolong the array if needed
		if(num_of_struct >= max-1){
			max*=2;
			Inventory = (INVENTORY*) realloc (Inventory, sizeof(INVENTORY)*max);
		}

		// allocate memory for product name
		Inventory[num_of_struct].prod = (char*) malloc (sizeof(char)*Inventory[num_of_struct].len_s+1);

		strcpy(Inventory[num_of_struct].prod,temp);

		num_of_struct ++;
	}

	// cleanup if something failed
	free(temp);
	for(int i=0; i<num_of_struct;i++){
		free(Inventory[i].prod);
	}
	free(Inventory);
	return NULL;
}

int main(){
	int all_aisle_items_size;
	int num_of_aisles;
	INVENTORY * all_aisle_items = read_aisle(&all_aisle_items_size,&num_of_aisles);
	
	if(all_aisle_items==NULL){
		printf("Nespravny vstup.\n");
		return 1;
	}
	
	int whole_list_size;
	int num_of_lists=0;
	LIST_ITEM * all_list_items = read_list(&whole_list_size,&num_of_lists);
	
	if(all_list_items==NULL){
		printf("Nespravny vstup.\n");
		for(int i=0; i<all_aisle_items_size;i++)
			free(all_aisle_items[i].prod);
		free(all_aisle_items);
		return 1;
	}
	
	// go through all items in the shopping list
	for(int i = 0; i < whole_list_size; i++){
		all_list_items[i].which_aisle = 0;

		// go through all items in the aisles
		for(int j = 0; j < all_aisle_items_size; j++){

			// if the item was already found in the aisle, skip
			if(all_list_items[i].num_of_found == 2){
				continue;
			}
			if(strcasecmp(all_aisle_items[j].prod, all_list_items[i].name)==0){

				all_list_items[i].num_of_found = 2;						  // exact match found
				all_list_items[i].which_aisle = all_aisle_items[j].aisle; // load the aisle number
				all_list_items[i].pos_in_aisle = j;						  // load the position in the aisle
				continue;
			}

			if(all_list_items[i].num_of_found != 1 && all_aisle_items[j].len_s > all_list_items[i].len_item){
				
				// try to find a substring
				if (strcasestr(all_aisle_items[j].prod,all_list_items[i].name) != NULL){

					all_list_items[i].num_of_found = 1;
					all_list_items[i].pos_in_aisle = j;
					all_list_items[i].which_aisle = all_aisle_items[j].aisle;
					
				}
			}	
			
		}
	}
	
	int counter = 0;

	// for each list, print out the optimised version
	for(int list = 0 ; list < num_of_lists + 1; list++){ 

		printf("Optimalizovany list_num:\n");
		counter = 0;

		// for each aisle, print out the items
		for(int aisle = 0; aisle <= num_of_aisles + 1; aisle++){
			// go over the list items
			for(int list_item = 0 ; list_item < whole_list_size ; list_item++){ 
				// print out the optimised way to traverse the aisles for each item
				if(all_list_items[list_item].which_aisle == aisle  && all_list_items[list_item].num_of_found != 0 && all_list_items[list_item].list_num == list){
					printf(" %d. %s -> #%d %s\n",counter, all_list_items[list_item].name, aisle , all_aisle_items[all_list_items[list_item].pos_in_aisle].prod);
					counter ++;
				}
				// mark the end
				if(aisle == num_of_aisles+1 && all_list_items[list_item].num_of_found == 0 && all_list_items[list_item].list_num == list){
					printf(" %d. %s -> N/A\n", counter, all_list_items[list_item].name);
					counter++;
				}
			}
		}
	}
	
	//Free of aisles	
	for(int i=0; i<all_aisle_items_size;i++)
		free(all_aisle_items[i].prod);
	free(all_aisle_items);
	//-----------------------

	//Free of shopping list
	for(int i=0; i<whole_list_size;i++)
		free(all_list_items[i].name);
	free(all_list_items);
	//-----------------------
	return 0;
}
