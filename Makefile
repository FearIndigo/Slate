CXXFLAGS=-Wall -O3 -g
BINARIES=slate

RGB_INCDIR=../rpi-rgb-led-matrix/include
RGB_LIBDIR=../rpi-rgb-led-matrix/lib
RGB_LIBRARY_NAME=rgbmatrix
RGB_LIBRARY=$(RGB_LIBDIR)/lib$(RGB_LIBRARY_NAME).a

LDFLAGS+=-L$(RGB_LIBDIR) -l$(RGB_LIBRARY_NAME) \
	-lrt -lm -lpthread

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
	$(CXX) $(CXXFLAGS) src/main.cc -o $@ $(LDFLAGS)
#gcc src/main.cc -o slate -lwiringPi