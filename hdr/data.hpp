/*****************************************************************************/
/* Project:    P.H.E.I.D. (Paired Helpers Evolutionary Information Delivery) */
/* Written by: Afshin Arefi (arefi.afshin@gmail.com)                         */
/* License:    GNU GPL V3                                                    */
/* Decription:                                                               */
/*             The data class keeping the input data neccesary for the       */
/*             computations and performing any precomputation needed.        */
/*****************************************************************************/

#ifndef HPP_DATA
#define HPP_DATA

#include"random_generator.hpp"
#include<vector>
#include<utility>

class data
{
  private:

  random_generator rg;
  vector<pair<double,double> > coordinates;
  vector<vector<double> > powers;
  
  public:

  double distance(pair<double,double>,pair<double,double>);
  data(int,double);
  void print();
  void print_powers();

};

#endif