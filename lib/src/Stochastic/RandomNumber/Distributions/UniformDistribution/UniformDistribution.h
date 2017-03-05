#include <Stochastic/RandomNumber/Distributions/base.h>
#include <stdint.h>

namespace Random
{

	class UniformDistributionInputs: public DistributionInputs
	{
		public:
	//	void init();
	};


	class UniformDistribution: public Distribution<double>
	{
		public:
	//	void init(const UniformDistributionInputs& inp);
		double getNumber()  = 0;
	};

	class MersenneTwisterInputs: public UniformDistributionInputs
	{
		private:
		typedef unsigned int  uint;

		uint m_seed;		

		public:
		void init( uint seed);
		uint getSeed() const;

	};



	class MersenneTwister: public UniformDistribution
	{
		private:
		
		typedef unsigned int  uint;

		 const static uint W = 32;
		 const static uint N = 624;
		 const static uint M = 397;
		 const static uint R = 31;
		 const static uint A = 0x9908B0DF;	

		 const static uint F = 1812433253;
		 const static uint U = 11;

		
		 const static uint S = 7;
		 const static uint B = 0x9D2C5680;
		
		 const static uint T = 15;
		 const static uint C = 0xEFC60000;

		 const static uint L = 18;

		 uint index;

		 uint MT[N];

		 const static uint LIM = 0xFFFFFFFF;

		 const static unsigned long long MASK_LOWER = (1ull << R) - 1;
    		 const static unsigned long long MASK_UPPER = (1ull << R);


		public:
		void init(const MersenneTwisterInputs& inp);
		void Twist();
		uint Extract();
		double getNumber();
	};

}
