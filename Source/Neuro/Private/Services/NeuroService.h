#pragma once
#include "NeuroPCH.h"
#include <memory>

class NeuroService {
	public:
	NeuroService(FString address, int32 port) {
		connection = std::make_unique<NeuroConnection>(address, port);
	};

	~NeuroService() {
		Disconnect();
		connection.reset();
	};

	void inline Connect() {
		connection->Connect();
	};

	bool inline IsConnected() {
		return connection->IsConnected();
	};

	void inline Disconnect() {
		connection->Close();
	};

	protected:
	std::unique_ptr<NeuroConnection> connection;

};

