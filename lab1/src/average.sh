  GNU nano 4.8                                                                                          numbersScript.sh                                                                                                     
#!/bin/bash

count=$#
sum=0

for arg in "$@"; do
	sum=$(echo "$sum + $arg" | bc)
done

average=$(echo "scale=2; $sum / $count" | bc)

echo "Amount of Args: $count"
echo "Avreage: $average"
