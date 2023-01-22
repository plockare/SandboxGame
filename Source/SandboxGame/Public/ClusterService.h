// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Http.h"
#include "ClusterService.generated.h"

/**
 * 
 */
UCLASS()
class SANDBOXGAME_API UClusterService : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable, Category="Cluster service")
	static void LogIn(FString Email, FString Password);

	static void OnLoginFinish(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully);
};
