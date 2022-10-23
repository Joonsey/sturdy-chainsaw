#include "tester.hpp"

Tester::Tester() {
	this->results = new Result();
};

void Tester::is_equal(bool condition, std::string error_msg = "")
{
	if (condition) this->results->add_success();
	else {
		std::cout << error_msg << std::endl;
		this->results->add_fail();
	}
};

std::string Tester::format_synapsis(int runs, int fails, int successes)
{
	std::string color_prefix;
	if (fails) color_prefix = "\033[1;31m"; // red
	else color_prefix = "\033[1;32m";		// green
	return color_prefix + "failed runs: " + std::to_string(fails) +
		", total runs: " + std::to_string(runs) +
		", successful runs " + std::to_string(successes) + "\033[m";
};

void Tester::conclude(){
	int return_code = 0;
	int runs = this->results->get_all_runs();
	int fails = this->results->get_fails();
	int successes = this->results->get_successes();

	std::string synapsis_message = this->format_synapsis(runs, fails, successes);
	std::cout << synapsis_message << std::endl;

	if (fails) return_code = 1;
	exit(return_code);
};

