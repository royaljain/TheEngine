#include <math.h>
#include <cmath>
#include <"BeasleySpringer.h"

using namespace std;

namespace Random
{


	void BeasleySpringer::init(BeasleySpringerInputs& inp)
	{
		U = inp.getUD();
	}
	
	double BeasleySpringer::getNumber()
	{
		double u = U.getNumber();
		double y = u - 0.5;
			
		if(fabs(y) < 0.42)
		{
			r = y*y;
			x = y*(((a_3 * r + a_2)*r + a_1)*r + a_0)/((((b_3 * r + b_2)*r + b_1)*r + b_0)*r + 1.0);
		} 
		else{
			r = u;
		
			if(y > 0){
			r = 1 - u;
			}
			
			r = log(-log(r));
			x = c_0 + r*(c_1 + r*(c_2 + r *(c_3 + r * (c_4 + r * (c_5 + r*(c_6 + r * (c_7 + r*c_8)))))));
			
			if(y < 0){
			x = -x;
			}
		}	
			
		return x;	
	}
		

	void BeasleySpringer::getNumbers(double* d,const int n)
	{
		for(int i= 0 ;i < n; i++)
		{
			d[i] = getNumber();
		}   	
	}


}
