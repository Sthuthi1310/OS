#! /bin/bash
echo "Enter the lower boundary: "
read n1
echo "Enter the upper boundary: "
read n2
for((i=n1; i<=n2; i++))
do
for((j=2; j<=$i/2; j++))
do
if [ $((i%j)) -eq 0 ] 
then
flag=1
break
fi
done
if [ $flag -eq 0 ] 
then 
echo -ne"$i"
fi
flag=0
done
