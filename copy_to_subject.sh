#!/bin/bash
echo -n "dir?>"
read input

mkdir -p $input \
&& cp -r philo/srcs/ $input \
&& cp -r philo/inc/ $input \
&& cp philo/Makefile $input

echo "output done!"