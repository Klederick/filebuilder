#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
int getlines(char* file){
	FILE *f;
	f = fopen(file, "r");
	int lines = 0;	
	char current = getc(f);
	while(current != EOF){
		if(current == '\n'){
			lines++;
		}
		current = getc(f);
		}
	
	return lines;
}
int random(int min, int max){
   return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}
int main(void){
	//FILE init	
	FILE * numero;
	FILE * z_meno;
	FILE * m_meno;
	FILE * m_priezvisko;
	FILE * z_priezvisko;
	FILE * seznam;
	//Open all files
	numero = fopen("numero.txt", "r");
	z_meno = fopen("zenskemeno.txt", "r");
	m_meno = fopen("muzskemeno.txt", "r");
	m_priezvisko = fopen("muzskepriezvisko.txt", "r");
	z_priezvisko = fopen("zenskepriezvisko.txt", "r");
	seznam = fopen("seznam.txt", "w");
	//check if all files are created
	
	if(access("numero.txt", F_OK) == 0 && access("zenskemeno.txt", F_OK) == 0 && access("muzskemeno.txt", F_OK) == 0 && access("zenskepriezvisko.txt", F_OK) == 0 && access("muzskepriezvisko.txt", F_OK) == 0){
		//Do nothing
	}else{
		printf("Some files are missing/corrupted");
		return 0;
        }
	//Reset randomizer for random results
	srand(time(NULL));
	//main loop for creating contacts
	//100 could be changed to change the amount of contacts
	for(int i = 0; i < 100; i++){	
		rewind(m_meno); rewind(m_priezvisko); rewind(z_meno); rewind(z_priezvisko);
	 //name && surname saving
		char _meno[20];
                char _priezvisko[20];
		if(i%2 == 0){	
	        	int menoID = random(0, getlines("muzskemeno.txt"));
	        	int priezviskoID = random(0, getlines("muzskepriezvisko.txt"));
	        	for(int a = 0; a < menoID; a++){
	        	        fscanf(m_meno, "%s",_meno);
	        	}
	        	for(int a = 0; a < priezviskoID; a++){
	        	        fscanf(m_priezvisko, "%s", _priezvisko);
	       		}
		}else{
			int menoID = random(0, getlines("zenskemeno.txt"));
                        int priezviskoID = random(0, getlines("zenskepriezvisko.txt"));
                        for(int a = 0; a < menoID; a++){
                                fscanf(z_meno, "%s",_meno);
                        }
                        for(int a = 0; a < priezviskoID; a++){
                                fscanf(z_priezvisko, "%s", _priezvisko);
                        }

		}
	        fprintf(seznam, "%s %s", _meno, _priezvisko);
	        putc('\n', seznam);
	
	//number saving
		char _cislo[10];
		rewind(numero);
        	for(int a = 0; a <= i; a++){  
		      fscanf(numero, "%s", _cislo);
        	}
        	fprintf(seznam, "%s", _cislo);
        	putc('\n', seznam);

	
	}	



	fclose(numero); fclose(z_meno); fclose(m_meno); fclose(m_priezvisko); fclose(z_priezvisko); fclose(seznam);
	return 0;


}
