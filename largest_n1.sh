#! /bin/bash
echo "Enter the size of the array: "
read n
echo "Enter the array elements: "
for ((i=0;i<n;i++))
do
read arr["$i"]
done
max=${arr[$i]}
for (( i=1;i<n;i++ ))
do
if [[ $max<${arr[$i]} ]]
then
max=${arr[$i]}
fi
done
echo "THe largest of given numbers is $max "