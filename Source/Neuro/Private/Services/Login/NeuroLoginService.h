#pragma once
#include "Services/NeuroService.h"

// TODO: Make UObject, so that methods can be exposed to blueprint
// TODO: Make async

// Login Service: Not Async.

class NeuroLoginService : public NeuroService {
	public:

	// Registers a user account
	TMap<FString, FString> RegisterUser(FString Username, FString Password);

	// Logs into a user account
	TMap<FString, FString> LoginUser(FString Username, FString Password);

	// Verifies a token with the server
	TMap<FString, FString> VerifyToken(FString token);

	private:

	FString UserToken;

	static const inline FString VerifyTokenCommand(FString Token) {
		return FString(TEXT("\x04\x01") + Token + FString(TEXT("\n")));
	}


	static const inline FString RegisterUserCommand(FString Username, FString Password) {
		return FString(TEXT("\x02\x01") + Username + TEXT("\x01") + Password + FString(TEXT("\n")));
	}

	static const inline FString LoginUserCommand(FString Username, FString Password) {
		return FString(TEXT("\x03\x01") + Username + TEXT("\x01") + Password + FString(TEXT("\n")));
	}
};

