/* **************************************************************************** */
/*                                                        _            _        */
/*                                                       / /\         /\ \      */
/*   CSR.h                                              / /  \       /  \ \     */
/*                                                     / / /\ \__   / /\ \ \    */
/*   By: sami0vic <soutidli>                          / / /\ \___\ / / /\ \_\   */
/*                                                    \ \ \ \/___// / /_/ / /   */
/*   Created: 2024/08/15 00:09:26 by soutidli          \ \ \     / / /__\/ /    */
/*   Updated: 2024/08/19 17:50:30 by abderrahim         \ \ \   / / /\ \        */
/*                                                /_/\__/ / /  / / /\ \ \       */
/*                                                \ \/___/ /  / / /  \ \ \      */
/*                                                 \_____\/   \/_/    \_\/.ma   */
/*                                                                              */
/* **************************************************************************** */

#ifndef CSR_H
#define CSR_H

#include <string>

using namespace std;

// Function declarations for CSR cipher
string encrypt_csr(const string& text, int shift);
string decrypt_csr(const string& text, int shift);
string SpiralMatrix(int n, const string& plaintext, int m);

// Function declarations for Caesar cipher
string encrypt_caesar(const string& text, int shift);
string decrypt_caesar(const string& text, int shift);

// Function declarations for Base64 cipher
bool isBase64(unsigned char c);
string base64Encode(const string &data);
string base64Decode(const string &encoded_string);


#endif // CSR_H
