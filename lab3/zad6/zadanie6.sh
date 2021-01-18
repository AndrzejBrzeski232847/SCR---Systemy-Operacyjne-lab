
#!/bin/sh

while :

do
echo "Obecny czas to :"
echo $(date)
sleep 1

trap 'echo Polecenie trap wykonane' 2 3 8 4

done

#zatrzymuje skrypt poleceniem
#kill -s STOP <pid>

#wznawiam skrypt poleceniem
#kill -s CONT <pid>
