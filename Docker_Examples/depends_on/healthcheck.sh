#!/usr/bin/env bash

set -e

timeout=3
while [ $timeout -gt 0 ]
do
  echo "Prepare launch... $timeout sec left "
  sleep 1s
  ((timeout--))
done

exit 0
