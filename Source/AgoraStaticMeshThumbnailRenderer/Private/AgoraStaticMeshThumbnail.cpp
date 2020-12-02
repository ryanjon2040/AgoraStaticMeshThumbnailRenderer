// Created by Satheesh (Twitter: @ryanjon2040 - Discord: ryanjon2040#5319). Please support Agora by becoming a Patron: https://www.patreon.com/ryanjon2040.


#include "AgoraStaticMeshThumbnail.h"
#include "Engine/StaticMesh.h"
#include "CanvasItem.h"

void UAgoraStaticMeshThumbnail::Draw(UObject* Object, int32 X, int32 Y, uint32 Width, uint32 Height, FRenderTarget* RenderTarget, FCanvas* Canvas, bool bAdditionalViewFamily)
{
	Super::Draw(Object, X, Y, Width, Height, RenderTarget, Canvas, bAdditionalViewFamily);
	
	UStaticMesh* StaticMesh = Cast<UStaticMesh>(Object);
	if (StaticMesh != nullptr && !StaticMesh->IsPendingKill())
	{
		FStaticMeshLODResources& LODModel = StaticMesh->RenderData->LODResources[0];

		Internal_DrawTextItem(Canvas, FVector2D(5.f, 5.f), "Vertices", FString::FromInt(LODModel.GetNumVertices()));
		Internal_DrawTextItem(Canvas, FVector2D(5.f, 25.f), "Triangles", FString::FromInt(LODModel.GetNumTriangles()));
		Internal_DrawTextItem(Canvas, FVector2D(5.f, 45.f), "LODs", FString::FromInt(StaticMesh->RenderData->LODResources.Num()));
		Internal_DrawTextItem(Canvas, FVector2D(5.f, 65.f), "Materials", FString::FromInt(StaticMesh->StaticMaterials.Num()));
	}
}

void UAgoraStaticMeshThumbnail::Internal_DrawTextItem(FCanvas*& Canvas, const FVector2D& AtLocation, const FString& InSuffix, const FString& InString)
{
	static const FLinearColor TextColor = FLinearColor(0.01f, 0.01f, 0.01f, 1.f);
	static const UFont* TextFont = GEngine->GetLargeFont();
	const FString TextMessage = InSuffix.IsEmpty() ? InString : FString::Printf(TEXT("%s: %s"), *InSuffix, *InString);
	FCanvasTextItem TextItem(AtLocation, FText::FromString(TextMessage), TextFont, TextColor);
	TextItem.Draw(Canvas);
}
