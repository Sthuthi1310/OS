#! /bin/bash
echo "Enter the lower bound and upper bound: "
read n1 n2
for ((i=n1;i<=n2;i++))
do
for ((j=2;j<=$i/2;j++))
do
if [[ $((i%j)) == 0 ]]
then
flag=1
break
fi
done
if [[ $flag == 0 ]]
then
echo -ne " $i"
fi
flag=0
done