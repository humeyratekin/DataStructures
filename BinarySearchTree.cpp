#include<stdio.h>
#include<stdlib.h>

struct dugum{
	int data;
	struct dugum *sol;
	struct dugum *sag;
};

typedef struct dugum Dugum;

Dugum *root=NULL;

Dugum *search(Dugum *root,int _data,int *found){
	*found=0;
	
	if(root->data==_data)
	{
		*found=1;
		return root;
	}
	if(root->data>_data)
		if(root->sol!=NULL)
			return search(root->sol,_data,found);
		else return root;	
	else
		if(root->sag!=NULL)
			return search(root->sag,_data,found);
		else return root;			
}

Dugum * AtaBul(Dugum *root,int _data){
	
	if(root->data>_data){

		if(root->sol!=NULL){
		
			if(root->sol->data==_data)
				return root;
			else
				return AtaBul(root->sol,_data);	
			}
			
	}
	else
		if(root->sag!=NULL){
			if(root->sag->data==_data)
				return root;
			else
				return AtaBul(root->sag,_data);	
	    }
		
}

int insert(int _data){
	int found;
	Dugum *Parent;
	Dugum *newNode=(Dugum *)malloc(sizeof(Dugum));
	newNode->data=_data;
	newNode->sag=NULL;
	newNode->sol=NULL;	
	if(root==NULL)
	{
	root=newNode;
	return 1;
	}
	
	Parent=search(root,_data,&found);
	if(found){
		printf("Ayný deðerli sayý aðaçta bulunmaktadýr");
		free(newNode);
		return 0;
	}
	
	
	if(Parent->data>_data){
		Parent->sol=newNode;
	}else
		Parent->sag=newNode;
	return 1;	
}

int deleteN(int _data){
	int found;
	Dugum *Cur=search(root,_data,&found);
	Dugum *ata;
	if(!found){
		printf("Aranan düðüm aðaçta bulunamadý.");
		return 0;
	}
	ata=AtaBul(root,_data);
	printf("%d\n",ata->data);
	if(Cur->sol=NULL&&Cur->sag==NULL)
		{
			if(ata->data>Cur->data){
			
				ata->sol=NULL;
				free(Cur);
				return 1;
			}
			else{
				ata->sag=NULL;	
				free(Cur);
				return 1;
				
			}
			
		}
	
}


void postOrder(Dugum *root){
	if(root->sol!=NULL)
		postOrder(root->sol);
	if(root->sag!=NULL)
		postOrder(root->sag);
	printf("%d\n",root->data);		
}
int main(){
	
	insert(15);
	insert(12);
	insert(14);
	insert(13);
	insert(45);
	insert(28);
	postOrder(root);
	printf("\n");
	deleteN(13);
	postOrder(root);
	
}
