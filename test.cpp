#include <bits/stdc++.h>

using namespace std;

// it's for you to text the decryption algorithm first

int main() {
    string normal = "hello$world";
    int m = normal.size();
    int n = ceil(sqrt(m)); // Size of the matrix (can be changed to any n x n)
    vector<vector<char>> matrix(n, vector<char>(n));
    string final = "";

    int track0 = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(track0 < m){
                matrix[i][j] = normal[track0];
                track0++;
            } else{
                matrix[i][j] = '$';
            }
            
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<'\n';
    }

    final += matrix[0][0];
    int value = 1;
    while(value<n){
        if(value%2 == 1){
            for(int i=0; i<value+1; i++){
                final += matrix[i][value];
            }
            for(int i=value-1; i>=0; i--){
                final += matrix[value][i];
            }
        }
        if(value%2 == 0){
            for(int i=0; i<value+1; i++){
                final += matrix[value][i];
            }
            for(int i=value-1; i>=0; i--){
                final += matrix[i][value];
            }
        }
        value++;
    }
    cout<<final;
    return 0;
}
