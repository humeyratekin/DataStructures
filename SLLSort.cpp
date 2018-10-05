#include <stdio.h>
#include <stdlib.h>

// Bir dugumu
struct dugum{
   int veri;       
   struct dugum * sonraki;
   
};

typedef struct dugum Dugum;

Dugum *basla=NULL;

//Bu metod geriye önceki durumu döner
Dugum * konumBul(int _veri)
{
	Dugum *onceki=basla;
	Dugum *simdiki=basla;
	for(;simdiki!=NULL;){
		
		if(_veri<simdiki->veri){
		
		return onceki; //BAÞLANGIÇ VEYA ARA DÜÐÜM OLMA DURUMU
		}
		onceki=simdiki;
		simdiki=simdiki->sonraki;
		}
		return onceki; //SON DÜÐÜMDEN SONRA	
	}
	
	

void ekle(int _veri)
{
   Dugum * yeni=(Dugum *)malloc(sizeof(Dugum));
   
   yeni->veri=_veri;
   yeni->sonraki=NULL;
   Dugum * onceki=konumBul(_veri);
   


    if(onceki==NULL) //basa ekler
   {
   		yeni->sonraki=basla;
   		basla=yeni;
   		return;
   }
   
   if(onceki==basla){
   	
   		yeni->sonraki=basla;
   		basla=yeni;
   		return;
   }
    if(onceki->sonraki==NULL) //sona ekler
   {
   		onceki->sonraki=yeni;
   		return;
				
   }                  //araya ekler
  
   
  		 
  		 yeni->sonraki=onceki->sonraki;  
  		 onceki->sonraki=yeni;
    
}



void sil()
{
   Dugum *simdiki=basla;
   basla=basla->sonraki;     
   free(simdiki);  
}

void listele()
{
  Dugum *simdiki=basla;   
  for(;simdiki!=NULL;simdiki=simdiki->sonraki)     
     printf("Data:%d\n",simdiki->veri);     
}

int listeBosmu(){
	
	return ((basla==NULL)?1:0);

}

int OgeSayisi(){
	int adet=0;
	Dugum *simdiki=basla;
	for(;simdiki!=NULL; simdiki=simdiki->sonraki)
	{
		adet++;
	}
	return adet;
}

int main(int argc, char *argv[])
{
  ekle(23);
  ekle(45);
  ekle(12);
  ekle(47);
  listele();
  printf("\nToplam oge sayisi:..%d\n",OgeSayisi());
 
  listele();
  printf("\nToplam oge sayisi:..%d\n",OgeSayisi());
  
  
    
  system("PAUSE");	
  return 0;
}
