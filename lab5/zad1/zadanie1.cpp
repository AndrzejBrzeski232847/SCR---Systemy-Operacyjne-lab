#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<string.h> 
#include<sys/wait.h> 
#define MSGSIZE 16


int lab5(char plik) {
	
	char msg1[] = "Hello, tutaj rodzic";
	char msg2[] = "Hello, tutaj dziecko";
	
	gets(msg1);
	gets(msg2);
	
	//zmienne
	int fd1[1];  // potok dla procesu rodzica - proces nadrz�dny
    int fd2[1];  // potok dla procesu dziecka - proces potomny
	FILE *fc, *fo;
	pid_t p; 
	
	//obs�uga b��d�w mog�cych powsta� przy tworzeniu nowego potoku
	//j�zeli wyst�pi� to wy�wietlany jest komunikat o bl�dzie
	if (pipe(fd1)==-1) 
    { 
        fprintf(stderr, "Pipe Failed" ); 
        return 1; 
    } 
    if (pipe(fd2)==-1) 
    { 
        fprintf(stderr, "Pipe Failed" ); 
        return 1; 
    } 
	
	
	
	//tworz� proces nadrz�dny i potomny
	p = fork(); 
	
	if (p < 0) 
    { 
        fprintf(stderr, "fork Failed" ); 
        return 1; 
    } 
    else if (p > 0)		// proces rodzica
    { 
	
		//tworz� plik tekstowy poza Ifem
		//gdzie pracuje proces nadrz�dny
		fd = creat(plik, "w");
		fo = oper(plik, O_RDWR );

        // wysy�amy tre�� dokumentu ukryt� pod �a�cuchem
		//znak�w msg1 poprzez potok 
        write(fd1[1], msg1); 
         
  
        // czekamy na proces potomny na wys�anie tre�ci pliku
        wait(NULL); 
  		close(fd1[1]);
    } 
    
    else	// proces potomny 
    { 
  
  		read(fd1[1], msg1); //odczytanie danych z potoku
  
        printf("\n");
        printf("#%s#",msg1);		//wypisanie na ekranie wiadomo�ci dodaj�c znak #
        printf("\n");
  		
		fprintf(fo, "%s", msg1);	//
        
		close(fd1[1]); 
  
        exit(0); 
    } 	
		
	close(fo); 	
}

int main() {

	char plik;
	
	printf("Podaj nazwe pliku tekstowego");
	scanf("%s", &plik);
	lab5(plik);
}
