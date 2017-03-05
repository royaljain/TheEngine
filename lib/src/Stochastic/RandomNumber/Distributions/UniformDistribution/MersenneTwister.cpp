#include "UniformDistribution.h"

/* https://en.wikipedia.org/wiki/Mersenne_Twister */

typedef unsigned int uint;

using namespace Random;

void MersenneTwisterInputs::init(uint seed)
{
	m_seed = seed;
}

uint MersenneTwisterInputs::getSeed() const
{
	return m_seed;
}

void MersenneTwister::init(const MersenneTwisterInputs& inp)
{
	MT[0] = inp.getSeed();	

	for(uint i=1;i< N;i++)
	{
		MT[i] = (F * (MT[i-1] ^ (MT[i-1] >> 30)) + i);
	}


	index = N;
} 


void MersenneTwister::Twist()
{
	uint i, x, xA;
	
	for ( i = 0; i < N; i++ )
    	{
        	x = (MT[i] & MASK_UPPER) + (MT[(i + 1) % N] & MASK_LOWER);

        	xA = x >> 1;

        	if ( x & 0x1 )
            	xA ^= A;

        	MT[i] = MT[(i + M) % N] ^ xA;
    	}

    	index = 0;
	
}


uint MersenneTwister::Extract()
{

    uint  y;
    uint  i = index;

    if ( index >= N )
    {
        Twist();
        i = index;
    }

    y = MT[i];
    index = i + 1;

    y ^= (MT[i] >> U);
    y ^= (y << S) & B;
    y ^= (y << T) & C;
    y ^= (y >> L);

    return y;
}

double MersenneTwister::getNumber()
{
	return (Extract()*1.0)/(LIM*1.0);
}
