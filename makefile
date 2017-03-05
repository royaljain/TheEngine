
CC=g++
CFLAGS= -I

build: projects

projects: Stochastic

Stochastic: RandomNumber

RandomNumber: Distributions

Distributions: Uniform

Uniform: 
