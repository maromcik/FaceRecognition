#!/bin/bash
build=false
while getopts ":b" option; do
  case $option in
    h) echo "usage: $0 [-h] [-b]"; exit ;;
    b) build=true ;;
    ?) echo "error: option -$OPTARG does not exist - specify -b if you want to build the image"; exit ;;
  esac
done
shift $(( OPTIND - 1 ))

if [ "$build" = true ] ; then
	docker build -t face_rec .
fi
docker run -itd -v $HOME/configuration.conf:/root/configuration.conf --name fr face_rec
