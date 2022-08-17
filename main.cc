// -*- coding:utf-8 -*-

#include <iostream>
//#include <ostream>
//#include <fstream>
//#include <vector>
//#include <Eigen/Dense>
//#include <chrono>
#include <cmath>

int main(){
  std::cout.precision(10); // Show 10 digits
  std::cout << std::scientific << std::endl;
  //constexpr double pi = std::acos(-1.0);

  double ef_thick;
  {
    double bb = 918.0;
    double hh = 75.0;
    //ef_thick = 4.0*2.0*bb*hh/(bb + 2.0*hh);
    ef_thick = 4.0*bb*hh/(bb + 2.0*hh);
  }
  double cc = 323.0;
  double ww = 190.0;
  double omega;
  {
    double sv1 = 241.0;
    double sv2 = 60.0;
    double gv = 361.0;
    double s1kg = 0.05;
    double s2kg = 0.04;
    double gkg = 0.01;
    omega = sv1*s1kg + sv2*s2kg + gv*gkg;
  }
  double epsh;
  {
    double alpha = 4.0;
    epsh = 2.4*(ww + 45.0/(-20.0 + 30.0*cc/ww)*alpha*omega);
  }
  double row;
  {
    double ss = 158.0 + 617.0;
    double gg = 979.0;
    double ae = 3.23;
    row = (cc + ww + ss + gg + ae)*0.001;
  }
  double beta;
  {
    beta = 30.0/row*(120.0/(-14.0 + 21.0*cc/ww) - 0.70);
  }
  double epshinf;
  {
    epshinf = (1.0 + beta/182.0)*epsh;
  }
  double day = 46.0;
  double st_dry_day = 7.0;
  double epds;
  {
    double rh = 60.0;
    epds = (1.0 - rh/100.0)/(1.0 - 60.0/100.0)*epshinf*(day - st_dry_day);
    epds = epds/((ef_thick/100.0)*(ef_thick/100.0)*beta + (day - st_dry_day));
  }

  std::cout << "ef_thick " << ef_thick << std::endl;
  std::cout << "cc/ww " << cc/ww << std::endl;
  std::cout << "omega " << omega << std::endl;
  std::cout << "epsh " << epsh << std::endl;
  std::cout << "row " << row << std::endl;
  std::cout << "beta " << beta << std::endl;
  std::cout << "epshinf " << epshinf << std::endl;
  std::cout << "epds " << epds << std::endl;
}
