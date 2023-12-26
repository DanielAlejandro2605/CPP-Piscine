#!/bin/bash

run_test() {
    ./PmergeMe "$@"
  echo "--------------------------------------------"
}

for ((i=1; i<=$1; i++)); do
    number_amount=$(shuf -i 1-3000 -n 1)
    echo "Número aleatorio: $number_amount"
    range=$((number_amount * 3))  # Realiza la operación matemática y almacena el resultado en 'range'
    echo "Rango: 0-$range"
    # Ejecuta una prueba en cada iteración
    run_test $(shuf -i 1-$range -n $number_amount)
done


# arg=`shuf -i 1-100000 -n 3000 | tr "\n" " "`