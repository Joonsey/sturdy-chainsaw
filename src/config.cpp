#include "config.hpp"

static string parse_line(string line_buffer)
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

string parse_settings_from_file(string file)
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
	return value;
}

