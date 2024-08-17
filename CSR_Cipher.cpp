/* **************************************************************************** */
/*                                                        _            _        */     
/*                                                       / /\         /\ \      */
/*   CSR_Cipher.cpp                                     / /  \       /  \ \     */
/*                                                     / / /\ \__   / /\ \ \    */
/*   By: sami0vic <soutidli>                          / / /\ \___\ / / /\ \_\   */
/*                                                    \ \ \ \/___// / /_/ / /   */
/*   Created: 2024/08/15 00:09:26 by soutidli          \ \ \     / / /__\/ /    */
/*   Updated: 202?/??/?? ??:??:?? by soutidli           \ \ \   / / /_____/     */
/*                                                /_/\__/ / /  / / /\ \ \       */
/*                                                \ \/___/ /  / / /  \ \ \      */
/*                                                 \_____\/   \/_/    \_\/.ma   */
/*                                                                              */
/* **************************************************************************** */



#include "CSR.h"
#include <bits/stdc++.h>


string CSREncrypt(const string& text, int shift){
    // Declaring string variables to work
    string plaintext = text;
    string edited = "";
    string output = "";
    // Replacing white spaces with '$'
    for(int i=0; i<plaintext.size(); i++){
        if(plaintext[i] == ' '){
            edited += '$';
        } else{
            edited += plaintext[i];
        }
    }
    // Doing Caesar Encryption
    edited = caesarEncrypt(edited, shift);
    // Calculating the size of the matrix n based on the size of the string
    int m = edited.size();
    int n = ceil(sqrt(m));
    // Calling function SpiralMatrix to encrypt the string edited
    output = SpiralMatrix(n, edited, m);
    return output;
}

string CSRDecrypt(const string& text, int shift){
    int n = sqrt(text.size());
    vector<vector<char>> Matrix(n,vector<char>(n));
    int track = 0;
    for(int i=0;i<n;i++){
        if(i%2==1){
            for(int j=0;j<i+1;j++){
                Matrix[j][i] = text[track];
                track++;
            }
            for(int j=i-1;j>=0;j--){
                Matrix[i][j] = text[track];
                track++;
            }
        }
        if(i%2==0){
            for(int j=0;j<i+1;j++){
                Matrix[i][j] = text[track];
                track++;
            }
            for(int j=i-1;j>=0;j--){
                Matrix[j][i] = text[track];
                track++;
            }
        }
    }
    string final = "";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(Matrix[i][j] == '$') final += ' ';
            else final += Matrix[i][j];
        }
    }
    return caesarDecrypt(final,shift);
}

string SpiralMatrix(int n, const string& plaintext, int m){
    vector<vector<char>> matrix(n, vector<char>(n));
    string normal = plaintext;
    string final = "";

    // To track our position in the string normal
    int track0 = 0;
    // To fill the matrix with the string normal
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
    // Traversing the matrix as a spiral to produce the string final
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
    return final;
}

string caesarEncrypt(const string& text, int shift){
    string encrypted;
    shift = shift%26;
    for (char c : text) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            encrypted += char((c - base + shift) % 26 + base);
        } else {
            encrypted += c;
        }
    }
    return encrypted;
}

string caesarDecrypt(const string& text, int shift) {
    return caesarEncrypt(text, 26 - (shift % 26));
}
