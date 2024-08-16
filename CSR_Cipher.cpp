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


string encrypt(const string& text, const string& key) {
    string encrypted = text;
    for (size_t i = 0; i < text.size(); ++i) {
        encrypted[i] = text[i] + key[i % key.size()];
    }
    return encrypted;
}

string decrypt(const string& text, const string& key) {
    string decrypted = text;
    for (size_t i = 0; i < text.size(); ++i) {
        decrypted[i] = text[i] - key[i % key.size()];
    }
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

