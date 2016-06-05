#pragma once

#include <functional>

/**
* Network Connection: Not Async
*/

typedef TMap<FString, FString> NeuroConnectionResponse;

class NeuroConnection {
	public:
	NeuroConnection(FString address, int32 port) :
		_address(address),
		_port(port) {

		_socket = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->
			CreateSocket(NAME_Stream, TEXT("default"), false);
	};

	~NeuroConnection() {
		Close();
		delete _socket;
		_socket = NULL;
		_address = NULL;
		_port = NULL;
	};

	bool Connect();
	void Close();
	bool IsConnected();

	NeuroConnectionResponse Execute(FString command);

	static inline TMap<FString, FString> Deserialize(FString data) {

		TMap<FString, FString> fields = TMap<FString, FString>();

		FString work = data;
		FString left;
		FString right;
		FString key;
		FString value;

		while (work.Split(TEXT("\x01"), &left, &right, ESearchCase::IgnoreCase, ESearchDir::FromStart)) {

			TKeyValuePair<FString, FString> kv = GetKV(left);
			fields.Add(kv.Key, kv.Value);

			work = right;
		}

		TKeyValuePair<FString, FString> kv = GetKV(work);
		fields.Add(kv.Key, kv.Value);

		return fields;
	}

	static inline TKeyValuePair<FString, FString> GetKV(FString data) {
		FString key;
		FString value;

		data.Split(TEXT("\x02"), &key, &value, ESearchCase::IgnoreCase, ESearchDir::FromStart);

		return TKeyValuePair<FString, FString>(key, value);
	}

	static inline FString Serialize(TArray<FString> data) {

		return FString("");
	}

	private:
	bool _send(const FString& data);
	bool _receive(uint32 DataSize, FString &buffer);

	FString _address;
	int32 _port;
	FSocket *_socket;
	std::function<void(FString)> _receive_callback;
};