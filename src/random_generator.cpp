/*****************************************************************************/
/* Project:    P.H.E.I.D. (Paired Helpers Evolutionary Information Delivery) */
/* Written by: Afshin Arefi (arefi.afshin@gmail.com)                         */
/* License:    GNU GPL V3                                                    */
/* Decription:                                                               */
/*             The random number generator wrapped arround CPPs generatoe to */
/*             produce numbers in different distributions in requied ranges. */
/*****************************************************************************/

#include"random_generator.hpp"
#include<cmath>
#include<utility>

using namespace std;

random_generator::random_generator(node node_count):
generator(0),
radius(0.0,1.0),
angle(0.0,2*PI),
rand_node(0,node_count-1)
{
  
}

pair<double, double> random_generator::coordinate()
{

  double a=angle(generator);
  double r=radius(generator);
  double x=sqrt(r)*cos(a);
  double y=r*sin(a);
  return make_pair(x,y);
}

node random_generator::random_node()
{
  return rand_node(generator);
}