// Fill out your copyright notice in the Description page of Project Settings.


#include "ClusterService.h"

void UClusterService::LogIn(FString Email, FString Password)
{
	FHttpRequestRef Request = FHttpModule::Get().CreateRequest();
	TSharedRef<FJsonObject> RequestObject = MakeShared<FJsonObject>();
	RequestObject->SetStringField("email", *Email);
	RequestObject->SetStringField("password", *Password);

	FString RequestBody;
	TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&RequestBody);
	FJsonSerializer::Serialize(RequestObject, Writer);

	UE_LOG(LogTemp, Display, TEXT("The Actor's email is %s"), *RequestBody);
	
	Request->SetURL("https://accounts.cluster.blackglobe.cz/api/login");
	Request->SetVerb("POST");
	Request->OnProcessRequestComplete().BindStatic(&UClusterService::OnLoginFinish);
	Request->SetContentAsString(RequestBody);
	Request->SetHeader("Content-Type", "application/json");
	Request->ProcessRequest();
}

void UClusterService::OnLoginFinish(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully)
{
	UE_LOG(LogTemp, Display, TEXT("The Actor's email is %s"), *Response->GetContentAsString());
}
