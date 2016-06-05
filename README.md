# Neuro

### About

Neuro is an Unreal Engine 4 networking plugin, designed to make it easy to create large multiplayer worlds by combining multiple UE4 servers where players will travel between them.

The basic infrastructure includes:

* The **Authentication Server** handles player Registration, Logins, and security token-based verification between game servers.

* The **World Server** which all game servers report to. World Server is responsible for determining which gameservers to transport players to in the event of map travel. It is also responsible for reporting basic player information, such as player map location.


### Building Neuro

1. Create `Plugins` folder in your project root, if one doesn't exist. Otherwise, continue to step 2.

2. Pull Neuro into the Plugins folder, such that your directory structure looks like: `YourGame/Plugins/Neuro`

3. In `YourGame.Build.cs` add the following in your constructor: 

```
PrivateDependencyModuleNames.AddRange(new string[] { "Neuro" });
PrivateIncludePathModuleNames.AddRange(new string[] { "Neuro" });
```

### Configuring Neuro (WIP)

1. In your game's `Config/DefaultGame.ini` configuration file, add the following:

```
[/Script/Neuro.Neuro]
LoginServerAddress="127.0.0.1"
LoginServerPort=34544
WorldServerAddress="127.0.0.1"
WorldServerPort=34545
```

*Of course, that config is an example that points to your local machine. You'll want to setup the ports and addresses for your specific case*


### Using Neuro (Example WIP)

##### Creating your GameInstance

*If you already have your own GameInstance for your game, skip forward to the **Adding Neuro to your GameInstance** section*

1. Create a new C++ class that inherits from `UGameInstance`.

2. Let UE4 know to use your new game instance by editing `DefaultEngine.ini`, and making sure in the section `[/Script/EngineSettings.GameMapsSettings]` you have
`GameInstanceClass=/Script/YourGame.YourGameInstanceClass`

##### Adding Neuro to your GameInstance

1. In your `UGameInstance` header file, make these changes:

    * `#include "Neuro.h"` somewhere at the top. *Make sure it is above your `#include "YourGameInstance.generated.h"` line, or the build system will complain*.
    
    * Within the class declaration body, add

```
public:
UPROPERTY(BlueprintReadOnly)
UNeuro *neuro;
```

2. In your `UGameInstance` class file, locate your constructor function and add this line:
`neuro = NewObject<UNeuro>();`

3. At this point, you're set. You can now access Neuro via Blueprints (or C++) by getting a reference to your GameInstance, and then the Neuro Property.

### License
TBD

