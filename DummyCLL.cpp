 #include<stdio.h>
#include<stdlib.h>

struct dugum{
	
	int veri;
	struct dugum *sonraki;
	
};

typedef struct dugum Dugum;

Dugum *basla;

void BaslangicOlustur(){
	basla = (Dugum *)malloc(sizeof(Dugum));
	basla->sonraki = basla;
}

Dugum * arama(int _deger)
{
	dugum *simdiki,*onceki;
	if(basla->sonraki!=basla){
		
		onceki=basla;
		simdiki=basla->sonraki;
		
		do{
			if(simdiki->veri>=_deger)
				return onceki;
			onceki=simdiki;
			simdiki=simdiki->sonraki;
		}while(simdiki!=basla);
		
		return onceki;
		
		}
	return basla; 
	
}

void Ekle(int _deger){
	
	Dugum *yeni,*simdiki,*onceki;
	yeni=(Dugum *)malloc(sizeof(Dugum));
	onceki=arama(_deger);
	simdiki=onceki->sonraki;
	yeni->veri=_deger;
	
	yeni->sonraki=simdiki;
	onceki->sonraki=yeni;
}

void Listele(){
	Dugum *simdiki;
	simdiki=basla->sonraki;
	while(simdiki!=basla){
		printf("%d\n",simdiki->veri);
		simdiki=simdiki->sonraki;
	}
	
}


void Delete(int _deger){
	
	
	Dugum *onceki;
	onceki=arama(_deger);
	
	 if(onceki->sonraki->veri!=_deger){
    	printf("Bulunamadý");
    	return;
	}
	
	Dugum *temp=onceki->sonraki->sonraki;
	free(onceki->sonraki);
	onceki->sonraki=temp;
	
}

int main(){
	
	BaslangicOlustur();

	Ekle(5);

	Ekle(3);
	Ekle(2);
	Ekle(34);
		Ekle(10);
		Delete(3);
		Delete(10);
	Listele();
	

	
}
