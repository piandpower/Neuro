using UnrealBuildTool;

public class Neuro : ModuleRules
{
	public Neuro(TargetInfo Target)
	{
		PrivateIncludePaths.AddRange(
			new string[] {
				"Neuro/Private",
				// ... add other private include paths required here ...
			}
		);

		PrivateDependencyModuleNames.AddRange(new string[]
		{
			"Core",
			"CoreUObject",
			"Engine",
			"Networking",
			"Sockets" 
		});

	}
}
