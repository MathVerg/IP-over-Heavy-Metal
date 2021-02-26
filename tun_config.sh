#! /bin/bash

openvpn --mktun --dev tunX

ip link set tunX up

ip addr add 10.0.0.1/24 dev tunX