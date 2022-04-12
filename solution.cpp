#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <algorithm>
#include <iterator>
#include <map>
#include <queue>
using namespace sol1086;
using namespace std;

/*takeaways
  - using sliding window technique
    - use a map to record how many unique chars this
      window includes
    - the window has to grow to the size of k first
      then after that every time it slides to the
      right we can start decreasing the count
      of the char that moves out of the window
      during sliding
*/

int Solution::find(string &S, int k)
{
  const int N = S.size();
  auto result = 0;
  /* k is too big, or S is too small
     - you will have repeated chars if the
       substring's length is more than 26
  */
  if (k > 26 || N < k)
    return result;

  auto chars = unordered_map<char, int>();

  for (auto i = 0; i < N; i++)
  {
    /* add the new char picking up by sliding the
       window to the right
    */
    chars[S[i]]++;

    /* window grows to the size of k
       - don't foget i is 0 based
    */
    if (i >= k)
    {
      /*remove the first char of the previous window */
      chars[S[i - k]]--;
      /* remove the char from the map if
         its count reaches 0
      */
      if (chars[S[i - k]] == 0)
        chars.erase(S[i - k]);
    }

    if (i >= k - 1 && chars.size() == k)
      result++;
  }

  return result;
}