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
std::string encrypt_csr(const std::string& text, int shift);
std::string decrypt_csr(const std::string& text, int shift);
std::string SpiralMatrix(int n, const std::string& plaintext, int m);

// Additional cipher functions
std::string encrypt_caesar(const std::string& text, int shift);
std::string decrypt_caesar(const std::string& text, int shift);

#endif // CSR_H
