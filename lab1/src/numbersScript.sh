#!/bin/bash

for i in {1..150}
do
	echo $(( $(od -An -N2 -i /dev/random) % 100)) >> numbers.txt
done
