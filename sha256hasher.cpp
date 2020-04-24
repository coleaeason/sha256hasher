#include <algorithm>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <list>
#include <map>
#include <mutex>
#include <openssl/sha.h>
#include <sstream>
#include <string>
#include <thread>
using namespace std;

// Hash and return in hex
string sha256InHex(const string str)
{
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.size());
    SHA256_Final(hash, &sha256);
    stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << hex << setw(2) << setfill('0') << (int) hash[i];
    }
    return ss.str();
}

// Helper function cast a string to uppercase, used for normalizing output.
string toUpper(string value)
{
    transform(value.begin(), value.end(), value.begin(), ::toupper);
    return value;
}

int main(int argc, char* argv[])
{
    uint64_t threads = 1;
    string file;

    // Must supply a file name
    if (argc < 3) {
        cerr << "Usage:" << endl;
        cerr << "./sha256hasher -file <filename> -threads <threads to use>" << endl;
        cerr << "Example: ./sha256hasher -file text.file -threads 8" << endl;
        return 1;
    }

    for (size_t i = 1; i < argc; i++) {
        if (argv[i] == "-file"s) {
            file = argv[i + 1];
        }

        // Check for threads count
        if (argv[i] == "-threads"s) {
            threads = stoi(argv[i + 1]);
        }
    }

    list<thread> threadList;
    mutex m_in;
    mutex m_out;
    ifstream is;
    is.open(file, ios::in);

    // Check for failure opening a given file.
    if (is.fail()) {
        cerr << "Couldn't open file " << file << endl;
        return 1;
    }

    // Start our threads up
    for (size_t i = 0; i < threads; i++) {
        threadList.emplace_back([&, i]() {
            while (true) {
                string temp;

                // Don't read over each other.
                {
                    lock_guard<decltype(m_in)> lock(m_in);

                    // Get a line for hashing.
                    getline(is, temp);

                    // If the eof bit gets set we're at the end of file.
                    if (is.eof()) {
                        return;
                    }
                }

                // Don't write over each other.
                {
                    lock_guard<decltype(m_out)> lock(m_out);
                    cout << toUpper(sha256InHex(temp)) << endl;
                }
            }
        });
    }

    // Join all of our threads so we can exit.
    int threadID = 0;
    for (auto& thread : threadList) {
        threadID++;
        thread.join();
    }

    return 0;
}
