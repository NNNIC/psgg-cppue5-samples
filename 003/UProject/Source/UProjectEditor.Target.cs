// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class UProjectEditorTarget : TargetRules
{
	public UProjectEditorTarget( TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.AddRange( new string[] { "UProject" } );
        WindowsPlatform.Compiler = WindowsCompiler.VisualStudio2022;
        WindowsPlatform.CompilerVersion = "14.32.31326";
	}
}
