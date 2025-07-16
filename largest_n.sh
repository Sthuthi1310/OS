#! /bin/bash
echo "Enter the size of the array: "
read n
declare -a array
echo "Enter the elements of the array: "
for((i=0; i<n; i++))
do
    read array["$i"]
done
max=${array[$i]}
for((i=1; i<n; i++))
do  
    if [ [ $max < ${array[$i]} ] ]
    then   
    max=${array[$i]}
    fi
done
echo "The largest of the given numbers is $max"