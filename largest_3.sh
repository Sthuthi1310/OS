#! /bin/bash
echo "Enter the numbers :"
read a b c 
if ((b>a))
then
max=$b 
else 
max=$a
fi
if ((max<c))
then
max=$c
fi
echo "Largest of 3 numbers is $max"
