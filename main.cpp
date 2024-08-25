/* **************************************************************************** */
/*                                                        _            _        */
/*                                                       / /\         /\ \      */
/*   main.cpp                                           / /  \       /  \ \     */
/*                                                     / / /\ \__   / /\ \ \    */
/*   By: sami0vic <soutidli>                          / / /\ \___\ / / /\ \_\   */
/*                                                    \ \ \ \/___// / /_/ / /   */
/*   Created: 2024/08/15 00:09:26 by soutidli          \ \ \     / / /__\/ /    */
/*   Updated: 2024/08/19 18:47:39 by abderrahim         \ \ \   / / /\ \        */
/*                                                /_/\__/ / /  / / /\ \ \       */
/*                                                \ \/___/ /  / / /  \ \ \      */
/*                                                 \_____\/   \/_/    \_\/.ma   */
/*                                                                              */
/* **************************************************************************** */


// Include Libraries
#include "CSR.h"
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <chrono>
#include <string>
#include <thread>
#include <vector>
#include <readline/readline.h>
#include <readline/history.h>

// Define Colors
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define ORANGE  "\033[38;5;208m"

using namespace std;

// Some ASCII Art ;)
const string CSR_ART = R"(
          _____                    _____                    _____          
         /\    \                  /\    \                  /\    \         
        /::\    \                /::\    \                /::\    \        
       /::::\    \              /::::\    \              /::::\    \       
      /::::::\    \            /::::::\    \            /::::::\    \      
     /:::/\:::\    \          /:::/\:::\    \          /:::/\:::\    \     
    /:::/  \:::\    \        /:::/__\:::\    \        /:::/__\:::\    \    
   /:::/    \:::\    \       \:::\   \:::\    \      /::::\   \:::\    \   
  /:::/    / \:::\    \    ___\:::\   \:::\    \    /::::::\   \:::\    \  
 /:::/    /   \:::\    \  /\   \:::\   \:::\    \  /:::/\:::\   \:::\____\ 
/:::/____/     \:::\____\/::\   \:::\   \:::\____\/:::/  \:::\   \:::|    |
\:::\    \      \::/    /\:::\   \:::\   \::/    /\::/   |::::\  /:::|____|
 \:::\    \      \/____/  \:::\   \:::\   \/____/  \/____|:::::\/:::/    / 
  \:::\    \               \:::\   \:::\    \            |:::::::::/    /  
   \:::\    \               \:::\   \:::\____\           |::|\::::/    /   
    \:::\    \               \:::\  /:::/    /           |::| \::/____/    
     \:::\    \               \:::\/:::/    /            |::|  ~|          
      \:::\    \               \::::::/    /             |::|   |          
       \:::\____\               \::::/    /              \::|   |          
        \::/    /                \::/    /                \:|   |          
         \/____/                  \/____/                  \|___|                                                                                               
)";

// function to display the App Banner
void banner_display(){
	cout << YELLOW << CSR_ART                      << RESET << endl;
    cout << RED    << "\tVersion: 3.3.0.1"         << RESET << endl;
    cout << CYAN   << "\tAuthors: @sami0vic & @redafraise" << RESET << endl;
    cout << CYAN   << "\tCorrector: @Creativty" << RESET << endl;
}

// function to Clear
void screen_clear(){
	// TODO(XENOBAS): replace with ansi escape code for erasure, look at:
	// https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797#erase-functions

	cout << "\033[2J" << "\033[H" << endl;
    /*#if(defined(_WIN32) || defined(_WIN64) || defined(__linux__))*/
    /*    system("clear"); */
    /*#else*/
    /*    system("cls");*/
    /*#endif*/

    banner_display();
}

// Function to Animate the '/'
void displayRotatingBackslash(int durationSeconds, string s){
    const char symbols[] ={'|', '/', '-', '\\'};
    int numSymbols = sizeof(symbols)/ sizeof(symbols[0]);
    auto start = chrono::steady_clock::now();
    while(chrono::duration_cast<chrono::seconds>(chrono::steady_clock::now()- start).count()< durationSeconds){
        for(int i = 0; i < numSymbols; ++i){
            cout<<"\r"<<s<<symbols[i]<<flush;
            this_thread::sleep_for(chrono::milliseconds(300));
        }
    }
	cout<<"\r"<<"                                    "<<"\r";
}

