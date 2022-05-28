CXXFLAGS=-Wall -O3 -g -std=c++17
SRC_DIR=src/
OBJECTS=$(patsubst %.cpp, %.o, $(wildcard $(SRC_DIR)*.cpp))
BINARIES=slate

RGB_INCDIR=matrix/include
RGB_LIBDIR=matrix/lib
RGB_LIBRARY_NAME=rgbmatrix

WP_LIBRARY_NAME=wiringPi

ENTT_INCDIR=entt/src

LDFLAGS+=-l$(WP_LIBRARY_NAME) -L$(RGB_LIBDIR) -l$(RGB_LIBRARY_NAME) -lrt -lm -lpthread

all : slate

slate : $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@ $(LDFLAGS)

%.o : %.cpp
	$(CXX) -I$(RGB_INCDIR) -I$(ENTT_INCDIR) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJECTS) $(BINARIES)