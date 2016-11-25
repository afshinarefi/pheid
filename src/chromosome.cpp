/*****************************************************************************/
/* Project:    P.H.E.I.D. (Paired Helpers Evolutionary Information Delivery) */
/* Written by: Afshin Arefi (arefi.afshin@gmail.com)                         */
/* License:    GNU GPL V3                                                    */
/* Decription:                                                               */
/*             The chromosome class used in genetic algorithm to keep a      */
/*             candidate solution.                                           */
/*****************************************************************************/

#include"chromosome.hpp"
#include"data.hpp"
#include<iostream>
#include<cstring>



chromosome::chromosome(data& d)
:db(d)
{
  for(int i=0;i<100;i++)
  {
    genes.push_back(make_pair(db.random_node(),db.random_node()));
  }
}

void chromosome::print()
{
  for(size_t i=0;i<genes.size();i++)
  {
    cout<<genes[i].first<<" "<<genes[i].second<<endl;
  }
}

double chromosome::fitness()
{
  double power_usage=0;
  delivered.resize(db.node_count,false);
  delivered[0]=true;
  for(size_t i=0;i<genes.size();i++)
  {
    if(delivered[genes[i].first])
    {
      power_usage+=transmit(genes[i].first,genes[i].second);
    }
  }
  for(int i=0;i<db.node_count;i++)
  {
    if(!delivered[i])
    {
      for(size_t j=0;j<db.sorted_power[i].size();j++)
      {
        if(delivered[db.sorted_power[i][j].second])
          power_usage+=transmit(db.sorted_power[i][j].second,i);
      }
    }
  }
  return power_usage;
}

double chromosome::transmit(node s,node d)
{
  for(int j=0;db.sorted_power[s][j].second!=d;j++)
  {
    delivered[j]=true;
  }
  delivered[d]=true;
  return db.powers[s][d];
}