// Function to Handle Encryption
void command_encrypt(const string& cipher, const string& text, const string& key){
    if(cipher == "-csr"){
        try {
            int shift = stoi(key);
            displayRotatingBackslash(2, "Encrypting the text, please wait ");
			cout << "Encrypted text: "<< encrypt_csr(text, shift) << endl;
        } catch (const invalid_argument& e) {
			cout << "Invalid key for CSR cipher. It should be an integer." << endl;
            cout << "Usage: encrypt <cipher> <key> <text>" << endl;
        }
    } else if(cipher == "-caesar"){
        try {
            int shift = stoi(key);
            displayRotatingBackslash(2, "Encrypting the text, please wait ");
			cout<< "Encrypted text: "<< encrypt_caesar(text, shift) << endl;
        } catch (const invalid_argument& e) {
			cout << "Invalid key for Caesar cipher. It should be an integer." << endl;
			cout << "Usage: encrypt <cipher> <key> <text>" << endl;
        }
    }  else if(cipher == "-base64"){
        try {
            int shift = stoi(key);
            displayRotatingBackslash(2, "Encrypting the text, please wait ");
			cout<< "Encrypted text: "<< base64Encode(text) << endl;
        } catch (const invalid_argument& e) {
			cout << "Invalid key for Base64 cipher. It should be an integer." << endl;
			cout << "Usage: encrypt <cipher> 0 <text>" << endl;
        }
    } else{
		cout << "Unknown cipher: " << cipher << endl;
    }
}

// Function to Brute Force Caesar Cipher
void brute_force_caesar(const string& text){
	cout << "Brute force results:" << endl;
    for(int shift = 1; shift < 26; ++shift){
		cout << '\t' << "Shift " << shift << ":\t" << decrypt_caesar(text, shift) << endl;
    }
}

// Function to Handle Decryption
void command_decrypt(const string& cipher, const string& text, const string& key){
    if (cipher == "-csr") {
        try {
            int shift = stoi(key);
            displayRotatingBackslash(2, "Decrypting the text, please wait ");
			cout << "Encrypted text: " << decrypt_csr(text, shift) << '\n';
        } catch(const invalid_argument& e){
			cout << "Invalid key for CSR cipher. It should be an integer." << endl;
            cout << "Usage: decrypt <cipher> <key> <text>" << endl;
        }
    } else if(cipher == "-caesar"){
        try {
            int shift = stoi(key);
            displayRotatingBackslash(2, "Decrypting the text, please wait ");
			cout <<"Decrypted text: " << decrypt_caesar(text, shift) << endl;
        } catch(const invalid_argument& e){
			cout << "Invalid key for Caesar cipher. It should be an integer." << endl;
            cout << "Usage: decrypt <cipher> <key> <text>" << endl;
        }
    } else if(cipher == "-base64"){
        try {
            int shift = stoi(key);
            displayRotatingBackslash(2, "Decrypting the text, please wait ");
			cout <<"Decrypted text: " << base64Decode(text) << endl;
        } catch(const invalid_argument& e){
			cout << "Invalid key for Base64 cipher. It should be an integer." << endl;
            cout << "Usage: decrypt <cipher> 0 <text>" << endl;
        }
    } else{
		cout << "Unrecognized cipher: " << cipher << endl;
    }
}

// List of Commands Available Now
const vector<string> commands = {
    "help", "clear", "cls", "exit", "cipher", "echo", "encrypt", "decrypt", "bruteforce"
};

// Command Completion Function
char** command_completion(const char* text, int start, int end){
    static vector<string> matches;
    matches.clear();

    if (start == 0) for(const auto& cmd:commands) { if(cmd.find(text) == 0) matches.push_back(cmd); }
    else return nullptr;

    char **result = (char**)malloc((matches.size() + 1) * sizeof(char*));
    if(result == nullptr) return nullptr;

    for(size_t i = 0; i < matches.size(); ++i){
        result[i] = strdup(matches[i].c_str());
        if(result[i] == nullptr){
            while (i > 0){
                free(result[--i]);
            }
            free(result);
            return nullptr;
        }
    }
    result[matches.size()] = nullptr;
    return result;
}

void	string_trim(string &str) {
	// REFERENCE: https://stackoverflow.com/questions/216823/how-to-trim-a-stdstring
	str.erase(0, str.find_first_not_of("\t\n\v\f\r "));
	str.erase(str.find_last_not_of("\t\n\v\f\r ") + 1);
}

