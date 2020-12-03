// Created by Satheesh - 2020. (Twitter: @ryanjon2040 - Discord: ryanjon2040#5319). Please support Agora by becoming a Patron: https://www.patreon.com/ryanjon2040.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "AgoraThumbnailRendererSettings.generated.h"

UENUM(BlueprintType)
enum class EAgoraThumbnailRendererFontType : uint8
{
	Tiny,
	Small,
	Medium,
	Large,
	Subtitle
};

UCLASS(config = AgoraThumbnailRender, defaultconfig)
class AGORASTATICMESHTHUMBNAILRENDERER_API UAgoraThumbnailRendererSettings : public UDeveloperSettings
{
	GENERATED_BODY()
	
private:

	/** Enable or disable custom Agora thumbnail rendering. */
	UPROPERTY(Config, EditAnywhere, Category = "Agora Thumbnail")
	uint8 bEnable : 1;

	UPROPERTY(Config, EditAnywhere, Category = "Agora Thumbnail", meta = (EditCondition = "bEnable"))
	uint8 bShowVertices : 1;

	UPROPERTY(Config, EditAnywhere, Category = "Agora Thumbnail", meta = (EditCondition = "bEnable"))
	uint8 bShowTriangles : 1;

	UPROPERTY(Config, EditAnywhere, Category = "Agora Thumbnail", meta = (EditCondition = "bEnable"))
	uint8 bShowLODs : 1;

	UPROPERTY(Config, EditAnywhere, Category = "Agora Thumbnail", meta = (EditCondition = "bEnable"))
	uint8 bShowMaterials : 1;

	UPROPERTY(Config, EditAnywhere, Category = "Agora Thumbnail", meta = (EditCondition = "bEnable"))
	FLinearColor TextColor;

	UPROPERTY(Config, EditAnywhere, Category = "Agora Thumbnail", meta = (EditCondition = "bEnable"))
	EAgoraThumbnailRendererFontType FontType;

	UPROPERTY(Config, EditAnywhere, Category = "Agora Thumbnail", meta = (EditCondition = "bEnable"))
	float TextPadding;

public:

	UAgoraThumbnailRendererSettings()
	{
		bEnable = true;
		bShowVertices = true;
		bShowTriangles = true;
		bShowLODs = true;
		bShowMaterials = true;
		TextColor = FLinearColor(0.01f, 0.01f, 0.01f, 1.f);
		FontType = EAgoraThumbnailRendererFontType::Large;
		TextPadding = 20.f;
	}

	static FORCEINLINE const UAgoraThumbnailRendererSettings* Get()
	{
		const UAgoraThumbnailRendererSettings* ProxyDevSettings = CastChecked<UAgoraThumbnailRendererSettings>(UAgoraThumbnailRendererSettings::StaticClass()->GetDefaultObject());
		IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
		return ProxyDevSettings;
	}

	virtual FName GetCategoryName() const override final { return TEXT("Agora"); }
	virtual FText GetSectionText() const override final { return FText::FromString("Agora Thumbnail Renderer"); }

	FORCEINLINE const bool IsEnabled() const { return bEnable; }
	FORCEINLINE const bool ShowVertices() const { return bShowVertices; }
	FORCEINLINE const bool ShowTriangles() const { return bShowTriangles; }
	FORCEINLINE const bool ShowLODs() const { return bShowLODs; }
	FORCEINLINE const bool ShowMaterials() const { return bShowMaterials; }
	FORCEINLINE const FLinearColor GetTextColor() const { return TextColor; }
	FORCEINLINE const float GetTextPadding() const { return TextPadding; }
	FORCEINLINE const class UFont* GetFont() const
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
				default:
					break;
			}

			return GEngine->GetSubtitleFont();
		}

		return nullptr;
	}
};
