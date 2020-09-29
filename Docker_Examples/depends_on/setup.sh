#!/bin/usr/env bash

echo "Building launch base image..."
docker build -t launch_base --file ./Dockerfile.launch_base .

echo "Building launch child image..."
docker build -t launch_child --file ./Dockerfile.launch_child .

echo "Done!"

docker-compose down
docker-compose up