#include "NeuroPCH.h"


// TODO: Lots of boilerplate code here. Could make Execute a template function instead

TMap<FString, FString> NeuroLoginService::VerifyToken(FString token) {

	NeuroConnectionResponse response = connection->Execute(VerifyTokenCommand(token));

	if (response["result"].Equals(TEXT("0"))) // successfully sent the command or not
		return TMap<FString, FString>();

	return NeuroConnection::Deserialize(response["data"]);
}

TMap<FString, FString> NeuroLoginService::LoginUser(FString Username, FString Password) {
	NeuroConnectionResponse response = connection->Execute(LoginUserCommand(Username, Password));

	if (response["result"].Equals(TEXT("0"))) // successfully sent the command or not
		return TMap<FString, FString>();

	return NeuroConnection::Deserialize(response["data"]);
}

TMap<FString, FString> NeuroLoginService::RegisterUser(FString Username, FString Password) {

	TMap<FString, FString> response = connection->Execute(RegisterUserCommand(Username, Password));

	if (response["result"].Equals(TEXT("0"))) // successfully sent the command or not
		return TMap<FString, FString>();

	return NeuroConnection::Deserialize(response["data"]);
}
