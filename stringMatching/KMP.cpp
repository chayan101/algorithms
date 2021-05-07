#include <bits/stdc++.h>
#define ll long long int
#define prime 3

using namespace std;

void prefixArr(int* arr,string patt, int m){
	arr[0] = 0;
	if(m > 1){
		int j = 0, i = 1;
		while(i < m && j <= i){
			if(patt[i] == patt[j]){
				arr[i] = j + 1;
				i++;
				j++;
			}else if(j == 0){
				arr[i++] = 0;
			}else{
				j = arr[j - 1];
			}
		}
	}
}

void stringMatchKMP(string text, string patt){
	int n = text.length();
	int m = patt.length();
	int arr[m];
	prefixArr(arr, patt, m);
	int j = 0, i = 0;
	while(i < n && j < m){
		if(text[i] == patt[j]){
			i++;
			j++;
			if(j == m){
				cout << i - m << endl;
				return;
			}
		}else{
			if(j == 0)
					i++;
			else{
				j = arr[j - 1];
			}
		}
	}
	cout << -1 << endl;
}

int main() {
    string text = "geeksforgeeksgeeksforgeeks";
    string patt = "forgeeksgeeks";
    stringMatchKMP(text,patt);
	return 0;
}