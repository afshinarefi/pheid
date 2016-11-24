/*****************************************************************************/
/* Project:    P.H.E.I.D. (Paired Helpers Evolutionary Information Delivery) */
/* Written by: Afshin Arefi (arefi.afshin@gmail.com)                         */
/* License:    GNU GPL V3                                                    */
/* Decription:                                                               */
/*             The chromosome class used in genetic algorithm to keep a      */
/*             candidate solution.                                           */
/*****************************************************************************/

#ifndef HPP_CHROMOSOME
#define HPP_CHROMOSOME

#include<vector>
#include"types.hpp"
#include<utility>

using namespace std;

class chromosome
{
  public:

  vector<pair<node,node> > genes;

  chromosome()
  {
    
  }

  double fitness();

  chromosome crossover(chromosome, chromosome);

};

#endif