bool	string_has_prefix(string &haystack, const char *needle) {
	if (haystack.size() < strlen(needle))
		return (false);
	return (strncmp(haystack.c_str(), needle, strlen(needle)) == 0);
}

int main(){
    char*		command = nullptr;
    const char	*prompt = "\001\033[38;5;208m\002csr> \001\033[0m\002";
	const char *history_filename = "history.txt";

    using_history();
	// history_no_expand_chars = (char *)" \t\n\r=$";
    const int history_failure = read_history(history_filename);
	if (history_failure) {
		cerr << "[error] " << "could not read history with return code: " << history_failure << endl;
		return (1);
	}

    // Set Completion function
    rl_attempted_completion_function = command_completion;

	// NOTE: Display banner only once everything is properly initalized.
    screen_clear();

	bool is_running = true;
	vector<char *> session_history;
    // Taking Commands
    while (is_running) {
        command = readline(prompt);
        if (command && *command) {
            add_history(command);
            write_history(history_filename);
        } else {
			free(command);
			continue ;
		}

		string command_str(command);
		session_history.push_back(command);

        // Command to erase the white spaces before & after the command
		string_trim(command_str);

        // Processing Command
		if (command_str == "exit") {
			is_running = false;
		} else if (command_str == "cls" || command_str == "clear") {
			screen_clear();
		} else if (command_str == "help") {
			cout << CYAN << "Available commands:" << endl;
			cout << CYAN << "\thelp        - Show this help message" << endl;
			cout << CYAN << "\tclear       - Clear the terminal" << endl;
			cout << CYAN << "\tcls         - Clear the terminal(WINDOWS Style)" << endl;
			cout << CYAN << "\texit        - Exit the console" << endl;
			cout << CYAN << "\tcipher      - Show all the Available Ciphers" << endl;
			cout << CYAN << "\techo <text> - Print the text" << endl;
			cout << CYAN << "\tencrypt <cipher> <key> <text> - Encrypt text with specified cipher" << endl;
			cout << CYAN << "\tdecrypt <cipher> <key> <text> - Decrypt text with specified cipher" << endl;
			cout << CYAN << "\tbruteforce <cipher> <text>    - Brute force decrypt text with specified cipher" << endl;
		} else if (command_str == "cipher") {
			cout << CYAN << "Available Ciphers:" << endl;
			cout << CYAN << "\tCSR     - Developed by SAMI&REDA" << endl;
			cout << CYAN << "\tCaesar  - Developed by Gaius Julius Caesar" << endl;
			cout << CYAN << "\tBase64  - Developed by Internet Engineering Task Force (IETF)" << endl;
		} else if (string_has_prefix(command_str, "echo")) {
			string cmd, text;
            istringstream iss(command_str);
            iss >> cmd;

            getline(iss, text);
            text = text.substr(text.find_first_not_of(' '));

            cout << text << '\n';
		} else if (string_has_prefix(command_str, "encrypt")) { 
			// DANGER: ^ is a very very bad idea, this lets command such as
			// encryptaodsjoiasjhdoiqwheoiqhw -csr ....
			istringstream iss(command_str);
			string cmd, cipher, key, text;

			iss >> cmd >> cipher >> key;
			getline(iss, text);
			string_trim(text);

			if(!cipher.empty() && !key.empty() && !text.empty()) command_encrypt(cipher, text, key);
			else cout << "Usage: encrypt <cipher> <key> <text>" << endl;
		} else if (string_has_prefix(command_str, "decrypt")) { // Decrypt 🔓
            string cmd, cipher, key, text;
			istringstream iss(command_str);

            iss >> cmd >> cipher >> key;
            getline(iss, text);
			string_trim(text);

            if(!cipher.empty() && !key.empty() && !text.empty()) command_decrypt(cipher, text, key);
            else cout << "Usage: decrypt <cipher> <key> <text>" << endl;
        } else if (string_has_prefix(command_str, "bruteforce")) { // Bruteforce 🛠️
            string			cmd, cipher, text;
			istringstream	iss(command_str);

            iss >> cmd >> cipher;
            getline(iss, text);
			string_trim(text);

            if(!cipher.empty() && !text.empty()) {
                if(cipher == "-caesar") brute_force_caesar(text);
                else cout << "Unknown cipher for brute force: " << cipher << endl;
            } else {
				cout << "Usage: bruteforce <cipher> <text>" << endl;
            }
        } else cout << "Unknown command: " << command_str << endl;
    }

	for (auto line: session_history) free(line);
    return 0;
}
