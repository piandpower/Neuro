#pragma once
#include <memory>
#include "Neuro.generated.h"

// TODO: Remove "ConnectToLoginServer()"
// TODO: Add UPROPERTY() of LoginService, and WorldService

UENUM(BlueprintType)
enum class ENeuroConnectionMessage : uint8 {
	NEURO_CONNECTION_FAILED UMETA(DisplayName = "Failed"),
	NEURO_CONNECTION_SUCCEEDED UMETA(DisplayName = "Success")
};


/**
* Networking system
*/
UCLASS(Config=Game)
class NEURO_API UNeuro : public UObject {
	GENERATED_BODY()

	public:
	UNeuro();
	UFUNCTION(BlueprintCallable, Category = "Networking")
	void ConnectToLoginServer();

	UPROPERTY(Config)
	FString LoginServerAddress;

	UPROPERTY(Config)
	int32 LoginServerPort;

	UPROPERTY(Config)
	FString WorldServerAddress;

	UPROPERTY(Config)
	int32 WorldServerPort;
};
