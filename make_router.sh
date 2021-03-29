#! /bin/bash

if [ "$(whoami)" != "root" ]; then
	echo "Please run with sudo."
	exit 1
fi

name=${name:-X}


while [ $# -gt 0 ]; do

   if [[ $1 == *"--"* ]]; then
        param="${1/--/}"
        declare $param="$2"
        # echo $1 $2 // Optional to see the parameter:value result
   fi

  shift
done

sysctl -w net.ipv4.ip_forward=1

ip link set tun$name promisc on

ip link set wlo1 promisc on