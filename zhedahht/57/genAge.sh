#!/bin/bash

round=${1:-1}

randnum=`./rand`

while [ "X$((round > 0))" = "X1" ];
#while [ "X0" = "X1" ];
do
		randnum=`./rand $randnum`;
		num=$((randnum % 100));
		echo $num;
		: $((round--));
done
