#ifndef __SIMPLE_FUNCTIONS_H_
#define __SIMPLE_FUNCTIONS_H_

double get_random() {
    /* Give a random number from the unit range (0,1) */
    return dsfmt_genrand_open_open(&rng);
}

/* Generate a random number from Exponential distribution with parameter 'lambda' */
double get_exp(double lambda) {
    double U = get_random();
	double result = - log(U)/lambda;
	return result;
}

/* Generate a random integer between 0 and value */
uInt get_rand_integer( uInt  value){
	double temp0 = value*get_random();
	
	return (uInt ) floor(temp0);
}

/* Generate a random integer from a Poisson distribution with parameter 'mean' */
uInt  get_poisson(double mean){
	double p =1.0;
	int k =0;

	if(mean<50){
		double a= exp(-mean);
		while( p>a){
			k+=1;
			p*=get_random();
		}
		k-=1;
	}
	else{
		double u = get_random();
		double v = get_random();
		double temp = sqrt(-2*log(u))*cos(2*PI*v);
		k = (uInt  )floor(mean+sqrt(mean)*temp);
	}
	return (uInt) k;
}


#endif // __SIMPLE_FUNCTIONS_H_