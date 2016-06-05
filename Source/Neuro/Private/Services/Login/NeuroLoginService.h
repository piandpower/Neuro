#pragma once
#include "Services/NeuroService.h"

// Login Service: Not Async.

class NeuroLoginService : public NeuroService {
	public:


	private:

	static const inline FString VerifyTokenCommand(FString Token) {
		return FString(TEXT("\x04\x01") + Token + FString(TEXT("\n")));
	}

	static const inline FString GetUsernameCommand(FString Token) {
		return FString(TEXT("\x05\x01") + Token + FString(TEXT("\n")));
	}

	static const inline FString RegisterUserCommand(FString Username, FString Password) {
		return FString(TEXT("\x02\x01") + Username + TEXT("\x01") + Password + FString(TEXT("\n")));
	}

	static const inline FString LoginUserCommand(FString Username, FString Password) {
		return FString(TEXT("\x03\x01") + Username + TEXT("\x01") + Password + FString(TEXT("\n")));
	}
};

