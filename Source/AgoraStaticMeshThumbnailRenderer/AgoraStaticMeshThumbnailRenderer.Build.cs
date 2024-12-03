// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

using System;
using UnrealBuildTool;

public class AgoraStaticMeshThumbnailRenderer : ModuleRules
{
	public AgoraStaticMeshThumbnailRenderer(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		CppStandard = CppStandardVersion.EngineDefault;
		DefaultBuildSettings = BuildSettingsVersion.Latest;
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
		
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", 
			"DeveloperSettings", 
			"UnrealEd",
			"Slate",
			"SlateCore"
		});
		
		if (Environment.GetEnvironmentVariable("YETI_STRICT_BUILD") == "true")
		{
			bUseUnity = false;
			PCHUsage = PCHUsageMode.NoPCHs;
			
			Console.WriteLine($"{ToString()} is using STRICT build.");
		}
	}
}
