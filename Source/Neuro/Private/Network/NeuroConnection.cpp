#include "NeuroPCH.h"

/* Connect */
bool NeuroConnection::Connect() {
	check(_socket);
	FIPv4Address ip;
	FIPv4Address::Parse(_address, ip);
	TSharedRef<FInternetAddr> addr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	addr->SetIp(ip.Value);
	addr->SetPort(_port);
	return _socket->Connect(*addr);
}

/* Close the socket. */
void NeuroConnection::Close() {
	check(_socket);
	_socket->Close();
}

/* Get socket status. */
bool NeuroConnection::IsConnected() {
	check(_socket);
	return (_socket->GetConnectionState() == ESocketConnectionState::SCS_Connected);
}

NeuroConnectionResponse NeuroConnection::Execute(FString command) {
	TMap<FString, FString> Result;

	_send(command);
	uint32 DataSize = 0;
	while (!_socket->HasPendingData(DataSize) && IsConnected()) {
		FPlatformProcess::Sleep(0.01f);
	}

	if (!IsConnected()) {
		Result.Add("result", "0");
		return Result;
	}

	FString Request;
	if (_receive(DataSize, Request)) {
		Result.Add("result", "1");
		Result.Add("data", Request.LeftChop(2));  // Removes trailing \r\n
		return Result;
	}

	Result.Add("result", "0");
	return Result;
}

/*
*
* Private
*
*/

/* Raw socket send */
bool NeuroConnection::_send(const FString & data) {
	check(_socket);

	if (!IsConnected()) return false;

	int32 BytesSent = 0;
	return _socket->Send((uint8*)TCHAR_TO_UTF8(*data), data.Len(), BytesSent);
}

/* Raw socket receive */
bool NeuroConnection::_receive(uint32 DataSize, FString & buffer) {
	check(_socket);

	if (!IsConnected()) return false;

	FArrayReaderPtr Datagram = MakeShareable(new FArrayReader(true));
	Datagram->SetNumUninitialized(FMath::Min(DataSize, 65507u));

	int32 BytesRead = 0;
	if (_socket->Recv(Datagram->GetData(), Datagram->Num(), BytesRead)) {
		char* Data = (char*)Datagram->GetData();
		Data[BytesRead] = '\0';
		buffer = UTF8_TO_TCHAR(Data);
		return true;
	}

	return false;
}