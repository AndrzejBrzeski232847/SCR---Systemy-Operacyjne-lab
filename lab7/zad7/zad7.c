/*

Wyobraźmy sobie koło o promieniu długości r 
wpisane w kwadrat o boku długości 2r. 

Pole tak zdefiniowanego koła to P(ko)=π r², 
podczas gdy pole powierzchni tak zdefiniowanego kwadratu wynosi P(kw)=4r². 

Stosunek tych dwóch pól wynosi π/4. Zatem, 
można wyznaczyć wartość liczby π korzystając 
z wcześniej poznanej metody.

Skoro pole powierzchni bryły można wyznaczyć przy 
pomocy podwójnej całki z krzywych opisujących bryłę, 
to próbkując (wyznaczając punkty należące do tych figur, 
wykorzystując losowe wartości z przedziałów) z 
odpowiednio dużą ilością próbek takie figury geometryczne, 
można obliczyć ich pola.

*/

#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>  //Header file for sleep(). man 3 sleep for details. 
#include <pthread.h>

#define M_PI 3.14159265358979323846

//Stwórz sensowną liczbę wątków, które wykonają procedurę //opisaną w następnym punkcie,

//Procedura: w ramach jednego wątku, dla sensownej liczby prób:

// A normal C function that is executed as a thread  
// when its name is specified in pthread_create() 
void *myThreadFunc(void *vargp) 
{ 
    sleep(1);
    
    int r = 0;
    int i = 0;
    float PI = 0;

    //przygotowanie do losowania liczby
    time_t t;
    srand((unsigned) time(&t));

    printf("Podaj promien r :");
    scanf("%d", &r);

    //pola figur
    Pko = M_PI*r*r;
    Pkw = 4*r*r;
    
    int x = (x <= Pko) && (x <= Pkw);
    int count_pko = 0;
    int count_pkw = 0;

    //	- wylosuj punkt,
    for(i=0; i <= x; i++) {
    	int y = rand() % Pko && rand() % Pkw;
    	
    	//	- jeśli znajduje się on w kole, zwiększ licznik //punktów w kole,
    	if( y > 0 && y < Pko ) {
    			count_pko++;


    	//	- dla każdego wylosowanego punktu zwiększ liczbę //punktów w kwadracie,
    	} else {
    			if( y > 0 && y > Pko && y < Pkw) {
    											count_pkw++;
		    												}
    	}
    	//	- wróć do punktu 1.
    
    	PI = 4* ( Pko/Pkw );
    	sleep(1);
    }

     return PI;
} 
   
int main() 
{ 
    pthread_t thread_id1, thread_id2; //zmienne thread_id1 i thread_id2 typu pthread_t
    								  //tak naprawde to integery używane do identyfikowania wątków w systemie
    printf("Before Thread\n"); 

    printf("Przed wątkiem nr 1");	// string wypisany na ekranie przed wykonaniem wątku
        pthread_create(&thread_id1, NULL, myThreadFunc, NULL);	//wywołanie funkcji tworzącej wątek 
        pthread_join(thread_id1, NULL);		//funkja charakterystyczna dla wątków - odpowiednik funkcji wait()
        									//funkcja na bazie której już zawiera wykonanie funkcji wait, lecz po stworzeniu wątku
                                            //daję czas programowi na wykonanie instrukcji, a następnie stworzenie nowego wątku
    printf("\nPo wątku nr 1");	// string wypisany na ekranie po wykonaniu wątku
    
    printf("\n");

    // instrukcje analogiczne do powyższych
    printf("Przed wątkiem nr 2");
        pthread_create(&thread_id2, NULL, myThreadFunc, NULL); 
        pthread_join(thread_id2, NULL); 
    printf("\nPo wątku nr 2");
    

    printf("After Thread\n"); 
    exit(0); 
}





/*
po zakończeniu danej ilości prób, liczba π powinna obliczona i udostępniona dla głównego programu,

główna procedura, po uzyskaniu wszystkich wyników, powinna wypisać wyniki uzyskane przez indywidualne wątki oraz obliczyć średnią estymatę wartości liczby π.
*/















