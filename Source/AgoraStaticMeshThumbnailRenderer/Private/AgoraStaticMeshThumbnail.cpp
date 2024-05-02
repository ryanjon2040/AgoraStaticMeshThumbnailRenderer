// Created by Satheesh - 2020. (Twitter: @ryanjon2040 - Discord: ryanjon2040#5319). Please support Agora by becoming a Patron: https://www.patreon.com/ryanjon2040.


#include "AgoraStaticMeshThumbnail.h"
#include "Engine/StaticMesh.h"
#include "CanvasItem.h"
#include "AgoraThumbnailRendererSettings.h"
#include "PhysicsEngine/BodySetup.h"

void UAgoraStaticMeshThumbnail::Draw(UObject* Object, int32 X, int32 Y, uint32 Width, uint32 Height, FRenderTarget* RenderTarget, FCanvas* Canvas, bool bAdditionalViewFamily)
{
	Super::Draw(Object, X, Y, Width, Height, RenderTarget, Canvas, bAdditionalViewFamily);
	
	const UAgoraThumbnailRendererSettings* ThumbnailSettings = UAgoraThumbnailRendererSettings::Get();
	if (ThumbnailSettings->IsEnabled())
	{
		if (UStaticMesh* StaticMesh = Cast<UStaticMesh>(Object))
		{
			const FStaticMeshLODResources& LODModel = StaticMesh->GetRenderData()->LODResources[0];
			const auto Vertices = StaticMesh->HasValidNaniteData() ? StaticMesh->GetNumNaniteVertices() : LODModel.GetNumVertices();
			const auto Tris = StaticMesh->HasValidNaniteData() ? StaticMesh->GetNumNaniteTriangles() : LODModel.GetNumTriangles();

			const float Padding = ThumbnailSettings->GetTextPadding();
			float LastLocation = 5.f;			
			if (ThumbnailSettings->ShowVertices())
			{
				Internal_DrawTextItem(Canvas, FVector2D(5.f, LastLocation), StaticMesh->HasValidNaniteData() ? "Nanite Vertices" : "Vertices", FString::FromInt(Vertices));
				LastLocation += Padding;
			}

			if (ThumbnailSettings->ShowTriangles())
			{
				Internal_DrawTextItem(Canvas, FVector2D(5.f, LastLocation), StaticMesh->HasValidNaniteData() ? "Nanite Triangles" : "Triangles", FString::FromInt(Tris));
				LastLocation += Padding;
			}

			if (ThumbnailSettings->ShowLODs() && !StaticMesh->HasValidNaniteData())
			{
				Internal_DrawTextItem(Canvas, FVector2D(5.f, LastLocation), "LODs", FString::FromInt(StaticMesh->GetRenderData()->LODResources.Num()));
				LastLocation += Padding;
			}

			if (ThumbnailSettings->ShowMaterials())
			{
				Internal_DrawTextItem(Canvas, FVector2D(5.f, LastLocation), "Materials", FString::FromInt(StaticMesh->GetStaticMaterials().Num()));
				LastLocation += Padding;
			}

			if (ThumbnailSettings->ShowCollisions())
			{
				FString CollisionString = "No Collision";
				if (StaticMesh->GetBodySetup() && StaticMesh->GetBodySetup()->AggGeom.GetElementCount() > 0)
				{
					CollisionString = FString::Printf(TEXT("Collision Prims: %i"), StaticMesh->GetBodySetup()->AggGeom.GetElementCount());
				}
				
				Internal_DrawTextItem(Canvas, FVector2D(5.f, LastLocation), "", CollisionString);
			}
		}
	}
}

void UAgoraStaticMeshThumbnail::Internal_DrawTextItem(FCanvas*& Canvas, const FVector2D& AtLocation, const FString& InSuffix, const FString& InString) const
{
	if (const UFont* Font = UAgoraThumbnailRendererSettings::Get()->GetFont())
	{
		const FString TextMessage = InSuffix.IsEmpty() ? InString : FString::Printf(TEXT("%s: %s"), *InSuffix, *InString);
		FCanvasTextItem TextItem(AtLocation, FText::FromString(TextMessage), Font, UAgoraThumbnailRendererSettings::Get()->GetTextColor());
		TextItem.Draw(Canvas);
	}
}
