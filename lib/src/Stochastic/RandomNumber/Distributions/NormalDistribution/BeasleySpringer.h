#include <Stochastic/RandomNumber/Distributions/UniformDistribution/UniformDistribution.h>



namespace Random
{

	class BeasleySpringerInputs: public DistributionInputs
	{
		public:

		BeasleySpringerInputs(UniformDistribution& U)
		{
			UD = U;
		}
		
		UniformDistribution getUD()
		{
			return UD;
		}

		
		
		private:
		
		UniformDistribution UD;
	

	};

	class BeasleySpringer: public Distribution<double>
	{

		public:
	
		void init(BeasleySpringerInputs& inp);
		double getNumber();
		void getNumbers(double* d,const int n); 
		

	
		private:
		
		double r;
		double x;

		static const double  a_0 = 2.50662823884;     
		static const double  b_0 = -8.47351093090;
		static const double  a_1 = -18.61500062529;   
		static const double  b_1 = 23.08336743743;
    		static const double  a_2 = 41.39119773534;    
		static const double  b_2 = -21.06224101826;
    		static const double  a_3 = -25.44106049637;   
		static const double  b_3 = 3.13082909833;

    		static const double  c_0 = 0.3374754822726147; 
		static  const double  c_5 = 0.0003951896511919;
	        static const double  c_1 = 0.9761690190917186; 
		static const double  c_6 = 0.0000321767881768;
    	 	static const double  c_2 = 0.1607979714918209;
		static const double  c_7 = 0.0000002888167364;
     	 	static const double  c_3 = 0.0276438810333863; 
		static const double  c_8 = 0.0000003960315187;
    	 	static const double  c_4 = 0.0038405729373609;

		UniformDistribution U;

	};






}
