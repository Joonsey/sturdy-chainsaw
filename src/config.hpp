#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class ConfigHandler
{
	public:
		string parse_settings_from_file(string);
	private:
		string parse_line(string);
};

