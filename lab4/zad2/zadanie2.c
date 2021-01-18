#include <stdio.h>
 
int main () {

	// inicjuję tryb ncurses
	//initscr();
   for( ; ; ) {
      i += 1;
      // sleep(1);
      // nanosleep(100000);
      // dodaję funckję refresh odświeżającą akcję na ekrnie
      //refresh();
   }

   //kończę tryb ncurses
   //endwin();

   return 0;
}

//Sprawdź czy Twój program pokazuje się w czołówce programów wykorzystujących cykle obliczeniowe
/*
ps -eo pid,ppid,cmd,%mem,%cpu --sort=-%mem | head

Wzór = ps --sort=-pcpu | head -n 6
ps -Ao user,uid,comm,pid,pcpu,tty --sort=-pcpu | head -n 6


*.