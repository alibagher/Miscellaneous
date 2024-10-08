#include <bits/stdc++.h>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s) {
    int numV = 0;
    bool inV = false;

    int height = 0;
    
    for (int i = 0; i < n; i++){
        if(s[i] == 'D'){
            height--;
        }else{
            height++;
        }

        if (inV && height == 0){
            inV = false;
            numV ++;
        }else if(!inV && height == -1){
            inV = true;
        }
    }
    return numV;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
