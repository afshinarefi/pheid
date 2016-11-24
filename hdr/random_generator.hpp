/*****************************************************************************/
/* Project:    P.H.E.I.D. (Paired Helpers Evolutionary Information Delivery) */
/* Written by: Afshin Arefi (arefi.afshin@gmail.com)                         */
/* License:    GNU GPL V3                                                    */
/* Decription:                                                               */
/*             The random number generator wrapped arround CPPs generatoe to */
/*             produce numbers in different distributions in requied ranges. */
/*****************************************************************************/

#ifndef HPP_RANDOM_GENERATOR
#define HPP_RANDOM_GENERATOR

#include<random>
#include"types.hpp"
#include<utility>

using namespace std;

class random_generator
{

  private:

  default_random_engine generator;
  uniform_real_distribution<double> radius{0.0,1.0};
  uniform_real_distribution<double> angle{0.0,2*PI};

  public:

  random_generator();
  pair<double, double> coordinate();


};

#endif