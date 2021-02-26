#! /bin/bash

if [ "$(whoami)" != "root" ]; then
	echo "Please run with sudo."
	exit 1
fi

openvpn --mktun --dev tunX

ip link set tunX up

ip addr add 10.0.0.1/24 dev tunX
