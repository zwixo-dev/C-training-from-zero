#include <stdio.h>
#include <stdlib.h>


typedef struct pile {
	int data;
	struct pile *next;
} Pile;

// is empty

int isEmpty(Pile *top) {
	return(top == NULL);
}

// empiler

Pile *empiler(Pile *top, int val) {

	Pile *newNode = malloc(sizeof(Pile));

	newNode->data = val;
	newNode->next = top;

	top = newNode;
    printf("%d added ! ", val);
    
	return top;
}

// depiler

Pile *depiler(Pile *top, int *val) {

	if(isEmpty(top)) {
	    printf("Status : Empty");
		return 0;
	}

	Pile *toDelete = top;
	*val = toDelete->data;
	top = toDelete->next;


	printf("%d removed", *val);
	free(toDelete);
	return top;
}

void display(Pile *top){
    if(isEmpty(top)){
        printf("Status : Empty");
        return;
    }
    Pile *tOp = top;
    while(tOp!=NULL){
        printf("%d -> ",tOp->data);
        tOp = tOp->next;
    }
}

int main() {
	Pile *top = NULL;
	int choice, val;

	do {
		printf("\n1 ====>Is Empty\n");
		printf("2 ====>Push\n");
		printf("3 ====>Pop\n");
		printf("4 ====>Display\n");
		printf("0 ====>Exit! \n");
		printf("choice : ");
		scanf("%d", &choice);
		
		switch(choice){
		    case 1:
		    
		    if(isEmpty(top)){
		        printf("Status : Empty");
		    } else{ printf("Status : Not Empty ! ");}
		    
		    break;
		    // 
		    case 2:
		        printf("Enter : ");
		        scanf("%d", &val);
		        top = empiler(top, val);
		    break;
		    // 
		    case 3:
		        top = depiler(top, &val);
		    break;
		    
	        case 4:
                display(top);
	        break;
	        
	        // default 
	        default: 
	        if(choice!=0){
	          printf("Invalid Coiche  !");  
	        }
	        break; 
		}
		
	} while(choice!=0);





	return 0;
}