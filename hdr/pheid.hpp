/*****************************************************************************/
/* Project:    P.H.E.I.D. (Paired Helpers Evolutionary Information Delivery) */
/* Written by: Afshin Arefi (arefi.afshin@gmail.com)                         */
/* License:    GNU GPL V3                                                    */
/* Decription:                                                               */
/*             The main class wrapping the whole project, providing an API   */
/*             for simple use.                                               */
/*****************************************************************************/

#ifndef HPP_PHEID
#define HPP_PHEID

#include<vector>
#include<types.hpp>
#include<chromosome.hpp>

class pheid
{
  public:

  static random_generator* generator;
  static data* db;
  
  vector<chromosome> population;
  vector<chromosome> new_generation;
  size_t pop_count;

  pheid(int);
  void create_initial_population();
  void evaluate();
  void generate_offspring();
  void create_new_population();
  void report();
  void print_population();
  void print_new_generation();
  void mutate();
};

#endif