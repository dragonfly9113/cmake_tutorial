#pragma once

#include "MathFunctions.h"

double mysqrt(double input)
{
	double result;

	// if we have log and exp then use them
#if defined (HAVE_LOG) && defined (HAVE_EXP)
	result = exp(log(input) * 0.5);
#else
	result = sqrt(input);
#endif

	return result;
}
