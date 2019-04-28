#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {
    // length of the word
    long len = s.length();
    //number of as per word
    long perWord = 0;

    for (int i = 0; i < len; i++){
        if (s[i] == 'a'){
            perWord++;
        }
        if(i == n){
            return perWord;
        }
    }

    //figure out which number of words is n part of. 
    long numWords = n/len;
    long ans = numWords * perWord;
    // number of letters traveresed so far
    long sofar = numWords*len;

    for (int i = 0; i < len; i++){
        if(sofar == n){
            return ans;
        }
        if (s[i] == 'a'){
            ans++;
        }
        sofar++;
    }
    
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}
