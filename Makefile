
install-dependencies:
    make install-wiring-pi && \
    make install-rgb-matrix
    
install-wiring-pi:
    git clone https://github.com/WiringPi/WiringPi.git && \
    ./WiringPi/build

install-rgb-matrix:
	curl https://raw.githubusercontent.com/adafruit/Raspberry-Pi-Installer-Scripts/master/rgb-matrix.sh >rgb-matrix.sh && \
	sudo bash rgb-matrix.sh

build:
	gcc src/main.cc -o slate -lwiringPi