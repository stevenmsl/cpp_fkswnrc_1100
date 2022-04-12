#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol1086;

/*
Input: S = "havefunonleetcode", K = 5
Output: 6
Explanation:
There are 6 substrings they are : 'havef','avefu','vefun','efuno','etcod','tcode'.
*/

tuple<string, int, int> testFixture1()
{
  return make_tuple("havefunonleetcode", 5, 6);
}

/*
Input: S = "home", K = 5
Output: 0
Explanation:
Notice K can be larger than the length of S. In this case is not possible to find any substring.
*/

tuple<string, int, int> testFixture2()
{
  return make_tuple("home", 5, 0);
}

void test1()
{
  auto f = testFixture1();
  cout << "Test 1 - expect to see " << to_string(get<2>(f)) << endl;
  Solution sol;
  cout << "result: " << to_string(sol.find(get<0>(f), get<1>(f))) << endl;
}

void test2()
{
  auto f = testFixture2();
  cout << "Test 2 - expect to see " << to_string(get<2>(f)) << endl;
  Solution sol;
  cout << "result: " << to_string(sol.find(get<0>(f), get<1>(f))) << endl;
}

main()
{
  test1();
  test2();
  return 0;
}