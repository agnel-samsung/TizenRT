#include "subst.h"

#include <boost/regex.hpp>
#include <boost/json.hpp>
#include <boost/json/src.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>

namespace substitution {

using jvalue = boost::json::value;
using jobject = boost::json::object;

std::string encode(int n);

std::string HashTable::next_hash() {
	return (std::stringstream() << omark << encode(i++) << cmark).str();
}

HashTable::HashTable() : i(0), omark("<"), cmark(">") {}
std::string HashTable::hash(const std::string& s) {
	auto token_it = th.find(s);

	std::string token_hash;
	if(token_it == th.end()) {
		token_hash = next_hash();
		th.insert(std::pair<std::string, std::string>(s, token_hash));
	}
	else {
		token_hash = token_it->second;
	}

	return token_hash;
	
}

std::ostream& operator<<(std::ostream& os, const HashTable& ht) {
	boost::json::object jo;
    for(auto pair : ht.th) {
        // os << pair.first << ", " << pair.second << std::endl;
		jo[ pair.second ] = pair.first;
    }

	os << jo << std::endl;
    return os;
}


//  s1: a single fmt string
//  len: ??
std::string subst(const std::string& s1, HashTable& ht) {
/*
	char *p = s;
	len = 0;

	while(*p != '%') {
		if(*p == '\0') {
			return p;
		}

		++p;
	}

Each conversion specification is introduced by the character %, and ends with a conversion specifier. In between there  may  be  (in this  order)  zero or more flags, an optional minimum field width, an optional precision and an optional length modifier.

*/

    // static const boost::regex e1(R"(%[+-]{0,1}[0-9]*\.{0,1}[0-9]*[fsdxcup][l]{0,1})");
    static const boost::regex e1(R"(%[-#0 +'I]?[*0-9]*(\.[*0-9]*)?(hh|[hlqLjzt]|ll)?[diouxXeEfFgGaAcsCSpnm])");
    std::string result;
	boost::sregex_iterator srit(s1.begin(), s1.end(), e1);
	boost::sregex_iterator itend;
	boost::sregex_iterator itlast;
    size_t last_tok = 1;

	while(srit != itend) {
		auto itobj = *srit;
        auto pos1 = std::distance(s1.begin(), itobj[0].first);
        auto count1 = std::distance(itobj[0].first, itobj[0].second);

        std::string token = s1.substr(last_tok, pos1 - last_tok);

        std::string hash = ht.hash(token);

        if(hash.length() < token.length())
            result += hash;
        else
            result += token;
        result += itobj[0].str();
        last_tok = std::distance(s1.begin(), itobj[0].second);
        //std::cout << "[" << token << "] (" << hash << ")" << std::endl;
		//std::cout << "  " << pos1 << "," << count1 << " : " << itobj[0] << std::endl;
        itlast = srit;
		srit++;
	}

    if(itlast != itend) {
        auto itobj = *itlast;
        auto pos1 = std::distance(s1.begin(), s1.end() - 1);
        auto count1 = std::distance(itobj[0].first, itobj[0].second);

        std::string token = s1.substr(last_tok, pos1 - last_tok);
        std::string hash = ht.hash(token);
        if(hash.length() < token.length())
            result += hash;
        else
            result += token;
    }

    //last_tok = std::distance(s1.begin(), itobj[0].second);
    //std::cout << "[" << token << "] (" << hash << ")" << std::endl;
    //std::cout << "  " << pos1 << "," << count1 << " : " << itobj[0] << std::endl;

/*

find %
if next char is %, skip both and reset search

*/

    return '\"' + result + '\"';

}

std::string subst_line(const std::string& line, HashTable& ht) {

	// static const boost::regex e(R"("[^"]*%[^"]*[^\]")");
	static const boost::regex e(R"("((\\")|[^"])*?%((\\")|[^"])*?")");


	std::string input = line;

	// std::cout << input << std::endl;

	boost::sregex_iterator srit(input.begin(), input.end(), e);
	boost::sregex_iterator itend;

    //  for each "...%..." sequence
    //      seq = /* the sequence */
    //      repl = subst(seq, lookup) 
    //      input.replace(curr_location, seq_length, repl)
    //      next_location = curr_location + seq_length
    //      

    size_t tpos = 0;
    std::string result;
	while(srit != itend) {
		auto itobj = *srit;
		//std::cout << itobj[0] << std::endl;
        int len;
        std::string hashed_str = subst(itobj[0].str().c_str(), ht);
        //std::cout << hashed_str << std::endl;

        size_t match_pos = std::distance(input.cbegin(), itobj[0].first);
        size_t match_len = std::distance(itobj[0].first, itobj[0].second);
        std::string token = input.substr(tpos, match_pos - tpos);
        result += token;
        result += hashed_str;
        tpos = std::distance(input.cbegin(), itobj[0].second);

		srit++;
	}

    result += input.substr(tpos);

	return result;
}

// parse grep output of the form:
//   <file path>:<line no>:<matching line>
//
// example:
//  tools/cmpconfig.c:116:                          printf("file2: %s=%s\n\n", list2->var, varval2);

bool parse_grep(const std::string& s, std::string& fname, int& line_no, std::string& line) {
    int icolon1 = -1, icolon2 = -1;

    auto slen = s.length();
    const char *cstr = s.c_str();
    int i = 0;
    for(; i < slen; ++i) {
        if(cstr[i] == ':'){ icolon1 = i++; break; }
    }

    if(icolon1 == -1) return false;

    for(; i < slen; ++i) {
        if(cstr[i] == ':'){ icolon2 = i; break; }
    }

    if(icolon1 < 1) return false;
    if(icolon2 - icolon1 < 2) return false;
    fname = s.substr(0, icolon1);
    line_no = std::stoi(s.substr(icolon1 + 1, icolon2 - icolon1 - 1));
    line = s.substr(icolon2 + 1);

    return true;
}

void escape_subst_str(std::string& s, char delim) {
    std::stringstream ssout;
    auto slen = s.length();
    const char *ptr_s = s.c_str();
    for(decltype(slen) i = 0; i < slen; ++i) {
        //  & is escaped as it has special meaning to sed
        if(ptr_s[i] == delim || ptr_s[i] == '&' || ptr_s[i] == '\\')
            ssout << '\\';
        //  bash does not have an escape for single quote within single quotes
        //  i.e. 'Bob\'s bar' will not work
        //  But we can close the opening single quote, add an unquoted but
        //  escaped singled quote (\') and re-open the single quote
        //  i.e. 'Bob'\''s bar' will work
        else if(ptr_s[i] == '\'')
            ssout << "'\\'";
        ssout << ptr_s[i];
    }

    s = ssout.str();
}


const char digits[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

std::string encode(int n) {
	std::string result;

	while(n > 0) {
		result = digits[n & 0x3f] + result;
		n >>= 6;
	}

	if(result.empty()) result += digits[0];


	return result;

}

std::string unsubst_line(std::string s, const std::map<std::string,std::string>& st) {
	std::string result;

	static const boost::regex e(R"(<[^>]*>)");

	boost::sregex_iterator srit(s.begin(), s.end(), e);
	boost::sregex_iterator itend;
	boost::sregex_iterator itlast;
    size_t last_tok = 0;

	while(srit != itend) {
		auto itobj = *srit;
        auto pos1 = std::distance(s.cbegin(), itobj[0].first);
        auto count1 = std::distance(itobj[0].first, itobj[0].second);

        std::string token = s.substr(last_tok, pos1 - last_tok);

		std::string s1 = itobj.str();
		std::map<std::string, std::string>::const_iterator it = st.find(s1);
		if(it != st.end())
        	result += token + it->second;
		else
			result += token + s1;

        last_tok = std::distance(s.cbegin(), itobj[0].second);
        //std::cout << "[" << token << "] (" << hash << ")" << std::endl;
		//std::cout << "  " << pos1 << "," << count1 << " : " << itobj[0] << std::endl;
        itlast = srit;
		srit++;
		
	}
	
    if(itlast != itend) {
        auto itobj = *itlast;
        auto pos1 = std::distance(s.begin(), s.end());
        auto count1 = std::distance(itobj[0].first, itobj[0].second);

        std::string token = s.substr(last_tok, pos1 - last_tok);
        result += token;
    }

    if(result.empty()) return s;
	return result;
}

int rex_main(int argc, char *argv[]) {
	if(argc < 3) return 1;

	std::string srex(argv[1]);
	std::string line(argv[2]);

	boost::regex e(srex);
	std::cout << "regex: " << srex << "\n";
	std::cout << "line: " << line << std::endl;
	
	boost::sregex_iterator srit(line.begin(), line.end(), e);
	boost::sregex_iterator itend;

    size_t tpos = 0;
    std::string result;
	while(srit != itend) {
		std::cout << srit->str() << std::endl;
		srit++;
	}

	return 0;
}

void load_str_table(const char *stjson, std::map<std::string, std::string>& st) {
    namespace pt = boost::property_tree;
    pt::ptree root;

    pt::read_json(stjson, root);

    for (pt::ptree::value_type &entry : root)
    {
        std::string name = entry.first;
        std::string value = entry.second.data();
        st.insert(std::make_pair(name, value));
    }
}

Decoder::Decoder(const char *stjson, const char *dbgname) : os(dbgname) {
    load_str_table(stjson, st);
}

std::string Decoder::flush() {
    std::string s = ss.str();
    ss.str(std::string());

    std::string result = unsubst_line(s, st);

    os << result;
    os.flush();

    return result;
}
    
std::string Decoder::decode(char c) {

    ss << c;
    if(c == '\r') {
        return flush();
    }

    return std::string();
}

}

extern "C" void *subst_load(const char *fname, const char *dbgname) {
    return static_cast<void *>(new substitution::Decoder(fname, dbgname));
}

extern "C" void subst_decode(void *handle, int c, void (*f)(int)) {
    substitution::Decoder *pd = static_cast<substitution::Decoder*>(handle);
    std::string s = pd->decode((char)c);
    const char *ptr = s.c_str();
    if(ptr[0]) {
      while(*ptr){
        f((int)*ptr);
        ++ptr;
      }
    }
}

extern "C" void subst_unload(void *handle) {
    substitution::Decoder *pd = static_cast<substitution::Decoder*>(handle);
    pd->flush();
    delete pd;
}

