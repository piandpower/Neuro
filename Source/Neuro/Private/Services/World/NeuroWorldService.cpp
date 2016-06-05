#include "NeuroPCH.h"

TArray<FString> NeuroWorldService::FindMap(FString MapName) {
	if (!NeuroService::IsConnected()) {
		UE_LOG(Neuro, Log, TEXT("FindMap: Not Connected to World Server."));
		return TArray<FString>();
	}

	NeuroConnectionResponse response = connection->Execute(FindMapCommand(MapName));


	return TArray<FString>();
}

// Register this gameserver with the World Server
void NeuroWorldService::RegisterServer(UWorld *world) {
	if (!NeuroService::IsConnected()) {
		UE_LOG(Neuro, Log, TEXT("RegisterServer: Not Connected to World Server."));
		return;
	}

	// Server params
	FString MapPackageLongName = world->GetName();
	FString MapPackageShortName = FPackageName::GetShortName(MapPackageLongName);
	FString ip, port, guid;
	guid = FString::FromInt(world->GetUniqueID());
	if (FParse::Value(FCommandLine::Get(), TEXT("port"), port)) {
		port = port.Replace(TEXT("="), TEXT(""));
	} else {
		port = FString("7777");
	}

	if (FParse::Value(FCommandLine::Get(), TEXT("listenaddress"), ip)) {
		ip = ip.Replace(TEXT("="), TEXT(""));
	} else {
		ip = FString("127.0.0.1");
	}

	NeuroConnectionResponse response = connection->Execute(
		RegisterMapCommand(ip, port, MapPackageShortName, guid));
}

// Unregister this gameserver with the World Server
void NeuroWorldService::UnregisterServer() {
	if (!NeuroService::IsConnected()) {
		UE_LOG(Neuro, Log, TEXT("ZeWorldService::UnregisterServer: Not Connected to World Server."));
		return;
	}

	NeuroConnectionResponse response = connection->Execute(UnregisterMapCommand());
}
