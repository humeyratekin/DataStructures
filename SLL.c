#include <stdio.h>
#include <stdlib.h>

// Bir dugumu
struct dugum{
   int veri;       
   struct dugum * sonraki;
};

typedef struct dugum Dugum;

Dugum *basla;

void ekle(int _veri)
{
   Dugum * yeni=(Dugum *)malloc(sizeof(Dugum));
   yeni->veri=_veri;
   yeni->sonraki=basla;
   basla=yeni;
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
  printf("liste %s\n",listeBosmu()?"bos":"bos deðil");
  ekle(5);
  ekle(20);
  ekle(12);
  listele();
  printf("\nToplam oge sayisi:..%d\n",OgeSayisi());
  sil();
  listele();
  printf("\nToplam oge sayisi:..%d\n",OgeSayisi());
  
  
    
  system("PAUSE");	
  return 0;
}
