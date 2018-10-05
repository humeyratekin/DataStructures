#include<stdio.h>
#include<conio.h>


void insertionSort(int dizi[],int n){
	
	if(n<2)
		return;
	int temp;
	int j;	
	for(int i=1; i<n; i++)
	{
		j=i;
		temp=dizi[i];
		for(;j>=1&&dizi[j-1]>temp; j--){
			dizi[j]=dizi[j-1];		
		}
		dizi[j]=temp;
	}	
	
}


void goruntule(int dizi[],int n)
{
	for(int i=0; i<n; i++){
		
		printf("%d\n",dizi[i]);
	}
}

void selectionSort(int dizi[],int n){
	
	int i,j;
	if(n<2)
		return;
		
	int smallest,temp;
	for(i=0; i<n-1; i++){
		
		smallest=i;
		for(j=i+1; j<n; j++){
			
			if(dizi[j]<dizi[smallest])
				smallest=j;
		}
		dizi[smallest]=temp;
		dizi[smallest]=dizi[i];
		dizi[i]=temp;
		
		
		
	}
	
}


void bubbleSort(int dizi[],int n){
	
	int i,j,dur;
	int temp;
		
	for(i=0; i<n; i++)
	{
		dur=0;
		for(j=0; j<n-i; j++)
		{
			if(dizi[j]>dizi[j+1]){
				temp=dizi[j+1];
				dizi[j+1]=dizi[j];
				dizi[j]=temp;
				dur=1;
			}
			
		}
		if(dur==0)
			break;
	}
	
}

int main(){
	
	int dizi[]={15,2,7,3,17,5};
	bubbleSort(dizi,6);
	goruntule(dizi,6);
	
	
	
}



