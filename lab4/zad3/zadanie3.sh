#!/bin/bash

man proc

ls -l /proc | head

ls -l /proc | grep '^d'

touch zadanie3.txt | ls -l /proc > zadanie3.txt

ps -aux

echo "Podaj numerek procesu"
read $idprocesu
ls -ltr /proc/$idprocesu

