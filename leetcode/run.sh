#!/bin/bash
# 参数个数
# echo "$#"

file_full_name=$1
file_name=${file_full_name%.cpp}

# echo $file_full_name
# echo $file_name

g++ "$file_full_name" -o "$file_name" && "./$file_name"
