#include <bits/stdc++.h>
#define ll long long int
#define prime 17

using namespace std;

ll createHashValue(string str, int n){
    ll result = 0;
    for(int i = 0; i < n; i++){
        result += str[i] * (ll)pow(prime, i);
    }
    return result;
}

ll recalculateHash(string str, int oldIndex, int newIndex,ll oldHash, int pattLength){
    ll newHash = oldHash - str[oldIndex];
    newHash /= prime;
    newHash += str[newIndex] * (ll)pow(prime, pattLength - 1);
    return newHash;
}

bool checkEqual(string str1, string str2, int start1, int  end1, int start2, int end2){
    if((end1 - start1 + 1) != (end2 - start2 + 1))
        return false;
    
    while(start1 <= end1){
        if(str1[start1] != str2[start2])
            return false;
        
        start1++;
        start2++;
    }
    
    return true;
}

void searchPatt(string text, string patt){
    int n = text.length();
    int m = patt.length();
    ll pattHash = createHashValue(patt, m);
    ll subHash = createHashValue(text, m);
    for(int i = 0; i <= n - m; i++ ){
        if(pattHash == subHash && checkEqual(text, patt, i, i + m - 1, 0, m - 1)){
            cout << i << " ";
        }
        if(i < n - m){
            subHash = recalculateHash(text, i, i + m, subHash, m);
        }
    }
    cout << endl;
}

int main() {
    string text = "geeksforgeeksgeeksforgeeks";
    string patt = "forgeeksgeeks";
    searchPatt(text, patt);
    
	return 0;
}
