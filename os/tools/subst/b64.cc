
char digits[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"

std::string encode(int n) {
	std::string result;

	while(n > 0) {
		result = digits[n & 0x3f] + result;
		n >>= 6;
	}

	if(result.empty()) result += digits[0];


	return result;

}

int decode(std::string b64) {

return 0;	
	
}


