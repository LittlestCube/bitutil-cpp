#pragma once

namespace BitUtil
{
	int getBit(int position, int value);
	
	short getBit(int position, short value);
	
	char getBit(int position, char value);
	
	void setBit(int position, int value, unsigned short &destination);
	
	void setBit(int position, int value, unsigned char &destination);
	
	
	
	void setByte(int position, int nbyte, int &val);
	
	void setByte(int position, int nbyte, unsigned short &val);
	
	int subByte(int position, int val);
	
	short subByte(int position, short val);
	
	
	
	int craftBitInt(int position);
	
	short craftBitShort(int position);
	
	char craftBitByte(int position);
	
	char craftByte(int bit7, int bit6, int bit5, int bit4, int bit3, int bit2, int bit1, int bit0);
	
	short craftShort(int nbyte1, int nbyte0);
	
	
	
	int parity(int input);
	
	short parity(short input);
	
	char parity(char input);
};