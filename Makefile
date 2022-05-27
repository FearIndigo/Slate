CXXFLAGS=-Wall -O3 -g -std=c++17
OBJECTS=main.o input.o
BINARIES=slate

RGB_INCDIR=matrix/include
RGB_LIBDIR=matrix/lib
RGB_LIBRARY_NAME=rgbmatrix
RGB_LIBRARY=$(RGB_LIBDIR)/lib$(RGB_LIBRARY_NAME).a

WP_LIBDIR=wiringPi
WP_LIBRARY_NAME=wiringPi
WP_LIBRARY=$(WP_LIBDIR)/lib$(WP_LIBRARY_NAME).a

ENTT_INCDIR=entt/src

LDFLAGS+=-l$(WP_LIBRARY_NAME) -L$(RGB_LIBDIR) -l$(RGB_LIBRARY_NAME) -lrt -lm -lpthread

all : slate

slate : $(WP_LIBRARY) $(OBJECTS) $(RGB_LIBRARY)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@ $(LDFLAGS)

$(RGB_LIBRARY): FORCE
	$(MAKE) -C $(RGB_LIBDIR)
#reconfig /boot/config.txt "^.*dtparam=audio.*$" "dtparam=audio=off"

$(WP_LIBRARY): FORCE
	cd $(WP_LIBDIR) && ./build && cd ..

main.o : main.cpp
input.o : src/input/input.cpp

%.o : %.cpp
	$(CXX) -I$(RGB_INCDIR) -I$(ENTT_INCDIR) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJECTS) $(BINARIES)
	cd $(WP_LIBDIR) && ./build uninstall && cd ..
	$(MAKE) -C $(RGB_LIBDIR) clean

FORCE:
.PHONY: FORCE