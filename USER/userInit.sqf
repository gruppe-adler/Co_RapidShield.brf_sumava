/*
*   Wird zum Missionsstart auf Server und Clients ausgeführt.
*   Funktioniert wie die init.sqf.
*/

if isServer then
{
    gm_fr_guardTowerCrew = ["gm_gc_army_rifleman_mpiak74n_80_str"]; // change the classnames in here to the type of soldier you want
    gm_fr_alarmSirenSound = "gm_alarmHorn"; // you can change this to other sounds
    gm_fr_alarmFlareAmmoType = "gm_flare_illum_red"; // you can change this to other flare sounds
    gm_fr_side_friendly = west; // use the appropriate side for your enemies
    gm_fr_side_enemy = east; // use the appropriate side for your enemies
    gm_fr_extendedDebugMode = 0; // leave it as 0
    gm_alias_fr_fnc_debugMarker = [{ "" }]; // leave this the way it is
	gm_alias_fr_fnc_raiseAlarm = [gm_fr_fnc_raiseAlarm];
	gm_alias_fr_fnc_shootFlare = [gm_core_fnc_shootIllumFlare];
    {
        _x call gm_fr_fnc_makeBorderTurret;
    } forEach allMissionObjects "gm_missionHelper_guardtower"; // you can change the logic type to any object you want, best to leave it this way
};