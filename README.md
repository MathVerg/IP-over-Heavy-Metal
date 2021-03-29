# IP over Heavy Metal

The goal of this project is to carry IPv4 packets using Heavy Metal, by coding bytes with frequencies. Written in C, using Sox and Aubio for sound management.
Made by Axel Lemoine and Mathéo Vergnolle in "MODAL INF472D-2020 : Distributed Applications"

## Dependencies

- only works on Linux systems
- `sox` and `aubio` can be installed on a Ubuntu system with `sudo apt install sox aubio-tools`

## Setup

- create and enable a tun interface using `tun_config.sh`. You can use the parameters `--addr`, `--mask` and `--name` (all self-explained) to configure it
- if you want a computer to forward packets from the tun, use the `make_router.sh` script (for the last line, enable promiscuous mode for the interface you intend to use to forward the packet)
- proof-of-concept setup : three computers
	- the **receiver** R  : you just need to note its IP address, and listen for packets (for instance, with `nc -u -l 1234`)
	- the **sender** S :
		- create a tun with a subnet close enough to the receiver's address, to make sure that the computer will route the corresponding packets into the tun
		- open a packet sending program on the tun, e.g. with `nc -u XXX.XXX.XXX.XXX`. The sniffing won't work if there is no program attached to the tun
		- start sniffing with the `mainSender` program ! Some ghost ipv6 packets may appear, but they should be discarded
		- raise the volume, and send a packet : you should hear some beautiful music !
	- the **router** F :
		- create a tun with any unused address, it doesn't matter ( `10.0.0.1` does the trick)
		- use `make_router.sh` to enable IPv4 forwarding and set the two interfaces (tun and wlan/eth) to promiscuous mode
		- launch `mainReceiver` to listen for sound and write it as a packet in the tun
	- be careful to place S anf F close to each other, so F can get the sound well with less interferences
	- to make it more **METAL**, define `GROWL` to `1` in `const.h`, but this may damage the transmission as much as your ears...

## Content of the code

- `soundCode` contains the functions used to convert bytes to sound
- `soundDecode` contains the functions used to convert sound to bytes
- `sniffer` and `feeder` are respectively used to capture and feed packets on a tun interface
- `tun` contains the code needed to allocate and link the tun
- `utils` has just basics functions (finding element in an array, conversion between types...)

