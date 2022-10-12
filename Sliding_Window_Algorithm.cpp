/*

Find the longest substring of a string containing `k` distinct characters
Given a string and a positive number k, find the longest substring of the string containing k distinct characters. If k is more than the total number of distinct characters in the string, return the whole string.

The problem differs from the problem of finding the longest subsequence with k distinct characters. Unlike subsequences, substrings are required to occupy consecutive positions within the original string.


For example, consider string abcbdbdbbdcdabd.

For k = 2, o/p is ‘bdbdbbd’
For k = 3, o/p is ‘bcbdbdbbdcd’
For k = 5, o/p is ‘abcbdbdbbdcdabd’

*/


#include <bits/stdc++.h>
using namespace std;


int main() {
	int k , ans = 0 , ind1 = 0 , ind2 = 0;
	string s;
	cin >> k >> s ;

	map<char  , int> mp;
	int n = s.size();
	int low = 0 , high = 0;
	mp[s[0]]++;
	while (high <= n && low >= 0) {


		if (mp.size() < k) {
			high++;
			mp[s[high]]++;

		}

		else if (mp.size() > k) {
			mp[s[low]]--;
			if (mp[s[low]] == 0) mp.erase(s[low]);
			low++;
		}

		else if (mp.size() == k) {
			if (ans < high - low + 1) {
				ans = high - low + 1 ;
				ind1 = low;
				ind2 = high;
			}
			high++;
			mp[s[high]]++;
		}

	}

	cout << ans << " " << s.substr(ind1 , ind2 - ind1 + 1) << endl;
	return 0;
}