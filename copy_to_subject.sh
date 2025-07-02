#!/bin/bash
echo -n "dir?>"
read input

mkdir -p $input/philo \
&& cp -r philo/srcs/ $input/philo \
&& cp -r philo/inc/ $input/philo \
&& cp -r philo/libs/ $input/philo \
&& cp philo/Makefile $input/philo

echo "output done!"