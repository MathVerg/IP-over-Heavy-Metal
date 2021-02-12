# IP over Heavy Metal

The goal of this project is to carry IP packets using Heavy Metal, by coding bytes with frequencies. Written in C, using Sox and Aubio for sound management.
Made by Axel Lemoine and Mathéo Vergnolle in "MODAL INF472D-2020 : Distributed Applications"

## Dependencies

- only works on Linux systems
- `sox` and `aubio` can be installed on a Ubuntu system with `sudo apt install sox aubio-tools`

## Manual

- `soundCode` contains the functions used to convert bytes to sound
- `soundDecode` contains the functions used to convert sound to bytes
