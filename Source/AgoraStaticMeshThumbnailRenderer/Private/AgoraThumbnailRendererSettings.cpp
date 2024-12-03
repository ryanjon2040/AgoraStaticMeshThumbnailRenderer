// Created by Satheesh (Twitter: @ryanjon2040 - Discord: ryanjon2040#5319). Please support Agora by becoming a Patron: https://www.patreon.com/ryanjon2040.

#include "AgoraThumbnailRendererSettings.h"
#include "Engine/Engine.h"
#include "Engine/Font.h"

UAgoraThumbnailRendererSettings::UAgoraThumbnailRendererSettings()
{
	bEnable = true;
	bShowVertices = true;
	bShowTriangles = true;
	bShowLODs = true;
	bShowMaterials = true;
	bShowCollision = true;
	TextColor = FLinearColor(0.7, 0.7, 0.7, 1.f);
	Font = FSlateFontInfo(GEngine->GetLargeFont(), 12, "Bold");
	TextPadding = 20.f;
}

const UAgoraThumbnailRendererSettings* UAgoraThumbnailRendererSettings::Get()
{
	return CastChecked<UAgoraThumbnailRendererSettings>(StaticClass()->GetDefaultObject());
}
