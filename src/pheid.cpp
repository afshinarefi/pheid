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
#include"chromosome.hpp"
#include"pheid.hpp"
#include<utility>
#include<algorithm>

using namespace std;

random_generator* pheid::generator;
data* pheid::db;

pheid::pheid(int pc)
:pop_count(pc)
{

}

void pheid::create_initial_population()
{
  for(size_t i=0;i<pop_count;i++)
  {
    chromosome chrom;
    population.push_back(chrom);
  }
}

  void pheid::evaluate()
  {
    for(size_t i=0;i<population.size();i++)
    {
      population[i].evaluate();
    }
    sort(population.begin(),population.end());
  }

  void pheid::generate_offspring()
  {
    for(size_t i=0;i<pop_count;i++)
    {
      chromosome p1=population[generator->sqrt_dist(0,population.size())];
      chromosome p2=population[generator->sqrt_dist(0,population.size())];
      new_generation.push_back(p1.crossover(p2));
    }
    for(size_t i=0;i<new_generation.size();i++)
    {
      new_generation[i].evaluate();
    }
    sort(new_generation.begin(),new_generation.end());
  }

  void pheid::create_new_population()
  {
    population.insert(population.end(),new_generation.begin(),new_generation.end());
    new_generation.resize(0);
    sort(population.begin(),population.end());
    population.resize((int)(0.60*pop_count));
    for(int i=0;population.size()<pop_count;i++)
    {
      chromosome chrom;
      population.push_back(chrom);
    }
  }

  void pheid::mutate()
  {
    for(size_t i=0;i<(pop_count/10);i++)
    {
      population[pop_count-1-generator->sqrt_dist(0,population.size())].mutate();
    }
  }

  void pheid::report()
  {
    //pheid::db->print();
    //population[0].evaluate();
    cout<<population[0].score<<endl;
    //population[0].print();
  }

  void pheid::print_population()
  {
    for(size_t i=0;i<population.size();i++)
      cout<<population[i].score<<endl;
  }

  void pheid::print_new_generation()
  {
    for(size_t i=0;i<new_generation.size();i++)
      cout<<new_generation[i].score<<endl;
  }

int main(int argc, char** argv)
{
  node node_count=10;
  sscanf(argv[1],"%hd",&node_count);
  pheid::generator=new random_generator(0,node_count);
  pheid::db=new data(node_count,2);
  for(int i=0;i<100;i++)
  {
    pheid ph(100);
    ph.create_initial_population();
    ph.evaluate();
    for(int i=0;i<500;i++)
    {
      //cout<<i<<": ";
      
      //ph.print_population();
      ph.generate_offspring();
      //ph.print_new_generation();
      ph.create_new_population();
      ph.mutate();
      ph.evaluate();
    }
    ph.report();
    delete pheid::db;
    pheid::db=new data(node_count,2);
  //923407
  }
  return 0;
}

