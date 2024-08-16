/* **************************************************************************** */
/*                                                        _            _        */     
/*                                                       / /\         /\ \      */
/*   CSR.h                                              / /  \       /  \ \     */
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



#ifndef CSR_H
#define CSR_H

#include <string>

using namespace std;

// Function declarations for CSR cipher
string CSREncrypt(const string& text, int shift);
string CSRDecrypt(const string& text, int shift);

// Additional cipher functions
string caesarEncrypt(const string& text, int shift);
string caesarDecrypt(const string& text, int shift);

#endif // CSR_H
