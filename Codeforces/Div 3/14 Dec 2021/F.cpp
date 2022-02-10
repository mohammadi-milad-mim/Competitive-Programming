#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
void computeLPSArray(char* pat, int M, int* lps);

string reverseStr(string str)
{
    int n = str.length();
 
    // Swap character starting from two
    // corners
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
    return str;
}
// Prints occurrences of txt[] in pat[]
bool KMPSearch(char* pat, char* txt)
{
	int M = strlen(pat);
	int N = strlen(txt);

	// create lps[] that will hold the longest prefix suffix
	// values for pattern
	int lps[M];

	// Preprocess the pattern (calculate lps[] array)
	computeLPSArray(pat, M, lps);

	int i = 0; // index for txt[]
	int j = 0; // index for pat[]
	while (i < N) 
    {
		if (pat[j] == txt[i]) {
			j++;
			i++;
		}

		if (j == M) {
			return true;
			j = lps[j - 1];
		}

		// mismatch after j matches
		else if (i < N && pat[j] != txt[i]) {
			// Do not match lps[0..lps[j-1]] characters,
			// they will match anyway
			if (j != 0)
				j = lps[j - 1];
			else
				i = i + 1;
		}
	}
    return false;
}

// Fills lps[] for given patttern pat[0..M-1]
void computeLPSArray(char* pat, int M, int* lps)
{
	// length of the previous longest prefix suffix
	int len = 0;

	lps[0] = 0; // lps[0] is always 0

	// the loop calculates lps[i] for i = 1 to M-1
	int i = 1;
	while (i < M) {
		if (pat[i] == pat[len]) {
			len++;
			lps[i] = len;
			i++;
		}
		else // (pat[i] != pat[len])
		{
			// This is tricky. Consider the example.
			// AAACAAAA and i = 7. The idea is similar
			// to search step.
			if (len != 0) {
				len = lps[len - 1];

				// Also, note that we do not increment
				// i here
			}
			else // if (len == 0)
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}

// Driver program to test above function
int main()
{
    lli x,y; cin>>x>>y;
    string s = bitset<64>(x).to_string();
    s.erase(0, min(s.find_first_not_of('0'), s.size()-1));
    string des = bitset<64>(y).to_string();
    des.erase(0, min(des.find_first_not_of('0'), des.size()-1));
    string s2 = reverseStr(s);
    s2.erase(0, min(s2.find_first_not_of('0'), s2.size()-1));
    //cout<<s<<endl<<s2<<endl<<des<<endl;
    int n1 = s.length();
    int n2 = s2.length();
    int nd = des.length();
    char cs[n1 + 1];
    char cs2[n2 + 1];
    char csd[nd + 1];
    strcpy(cs, s.c_str());
    strcpy(cs2, s2.c_str());
    strcpy(csd, des.c_str());
	bool f1 = KMPSearch(cs, csd);
    bool f2 = KMPSearch(cs2, csd);
    if (f1 or f2)
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
}
