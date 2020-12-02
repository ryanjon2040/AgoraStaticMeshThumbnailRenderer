// Created by Satheesh (Twitter: @ryanjon2040 - Discord: ryanjon2040#5319). Please support Agora by becoming a Patron: https://www.patreon.com/ryanjon2040.

#include "AgoraStaticMeshThumbnailRenderer.h"
#include "ThumbnailRendering/ThumbnailManager.h"
#include "Engine/StaticMesh.h"
#include "AgoraStaticMeshThumbnail.h"

#define LOCTEXT_NAMESPACE "FAgoraStaticMeshThumbnailRendererModule"

void FAgoraStaticMeshThumbnailRendererModule::StartupModule()
{
	UThumbnailManager::Get().UnregisterCustomRenderer(UStaticMesh::StaticClass());
	UThumbnailManager::Get().RegisterCustomRenderer(UStaticMesh::StaticClass(), UAgoraStaticMeshThumbnail::StaticClass());
}

void FAgoraStaticMeshThumbnailRendererModule::ShutdownModule()
{
	
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FAgoraStaticMeshThumbnailRendererModule, AgoraStaticMeshThumbnailRenderer)
