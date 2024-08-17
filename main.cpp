/* **************************************************************************** */
/*                                                        _            _        */     
/*                                                       / /\         /\ \      */
/*   main.cpp                                           / /  \       /  \ \     */
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


// Include Libraries
#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
#include <thread>
#include <chrono>
#include <sstream>
#include <readline/readline.h>
#include <readline/history.h>
#include <vector>
#include <cstring>
#include "CSR.h"

//Define Colors
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
void displayBanner(){
    cout<<YELLOW<<CSR_ART<<RESET<<'\n';
    cout<<RED<<"    Version: 3.3.0.1"<<RESET<<'\n';
    cout<<CYAN<<"    Authors: SAMIOVIC & REDA"<<RESET<<'\n';
}

// function to Clear
void clearScreen(){
    #if(defined(_WIN32) || defined(_WIN64) || defined(__linux__))
        system("clear"); 
    #else
        system("cls");
    #endif

    displayBanner();
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
void handleEncryption(const string& cipher, const string& text, const string& key){
    if(cipher == "-csr"){
        try{
            int shift = stoi(key);
            displayRotatingBackslash(2, "Encrypting the text, please wait ");
            cout<<"Encrypted text: "<<CSREncrypt(text, shift)<<'\n';
        } catch(const invalid_argument& e){
            cout<<"Invalid key for CSR cipher. It should be an integer."<<'\n';
            cout<<"Usage: encrypt <cipher> <key> <text>"<<'\n';
        }
    } else if(cipher == "-caesar"){
        try{
            int shift = stoi(key);
            displayRotatingBackslash(2, "Encrypting the text, please wait ");
            cout<<"Encrypted text: "<<caesarEncrypt(text, shift)<<'\n';
        } catch(const invalid_argument& e){
            cout<<"Invalid key for Caesar cipher. It should be an integer."<<'\n';
            cout<<"Usage: encrypt <cipher> <key> <text>"<<'\n';
        }
    } else{
        cout<<"Unknown cipher: "<<cipher<<'\n';
    }
}

// Function to Brute Force Caesar Cipher
void caesarBruteForce(const string& text){
    cout<<"Brute force results:\n";
    for(int shift = 1; shift < 26; ++shift){
        string decrypted = caesarDecrypt(text, shift);
        cout<<"   Shift "<<shift<<": "<<decrypted<<'\n';
    }
}

// Function to Handle Decryption
void handleDecryption(const string& cipher, const string& text, const string& key){
    if(cipher == "-csr"){
        try{
            int shift = stoi(key);
            displayRotatingBackslash(2, "Decrypting the text, please wait ");
            cout<<"Encrypted text: "<<CSRDecrypt(text, shift)<<'\n';
        } catch(const invalid_argument& e){
            cout<<"Invalid key for CSR cipher. It should be an integer."<<'\n';
            cout<<"Usage: decrypt <cipher> <key> <text>"<<'\n';
        }
    } else if(cipher == "-caesar"){
        try{
            int shift = stoi(key);
            displayRotatingBackslash(2, "Decrypting the text, please wait ");
            cout<<"Decrypted text: "<<caesarDecrypt(text, shift)<<'\n';
        } catch(const invalid_argument& e){
            cout<<"Invalid key for Caesar cipher. It should be an integer."<<'\n';
            cout<<"Usage: decrypt <cipher> <key> <text>"<<'\n';
        }
    } else{
        cout<<"Unknown cipher: "<<cipher<<'\n';
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

    if(start == 0){
        for(const auto& cmd:commands){
            if(cmd.find(text) == 0){
                matches.push_back(cmd);
            }
        }
    } else{
        return nullptr;
    }

    char** result = (char**)malloc((matches.size() + 1) * sizeof(char*));
    if(result == nullptr){
        return nullptr;
    }

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



int main(){
    clearScreen();
    const char* prompt = ORANGE "csr> " RESET;
    char* command;
    using_history();
    read_history("history.txt");

    // Set Completion function
    rl_attempted_completion_function = command_completion;


    // Taking Commands
    while(true){
        command = readline(prompt);
        if (command && *command) {
            add_history(command);
            write_history("history.txt");
        }

        string command_str(command);
        free(command);

        // Command to erase the white spaces before & after the command
        command_str = command_str.substr(command_str.find_first_not_of(' '));
        command_str = command_str.substr(0, command_str.find_last_not_of(' ') + 1);

        // Processing Command
        if(command_str == "exit"){ // Exit :(
            break;
        } else if(command_str == "clear" || command_str == "cls"){ // Clear 🗑
            clearScreen();
        } else if(command_str == "help"){ // Help Menu 🚨
            cout<<CYAN<<"Available commands:\n";
            cout<<CYAN<<"    help        - Show this help message\n";
            cout<<CYAN<<"    clear       - Clear the terminal\n";
            cout<<CYAN<<"    cls         - Clear the terminal(WINDOWS Style)\n";
            cout<<CYAN<<"    exit        - Exit the console\n";
            cout<<CYAN<<"    cipher      - Show all the Available Ciphers\n";
            cout<<CYAN<<"    echo <text> - Print the text\n";
            cout<<CYAN<<"    encrypt <cipher> <key> <text> - Encrypt text with specified cipher\n";
            cout<<CYAN<<"    decrypt <cipher> <key> <text> - Decrypt text with specified cipher\n";
            cout<<CYAN<<"    bruteforce <cipher> <text>    - Brute force decrypt text with specified cipher\n";
        } else if(command_str == "cipher"){ // Ciphers Menu 𝄃𝄃𝄂𝄂𝄀𝄁𝄃𝄂𝄂𝄃
            cout<<CYAN<<"Available Ciphers:\n";
            cout<<CYAN<<"    CSR     - Developed by SAMI&REDA\n";
            cout<<CYAN<<"    Caesar  - Developed by Gaius Julius Caesar\n";
            cout<<CYAN<<"    Base64  - Developed by Internet Engineering Task Force (IETF)\n";
        } else if(command_str.rfind("echo", 0) == 0){ // Echo a.k.a print 🖨️
            istringstream iss(command_str);
            string cmd, text;
            iss >> cmd;
            getline(iss, text);
            text = text.substr(text.find_first_not_of(' '));
            cout << text << '\n';
        } else if(command_str.rfind("encrypt", 0) == 0){ // Encrypt 🔐
            istringstream iss(command_str);
            string cmd, cipher, key, text;
            iss >> cmd >> cipher >> key;
            getline(iss, text);
            text = text.substr(text.find_first_not_of(' '));

            if(!cipher.empty() && !key.empty() && !text.empty()){
                handleEncryption(cipher, text, key);
            } else{
                cout << "Usage: encrypt <cipher> <key> <text>" << '\n';
            }
        } else if(command_str.rfind("decrypt", 0) == 0){ // Decrypt 🔓
            istringstream iss(command_str);
            string cmd, cipher, key, text;
            iss >> cmd >> cipher >> key;
            getline(iss, text);
            text = text.substr(text.find_first_not_of(' '));

            if(!cipher.empty() && !key.empty() && !text.empty()){
                handleDecryption(cipher, text, key);
            } else{
                cout << "Usage: decrypt <cipher> <key> <text>" << '\n';
            }
        } else if(command_str.rfind("bruteforce", 0) == 0){ // Bruteforce 🛠️
            istringstream iss(command_str);
            string cmd, cipher, text;
            iss >> cmd >> cipher;
            getline(iss, text);
            text = text.substr(text.find_first_not_of(' '));

            if(!cipher.empty() && !text.empty()){
                if(cipher == "-caesar"){
                    caesarBruteForce(text);
                } else{
                    cout << "Unknown cipher for brute force: " << cipher << '\n';
                }
            } else{
                cout << "Usage: bruteforce <cipher> <text>" << '\n';
            }
        } else{
            cout<<"Unknown command: "<<command<<'\n';
        }
    }

    return 0;
}
