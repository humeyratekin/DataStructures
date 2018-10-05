  #include<stdio.h>
#include<stdlib.h>

struct node{
	
	int data;
	struct node *next;
	
};

typedef struct node Node;

Node *rear=NULL;

Node * search(int _data)
{
	Node *cur,*prev;
	if(rear!=NULL){
		
		prev=cur;
		cur=rear->next;
		
		do{
			if(cur->data>=_data)
				return prev;
			prev=cur;
			cur=cur->next;
		}while(cur!=rear->next);
		
		return prev;
		
		}
	return NULL; 
	
}

void insert(int _data){
	Node *prev,*newNode;
	
	if(rear==NULL){
		newNode=(Node *)malloc(sizeof(Node));
		rear=newNode;
		newNode->next=newNode;
		return;

	}
	newNode=(Node *)malloc(sizeof(Node));
    prev=search(_data);
    
    newNode->data=_data;
    newNode->next=prev->next;
    prev->next=newNode;
	
	if(rear->data<_data){
		rear=newNode;
	}	
	
}

void deleteNode(int _data){
	Node *prev,*newNode;
	if(rear==NULL){
		printf("Liste boş");
		return;
	}
	
	prev=search(_data);
	
    if(prev->next->data!=_data){
    	printf("Bulunamadı");
    	return;
	}
	
	if(rear->next==rear){
		if(_data==rear->data){
			free(rear);
			rear=NULL;
		
		}
	}

	
	if(prev->next==rear){ //son
		
		rear=prev;
	}
	Node *temp=prev->next->next;
	free(prev->next);
	prev->next=temp;
	
}
void listele(){
	Node *cur=rear->next;
	Node *prev;
	
		do{
			printf("Node degeri: %d\n",cur->data);
			cur=cur->next;
		}while(cur!=rear->next);
	
}

  
int main(){
	
	insert(1);
	insert(9);
	insert(7);
	
	listele();
	
}




