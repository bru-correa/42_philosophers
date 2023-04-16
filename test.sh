#!/usr/bin/bash

run_test() {
  valgrind --tool=helgrind ./philo $1 $2 $3 $4
}

# run_test 2 200 200 200 2
./philo 2 200 200 200 2
