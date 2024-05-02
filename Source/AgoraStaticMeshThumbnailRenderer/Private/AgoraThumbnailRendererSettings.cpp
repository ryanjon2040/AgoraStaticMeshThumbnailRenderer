// Created by Satheesh (Twitter: @ryanjon2040 - Discord: ryanjon2040#5319). Please support Agora by becoming a Patron: https://www.patreon.com/ryanjon2040.

#include "AgoraThumbnailRendererSettings.h"
#include "Engine/Font.h"

UAgoraThumbnailRendererSettings::UAgoraThumbnailRendererSettings()
{
	bEnable = true;
	bShowVertices = true;
	bShowTriangles = true;
	bShowLODs = true;
	bShowMaterials = true;
	bShowCollision = true;
	TextColor = FLinearColor(0.01f, 0.01f, 0.01f, 1.f);
	FontType = EAgoraThumbnailRendererFontType::Large;
	TextPadding = 20.f;
	CustomFont = nullptr;
}

const UAgoraThumbnailRendererSettings* UAgoraThumbnailRendererSettings::Get()
{
	return CastChecked<UAgoraThumbnailRendererSettings>(StaticClass()->GetDefaultObject());
}

UFont* UAgoraThumbnailRendererSettings::GetFont() const
{
	if (GEngine)
	{
		switch (FontType)
		{
			case EAgoraThumbnailRendererFontType::Tiny:
				return GEngine->GetTinyFont();
			case EAgoraThumbnailRendererFontType::Small:
				return GEngine->GetSmallFont();
			case EAgoraThumbnailRendererFontType::Medium:
				return GEngine->GetMediumFont();
			case EAgoraThumbnailRendererFontType::Large:
				return GEngine->GetLargeFont();
			case EAgoraThumbnailRendererFontType::Subtitle:
				return GEngine->GetSubtitleFont();
			default:
				break;
		}

		return CustomFont.LoadSynchronous();
	}

	return nullptr;
}
