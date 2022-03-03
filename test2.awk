#!/usr/bin/env bash
 /^\s*$/ {next;} 
{ 
  min = $2; max = $2; sum = $2;
  for (i=3; i<=NF; i++) {
    if (min > $i) min = $i;
    if (max < $i) max = $i;
    sum+=$i }
    if (s<max) s = max;
    if (f>min) f = min;
  printf "%-15s min=%2i max=%2i avg=%2.3f\n", $1, min, max, sum/(NF-1)
}   END {printf "Общее Min=%2i Max=%2i\n", f, s} 
