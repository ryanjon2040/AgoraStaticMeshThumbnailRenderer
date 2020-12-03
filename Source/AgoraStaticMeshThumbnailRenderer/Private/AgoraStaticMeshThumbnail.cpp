// Created by Satheesh - 2020. (Twitter: @ryanjon2040 - Discord: ryanjon2040#5319). Please support Agora by becoming a Patron: https://www.patreon.com/ryanjon2040.


#include "AgoraStaticMeshThumbnail.h"
#include "Engine/StaticMesh.h"
#include "CanvasItem.h"
#include "AgoraThumbnailRendererSettings.h"

void UAgoraStaticMeshThumbnail::Draw(UObject* Object, int32 X, int32 Y, uint32 Width, uint32 Height, FRenderTarget* RenderTarget, FCanvas* Canvas, bool bAdditionalViewFamily)
{
	Super::Draw(Object, X, Y, Width, Height, RenderTarget, Canvas, bAdditionalViewFamily);
	
	const UAgoraThumbnailRendererSettings* ThumbnailSettings = UAgoraThumbnailRendererSettings::Get();
	if (ThumbnailSettings->IsEnabled())
	{
		UStaticMesh* StaticMesh = Cast<UStaticMesh>(Object);
		if (StaticMesh != nullptr && !StaticMesh->IsPendingKill())
		{
			FStaticMeshLODResources& LODModel = StaticMesh->RenderData->LODResources[0];

			const float Padding = ThumbnailSettings->GetTextPadding();
			float LastLocation = 5.f;			
			if (ThumbnailSettings->ShowVertices())
			{
				Internal_DrawTextItem(Canvas, FVector2D(5.f, LastLocation), "Vertices", FString::FromInt(LODModel.GetNumVertices()));
				LastLocation += Padding;
			}

			if (ThumbnailSettings->ShowTriangles())
			{
				Internal_DrawTextItem(Canvas, FVector2D(5.f, LastLocation), "Triangles", FString::FromInt(LODModel.GetNumTriangles()));
				LastLocation += Padding;
			}

			if (ThumbnailSettings->ShowLODs())
			{
				Internal_DrawTextItem(Canvas, FVector2D(5.f, LastLocation), "LODs", FString::FromInt(StaticMesh->RenderData->LODResources.Num()));
				LastLocation += Padding;
			}

			if (ThumbnailSettings->ShowMaterials())
			{
				Internal_DrawTextItem(Canvas, FVector2D(5.f, LastLocation), "Materials", FString::FromInt(StaticMesh->StaticMaterials.Num()));
			}
		}
	}
}

void UAgoraStaticMeshThumbnail::Internal_DrawTextItem(FCanvas*& Canvas, const FVector2D& AtLocation, const FString& InSuffix, const FString& InString)
{
	const UFont* Font = UAgoraThumbnailRendererSettings::Get()->GetFont();
	if (Font)
	{
		const FString TextMessage = InSuffix.IsEmpty() ? InString : FString::Printf(TEXT("%s: %s"), *InSuffix, *InString);
		FCanvasTextItem TextItem(AtLocation, FText::FromString(TextMessage), Font, UAgoraThumbnailRendererSettings::Get()->GetTextColor());
		TextItem.Draw(Canvas);
	}
}
