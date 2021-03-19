// Fill out your copyright notice in the Description page of Project Settings.

#define printF(text, fstring) if(GEngine) GEngine->AddOnScreenDebugMessage(-1, 5), FColour::Green, Fstring::Printf(TEXT(text), fstring));

#include "nextLevelTrigger.h"
#include "DrawDebugHelpers.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

AnextLevelTrigger::AnextLevelTrigger()
{
	OnActorBeginOverlap.AddDynamic(this, & AnextLevelTrigger::OnOverlapBegin);
	OnActorEndOverlap.AddDynamic(this, &AnextLevelTrigger::OnOverlapEnd);
}


void AnextLevelTrigger::BeginPlay()
{
	Super::BeginPlay();

	//DrawDebugBox(GetWorld(), GetActorLocation(), GetComponentsBoundingBox().GetExtent(), FColor::Green.WithAlpha(0), true, -1, 0, 5);

	
}

void AnextLevelTrigger::OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor)
{
	if (OtherActor && (OtherActor != this) && OtherActor == SpecificActor)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, TEXT("Overlap Begin"));

		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, FString::Printf(TEXT("CONGRATUALATIONS, NEXT LEVEL!")));

		UGameplayStatics::OpenLevel(this, LevelToLoad);
	}
}

void AnextLevelTrigger::OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor)
{
	if (OtherActor && (OtherActor != this) && OtherActor == SpecificActor)
	{
		GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, TEXT("Overlap Ended"));

		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, FString::Printf(TEXT("%s has left the Trigger Box"), *OtherActor->GetName()));
	}
}

