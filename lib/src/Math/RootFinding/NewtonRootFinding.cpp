#include "NewtonRootFinding.h"
#include <stdlib.h>
#include <iostream>

namespace Math
{
	double NewtonRootFinding::findRoot(double initial, double val)
	{
		double error = 100.0;
		int steps = 0;
		double result = initial;		
		double tol = 1e-8;
		while(error > epsilon && steps < max_steps && result > tol)
		{
			result = result - (func(result)-val)/funcDiff(result);
			error = func(result) - val;
			error = error > 0 ? error : -error;
			steps++;
		} 

		std::cout<<steps<<std::endl;		
		return result;

	}



}
