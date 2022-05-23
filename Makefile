CXXFLAGS=-Wall -O3 -g
OBJECTS=main.o
BINARIES=slate

RGB_INCDIR=matrix/include
RGB_LIBDIR=matrix/lib
RGB_LIBRARY_NAME=rgbmatrix
RGB_LIBRARY=$(RGB_LIBDIR)/lib$(RGB_LIBRARY_NAME).a

WP_LIBDIR=wiringPi
WP_LIBRARY_NAME=wiringPi
WP_LIBRARY=$(WP_LIBDIR)/lib$(WP_LIBRARY_NAME).a

LDFLAGS+=-l$(WP_LIBRARY_NAME) \
         -L$(RGB_LIBDIR) -l$(RGB_LIBRARY_NAME) \
          -lrt -lm -lpthread

all : slate

slate : $(OBJECTS) $(RGB_LIBRARY) $(WP_LIBRARY)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@ $(LDFLAGS)

$(RGB_LIBRARY): FORCE
	$(MAKE) -C $(RGB_LIBDIR) HARDWARE_DESC=adafruit-hat-pwm
#reconfig /boot/config.txt "^.*dtparam=audio.*$" "dtparam=audio=off"

$(WP_LIBRARY): FORCE
	cd $(WP_LIBDIR) && ./build && cd ..

main.o : src/main.cc

%.o : %.cc
	$(CXX) -I$(PP_INCDIR) -I$(RGB_INCDIR) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJECTS) $(BINARIES)
	cd $(WP_LIBDIR) && ./build uninstall && cd ..
	$(MAKE) -C $(RGB_LIBDIR) clean

FORCE:
.PHONY: FORCE