#include <stdio.h>

//operacje na plikach
#include <fcntl.h>
#include <string.h>

//funkcja stat
#include <sys/stat.h>

//funkcja mmap
#include <sys/mman.h>

//funkcja truncate i ftruncate
#include <unistd.h>
#include <sys/types.h>

int main(void) {

  FILE *fd;
  
  //pami�� wsp�lna
  struct stat st;
  
  //bufor
  char plik[100];

  if( fd < 0 )
	handle_error("open");

	int i=1;
	while(1) {
		printf("Podaj nazwe pliku %d : ",i);
		gets(plik);
		
		//tworz� i otwierm plik podany w p�tli
		fd = creat(plik, "w");
		fd = open(plik, O_RDWR, SIRUSR | S_IWUSR);
		
		printf("\n");
		//operacja na w�a�ciwo�ciach pliku
		stat(plik, &st);
		//ustawiona wielko�� obszaru pami�ci - obliczenie d�ugo�ci pliku
		size = st.st_size;
		//mapowanie obszaru pami�ci wsp�lnej
		char *file_in_memory = mmap( NULL, st.st_size, PROT_READ | PROT_WRITE ,MAP_SHARED, fd, 0 );
		//zmiana wielko�ci obszaru pami�ci na 1000 bajt�w
		int change_size = ftruncate(fd,1000);
		
		//wczytanie pliku do zmapowanego obszaru pami�ci
		munmap(file_in_memory, st.st_size);
		close(fd);
		
		i++;
		sleep(1);
	}


}
