#ifndef I2C_H
#define I2C_H

#ifndef DEBUG
#define DEBUG 0
#endif

int I2C_Init(int AddrId);
int I2C_SendByte(int fd, unsigned int data);
int I2C_ReadByte(int fd);


#endif
