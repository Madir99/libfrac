#include "libfrac.hpp"
#include "iostream"
#include "cstring"
#include "math.h"

int * flt2frc(float value) {
	bool neg = value < 0;
	if(neg) value = value * -1;
	float i = std::trunc(value);
	float f = value - i;
	float bot = 1;
	if(value > i) bot = 1 / (value - i);
	i = std::round(bot);
	f = bot - i;
	while(bot > i) {
		bot = bot * (1 / f);
		i = trunc(bot);
		f = bot - i;
	}
	int top = (int)(std::round(value * bot));
	if(neg) top = top * -1;
	return frcsimp(top ,(int)(std::round(bot)));
}
int * frcsimp(int a, int b) {
	bool neg1 = a < 0;
	bool neg2 = b < 0;
	if(neg1) a = a * -1;
	if(neg2) b = b * -1;
	if (neg1 == neg2) neg1 = neg2 = false;
	static int ret[2];
	ret[0] = a;
	ret[1] = b;
	for(int i = 2; i <= ret[0] ;i++) {
		if((ret[0] % i)+(ret[1] % i) == 0) {
			ret[0] = ret[0] / i;
			ret[1] = ret[1] / i;
			i = 1;
		}
	}
	if(neg1) ret[0] = ret[0] * -1;
	if(neg2) ret[1] = ret[1] * -1;
	return ret;
}
