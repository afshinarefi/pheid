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
#include"types.hpp"
#include<vector>
#include<utility>

class data
{
  public:
  node node_count;

  vector<coor> coordinates;
  vector<vector<double> > powers;
  vector<vector<pair<double,node>>> sorted_power;

  public:

  double distance(coor,coor);
  data(int,double);
  void print();
  void print_powers();
  void print_sorted_powers();
  node random_node();
};

#endif