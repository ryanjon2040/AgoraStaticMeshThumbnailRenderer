// Created by Satheesh (Twitter: @ryanjon2040 - Discord: ryanjon2040#5319). Please support Agora by becoming a Patron: https://www.patreon.com/ryanjon2040.

#pragma once

#include "CoreMinimal.h"
#include "ThumbnailRendering/StaticMeshThumbnailRenderer.h"
#include "AgoraStaticMeshThumbnail.generated.h"


UCLASS(MinimalAPI)
class UAgoraStaticMeshThumbnail : public UStaticMeshThumbnailRenderer
{
	GENERATED_BODY()
	

	virtual void Draw(UObject* Object, int32 X, int32 Y, uint32 Width, uint32 Height, FRenderTarget* RenderTarget, FCanvas* Canvas) override;

private:

	void Internal_DrawTextItem(UPARAM(ref) FCanvas*& Canvas, const FVector2D& AtLocation, const FString& InSuffix, const FString& InString);

};
