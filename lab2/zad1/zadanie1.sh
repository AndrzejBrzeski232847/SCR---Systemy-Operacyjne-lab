#!/bin/bash

printf -v day '%(%a)T'

case $day in 
  Mon) echo "Witaj uzytkowniku - jest $day";;
  Tue) echo "Witaj uzytkowniku - jest $day";;
  Wed) echo "Witaj uzytkowniku - jest $day";;
  Thu) echo "Witaj uzytkowniku - jest $day";;
  Fri) echo "Witaj uzytkowniku - jest $day";;
  Sat) echo "Witaj uzytkowniku - jest weekend - $day";;
  Sun) echo "Witaj uzytkowniku - jest weekend - $day";;
esac
