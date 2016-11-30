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
#include"pheid.hpp"
#include<iostream>
#include<cstring>
#include<utility>

/*****************************************************************************/

chromosome::chromosome()
{
  genes.push_back(make_pair(0,pheid::db->random_node()));
  for(int i=1;i<100;i++)
  {
    genes.push_back(make_pair(pheid::db->random_node(),pheid::db->random_node()));
  }
}

/*****************************************************************************/

chromosome::chromosome(chromosome parent1,chromosome parent2)
{
  int break_point1=pheid::generator->uniform_dist(0,parent1.genes.size());
  genes.insert(genes.end(),parent1.genes.begin(),parent1.genes.begin()+break_point1);
  int break_point2=pheid::generator->uniform_dist(0,parent2.genes.size());
  genes.insert(genes.end(),parent2.genes.begin()+break_point2,parent2.genes.end());
}

/*****************************************************************************/

void chromosome::print()
{
  for(size_t i=0;i<new_genes.size();i++)
  {
    cout<<new_genes[i].first<<" "<<new_genes[i].second<<endl;
  }
}

/*****************************************************************************/

chromosome chromosome::crossover(chromosome parent)
{
  chromosome child(*this,parent);
  return child;
}


/*****************************************************************************/

double chromosome::fitness()
{
  new_genes.resize(0);
  double power_usage=0;
  delivered.resize(0);
  delivered.resize(pheid::db->node_count,false);
  delivered[0]=true;
  for(size_t i=0;i<genes.size();i++)
  {
    if(delivered[genes[i].first])
    {
      power_usage+=transmit(genes[i].first,genes[i].second);
    }
  }
  for(int i=0;i<pheid::db->node_count;i++)
  {
    if(!delivered[i])
    {
      for(size_t j=0;j<pheid::db->sorted_power[i].size();j++)
      {
        if(delivered[pheid::db->sorted_power[i][j].second])
        {
          power_usage+=transmit(pheid::db->sorted_power[i][j].second,i);
          break;
        }
      }
    }
  }
  genes.resize(0);
  genes.insert(genes.end(),new_genes.begin(),new_genes.end());
  
  return power_usage;
}

/*****************************************************************************/

double chromosome::transmit(node s,node d)
{
  double power_usage=0;
  node furthest=65535;
  for(int j=0;pheid::db->sorted_power[s][j].second!=d;j++)
  {
    if(!delivered[pheid::db->sorted_power[s][j].second])
    {
      delivered[pheid::db->sorted_power[s][j].second]=true;
      power_usage=pheid::db->sorted_power[s][j].first;
      furthest=pheid::db->sorted_power[s][j].second;
    }
  }
  if(!delivered[d])
  {
    delivered[d]=true;
    power_usage=pheid::db->powers[s][d];
    furthest=d;
  }
  if(furthest!=65535)
    new_genes.push_back(make_pair(s,furthest));
  return power_usage;
}

/*****************************************************************************/

  const bool chromosome::operator<(const chromosome& ch) const
  {
    if(ch.score>score)
      return true;
    return false;
  }

/*****************************************************************************/

void chromosome::mutate()
{
  int genes_num=pheid::generator->uniform_dist(0,genes.size()-1);
  genes[genes_num].second=pheid::generator->random_node();
}

/*****************************************************************************/


  void chromosome::evaluate()
  {
    score=fitness();
  }