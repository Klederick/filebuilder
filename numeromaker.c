#include<stdio.h>
#include<stdlib.h>

int main(void){

//reset numero.txt file, teoreticky nepotrebne kvoli w parametru, nechavam to tu pre istotu 
if(remove("numero.txt") == 0) {
   printf("odstranil som numero.txt\n");
}else{
   printf("numero nikdy neexistovalo\n");
}

//open file
FILE * numero;
numero = fopen("numero.txt", "w");
//pocet kontaktov by sa teoreticky dal pozmenit v pripade ak spustime programy na generaciu s rovnakym ciselnym
//parametrom, pre tento problemset by malo postacit 100 kontaktov
for(int i = 0; i < 100; i++){
	for(int a = 0; a < 9; a++){
		 char digit = rand() % 10 + '0';
		 
		 putc(digit, numero);
	}
	putc('\n',numero);
}

fclose(numero);

return 0;

}
