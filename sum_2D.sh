#! /bin/bash
declare -A X
declare -A Y
declare -A Z
echo "Enter the size of arrays :"
read m n
echo "Enter the elements of first array : "
for ((i=0;i<m;i++))
do
for ((j=0;j<n;j++))
do
read X[$i,$j]
done
done
echo "Enter the elements of the second array: "
for ((i=0;i<m;i++))
do
for ((j=0;j<n;j++))
do
read Y[$i,$j]
done
done
echo "First array is: "
for ((i=0;i<m;i++))
do
for ((j=0;j<n;j++))
do
echo -ne "${X[$i,$j]}"
done
echo 
done
echo "Second array is: "
for ((i=0;i<m;i++))
do
for ((j=0;j<n;j++))
do
echo -ne "${Y[$i,$j]}"
done
echo 
done
echo "Sum of two matrices is : "
for ((i=0;i<m;i++))
do
for ((j=0;j<n;j++))
do
Z[$i,$j]=$((X[$i,$j]+Y[$i,$j]))
echo -ne "${Z[$i,$j]} "
done
echo 
done
