#include <wiringPi.h>
#include <stdio.h>
#include "I2C.h"

#ifdef DEBUG
#undef DEBUG
#endif
#define DEBUG 1

#define AddrCom 0x12

/*
	Fonctionne de paire avec le programme test_I2C.c du µC.
	Envoie un nombre et attend en retour le nombre + 1
*/

int main (void)
{

	int fd = I2C_Init(AddrCom);
	delay (500);

	int data = 0;
	printf("Entrez un entier 0-255 à envoyer :\n");
	scanf("%d",&data);

	I2C_SendByte(fd, data);
	delay (500);

	int result = I2C_ReadByte(fd);
	printf("Valeur retourné : %d\n",result);

	return 0 ;
}