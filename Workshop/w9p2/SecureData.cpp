/*
Patel Tirth 
Id: 172244212
*/
#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <functional>
#include <vector>
#include <future>
#include "SecureData.h"

namespace w9 {

    void converter(char* t, char key, int n, const Cryptor& c) {
        for (int i = 0; i < n; i++)
            t[i] = c(t[i], key);
    }

    SecureData::SecureData(const char* file, char key, std::ostream* pOfs) {
        ofs = pOfs;

        // open text file
        std::fstream input(file, std::ios::in);
        if (!input)
            throw std::string("\n***Failed to open file ") +
            std::string(file) + std::string(" ***\n");

        // copy from file into memory
        input.seekg(0, std::ios::end);
        nbytes = (int)input.tellg() + 1;

        text = new char[nbytes];

        input.seekg(std::ios::beg);
        int i = 0;
        input >> std::noskipws;
        while (input.good())
            input >> text[i++];
        text[nbytes - 1] = '\0';
        *ofs << "\n" << nbytes - 1 << " bytes copied from file "
            << file << " into memory (null byte added)\n";
        encoded = false;

        // encode using key
        code(key);
        *ofs << "Data encrypted in memory\n";
    }

    SecureData::~SecureData() {
        delete[] text; // Free the memory pointed by text
    }

    void SecureData::display(std::ostream& os) const {
        if (text && !encoded)
            os << text << std::endl;
        else if (encoded)
            throw std::string("\n***Data is encoded***\n");
        else
            throw std::string("\n***No data stored***\n");
    }

    void SecureData::code(char key) {
        int partitionSize = nbytes / 4;
        int remainingBytes = nbytes % 4;

        auto task1 = std::async(std::launch::async, [this, key, partitionSize]() {
            converter(text, key, partitionSize, Cryptor());
            });

        auto task2 = std::async(std::launch::async, [this, key, partitionSize]() {
            converter(text + partitionSize, key, partitionSize, Cryptor());
            });

        auto task3 = std::async(std::launch::async, [this, key, partitionSize]() {
            converter(text + 2 * partitionSize, key, partitionSize, Cryptor());
            });

        auto task4 = std::async(std::launch::async, [this, key, partitionSize, remainingBytes]() {
            converter(text + 3 * partitionSize, key, partitionSize + remainingBytes, Cryptor());
            });

        task1.wait();
        task2.wait();
        task3.wait();
        task4.wait();

        encoded = !encoded;
    }

    void SecureData::backup(const char* file) {
        if (!text)
            throw std::string("\n***No data stored***\n");
        else if (!encoded)
            throw std::string("\n***Data is not encoded***\n");
        else
        {
            std::ofstream fs;
            fs.open(file, std::ios::out | std::ios::binary);

            fs.write(text, nbytes);

            fs.close();
        }
    }

    void SecureData::restore(const char* file, char key) {
        if (text) {
            delete[] text;
        }

        std::ifstream is;
        is.open(file, std::ios::in | std::ios::binary);

        text = new char[nbytes + 1];

        is.read(text, nbytes);
        *ofs << "\n" << nbytes << " bytes copied from binary file "
            << file << " into memory.\n";

        encoded = true;

        // decode using key
        code(key);

        *ofs << "Data decrypted in memory\n\n";
    }

    std::ostream& operator<<(std::ostream& os, const SecureData& sd) {
        sd.display(os);
        return os;
    }
}
