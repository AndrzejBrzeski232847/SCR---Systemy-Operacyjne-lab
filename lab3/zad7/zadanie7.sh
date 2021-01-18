#!/bin/sh

#sprawdzenie priorytetu procesu
#ps -lu <uzytkownik> | grep proces.sh

echo "Podaj wartosc priorytetu"
read priorytet

echo "Podaj wartosc nizszego priorytetu"
read priorytet2

#zmiana priorytetu podczas uruchomienia procesu
nice -$priorytet ./proces.sh

#wykonuje sie nieskonczona petla - jezeli bedzie ona skonczona
#wtedy skrypt wykona polecenie renice

echo "Podaj pid procesu"
read id_p

#zmiana uruchomionego i dzialajace procesu
renice -n $priorytet2 -p $id_p

#0 T  1000  6733 10700  0  80   0 -  1157 signal pts/0    00:00:00 proces.sh
#0 T  1000  7055  5621  0  95  15 -  1157 signal pts/1    00:00:00 proces.sh
#0 S  1000  7181  7175  0  85   5 -  1157 wait   pts/1    00:00:00 proces.sh
