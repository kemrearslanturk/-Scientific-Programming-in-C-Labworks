#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 32
 struct node {
 int id;
char name[N]; 
 struct node *next;
} list;
struct node *node_head = NULL;
struct node *temp=NULL;
struct node* q =NULL;

void Clearscreen () {
 system("cls");
}
void Wait () {
 char temp_data;
 printf ("Press Enter to continue!!!\n");
 temp_data = getchar ();
 temp_data = getchar ();
Clearscreen ();
}

 void Insert (int number, char name[N]){
 	struct node* insert=(struct node*)malloc(sizeof(struct node));
 	strcpy(insert->name, name);
 	insert->id=number;
 	insert->next=NULL;
 	if(node_head==NULL){
 		node_head=insert;
	 }
	 else{
	 	q=node_head;
	 	for(;q->next!=NULL;){
	 		q=q->next;
		 }
		 q->next=insert;
	 }
 }
void listing(){
	q= node_head;
	for(;q!=NULL; ){
		printf("%s %d \n", q->name,q->id);
		q = q->next;
	}
}

void Remove(struct node *head,int key)
{
	temp=head;
	int flag,prev;
    while (temp != NULL)
    {
        if (temp->id == key)
        {
          flag=1;
          break;
      }
          else{
          
          	 temp = temp->next;
		  }
            
        
       
    }
    if(flag){
    	if(temp == head){
                head = temp->next;
            }
            else{
                
            }
    	
	}
}


void search(struct node *head, int key)
{
    while (head != NULL)
    {
        if (head->id == key)
        {
            printf("Student found in the list\n");
            return;
        }
        head = head->next;
    }
    printf("Student number has not been found in the list ...");
}


int main(){
	int islem;
	int number;
	char std[N];
	int sayac=0;
	while(1){
	Wait();
	printf(" 1.Insert\n");
	printf(" 2.Listing\n");
	printf(" 3.Search\n");
	printf(" 4.Remove\n");
	printf(" 5.Exit\n");
	printf(" Please select an option: ");
	scanf("%d",&islem);
	switch(islem){
		case 1:
			printf("Enter the student number: ");
			scanf("%d",&number);
			printf("Enter the student name: ");
			scanf("%s",&std);
			printf("student %s and number %d added to list \n",std,number);
			Insert(number,std);
	        break;
	    case 2:
	    	if(sayac==0){
	    		printf("The list is empty. Please create theListing after adding student number ..\n");
			}
			else
	    listing();
	    	
	        break;
	    case 3:
	    	printf("Enter the student number: ");
			scanf("%d",&number);
			search(node_head,number);
			
	    	
	        break;
	    case 4:
	    	printf("Enter the student number: ");
			scanf("%d",&number);
			printf("Enter the student name: ");
			scanf("%s",&std);
			printf("student %s and number %d deleted from the list \n",std,number);
	    	
	        break;
	    case 5:
	    printf("Finish Programming");
			return 0;
		default:
		printf("FALSE CHOOSE...\n");
		break;
	}
	sayac++;
}
}

