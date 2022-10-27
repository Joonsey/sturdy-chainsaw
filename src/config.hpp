#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>

using namespace std;

void check_config(char* current_arg, bool &no_config);

class ConfigHandler
{
	public:
		ConfigHandler();
		string parse_settings_from_file(string);
		vector<string>* settings;
	private:
		string parse_line(string);
};

