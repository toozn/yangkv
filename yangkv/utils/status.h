#include <algorithm>
#include <string>
#include "env.h"
#pragma once

class Status {
public:
	Status() {
		msg_ = "";
	}

	Status(std::string msg) {
		msg_ = msg;
	} 

	static Status OK() {
		return Status();
	}

	static Status NotFound() {
		return Status(kNotFound);
	}

	static Status Error() {
		return Status(kError);
	}

	bool ok() {
		return msg_ == "";
	}
	bool isNotFound() {
		return msg_ == kNotFound;
	}
	bool isError() {
		return msg_ == kError;
	}
private:
	std::string msg_;
};
