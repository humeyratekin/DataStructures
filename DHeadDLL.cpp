#include<stdio.h>
#include<stdlib.h>

struct node{
	
	int data;
	struct node *next;
	struct node *prev;
	
};

typedef struct node Node;

Node *head,*dummyH;

Node * Search(int _data){
	Node *Cur=head->next;
	
	while(Cur!=head){
		
		if(Cur->data>=_data)
			return Cur;
		Cur=Cur->next;	
		
	}
	
	return Cur;
	
}

void Delete(int _data){
	
	Node *Cur;

	Cur=Search(_data);
	
	if(Cur==head){
		printf("Aranan öðe bulunamadý");
		return;
	}
	
	
	(Cur->prev)->next=Cur->next;
	
	(Cur->next)->prev=Cur->prev;
	free(Cur);
}

void Insert(int _data){
	
	Node *Cur,*NewNode;
	NewNode=(Node *)malloc(sizeof(Node));
	Cur=Search(_data);
	
	NewNode->data=_data;
	
	(Cur->prev)->next=NewNode;
	NewNode->prev=Cur->prev;
	Cur->prev=NewNode;
	NewNode->next=Cur;
}

void List(){
	Node *Cur=head->next;
	
	while(Cur!=head){
		printf("%d",Cur->data);
		Cur=Cur->next;
		if(Cur!=head){
			printf("-");
		}
	}
	
}

int main(){
	
	dummyH=(Node *)malloc(sizeof(Node));
	head=dummyH;
	dummyH->next=dummyH;
	dummyH->prev=dummyH;
	
	Insert(45);
	Insert(56);
	Insert(3);
	List();
	printf("\n");
	Delete(45);
	Insert(5);
	List();
	
} 
