#!/bin/bash

# Función para ejecutar una prueba con argumentos dados
run_test() {
    ./PmergeMe "$@"
  # if [ $? -ne 0 ]; then
  #   echo "Se produjo un segfault. Argumentos: $*"
  #   cat segfault_log.txt
  # fi
  echo "--------------------------------------------"
#   rm -f segfault_log.txt
}

# Usando un bucle for para $1 iteraciones (tomando el valor del primer argumento)
for ((i=1; i<=$1; i++)); do
    number_amount=$(shuf -i 1-3000 -n 1)
    echo "Número aleatorio: $number_amount"
    range=$((number_amount * 3))  # Realiza la operación matemática y almacena el resultado en 'range'
    echo "Rango: 0-$range"
    # Ejecuta una prueba en cada iteración
    run_test $(shuf -i 0-$range -n $number_amount)
done

# number_amount=$(shuf -i 1-3000 -n 1)
# echo "Número aleatorio: $number_amount"
# range=$((number_amount * 3))  # Realiza la operación matemática y almacena el resultado en 'range'
# echo "Rango: 0-$range"
# # Ejecuta una prueba en cada iteración
# run_test $(shuf -i 0-$range -n $number_amount)



# arg=`shuf -i 1-100000 -n 3000 | tr "\n" " "`
# echo $arg
