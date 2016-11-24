/*****************************************************************************/
/* Project:    P.H.E.I.D. (Paired Helpers Evolutionary Information Delivery) */
/* Written by: Afshin Arefi (arefi.afshin@gmail.com)                         */
/* License:    GNU GPL V3                                                    */
/* Decription:                                                               */
/*             The main class wrapping the whole project, providing an API   */
/*             for simple use.                                               */
/*****************************************************************************/

#include<iostream>
#include"data.hpp"
#include <utility>

using namespace std;

int main(int argc, char** argv)
{
  data d(10,2);
  d.print_powers();
  return 0;
}

