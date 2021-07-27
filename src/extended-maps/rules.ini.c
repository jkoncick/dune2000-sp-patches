#include <windows.h>
#include <stdio.h>
#include "macros/patch.h"
#include "dune2000.h"
#include "patch.h"
#include "ini.h"
#include "rules.h"
#include "utils.h"

LPCTSTR rulesIni = ".\\rules.ini";
LPCTSTR rulesSpawnIni = ".\\rules-spawn.ini";

// Newly added rules
bool    rulesExt__InfiniteSpice         = false;
uint8_t rulesExt__infantryReleaseLimit  = 4;
uint8_t rulesExt__infantryReleaseChance = 5;

static void LoadVars(LPCTSTR fileName);

void LoadRulesFromMap()
{
    Mission__LoadVarsFile();
    LoadVars(SpawnerActive ? rulesSpawnIni : rulesIni);
    char mapIniPath[256];
    sprintf(mapIniPath, ".\\%s%s", GameType == GT_SINGLEPLAYER ? MissionsResourcePath : MapsResourcePath, PathChangeExtension(MissionMap, ".ini"));
    LoadVars(mapIniPath);
}

static void LoadVars(LPCTSTR fileName)
{
    harvestUnloadDelay = IniGetInt("Vars", "harvestUnloadDelay", harvestUnloadDelay, fileName);
    harvestBlobValue = IniGetInt("Vars", "harvestBlobValue", harvestBlobValue, fileName);
    harvestLoadSpiceDelay = IniGetInt("Vars", "harvestLoadSpiceDelay", harvestLoadSpiceDelay, fileName);
    starportUpdateDelay = IniGetInt("Vars", "starportUpdateDelay", starportUpdateDelay, fileName);
    starportStockIncreaseDelay = IniGetInt("Vars", "starportStockIncreaseDelay", starportStockIncreaseDelay, fileName);
    starportStockIncreaseProb = IniGetInt("Vars", "starportStockIncreaseProb", starportStockIncreaseProb, fileName);
    starportCostVariationPercent = IniGetInt("Vars", "starportCostVariationPercent", starportCostVariationPercent, fileName);
    starportFrigateDelay = IniGetInt("Vars", "starportFrigateDelay", starportFrigateDelay, fileName);
    refineryExplosionOffsetX = IniGetInt("Vars", "refineryExplosionOffsetX", refineryExplosionOffsetX, fileName);
    refineryExplosionOffsetY = IniGetInt("Vars", "refineryExplosionOffsetY", refineryExplosionOffsetY, fileName);
    HarvesterDriveDistance = IniGetInt("Vars", "HarvesterDriveDistance", HarvesterDriveDistance, fileName);
    RepairDriveDistance = IniGetInt("Vars", "RepairDriveDistance", RepairDriveDistance, fileName);
    BuildingRepairValue = IniGetInt("Vars", "BuildingRepairValue", BuildingRepairValue, fileName);
    UnitRepairValue = IniGetInt("Vars", "UnitRepairValue", UnitRepairValue, fileName);
    SinglePlayerDelay = IniGetInt("Vars", "SinglePlayerDelay", SinglePlayerDelay, fileName);
    NumberOfFremen = IniGetInt("Vars", "NumberOfFremen", NumberOfFremen, fileName);
    SandWormAppetite = IniGetInt("Vars", "SandWormAppetite", SandWormAppetite, fileName);
    SandWormInitialSleep = IniGetInt("Vars", "SandWormInitialSleep", SandWormInitialSleep, fileName);
    SandWormFedSleep = IniGetInt("Vars", "SandWormFedSleep", SandWormFedSleep, fileName);
    SandWormShotSleep = IniGetInt("Vars", "SandWormShotSleep", SandWormShotSleep, fileName);
    NumberOfCrates = IniGetInt("Vars", "NumberOfCrates", NumberOfCrates, fileName);
    CratesPerPlayer = IniGetBool("Vars", "CratesPerPlayer", CratesPerPlayer, fileName);
    DevastatorExplodeDelay = IniGetInt("Vars", "DevastatorExplodeDelay", DevastatorExplodeDelay, fileName);
    IgnoreDistance = IniGetInt("Vars", "IgnoreDistance", IgnoreDistance, fileName);
    CrateCash = IniGetInt("Vars", "CrateCash", CrateCash, fileName);
    ShowWarnings = IniGetBool("Vars", "ShowWarnings", ShowWarnings, fileName);
    DeathHandAccuracy = IniGetInt("Vars", "DeathHandAccuracy", DeathHandAccuracy, fileName);
    
    rulesExt__InfiniteSpice = IniGetBool("Vars", "InfiniteSpice", fileName == rulesSpawnIni || fileName == rulesIni ? false : rulesExt__InfiniteSpice, fileName);
    rulesExt__infantryReleaseLimit = IniGetInt("Vars", "infantryReleaseLimit", rulesExt__infantryReleaseLimit, fileName);
    rulesExt__infantryReleaseChance = IniGetInt("Vars", "infantryReleaseChance", rulesExt__infantryReleaseChance, fileName);
}
