/*

Find all substrings of a string that are a permutation of another string
Find all substrings of a string that contains all characters of another string. In other words, find all substrings of the first string that are anagrams of the second string.

Please note that the problem specifically targets substrings that are contiguous (i.e., occupy consecutive positions) and inherently maintains the order of elements.


For example,

The first string is 'XYYZXZYZXXYZ'
The second string is 'XYZ'

Anagram 'YZX' present at index 2
Anagram 'XZY' present at index 4
Anagram 'YZX' present at index 6
Anagram 'XYZ' present at index 9

*/



#include <bits/stdc++.h>
using namespace std;


int main() {

	set<int> ans;
	bool a = true;

	string s1 , substring ;

	cin >> s1 >> substring;

	map<char , int> mp;

	for (int i = 0; i < substring.size(); ++i) {
		mp[substring[i]]++;
		mp[s1[i]]--;
		if (mp[substring[i]] == 0) mp.erase(mp[substring[i]]);
		if (mp[s1[i]] == 0) mp.erase(mp[s1[i]]);
	}

	int dumi = substring.size() ;
	int size1 = s1.size() , size2 = substring.size() ;

	// for (auto x : mp) cout << x.first << " " << x.second << endl;

	while (dumi != size1 + 1) {

		a = true;
		for (auto x : mp) if (x.second != 0) {a = false ; break;}

		if (a) ans.insert(dumi - size2);

		mp[s1[dumi - size2]]++;
		if (mp[s1[dumi - size2]] == 0) mp.erase(mp[s1[dumi - size2]]) ;

		mp[s1[dumi]]--;
		if (mp[s1[dumi]] == 0) mp.erase(mp[s1[dumi]]) ;

		dumi++;
	}

	for (auto x : ans) cout << x << " ";


	return 0;
}