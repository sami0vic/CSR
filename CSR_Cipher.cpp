/* **************************************************************************** */
/*                                                        _            _        */
/*                                                       / /\         /\ \      */
/*   CSR_Cipher.cpp                                     / /  \       /  \ \     */
/*                                                     / / /\ \__   / /\ \ \    */
/*   By: sami0vic <soutidli>                          / / /\ \___\ / / /\ \_\   */
/*                                                    \ \ \ \/___// / /_/ / /   */
/*   Created: 2024/08/15 00:09:26 by soutidli          \ \ \     / / /__\/ /    */
/*   Updated: 2024/08/19 18:31:11 by abderrahim         \ \ \   / / /\ \        */
/*                                                /_/\__/ / /  / / /\ \ \       */
/*                                                \ \/___/ /  / / /  \ \ \      */
/*                                                 \_____\/   \/_/    \_\/.ma   */
/*                                                                              */
/* **************************************************************************** */



#include "CSR.h"
#include <bits/stdc++.h>

const char space_replacement = '$';

string encrypt_csr(const string& text, int shift){
    // Declaring string variables to work
	string plaintext	= text;
    string edited		= "";
    string output		= "";
    // Replacing white spaces with `space_replacement`
    for (char rune: plaintext){
        if (rune == ' ') edited += space_replacement;
        else edited += rune;
    }
    // Doing Caesar Encryption
    edited = encrypt_caesar(edited, shift);
    // Calculating the size of the matrix n based on the size of the string
    int m = edited.size();
    int n = ceil(sqrt(m));
    // Calling function SpiralMatrix to encrypt the string edited
    output = SpiralMatrix(n, edited, m);
    return output;
}

string decrypt_csr(const string& text, int shift){
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
            if(Matrix[i][j] == space_replacement) final += ' ';
            else final += Matrix[i][j];
        }
    }
    return decrypt_caesar(final,shift);
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
                matrix[i][j] = space_replacement;
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

string encrypt_caesar(const string& text, int shift){
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

string decrypt_caesar(const string& text, int shift) {
    return encrypt_caesar(text, 26 - (shift % 26));
}

string base64Encode(const string &data) {
    static const string base64_chars =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "0123456789+/";
    
    string encoded_string;
    int i = 0;
    int j = 0;
    unsigned char char_array_3[3];
    unsigned char char_array_4[4];

    for (int n = 0; n < data.size(); n++) {
        char_array_3[i++] = data[n];
        if (i == 3) {
            char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
            char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
            char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
            char_array_4[3] = char_array_3[2] & 0x3f;

            for (i = 0; i < 4; i++)
                encoded_string += base64_chars[char_array_4[i]];
            i = 0;
        }
    }

    if (i) {
        for (j = i; j < 3; j++)
            char_array_3[j] = '\0';

        char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
        char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
        char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
        char_array_4[3] = char_array_3[2] & 0x3f;

        for (j = 0; j < i + 1; j++)
            encoded_string += base64_chars[char_array_4[j]];

        while ((i++ < 3))
            encoded_string += '=';
    }

    return encoded_string;
}

bool isBase64(unsigned char c) {
    return (isalnum(c) || (c == '+') || (c == '/'));
}

string base64Decode(const string &encoded_string) {
    static const string base64_chars =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "0123456789+/";
    
    int in_len = encoded_string.size();
    int i = 0;
    int j = 0;
    int in_ = 0;
    unsigned char char_array_4[4], char_array_3[3];
    string decoded_string;

    while (in_len-- && (encoded_string[in_] != '=') && isBase64(encoded_string[in_])) {
        char_array_4[i++] = encoded_string[in_]; in_++;
        if (i == 4) {
            for (i = 0; i < 4; i++)
                char_array_4[i] = base64_chars.find(char_array_4[i]);

            char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
            char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
            char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

            for (i = 0; i < 3; i++)
                decoded_string += char_array_3[i];
            i = 0;
        }
    }

    if (i) {
        for (j = i; j < 4; j++)
            char_array_4[j] = 0;

        for (j = 0; j < 4; j++)
            char_array_4[j] = base64_chars.find(char_array_4[j]);

        char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
        char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
        char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

        for (j = 0; (j < i - 1); j++) decoded_string += char_array_3[j];
    }

    return decoded_string;
}