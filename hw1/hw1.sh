#!/bin/sh

min=1
max=10
isGuessed=false
guess_num=0


checkSize() {
  if [ $guess_num -gt $answer_num ]; then
    max=$(($guess_num-1))
  elif [ $guess_num -lt $answer_num ]; then
    min=$(($guess_num+1))
  fi
}

echo "Welcome to the Number Guessing Game!"

echo "Please enter the target number: \c"
read answer_num

while [ $guess_num -ne $answer_num ]; do
  echo "Please enter a number between $min and $max: \c"
  read guess_num
  checkSize;
done

echo Bingo!
