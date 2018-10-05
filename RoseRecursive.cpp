#include<stdio.h>
#include<stdlib.h>

int ABFunc(int a,int b){
	int result;
	if(b==0)
		result=0;
	else if(b>0)
		result=(a+ABFunc(a,b-1));
	else
	    result=(-a+ABFunc(a,b+1));		
	
	return result;
}
int Rose(int n){
	
	if(n==1){
		return 0;
	}else
		{
			return(1+Rose(n/2));
		}
		
}
int main(){
	
	printf("%d",ABFunc(-12,-6));
}
