#include <iostream>
using namespace std;

void set(int& num, int pos)
{
	num |= (1 << pos);
}

void unset(int& num, int pos)
{
    num &= (~(1<<pos));
}

void toggle(int& num, int pos) 
{ 
    num ^= (1 << pos); 
}

bool at_position(int num, int pos)
{
    bool bit = num & (1 << pos);
    return bit;
}

int main()
{

}
