// Workshop 9 - Multi-Threading
// SecureData.cpp

//
//  Name: hansol CHo
//  Student ID: 103608170
//  Seneca Email: hscho5@myseneca.ca
//  Date of completion: November 27, 2018
//

#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <functional>
#include "SecureData.h"

using namespace std;

namespace w9 {
    
    void converter(char* t, char key, int n, const Cryptor& c) {
        for (int i = 0; i < n; i++)
            t[i] = c(t[i], key);
    }
    
    SecureData::SecureData(const char* file, char key, ostream* pOfs)
    {
        ofs = pOfs;
        
        // open text file
        fstream input(file, std::ios::in);
        if (!input)
            throw string("\n***Failed to open file ") +
            string(file) + string(" ***\n");
        
        // copy from file into memory
        input.seekg(0, std::ios::end);
        nbytes = (int)input.tellg() + 1;
        
        text = new char[nbytes];
        
        input.seekg(ios::beg);
        int i = 0;
        input >> noskipws;
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
        delete[] text;
    }
    
    void SecureData::display(std::ostream& os) const {
        if (text && !encoded)
            os << text << std::endl;
        else if (encoded)
            throw std::string("\n***Data is encoded***\n");
        else
            throw std::string("\n***No data stored***\n");
    }
    
    void SecureData::code(char key)
    {
        // TODO: rewrite this function to use at least two threads
        //         to encrypt/decrypt the text.
        //converter(text, key, nbytes, Cryptor());
        
        int size1 = nbytes/3;
        int size2 = nbytes - 2*size1;
        
        auto t1 = bind ( converter, text, key , size1, Cryptor() );
        auto t2 = bind ( converter, &text[size1-1], key , size1, Cryptor() );
        auto t3 = bind ( converter, &text[2*size1-1], key , size2, Cryptor() );
        
        std::thread task1 ( t1 );
        std::thread task2 ( t2 );
        std::thread task3 ( t3 );
        
        task1.join();
        task2.join();
        task3.join();
        
        encoded = !encoded;
    }
    
    void SecureData::backup(const char* file) {
        if (!text)
            throw std::string("\n***No data stored***\n");
        else if (!encoded)
            throw std::string("\n***Data is not encoded***\n");
        else
        {
            // TODO: open a binary file for writing
            fstream output(file, std::ios::out|std::ios::binary);
            
            // TODO: write data into the binary file
            //         and close the file
            output.write(text, nbytes-1);
            output.close();
        }
    }
    
    void SecureData::restore(const char* file, char key) {
        // TODO: open binary file for reading
        fstream input(file, std::ios::in|std::ios::binary);
        
        // TODO: - allocate memory here for the file content
        delete [] text;
        text = nullptr;
        input.seekg(0, std::ios::end);
        nbytes = (int)input.tellg()+1;
        text = new char[nbytes];
        input.clear();
        
        // TODO: - read the content of the binary file
        input.seekg(std::ios::beg);
        input.read(text, nbytes-1);
        
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

