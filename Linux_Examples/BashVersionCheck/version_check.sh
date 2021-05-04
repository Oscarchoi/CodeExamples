#!/bin/bash

REQUIRE_VERSTION="9.12.7a"
VERSION=$(gcc --version | head -n1 | awk '{print $4}')

# example
# VERSION=$(docker-compose --version | awk '{print $3}')

echo "Required: "$REQUIRE_VERSTION
echo "Current: "$VERSION

if [ "$(printf "$REQUIRE_VERSTION\n$VERSION" | sort -V | head -n1)" = $REQUIRE_VERSTION ]
then
  echo "Current version is GREATER than or Equal to required."
else 
  echo "Current version is LESS than required."
fi
