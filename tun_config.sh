#! /bin/bash

if [ "$(whoami)" != "root" ]; then
	echo "Please run with sudo."
	exit 1
fi

name=${name:-X}
addr=${addr:-10.0.0.1}
mask=${mask:-24}


while [ $# -gt 0 ]; do

   if [[ $1 == *"--"* ]]; then
        param="${1/--/}"
        declare $param="$2"
        # echo $1 $2 // Optional to see the parameter:value result
   fi

  shift
done

openvpn --mktun --dev tun$name

ip link set tun$name up

ip addr add $addr/$mask dev tun$name
