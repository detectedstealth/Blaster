// Copyright Warply Designed


#include "HUD/OverHeadWidget.h"

#include "Components/TextBlock.h"
#include "GameFramework/PlayerState.h"

void UOverHeadWidget::SetDisplayText(FString TextToDisplay)
{
	if (DisplayText)
	{
		DisplayText->SetText(FText::FromString(TextToDisplay));
	}
}

void UOverHeadWidget::ShowPlayerNetRole(APawn* InPawn)
{
	ENetRole RemoteRole = InPawn->GetRemoteRole();
	FString Role;

	switch (RemoteRole)
	{
	case ROLE_Authority:
		Role = FString("Authority");
		break;

	case ROLE_AutonomousProxy:
		Role = FString("Autonomous Proxy");
		break;

	case ROLE_SimulatedProxy:
		Role = FString("Simulated Proxy");
		break;
		
	case ROLE_None:
		Role = FString("None");
		break;
	default:
		Role = FString("None");
		break;
	}
	FString PlayerName = "NULL";
	if (InPawn->GetPlayerState())
	{
		PlayerName = InPawn->GetPlayerState()->GetPlayerName();
	}
	FString RemoteRoleString = FString::Printf(TEXT("%s Remote Role: %s"), *PlayerName, *Role);
	SetDisplayText(RemoteRoleString);
}

void UOverHeadWidget::NativeDestruct()
{
	RemoveFromParent();
	Super::NativeDestruct();
}
