#include "config.hpp"
#include <iostream>

ConfigHandler::ConfigHandler()
{
	this->settings = new vector<string>();
}

void check_config(char* current_arg, bool &no_config)
{
	if (!no_config) {
		no_config = !strcmp(current_arg, "--no-config");
	}
}

string ConfigHandler::parse_line(string line_buffer)
{
	string value;
	bool found;
	for ( string::iterator it=line_buffer.begin(); it!=line_buffer.end(); it++)
	{
		if (found)
		{
			value.append(it.base());
			break;
		}
		if (*it == '='){
			found = true;
		}
	}
	//cout << "value:" << value << endl;
	return value;
}

string ConfigHandler::parse_settings_from_file(string file)
{
	// todo
	// value array with all values
	// possibly hashmap
	string buffer;
	string value;
	ifstream config_file(file);
	while(getline(config_file, buffer))
	{
		value = parse_line(buffer);
	}
	config_file.close();
	this->settings->push_back(value);
	return value;
}

