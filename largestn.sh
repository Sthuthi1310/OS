#! /bin/bash
echo "Enter the size of array: "
read n
echo "ENterr the array elements : "
for ((i=0;i<n;i++))
do
read a["$i"]
done
max=${a[0]}
for (( i=1;i<n;i++ ))
do
if [[ ${a[$i]}>$max ]]
then
max=${a[$i]}
fi
done
echo "Largest of all numbers is $max"