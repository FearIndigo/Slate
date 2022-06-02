CXXFLAGS=-Wall -O3 -g -std=c++17
SOURCES:=$(wildcard *.cpp src/*/*.cpp src/*/*/*.cpp src/*/*/*/*.cpp)
OBJECTS:=$(patsubst %.cpp,%.o,$(SOURCES))
TARGET=slate

RGB_INCDIR=matrix/include
RGB_LIBDIR=matrix/lib
RGB_LIBRARY_NAME=rgbmatrix

WP_LIBRARY_NAME=wiringPi

ENTT_INCDIR=entt/src

SLATE_INCDIR=src

LDFLAGS+=-l$(WP_LIBRARY_NAME) -L$(RGB_LIBDIR) -l$(RGB_LIBRARY_NAME) -lrt -lm -lpthread

all : $(TARGET)

$(TARGET) : $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@ $(LDFLAGS)

%.o : %.cpp
	$(CXX) -I$(RGB_INCDIR) -I$(ENTT_INCDIR) -I$(SLATE_INCDIR) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJECTS) $(TARGET)