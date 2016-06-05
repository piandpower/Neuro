#include "NeuroPCH.h"

UNeuro::UNeuro() {
	UE_LOG(Neuro, Log, TEXT("Init"));

	LoadConfig(UNeuro::StaticClass());
	UE_LOG(Neuro, Log, TEXT("Port: %d"), LoginServerPort);

}

void UNeuro::ConnectToLoginServer() {
	UE_LOG(Neuro, Log, TEXT("ConnectToLoginServer"));
}