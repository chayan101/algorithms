#include <bits/stdc++.h>
#define ll long long int
#define prime 119

using namespace std;

ll hashValue(string str, int n){
    ll result = 0;
    for(int i = 0; i < n; i++){
        result += (ll)(str[i] * (ll)pow(prime , i));
    }
    return result;
}

ll recalculateHashValue(ll oldHash, string str, int oldIndex, int newIndex, int pattLength){
    ll newHash = oldHash - str[oldIndex];
    newHash /= prime;
    newHash += (ll)(str[newIndex] * (ll)pow(prime, pattLength - 1));
    return newHash;
}

bool compareString(string str1, string str2,int start1, int end1, int start2, int end2){
    if(end1 - start1 != end2 - start2)
        return false;
    
    while(start1 <= end1){
        if(str1[start1] != str2[start2]){
            return false;
        }
        start1++;
        start2++;
        
    }
    
    return true;
}



//function returns a vector containing the indices where the pattern matches the text
vector<int> matchStringRabinKarp(string text, string pattern){
    int n = text.length();
    int m = pattern.length();
    bool res;
    vector<int> sol;
    
    ll patternHash = hashValue(pattern, m);
    ll subHash = hashValue(text,m);
    ll substringHash;
    
    for(int i = 0; i < n - m + 1; i++){
        if(subHash == patternHash && compareString(pattern, text, 0, m - 1, i, i + m - 1)){
              sol.push_back(i);
         }     
      subHash = recalculateHashValue(subHash, text, i, i + m , m);
    }
    
    return sol;
}

//driver code to test the above function
int main() {
	string text = "mmmmmabd";
	string pat = "abd";
	vector <int> res = matchStringRabinKarp(text, pat);
	
	for(int i = 0; i < res.size(); i++){
	    cout<<res[i]<<" ";
	}
	cout << endl;
	return 0;
}
