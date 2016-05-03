#ifndef __RANDOM_GEN_FUNCTION_H_
#define __RANDOM_GEN_FUNCTION_H_

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
uInt get_rand_integer(uInt max_value){
	double result = max_value*get_random();

	return (uInt) floor(result);
}

/* Generate a random integer from a Poisson distribution with parameter 'mean' */
uInt get_poisson(double mean){
	double p =1.0;
	uInt k =0;

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
		k = (uInt)floor(mean+sqrt(mean)*temp);
	}
	return (uInt) k;
}

// Sample from a list with given weight
int get_sample(vector<double> weight, double total_weight){
  double random_x = get_random()*total_weight;
  assert(random_x > 0 & <= total_weight)
  double temp = 0;
  int index = 0;
  while (temp < random_x) {
    index++;
    temp += weight[index - 1]; //This is -1 because the first value should be 0
  }
  return index; //this is the position from the
}

#endif //__RANDOM_GEN_FUNCTION_H_
