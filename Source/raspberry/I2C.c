#include <errno.h>
#include <stdio.h>
#include <wiringPiI2C.h>
#include "I2C.h"


/*
   Contients les fonctions permettant à la raspberry de communiquer en I2C.
   Les pins de communication I2C de la raspberry sont : SDA = 3 et SCL = 5
*/


//Initialise la communication I2C avec l'appareil en AddrId
int I2C_Init(int AddrId)
{
   int fd;
   if( fd = wiringPiI2CSetup(0x12) )
      printf("I2C communication initialisé avec succés.\n");
   else
      fprintf(stderr,"I2C Init Error.  Errno is: ",strerror(errno));

   return fd; //Linux file handler, used by other function.
}

int I2C_SendByte(int fd, unsigned int data)
{
   int ret = -1;
   if(ret = wiringPiI2CWrite(fd, data) == -1)
   {
      if(DEBUG) fprintf(stderr,"I2C SendByte Error.  Errno is: ",strerror(errno));
      return 0;
   }

   if(DEBUG) printf("I2C byte send %d with succes.\n",data);
   return 1;

}

int I2C_ReadByte(int fd)
{
   int data = wiringPiI2CRead(fd);
   if(data == -1)
   {
      if(DEBUG) fprintf(stderr,"I2C ReadByte Error.  Errno is: ",strerror(errno));
      return 0;
   }

   if(DEBUG) printf("I2C read byte %d.\n",data);
   return data;
}


