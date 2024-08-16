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


string CSREncrypt(const string& text, int shift) {
    string plaintext = text;
    string edited = "";
    string output = "";
    for(int i=0; i<plaintext.size(); i++){
        if(plaintext[i] == ' '){
            edited += '$';
        } else{
            edited += plaintext[i];
        }
    }
    edited = caesarEncrypt(edited, shift);
    return edited;
}

string CSRDecrypt(const string& text, int shift) {
    string decrypted = text;

    return decrypted;
}

string caesarEncrypt(const string& text, int shift) {
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

