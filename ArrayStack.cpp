#include <stdio.h>
#include <stdlib.h>

#define SIZE 50

int yigit[SIZE];

int top=-1;
void push(int _veri){
	if(top+1==SIZE){

		printf("Yýðýt dolu..\n");
		return;	
	}
	++top;
	yigit[top]=_veri;
  }
  
  void pop(){
  	if(top==-1){
  		printf("Stack boþ..\n");
  		return;
	  }
	  
	--top;
  	
  }
  
  int topData(int *_data){
  		if(top==-1){
  		printf("Stack boþ..\n");
  		return 0;
	  }
		
		*_data=yigit[top];
		return 1;
  	
  }

void Yazdir(){
	
	int i=top;
	for(;i>=0; i--){
		
		printf("Stack[%d]=%d\n",i+1,yigit[i]);
	}


}  
  int main(){
  	
  	push(4);
  	push(34);
  	push(-4);
  	Yazdir();
  	
  }
