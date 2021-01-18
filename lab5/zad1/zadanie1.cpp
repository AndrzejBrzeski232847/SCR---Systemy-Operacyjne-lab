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
	int fd1[1];  // potok dla procesu rodzica - proces nadrzêdny
    int fd2[1];  // potok dla procesu dziecka - proces potomny
	FILE *fc, *fo;
	pid_t p; 
	
	//obs³uga b³êdów mog¹cych powstaæ przy tworzeniu nowego potoku
	//jêzeli wyst¹pi¹ to wyœwietlany jest komunikat o blêdzie
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
	
	
	
	//tworzê proces nadrzêdny i potomny
	p = fork(); 
	
	if (p < 0) 
    { 
        fprintf(stderr, "fork Failed" ); 
        return 1; 
    } 
    else if (p > 0)		// proces rodzica
    { 
	
		//tworzê plik tekstowy poza Ifem
		//gdzie pracuje proces nadrzêdny
		fd = creat(plik, "w");
		fo = oper(plik, O_RDWR );

        // wysy³amy treœæ dokumentu ukryt¹ pod ³añcuchem
		//znaków msg1 poprzez potok 
        write(fd1[1], msg1); 
         
  
        // czekamy na proces potomny na wys³anie treœci pliku
        wait(NULL); 
  		close(fd1[1]);
    } 
    
    else	// proces potomny 
    { 
  
  		read(fd1[1], msg1); //odczytanie danych z potoku
  
        printf("\n");
        printf("#%s#",msg1);		//wypisanie na ekranie wiadomoœci dodaj¹c znak #
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
