#include <RcppArmadillo.h>

// [[Rcpp::depends(RcppArmadillo)]]
//' @title Binomial coefficient
//'
//' @param n integer.
//' @param k integer.
//'
//'
//' @return binomial coefficient
//'
//'
//' @author Raphaël Jauslin \email{raphael.jauslin@@unine.ch}
//'
//'
//' @export
// [[Rcpp::export]]
long long int choose(int n, int k)
{
  long long int res = 1;

  // Since C(n, k) = C(n, n-k)
  if(k > n - k){
    k = n - k;
  }

  // Calculate value of
  // [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1]
  for (int i = 0; i < k; ++i){
    res *= (n - i);
    res /= (i + 1);
  }

  return res;
}