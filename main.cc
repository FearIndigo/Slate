#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <math.h>
#include <signal.h>

#include <wiringSerial.h>
#include "led-matrix.h"

using rgb_matrix::RGBMatrix;
using rgb_matrix::Canvas;

volatile bool interrupt_received = false;
static void InterruptHandler(int signo) {
  interrupt_received = true;
}

int main(int argc, char *argv[]) {
  int fd;
  bool al, ar, bl, br;

  if((fd=serialOpen("/dev/ttyACM0",9600))<0){
    fprintf(stderr,"Unable to open serial device: %s\n",strerror(errno));
    return 1;
  }
  
  RGBMatrix::Options defaults;
  defaults.hardware_mapping = "adafruit-hat-pwm";
  defaults.rows = 32;
  defaults.cols = 64;
  defaults.chain_length = 1;
  defaults.parallel = 1;
  defaults.show_refresh_rate = false;
  Canvas *canvas = RGBMatrix::CreateFromFlags(&argc, &argv, &defaults);
  if (canvas == NULL)
    return 1;

  // It is always good to set up a signal handler to cleanly exit when we
  // receive a CTRL-C for instance. The DrawOnCanvas() routine is looking
  // for that.
  signal(SIGTERM, InterruptHandler);
  signal(SIGINT, InterruptHandler);

  for (;;){
  	if (interrupt_received)
  	  break;
  	al = serialGetchar(fd)=='1';
  	ar = serialGetchar(fd)=='1';
  	bl = serialGetchar(fd)=='1';
  	br = serialGetchar(fd)=='1';
    canvas->SetPixel(0,0,0,0,al?255:0);
    canvas->SetPixel(0,31,0,0,ar?255:0);
    canvas->SetPixel(63,0,0,0,bl?255:0);
    canvas->SetPixel(63,31,0,0,br?255:0);
  }

  // Animation finished. Shut down the RGB matrix.
  canvas->Clear();
  delete canvas;

  return 0;
}
