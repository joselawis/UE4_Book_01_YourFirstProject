// Fill out your copyright notice in the Description page of Project Settings.


#include "ScoreController.h"
#include "Blueprint/UserWidget.h"
#include "TextWidgetTypes.h"
#include "TextBlock.h"

// Sets default values
AScoreController::AScoreController() : score(0)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AScoreController::BeginPlay()
{
	Super::BeginPlay();

	if (ScoreTextWidget)
	{
		// 1 Creamos la instancia del BP_Score_Widget y conservamos el puntero
		pScoreTextWidget = CreateWidget<UUserWidget>(GetGameInstance(), ScoreTextWidget);

		if (pScoreTextWidget.IsValid())
		{
			// 2 Añadimos al viewport el widget
			pScoreTextWidget->AddToViewport();
			// 3 Guardamos el puntero al widget de texto de la puntuacion
			pScoreText = (UTextBlock*) pScoreTextWidget->GetWidgetFromName("ScoreText");
		}
	}
	
}

// Called every frame
void AScoreController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AScoreController::IncreaseScore(int amount)
{
	if(pScoreText.IsValid())
	{
		score += amount;
		pScoreText->SetText(FText::FromString(FString::FromInt(score)));
	}
}

