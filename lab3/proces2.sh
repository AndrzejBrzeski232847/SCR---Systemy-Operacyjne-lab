#!/bin/sh

while :
do 
	echo "Pracuje"
	echo "Zapis do potoku"
	ls > FIFO
	echo "Odczyt z potoku"
	cat zadanie.txt < FIFO
	sleep 1
done
