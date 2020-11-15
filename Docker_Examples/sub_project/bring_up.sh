#!/usr/bin/env bash

set -e

DEFAULT_PACKAGES=("common")

PACKAGES=()
if [ $# -gt 0 ]; then
  for package in "$@"; do
    PACKAGES+=($package/)
  done
else
  for folder in */; do
    if [[ ! " ${DEFAULT_PACKAGES[@]}/ "  =~ " ${folder} " ]]; then
      PACKAGES+=($folder)
    fi
  done
fi
PACKAGES+=($DEFAULT_PACKAGES/)

# Clear environment file
rm  .env
touch .env
echo "COMPOSE_HOME=" $(pwd) > .env

# Include target packages
COMPOSE_FILES=""
for package in ${PACKAGES[@]}; do
  echo $package
  for file in "$package"*; do
    echo "  " $file
    if [[ "$file" =~ docker-compose\.yml$ ]]; then
      echo "Found" $file
      COMPOSE_FILES+=" -f "$file
    elif [[ "$file" =~ setup\.sh$ ]]; then
      echo "Found" $file
      exec $file &
    fi
  done
done

echo "COMMON_APP_PATH=$(pwd)/common/" >> .env

echo "docker-compose" $COMPOSE_FILES "config"
docker-compose $COMPOSE_FILES config > docker-compose.yml