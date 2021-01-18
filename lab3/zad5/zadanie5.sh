
#!/bin/sh

#Mozliwe jest rowniez podanie godziny w innym formacie na przyklad:
#echo $(date+"%T")

while :

do
echo "Obecny czas to :"
echo $(date)
sleep 1

trap 'echo Polecenie trap wykonane' 2 3 8 4

done

#umieszczam polecenie trap dla sygnalow reprezentowany liczbami
#z listy generowanej poleceniem : trap -l
#trap 'echo Polecenie trap wykonane' 2 3 8 4
#brak mozliwosci usmierecenia procesu poleceniem kill -SIGKILL <pid>
#dziala jedynie CTRL+Z
