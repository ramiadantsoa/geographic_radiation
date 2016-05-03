 #include <stdio.h>
 #include <stdlib.h>
 #include <iostream>
 #include <time.h>
 #include <math.h>
 #include <assert.h>
 #include <vector>
 #include "dSFMT/dSFMT.h"

 typedef unsigned long int uInt;

 #define PI 3.1415926535897932385
 using namespace std;

 //This part initialize the random seed
 const int rng_seed = (const int)time(NULL);
 dsfmt_t rng;

 // It has to be here, I don't know what it does
 void init_rng() {
     dsfmt_init_gen_rand(&rng, rng_seed);
 }

 //From my libarary
 #include "mylibrary/random_gen_function.h"

 int main(){
   init_rng();
   double rand_x;
   rand_x = get_random();
   cout << "the random number is: " << rand_x << endl;
   std::cout << "Hello World!" << std::endl;

   return 0;
 }
