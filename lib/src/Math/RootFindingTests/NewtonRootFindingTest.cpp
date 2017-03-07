#include <Math/RootFinding/NewtonRootFinding.h>
#include <math.h>
#include <assert.h>
#include <iostream>

# define M_PI           3.14159265358979323846

int main() {
	
	Math::NewtonRootFinding N(1e-11,1000,sin,cos);
	
	assert(((M_PI/6.0) - N.findRoot(M_PI/12.0,0.5)) < 1e-4);	
	assert(((M_PI/6.0) - N.findRoot(M_PI/8.0,0.5)) < 1e-4);	
	assert(((M_PI/6.0) - N.findRoot(M_PI/4.0,0.5)) < 1e-4);	
	assert(((M_PI/6.0) - N.findRoot(M_PI/1.0,0.5)) < 1e-4);	

	
	
	Math::NewtonRootFinding N2(1e-8,1000,
	[](double x){return (x-1)*(x-2)*(x-3);},
	[](double x){return 3*x*x -12*x + 11;});
	
	assert(( 3 - N2.findRoot(5,0.0)) < 1e-4);	
	assert(( 1 - N2.findRoot(-5,0.0)) < 1e-4);	



}
