/*****************************************************************************/
/* Project:    P.H.E.I.D. (Paired Helpers Evolutionary Information Delivery) */
/* Written by: Afshin Arefi (arefi.afshin@gmail.com)                         */
/* License:    GNU GPL V3                                                    */
/* Decription:                                                               */
/*             The data class keeping the input data neccesary for the       */
/*             computations and performing any precomputation needed.        */
/*****************************************************************************/

#include"data.hpp"
#include"pheid.hpp"
#include<vector>
#include<utility>
#include<iostream>
#include<cmath>
#include<algorithm>    // sort()

using namespace std;

data::data(int nc,double alpha)
:node_count(nc)
{
  coordinates.push_back(make_pair(0,0));
  for(int i=1;i<node_count;i++)
  {
    coordinates.push_back(pheid::generator->coordinate());
  }
  for(int i=0;i<node_count;i++)
  {
    vector<double> row;
    vector<pair<double,node>> sorted_row;
    for(int j=0;j<node_count;j++)
    {
      double power=pow(distance(coordinates[i],coordinates[j]),alpha);
      row.push_back(power);
      sorted_row.push_back(make_pair(power,j));
    }
    sort(sorted_row.begin(),sorted_row.end());
    powers.push_back(row);
    sorted_power.push_back(sorted_row);
  }
}

double data::distance(coor a,coor b)
{
  double dist_x=(b.first-a.first);
  double dist_y=(b.second-a.second);
  return sqrt(dist_x*dist_x+dist_y*dist_y);
}

void data::print()
{
  for(vector<coor>::iterator it=coordinates.begin();it<coordinates.end();it++)
  {
    cout<<it->first<<","<<it->second<<endl;
  }
}

void data::print_powers()
{
  for(size_t i=0;i<powers.size();i++)
  {
    for(size_t j=0;j<powers[i].size();j++)
    {
      printf("%1.3lf ",powers[i][j]);
    }
    printf("\n");
  }
}

void data::print_sorted_powers()
{
  for(size_t i=0;i<sorted_power.size();i++)
  {
    for(size_t j=0;j<sorted_power[i].size();j++)
    {
      printf("(%1.3lf,%3d)",sorted_power[i][j].first,sorted_power[i][j].second);
    }
    printf("\n");
  }
}

node data::random_node()
{
  return pheid::generator->random_node();
}