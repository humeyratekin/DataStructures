#include<stdio.h>
#include<stdlib.h>

struct node{
	
	int data;
	struct node *next;
	struct node *prev;
	
};

typedef struct node Node;

Node *head,*temp;

Node * Find(int _data){
	
	
	Node *Cur,*Temp;
	Cur=head;
	
	
		
	while(Cur!=NULL){
		
		if(Cur->data>=_data){
			return Cur;
			
			
		}
			
		
		if(Cur->next==NULL){
			temp=Cur;
		}
		
		Cur=Cur->next;
	}
	
	
	return Cur;
}


void Delete(int _data){
	Node *Cur;
	Cur=Find(_data);
	if(Cur->next==NULL){
		Cur->prev->next=NULL;
		free(Cur);
		return;
	}	
	
	if(Cur->prev==NULL){
		head=Cur->next;
		free(Cur);
		return;
		
	}
	
	Cur->prev->next=Cur->next;
	Cur->next->prev=Cur->prev;
	free(Cur);
	
}


void Insert(int _data){
	
	Node *NewNode=(Node *)malloc(sizeof(Node));
	Node *Cur;
	

	NewNode->data=_data;

	if(head==NULL){ //Listenin boþ olduðu durum
		NewNode->prev=head;
		NewNode->next=NULL;
		head=NewNode;
		return;
	}
	
	
	Cur=Find(_data);
	
	if(Cur==head)
	{	
		NewNode->next=Cur;
		head=NewNode;
		NewNode->prev=NULL;
		return;
	}
	
	if(Cur==NULL){
		
		temp->next=NewNode;		
		NewNode->prev=temp;
		NewNode->next=NULL;
		return;
	}
	
	NewNode->prev=Cur->prev;
	(Cur->prev)->next=NewNode;
	Cur->prev=NewNode;
	NewNode->next=Cur;
	return;
	
}

void List(){
	
	Node *Cur=head;
	
	do{
		
		printf("\n%d",Cur->data);
		Cur=Cur->next;
	}while(Cur!=NULL);
	
	
}

int main(){
	
	Insert(50);
	Insert(33);
	Insert(21);
	Insert(67);
	Insert(76);

	
	List();
	}
