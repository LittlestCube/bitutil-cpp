class BitUtil
{
	int bit(int position, int value)
	{
		return ((value & (0x1 << (position))) >> position) & 0x1;
	}
	
	short bit(int position, short value)
	{
		return (short) bit(position, (int) value);
	}
	
	char bit(int position, char value)
	{
		return (char) bit(position, (int) value);
	}
	
	int setBit(int position, int value, int destination)
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
		
		return destination;
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
		short s = 0;
		
		s = (short) setByte(0, nbyte0, s);
		s = (short) setByte(1, nbyte1, s);
		
		return s;
	}
	
	
	
	int setByte(int position, int nbyte, int val)
	{
		nbyte = nbyte & 0xFF;
		
		int actualPosition = position * 8;
		
		val = (short) ((nbyte << actualPosition) | (val & ~(0xFF << actualPosition)));
		
		return val;
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
	
	
	
	int parity(int input)
	{
		int parity = 0;
		
		for (int i = 0; i < 32; i++)
		{
			parity ^= bit(i, input);
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