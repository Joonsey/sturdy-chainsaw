#pragma once
class Result {
	public:
		Result();
		int get_all_runs();
		int get_fails();
		int get_successes();
		void add_fail();
		void add_success();
	private:
		int success;
		int fails;
		int runs;
};
