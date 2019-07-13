// A simple program that computes the squre root of a number

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "TutorialConfig.h"
#ifdef USE_MYMATH
//#include "MathFuncitons.h"
#include "MathFunctions/MathFunctions.h"
#endif

int main(int argc, char *argv[])
{
    if (argc < 2) {
	fprintf(stdout, "%s Version %d.%d\n",
		argv[0],
		Tutorial_VERSION_MAJOR,
		Tutorial_VERSION_MINOR);


        fprintf(stdout, "Usage: %s number\n", argv[0]);
	return 1;
    }

    double inputValue = atof(argv[1]);

	double outputValue;
	if (inputValue < 0) {
		outputValue = 0;
	}
	else {
#ifdef USE_MYMATH
		outputValue = mysqrt(inputValue);
		fprintf(stdout, "Use my math version.\n");
#else
		outputValue = sqrt(inputValue);
		fprintf(stdout, "Use system math version.\n");
#endif
	}

    fprintf(stdout, "The square root of %g is %g\n", inputValue, outputValue);

    return 0;
}

