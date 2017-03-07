

namespace Math
{	
	class NewtonRootFinding
	{
		public:
		
		NewtonRootFinding(double (*f)(double), double (*fDiff)(double))
		: epsilon(1e-4), max_steps(100), func(f), funcDiff(fDiff)
		{}
		

		NewtonRootFinding(const double& e, const int& s, double (*f)(double), double (*fDiff)(double))
		: epsilon(e), max_steps(s), func(f), funcDiff(fDiff)
		{}


		double findRoot(double initial, double val);
		  
		
		private:
			
		double (*func)(double);
		double (*funcDiff)(double);
		double epsilon;
		int max_steps;
		
	};

}
