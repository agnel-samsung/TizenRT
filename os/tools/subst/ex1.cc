#include <string>
#include <cstdlib>
#include <iostream>
#include <boost/regex.hpp>

using namespace std;

std::string subst_line(const std::string& line /*, HashTable& ht*/) {

	static const boost::regex e(R"("[^"]*%[^"]*")");

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
		std::cout << itobj[0] << std::endl;
        int len;
        //std::string hashed_str = subst(itobj[0].str().c_str(), ht);
        //std::cout << hashed_str << std::endl;

/*
        size_t match_pos = std::distance(input.cbegin(), itobj[0].first);
        size_t match_len = std::distance(itobj[0].first, itobj[0].second);
        std::string token = input.substr(tpos, match_pos - tpos);
        result += token;
        result += hashed_str;
        tpos = std::distance(input.cbegin(), itobj[0].second);
*/
		srit++;
	}

    result += input.substr(tpos);

	return result;
}

int main() {
    std::string input;
    std::getline(cin, input);
    subst_line(input);
    return 0;
}

int main2(int argc, char *argv[]) {
    if(argc < 4) {
        cout << "Usage:\n\n\tex1 string pos count" << std::endl;
        return 1;
    }

    string s = argv[1];
    size_t pos = std::atoi(argv[2]);
    size_t count = std::atoi(argv[3]);

    cout << "s: " << s << endl;
    cout << "pos: " << pos << endl;
    cout << "count: " << count << endl;
    cout << "substr: " << s.substr(pos, count) << endl;
    return 0;
}

