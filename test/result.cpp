#include "result.hpp"
void Result::add_success()
{
	this->success += 1;
	this->runs += 1;

};

void Result::add_fail()
{
	this->fails += 1;
	this->runs += 1;
};

int Result::get_all_runs() {
	return this->runs;
};
int Result::get_successes() {
	return this->success;
};
int Result::get_fails() {
	return this->fails;
};

Result::Result() {
	this->success = 0;
	this->fails = 0;
	this->runs = 0;
}
