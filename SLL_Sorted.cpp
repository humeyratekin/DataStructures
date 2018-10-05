#include <stdio.h>
#include <stdlib.h>

// Bir dugumu
struct dugum{
   int veri;       
   struct dugum * sonraki;
};

typedef struct dugum Dugum;

Dugum *basla=NULL;

int listeBosmu()
{
  return ((basla==NULL)?1:0);   
}

int ogeSayisi()
{
  Dugum *simdiki=basla;  
  int adet=0;
  
  for (;simdiki!=NULL;simdiki=simdiki->sonraki)   
       adet++;
  return adet;     
}

// bu method geriye onceki dugumu doner
Dugum * konumBul(int _veri,int oper)
{
  Dugum *onceki=basla,*simdiki=basla;
  for(;simdiki!=NULL;){
  	
  	if(oper==0) //veri silmek için kullandýðýmýz eþitlik durumu
	{
		for(;simdiki!=NULL;){
			
			if (_veri == simdiki->veri) {
				 return onceki;
			}
            
			
		  onceki=simdiki;
   		  simdiki=simdiki->sonraki;
		}
		
	}
	else if(oper==1) //küçükten büyüðe sýralama ile veri ekleme
	{
		for(;simdiki!=NULL;){
		 
   		  
   		    if(_veri < simdiki->veri)
	        {
   		  		return onceki;
			}
			 
		onceki=simdiki;
   		simdiki=simdiki->sonraki;
              
		}
		
	}
	else             //büyükten küçüðe sýralama ile veri ekleme
	{
		for(;simdiki!=NULL;){
		 
   		  
   		    if(_veri > simdiki->veri)
	        {
   		  		return onceki;
			}
			 
		onceki=simdiki;
   		simdiki=simdiki->sonraki;
              
		}
	}

 
} 
	 return onceki; //son dugumden sonra       
}

void ekle(int _veri)
{
   Dugum * onceki;  
   Dugum * yeni=(Dugum *)malloc(sizeof(Dugum));
   yeni->veri=_veri;
   yeni->sonraki=NULL;
   onceki=konumBul(_veri,1);
   // basa ekleme durumu
   if (onceki==NULL){
      yeni->sonraki=basla;
      basla=yeni;
      return;                   
   }
   
   // sona ekleme durumu
   if (onceki->sonraki==NULL){
       onceki->sonraki=yeni;
       return;
   }
   
   // araya ekleme durumu
   yeni->sonraki=onceki->sonraki;
   onceki->sonraki=yeni;    
}

void sil(int _veri)
{
   Dugum * onceki,*temp; 
   if (listeBosmu()){
     printf("Liste boþ!\n");
     return;                      
   }
   onceki=konumBul(_veri,0);
   printf("%d\n",onceki->veri);
   if (onceki->sonraki==NULL)
   {
     if (onceki==basla) //baslangic durumu
     {
       free(onceki);
       basla=NULL;                 
     }
     else {                       
         printf("Aranan öðe bulunamadý!\n");
         return;                   
     }    
   }
   else { 
   temp=onceki->sonraki;
   onceki->sonraki=onceki->sonraki->sonraki;     
   free(temp);
   }  
}

void listele()
{
  Dugum *simdiki=basla;   
  for(;simdiki!=NULL;simdiki=simdiki->sonraki)     
     printf("Data:%d\n",simdiki->veri);     
}

int main(int argc, char *argv[])
{
  printf("liste %s\n",
         (listeBosmu()?"boþ":"boþ deðil"));  
  ekle(5);
  ekle(20);
  ekle(12);
  ekle(8);
  listele();
  printf("Listemizde toplam %d oge vardýr\n",
          ogeSayisi());
  sil(12);
  listele();
  printf("Listemizde toplam %d oge vardýr\n",
          ogeSayisi());
    


  system("PAUSE");	
  return 0;
}
