  #include<stdio.h>
#include<stdlib.h>

struct dugum{
	
	int veri;
	struct dugum *sonraki;
	
};

typedef struct dugum Dugum;

Dugum *son=NULL;

Dugum * arama(int _deger)
{
	dugum *simdiki,*onceki;
	if(son!=NULL){
		
		onceki=son;
		simdiki=son->sonraki;
		
		do{
			if(simdiki->veri>=_deger)
				return onceki;
			onceki=simdiki;
			simdiki=simdiki->sonraki;
		}while(simdiki!=son->sonraki);
		
		return onceki;
		
		}
	return NULL; 
	
}

void ekle(int _deger){
	Dugum *onceki,*yenidugum;
	
	if(son==NULL){
		yenidugum=(Dugum *)malloc(sizeof(Dugum));
		son=yenidugum;
		yenidugum->sonraki=yenidugum;
		return;

	}
	yenidugum=(Dugum *)malloc(sizeof(Dugum));
    onceki=arama(_deger);
    
    yenidugum->veri=_deger;
    yenidugum->sonraki=onceki->sonraki;
    onceki->sonraki=yenidugum;
	
	if(son->veri<_deger){
		son=yenidugum;
	}	
	
}

void sil(int _deger){
	Dugum *onceki,*yenidugum;
	if(son==NULL){
		printf("Liste boþ");
		return;
	}
	
	onceki=arama(_deger);
	
    if(onceki->sonraki->veri!=_deger){
    	printf("Bulunamadý");
    	return;
	}
	
	if(son->sonraki==son){
		if(_deger==son->veri){
			free(son);
			son=NULL;
		
		}
	}

	
	if(onceki->sonraki==son){ //son
		
		son=onceki;
	}
	Dugum *temp=onceki->sonraki->sonraki;
	free(onceki->sonraki);
	onceki->sonraki=temp;
	
}
void listele(){
	Dugum *simdiki=son->sonraki;
	Dugum *onceki;
	
		do{
			printf("Dugum degeri: %d\n",simdiki->veri);
			simdiki=simdiki->sonraki;
		}while(simdiki!=son->sonraki);
	
}

  
int main(){
	
	ekle(1);
	ekle(9);
	ekle(7);
	
	listele();
	
}




