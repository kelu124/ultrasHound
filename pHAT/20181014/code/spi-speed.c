#include <stdio.h>
#include <stdlib.h>

#include <pigpio.h>

/*
   gcc -pthread -o spi-speed spi-speed.c -lpigpio
*/

int main(int argc, char *argv[])
{
   int i;
   int h;
   int loops;
   int speed;
   double start, diff, sps;
   unsigned char buf[2];

   if (argc > 1) loops = atoi(argv[1]);
   else loops = 1000000;

   if (argc > 2) speed = atoi(argv[2]);
   else speed = 1000000;

   if (gpioInitialise() < 0) return 1;

   h = spiOpen(0, speed, 0);

   if (h < 0) return 2;

   start = time_time();

   for (i=0; i<loops; i++)
   {
      buf[0] = 104; // x start_bit single_mode ch1 msbf xxx
      buf[1] = 0;

      spiXfer(h, buf, buf, 2);
   }

   diff = time_time() - start;

   printf("sps=%.1f @ %d bps (%d/%.1f)\n",
      (double)loops / diff, speed, loops, diff);

   spiClose(h);

   gpioTerminate();

   return 0;
}
