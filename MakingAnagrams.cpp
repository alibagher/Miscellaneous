#include <bits/stdc++.h>

using namespace std;

// Complete the makeAnagram function below.
int makeAnagram(string a, string b) {
    int lena = a.length();
    int lenb = b.length();

    //an array of bool to see if each index has been accounted for by the other string.
    bool useda [lena] = {false};
    bool usedb [lenb] = {false};

    int del = 0; 
    bool found = false;
    for (int i = 0; i < lena; i++){
        for (int j = 0; j < lenb; j++){
            if(a[i] == b[j] && !usedb[j]){
                usedb[j] = true;
                found = true; 
                break;
            }
        }
        if(!found){
            del++;
        }
        found = false;
    }
    
    found = false;
    
    for (int i = 0; i < lenb; i++){
        for (int j = 0; j < lena; j++){
            if(b[i] == a[j] && !useda[j]){
                useda[j] = true;
                found = true; 
                break;
            }
        }
        if(!found){
            del++;
        }
        found = false;
    }

    return del;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    fout << res << "\n";

    fout.close();

    return 0;
}
