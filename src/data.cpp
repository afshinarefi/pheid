/*****************************************************************************/
/* Project:    P.H.E.I.D. (Paired Helpers Evolutionary Information Delivery) */
/* Written by: Afshin Arefi (arefi.afshin@gmail.com)                         */
/* License:    GNU GPL V3                                                    */
/* Decription:                                                               */
/*             The data class keeping the input data neccesary for the       */
/*             computations and performing any precomputation needed.        */
/*****************************************************************************/

#include"data.hpp"
#include<vector>
#include<utility>
#include<iostream>
#include<cmath>

using namespace std;

data::data(int node_count,double alpha)
{
  for(int i=0;i<node_count;i++)
  {
    coordinates.push_back(rg.coordinate());
  }
  for(int i=0;i<node_count;i++)
  {
    vector<double> row;
    for(int j=0;j<node_count;j++)
    {
      row.push_back(pow(distance(coordinates[i],coordinates[j]),alpha));
    }
    powers.push_back(row);
  }
}

double data::distance(pair<double,double> x,pair<double,double> y)
{
  return sqrt((y.first-x.first)*(y.first-x.first)+(y.second-x.second)*(y.second-x.second));
}

void data::print()
{
  for(vector<pair<double, double> >::iterator it=coordinates.begin();it<coordinates.end();it++)
  {
    cout<<it->first<<" "<<it->second<<endl;
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