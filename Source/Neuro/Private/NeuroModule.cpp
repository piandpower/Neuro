#include "NeuroPCH.h"

DEFINE_LOG_CATEGORY(Neuro);

class FNeuro : public INeuro {

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

IMPLEMENT_MODULE(FNeuro, Neuro);

void FNeuro::StartupModule() {
	UE_LOG(Neuro, Log, TEXT("StartupModule()"));
}
void FNeuro::ShutdownModule() {
	UE_LOG(Neuro, Log, TEXT("ShutdownModule()"));
}