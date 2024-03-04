#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <cstdint>

using namespace std;

uint32_t rotate_right(uint32_t line, int shift){
    return (line >> shift) | (line << (32 - shift));
}

uint32_t choose(uint32_t one, uint32_t two, uint32_t three){
    return ((one & two) ^ ((~one) & three));
}

uint32_t majority(uint32_t maj1, uint32_t maj2, uint32_t maj3){
    return ((maj1 & maj2) ^ (maj1 & maj3) ^ (maj2 & maj3));
}

uint32_t lower_sigma0(vector<uint32_t> schedule, int line1){
    return ((rotate_right(schedule[line1 - 15], 7)) ^ (rotate_right(schedule[line1 - 15], 18)) ^ (schedule[line1 - 15] >> 3));
}

uint32_t lower_sigma1(vector<uint32_t> schedule1, int line2){
    return ((rotate_right(schedule1[line2 - 2], 17)) ^ (rotate_right(schedule1[line2 - 2], 19)) ^ (schedule1[line2 - 2] >> 10));
}

uint32_t w16plus(vector<uint32_t> schedule2, int line3){
    return((schedule2[line3 - 16]) + (lower_sigma0(schedule2, line3)) + (schedule2[line3 - 7]) + lower_sigma1(schedule2, line3));
}

uint32_t upper_sigma1(uint32_t eee){
    return ((rotate_right(eee, 6)) ^ (rotate_right(eee, 11)) ^ (rotate_right(eee, 25)));
}

uint32_t upper_sigma0(uint32_t aaa){
    return ((rotate_right(aaa, 2)) ^ (rotate_right(aaa, 13)) ^ (rotate_right(aaa, 22)));
}

uint32_t temp1(uint32_t hhh, uint32_t s1, uint32_t chosen1, uint32_t chosen2, uint32_t chosen3, vector<uint32_t> k_, vector<uint32_t> w_, int counter){
    return (hhh + upper_sigma1(s1) + choose(chosen1, chosen2, chosen3) + k_[counter] + w_[counter]);
}

uint32_t temp2(uint32_t s0, uint32_t major1, uint32_t major2, uint32_t major3){
    return (upper_sigma0(s0) + majority(major1, major2, major3));
}


int main() {

    uint32_t h0 = 0x6a09e667;
    uint32_t h1 = 0xbb67ae85;
    uint32_t h2 = 0x3c6ef372;
    uint32_t h3 = 0xa54ff53a;
    uint32_t h4 = 0x510e527f;
    uint32_t h5 = 0x9b05688c;
    uint32_t h6 = 0x1f83d9ab;
    uint32_t h7 = 0x5be0cd19;

    vector <uint32_t> k{0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
   0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
   0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
   0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
   0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
   0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
   0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
   0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2};


   cout << "Please enter the string to be hashed. Multiple lines can be entered.\n";
   cout << "When finished press Enter, then Ctrl+Z on Windows or Ctrl+D on Mac/Linux,\n";
   cout << "and then press Enter again.\n\n";



   //Program initializes two strings. This is done to append
   // each line of input into the string since there can
   //be multiple lines.
   string original;
   string hashable;

   while (getline(cin, original)) {
        if (!hashable.empty()) {
            hashable += "\n";
        }
    hashable += original;
    }


    //Program initializes a vector holding an 8bit int for every character
    vector<uint8_t> hashablevec8;

        for (int i = 0; i < hashable.length(); i++){
            hashablevec8.push_back(hashable[i]);
    }

    //program adds binary 10000000 to the end of the vector to signify end of string
    hashablevec8.push_back(128);


    //program appends 0s until there are 64bits til the next multiple of 512
    while (((hashablevec8.size() * 8) + 64) % 512 != 0){
        hashablevec8.push_back(0);
    }

    //program appends 64 bit message length int into the 8 bit vector
    uint64_t messagelength = (hashable.size() * 8) ;

    for (int i = 7; i >= 0; --i) {
        hashablevec8.push_back((messagelength >> (i * 8)) & 255);
    }


    //program initializes and converts 8 bit vector to 32 bit vector for
    //main functions and for loops
    vector<uint32_t> hashablevec32;

    for (int i = 0; i < hashablevec8.size(); i += 4) {
        uint32_t temp32 = 0;
        for (int j = 0; j < 4; ++j) {
            temp32 <<= 8;
            temp32 |= hashablevec8[i + j];
        }
        hashablevec32.push_back(temp32);
    }

    int num_of_chunks = ((hashablevec32.size() * 32) / 512);

    //MAIN FOR LOOP
    for(int i = 0; i < num_of_chunks; i++){
        vector<uint32_t> w(64);
        for(int j = 0; j < 64; j++){
            if (j < 16){
                w[j] = hashablevec32[j + (i * 16)];
            } else {
               w[j] = w16plus(w, j);
            }
        }

       uint32_t a = h0;
       uint32_t b = h1;
       uint32_t c = h2;
       uint32_t d = h3;
       uint32_t e = h4;
       uint32_t f = h5;
       uint32_t g = h6;
       uint32_t h = h7;

       //COMPRESSION LOOP
       for(int iter = 0; iter < 64; iter++){
        uint32_t temporary1 = temp1(h, e, e, f, g, k, w, iter);
        uint32_t temporary2 = temp2(a, a, b, c);

        h = g;
        g = f;
        f = e;
        e = (d + temporary1);
        d = c;
        c = b;
        b = a;
        a = (temporary1 + temporary2);

       }
    h0 = (h0 + a);
    h1 = (h1 + b);
    h2 = (h2 + c);
    h3 = (h3 + d);
    h4 = (h4 + e);
    h5 = (h5 + f);
    h6 = (h6 + g);
    h7 = (h7 + h);

    }

    cout << "\n" << hex << h0 << h1 << h2 << h3 << h4 << h5 << h6 << h7 << "\n";

    return 0;

}

