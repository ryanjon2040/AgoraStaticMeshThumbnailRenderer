// Created by Satheesh - 2020. (Twitter: @ryanjon2040 - Discord: ryanjon2040#5319). Please support Agora by becoming a Patron: https://www.patreon.com/ryanjon2040.

#pragma once

#include "Engine/DeveloperSettings.h"
#include "Fonts/SlateFontInfo.h"
#include "AgoraThumbnailRendererSettings.generated.h"

class UFont;

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
	uint8 bShowCollision : 1;

	UPROPERTY(Config, EditAnywhere, Category = "Agora Thumbnail", meta = (EditCondition = "bEnable"))
	FLinearColor TextColor;

	UPROPERTY(Config, EditAnywhere, Category = "Agora Thumbnail", meta = (EditCondition = "bEnable"))
	FSlateFontInfo Font;

	UPROPERTY(Config, EditAnywhere, Category = "Agora Thumbnail", meta = (EditCondition = "bEnable"))
	float TextPadding;

public:

	UAgoraThumbnailRendererSettings();

	static const UAgoraThumbnailRendererSettings* Get();

	virtual FName GetCategoryName() const override final { return TEXT("Agora"); }
	virtual FText GetSectionText() const override final { return FText::FromString("Agora Thumbnail Renderer"); }

	const FSlateFontInfo* GetFont() const { return &Font; }

	FORCEINLINE const bool IsEnabled() const				{ return bEnable; }
	FORCEINLINE const bool ShowVertices() const				{ return bShowVertices; }
	FORCEINLINE const bool ShowTriangles() const			{ return bShowTriangles; }
	FORCEINLINE const bool ShowLODs() const					{ return bShowLODs; }
	FORCEINLINE const bool ShowMaterials() const			{ return bShowMaterials; }
	FORCEINLINE const bool ShowCollisions() const			{ return bShowCollision; }
	FORCEINLINE const FLinearColor GetTextColor() const		{ return TextColor; }
	FORCEINLINE const float GetTextPadding() const			{ return TextPadding; }
};
