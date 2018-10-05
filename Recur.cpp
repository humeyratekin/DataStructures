#include<stdio.h>
#include<stdlib.h>


int Func(int numb){
	
	if(numb==1){
		return 0;
	}else
		return 1+Func(numb/2);
	
	
}

int FuncUs(int numb){
	
	if(numb==1){
		return 2;
	}else{
		numb--;
		return 2*FuncUs(numb);
	}
		
}

int Carp(int a, int b){
	int result;
	
	if(b==0)
		result=0;
	else if(b>0)
	 	result=a+Carp(a,b-1);
	else
		result=-a+Carp(a,b+1); 	
		
	return result;
	
}

int factorial(int numb){
	
	if(numb==1)
		return 1;
	else
		return numb*factorial(numb-1);
}

int gcd(int a,int b){
	int r;
	if(b>a)
		return gcd(b,a);
	r=a%b;
	if(r==0)
		return b;
	else
		return gcd(b,r);
	
}

int Sum_Array(int low,int high,int arr[]){
	
	
	
	int sum;
	if(high==low)
	    sum=arr[high];
	else
	{
		
		sum=arr[low]+Sum_Array(low+1,high,arr);		
	}	
	return sum;	
}

int FibNumb(int a){
	if(a==1||a==2)
		return 1;
	else
		return FibNumb(a-1)+FibNumb(a-2);
	
}

void DecToBin(int a){
	if(a>0){
		DecToBin(a/2);
		printf("%d",a%2);
		
	}
	
}

void MergeSort(int array[], int lower, int upper)
{  
     int tempArray[upper+1];
     int k, mid;

     if (lower < upper)   // if not we have a stopping case
     {      mid = (lower + upper - 1) / 2;
            MergeSort(array, lower, mid);      // recursive call
            MergeSort(array, mid + 1, upper);  // recursive call
            // Merge the two sorted pieces together:      
            Merge(tempArray,array,lower,mid,upper);
            // Copy the data back into array:
            for (k = lower; k <= upper; k++)
                        array[k] = tempArray[k];
     }   
}

void Merge(int merged [],int array [],int lower, int mid, int upper)
{
   int apos =lower;
   int bpos =lower;
   int cpos =mid+1;
   while (bpos <= mid  && cpos <= upper)
   {
        if (array[bpos] < array[cpos]){
            merged[apos]=array[bpos];
            bpos++; apos++; 
        }
        else {
            merged[apos]=array[cpos];
            cpos++; apos++;   }
    }
    while (bpos <= mid){
       merged[apos]=array[bpos];
       bpos++; apos++; }
    while (cpos <= upper){
       merged[apos]=array[cpos];
       cpos++; apos++;  }
}


int main(){
	int Arr[]={10,10,10,5};
	printf("%d",FibNumb(5));
	
	DecToBin(8);
}
