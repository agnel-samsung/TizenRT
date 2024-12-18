#include <iostream>
#include <string>
#include <boost/format.hpp>

#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>

#include "subst.h"

int subst_main();

int unsubst_main(int argc, char *argv[]);

void usage();

int main(int argc, char *argv[]) {

	if(argc == 1)
		return subst_main();

	std::string arg1(argv[1]);
	if(arg1 == "--reverse")
		return unsubst_main(argc, argv);
	else if(arg1 == "--help") {
		usage();
		return 0;
	}
		
	usage();
	return 1;
}

void usage() {
		std::cout << R"(
Usage:

	subst [--reverse <string-table.json>]

)" << std::endl;
}

int subst_main() {

	using substitution::HashTable;
	using substitution::parse_grep;
	using substitution::subst_line;
	using substitution::escape_subst_str;

    std::string input;
    HashTable ht;
    while(std::getline(std::cin, input)) {
        std::string fname;
        int line_no;
        std::string line;

        if(parse_grep(input, fname, line_no, line)) {

            std::string subst_str = subst_line(line, ht);

            escape_subst_str(subst_str);
            std::string sed_cmd = (boost::format("sed -i '%ds/^.*$/%s/' %s")
				% line_no % subst_str.c_str() % fname.c_str()).str();

            if(system(sed_cmd.c_str()) != 0)
                std::cerr << sed_cmd << std::endl;

        }
        else {
            std::cerr << "parse_grep failed for:\n" << input << std::endl;
        }
    }

    std::cout << ht;
    return 0;
}

int unsubst_main(int argc, char *argv[]) {
	using substitution::unsubst_line;

	std::map<std::string, std::string> st;

	if(argc < 3) {
		usage();
		return 1;
	}

	std::string arg2(argv[2]);

    substitution::load_str_table(arg2.c_str(), st);

/*
	for(std::pair p : st) {
		std::cout << p.first << ": " << p.second << std::endl;
	}

	read a line of stdin
	use regex to parse out <> enclosed strings
	for each string
		lookup table, replace the string
	print resulting string

*/
    std::string input;
    while(std::getline(std::cin, input)) {
		std::cout << unsubst_line(input, st) << std::endl;
    }

	return 0;
}

