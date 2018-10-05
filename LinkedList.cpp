//C'de BASÝT BÝR LÝNKED LÝST YAPISI KURMAK

#include <stdio.h>
#include <stdlib.h>

struct Node{
	int item;
	struct Node *next;
	
};

typedef struct Node node;

node *head;

void Insert(int _data){
	
	
	node * yeniDugum=(node *)malloc(sizeof(node));
	yeniDugum->next=head;
	yeniDugum->item=_data;
	head=yeniDugum;
	
	
	
}


void DeleteAtStart(){
	
	node *Current=head;
	head=head->next;
	free(Current);
	
	
}

void DeleteAtEnd(){
	node *Current=head;
	for(;Current->next!=NULL; Current=Current->next){
		
		
		
			if(Current->next->next==NULL){
				
				Current->next=NULL;
				free(Current->next->next);
				break;
			}
	
	}
	}
	

void ListNodes(){
	
	node *Current=head;
	for(;Current!=NULL; Current=Current->next){
		
		printf("DATA...: %d\n",Current->item);
	}

	
	
}


int main(int argc, char *argv[]){
	
	Insert(4);
	Insert(6);
	Insert(2);
	Insert(23);
	DeleteAtStart();
	DeleteAtEnd();
	ListNodes();
	
}
