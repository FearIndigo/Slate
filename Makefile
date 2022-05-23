# There are several different pinouts for various breakout boards that uses
# this library. If you are using the described pinout in the toplevel README.md
# or the standard active-3 breakout board, then 'regular' is the one you'd like
# to use.
#
# Adafruit also made a breakout board, if you want to use that, choose
# 'adafruit-hat'
#
# These are the choices
#   regular            # Following this project wiring and using these PCBs
#   adafruit-hat       # If you have a RGB matrix HAT from Adafruit
#   adafruit-hat-pwm   # If you have an Adafruit HAT with PWM hardware mod.
#   regular-pi1        # If you have an old Pi1 and regular didn't work.
#   classic            # (deprecated) Classic Pi1/2/. Not used anymore.
#   classic-pi1        # (deprecated) Classic pinout on Rasperry Pi 1
HARDWARE_DESC=adafruit-hat-pwm

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
	$(MAKE) -C $(RGB_LIBDIR)

$(WP_LIBRARY): FORCE
	$(WP_LIBDIR)/build

main.o : src/main.cc

%.o : %.cc
	$(CXX) -I$(PP_INCDIR) -I$(RGB_INCDIR) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJECTS) $(BINARIES)
	$(MAKE) -C $(RGB_LIBDIR) clean

FORCE:
.PHONY: FORCE