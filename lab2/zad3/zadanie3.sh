#!/bin/sh

#Pytanie o rozszerzenie
echo Hi , podaj proszę rozszerzenie szukanego pliku:
read rozszerzenie

#Pytanie o maske
echo Hi , podaj proszę maske szukanego pliku:
read maska

#Pytanie o N dni
echo Hi , podaj proszę ilość N dni ostatniej aktywności szukanego pliku:
read N

#Pytanie o nazwe archiwum
echo Hi , podaj proszę nazwe archiwum:
read archiwum

echo Szukam pliku

mkdir $archiwum
touch $archiwum/$archiwum 
find . -type f -iname "$maska*"."*$rozszerzenie" -mtime -$N > $archiwum/$archiwum
tar -cvf $archiwum.tar $archiwum/

#mkdir $archiwum | touch $archiwum/$archiwum | find . -type f -mtime -$N | tar -cvf $archiwum.tar $archiwum/

echo Wykonano

#find . -type f -name "*.txt"

#The find command is slow, use this command will give you result immediately:
#locate "/etc/*.conf"

#tar -cf archiwum.tar wpis1.txt wpis2.txt wpis3.txt



