#include <BitUtil.h>

namespace BitUtil
{
	int getBit(int position, int value)
	{
		return ((value & (0x1 << (position))) >> position) & 0x1;
	}
	
	short getBit(int position, short value)
	{
		return (short) getBit(position, (int) value);
	}
	
	char getBit(int position, char value)
	{
		return (char) getBit(position, (int) value);
	}
	
	
	
	void setBit(int position, int value, int &destination)
	{
		value %= 2;
		
		if (value == 0)
		{
			destination &= ~((0x1 << position));
		}
		
		else
		{
			destination |= (0x1 << position);
		}
	}
	
	void setBit(int position, int value, unsigned short &destination)
	{
		int cval = destination;
		
		setBit(position, value, cval);
		
		destination = (unsigned short) cval;
	}
	
	void setBit(int position, int value, unsigned char &destination)
	{
		int cval = destination;
		
		setBit(position, value, cval);
		
		destination = (unsigned char) cval;
	}
	
	
	
	int subBits(int from, int to, int value)
	{
		int bits = 0;
		
		for (int i = from; i <= to; i++)
		{
			bits |= getBit(i, value) << (i - from);
		}
		
		return bits;
	}
	
	void setBits(int from, int to, int directValue, unsigned short &destination)
	{
		for (int i = from; i <= to; i++)
		{
			setBit(i, ((directValue & (0x1 << (i - from))) >> (i - from)), destination);
		}
	}
	
	void setBits(int from, int to, int directValue, unsigned char &destination)
	{
		for (int i = from; i <= to; i++)
		{
			setBit(i, ((directValue & (0x1 << (i - from))) >> (i - from)), destination);
		}
	}
	
	
	
	int subByte(int position, int val)
	{
		int selectedByte = (8 * position);
		
		return ((val & (0xFF << selectedByte))) >> selectedByte;
	}
	
	short subByte(int position, short val)
	{
		return (short) subByte(position, (int) val);
	}
	
	void setByte(int position, int ibyte, int &destination)
	{
		ibyte = ibyte & 0xFF;
		
		int actualPosition = position * 8;
		
		destination = (short) ((ibyte << actualPosition) | (destination & ~(0xFF << actualPosition)));
	}
	
	void setByte(int position, int ibyte, unsigned short &val)
	{
		int sval = val;
		
		setByte(position, ibyte, sval);
		
		val = (short) sval;
	}
	
	
	
	int craftBitInt(int position)
	{
		return (1 << position);
	}
	
	short craftBitShort(int position)
	{
		return (short) craftBitInt(position);
	}
	
	char craftBitByte(int position)
	{
		return (char) craftBitInt(position);
	}
	
	char craftByte(int bit7, int bit6, int bit5, int bit4, int bit3, int bit2, int bit1, int bit0)
	{
		return (char) ((bit7 << 7) | (bit6 << 6) | (bit5 << 5) | (bit4 << 4) | (bit3 << 3) | (bit2 << 2) | (bit1 << 1) | (bit0));
	}
	
	short craftShort(int nbyte1, int nbyte0)
	{
		unsigned short s = 0;
		
		setByte(0, nbyte0, s);
		setByte(1, nbyte1, s);
		
		return s;
	}
	
	
	
	int parity(int input)
	{
		int parity = 0;
		
		for (int i = 0; i < 32; i++)
		{
			parity ^= getBit(i, input);
		}
		
		return parity;
	}
	
	short parity(short input)
	{
		return (short) parity((int) input & 0xFFFF);
	}
	
	char parity(char input)
	{
		return (char) parity((int) input & 0xFF);
	}
};