#pragma once
#include "Services/NeuroService.h"

// TODO: Make UObject, so that methods can be exposed to blueprint
// TODO: Make async

// World Service: Not Async.

class NeuroWorldService : public NeuroService {
	public:

	// Finds a server hosting a particular map by map name
	TArray<FString> FindMap(FString MapName);

	// Register this gameserver with the World Server
	void RegisterServer(UWorld *world);

	// Unregister this gameserver with the World Server
	void UnregisterServer();

	private:
	static const inline FString RegisterMapCommand(FString IP, FString Port, FString MapName, FString MapGuid) {
		return FString(TEXT("\x02\x01") + IP + TEXT("\x01") + Port + TEXT("\x01") + MapName + TEXT("\x01") + MapGuid + TEXT("\n"));
	}

	static const inline FString UnregisterMapCommand() {
		return FString(TEXT("\x03\x01") + FString(TEXT("\n")));
	}


	static const inline FString FindMapCommand(FString Map) {
		return FString(TEXT("\x04\x01") + Map + FString(TEXT("\n")));
	}
};

