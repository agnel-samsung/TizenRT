#ifndef _SUBST_H_

#define _SUBST_H_

#ifdef __cplusplus

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include <map>

namespace substitution {

typedef std::map<std::string, std::string> TokenHash;

class HashTable {
    using ostream=std::ostream;

    int i;
    std::string omark;
    std::string cmark;
    TokenHash th;

    std::string next_hash();

public:
    HashTable();
    std::string hash(const std::string& s);

    friend ostream& operator<<(ostream& os, const HashTable& ht);
};

bool parse_grep(const std::string& s, std::string& fname, int& line_no, std::string& line);
std::string subst_line(const std::string& line, HashTable& ht);
void escape_subst_str(std::string& s, char delim = '/');

std::string unsubst_line(std::string s, const std::map<std::string,std::string>& st);
void load_str_table(const char *stjson, std::map<std::string, std::string>& st);

class Decoder {
	std::map<std::string, std::string> st;
    std::stringstream ss;
    std::ofstream os;

public:
    std::string decode(char c);
    std::string flush();

    Decoder(const char *stjson, const char *dbgname);
};

} 

extern "C" {
#endif

void *subst_load(const char *fname, const char *dbgname);
void subst_decode(void *handle, int c, void (*f)(int));
void subst_unload(void *handle);

#ifdef __cplusplus
}
#endif

#endif
