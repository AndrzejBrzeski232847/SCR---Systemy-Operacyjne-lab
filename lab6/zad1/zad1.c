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
  
  //pamiêæ wspólna
  struct stat st;
  
  //bufor
  char plik[100];

  if( fd < 0 )
	handle_error("open");

	int i=1;
	while(1) {
		printf("Podaj nazwe pliku %d : ",i);
		gets(plik);
		
		//tworzê i otwierm plik podany w pêtli
		fd = creat(plik, "w");
		fd = open(plik, O_RDWR, SIRUSR | S_IWUSR);
		
		printf("\n");
		//operacja na w³aœciwoœciach pliku
		stat(plik, &st);
		//ustawiona wielkoœæ obszaru pamiêci - obliczenie d³ugoœci pliku
		size = st.st_size;
		//mapowanie obszaru pamiêci wspólnej
		char *file_in_memory = mmap( NULL, st.st_size, PROT_READ | PROT_WRITE ,MAP_SHARED, fd, 0 );
		//zmiana wielkoœci obszaru pamiêci na 1000 bajtów
		int change_size = ftruncate(fd,1000);
		
		//wczytanie pliku do zmapowanego obszaru pamiêci
		munmap(file_in_memory, st.st_size);
		close(fd);
		
		i++;
		sleep(1);
	}


}
