#include "NeuroPCH.h"

DEFINE_LOG_CATEGORY(NeuroPlugin);

class FNeuroPlugin : public INeuroPlugin {

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

IMPLEMENT_MODULE(FNeuroPlugin, NeuroPlugin);

void FNeuroPlugin::StartupModule() {
	UE_LOG(NeuroPlugin, Log, TEXT("Neuro: StartupModule()"));
}
void FNeuroPlugin::ShutdownModule() {
	UE_LOG(NeuroPlugin, Log, TEXT("Neuro: ShutdownModule()"));
}