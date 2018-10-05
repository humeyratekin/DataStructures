#include <stdio.h>
#include <stdlib.h>

int dogArama(int a[],int ilk,
                   int son,int anahtar)
{
   int i;
   for(i=ilk;i<=son;i++)
      if (a[i]==anahtar)                  
         return i;          
   return -1;                
}                   
                  
int ikiliArama(int a[],int ilk, int son,int anahtar)
{ int ortanokta;  
  while (ilk<=son){
      ortanokta=(ilk+son)/2;
      if (a[ortanokta]==anahtar)
          return ortanokta;
      if (a[ortanokta]>anahtar)
          son=ortanokta-1;
      else      
          ilk=ortanokta+1;
  } 
  return -1;       
}     
              
void birlestir(int a[],int sol,
                       int orta,int sag);
                       
void birSirala(int a[],int sol,int sag)
{
  int orta;
  
  if (sol<sag){
     orta=(sol+sag)/2;       
     birSirala(a,sol,orta);//sol tarafý cagir
     birSirala(a,orta+1,sag); // sag tarafý cagir
     birlestir(a,sol,orta,sag);
  }
}

void birlestir(int a[],int sol,
                       int orta,int sag)
{ int i;
  int b[sag-sol+1];   
  int solI=sol;
  int sagI=orta+1;     
  int bIndis=sol;
  while (solI<=orta && sagI<=sag)
  {
    if (a[solI]<a[sagI])
       b[bIndis++]=a[solI++]; //sol kucuk
    else      
       b[bIndis++]=a[sagI++]; //sag kucuk
  }   
  //geri kalanlarý kopyala
  while (solI<=orta) b[bIndis++]=a[solI++];  
  while (sagI<=sag)  b[bIndis++]=a[sagI++];
  //orjinal listeye kopyala
  for (i=sol;i<=sag;i++)
       a[i]=b[i];
}

void goruntule(int a[],int elsay)
{  int i;
   for (i=0;i<elsay;i++)  
       printf("%d\n",a[i]);
}

int main(int argc, char *argv[])
{
  int a[]={43,23,32,17,8,3,19,25};
  
  birSirala(a,0,7);
  goruntule(a,8);
  
  system("PAUSE");	
  return 0;
}
