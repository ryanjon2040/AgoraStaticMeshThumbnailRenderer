// Created by Satheesh (Twitter: @ryanjon2040 - Discord: ryanjon2040#5319). Please support Agora by becoming a Patron: https://www.patreon.com/ryanjon2040.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FAgoraStaticMeshThumbnailRendererModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
