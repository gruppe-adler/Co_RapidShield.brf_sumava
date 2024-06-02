params ["_object"];

[_object] call BIS_fnc_initIntelObject;

if (isServer) then
{
	// Diary picture:
	_object setVariable [
		"RscAttributeDiaryRecord_texture",
		"gm\gm_structures\gm_structures_euro_80\furniture\data\gm_paper_print_08_co.paa", // Path to picture
		true
	];

	// Diary Title and Description:
	[
		_object,
		"RscAttributeDiaryRecord",
		["New Intel", "We need to install AA emplacements near the early warning radar. I heard rumors of an air raid.. I'll mark them on the map."] // Array in format [Title, Description]
	] call BIS_fnc_setServerVariable;

	// Diary entry shared with (follows BIS_fnc_MP target rules):
	_object setVariable ["recipients", west, true];

	// Sides that can interact with the intel object:
	_object setVariable ["RscAttributeOwners", [west], true];


	{	
		private _zeus = _x;
		// Register intel object with Zeus as curator editable (_zeus is the curator module):
		_zeus addCuratorEditableObjects [[_object], false];
		
		// Add Zeus scripted event:
		[_zeus, "IntelObjectFound", {
			hint "Intel found";

			private _markers = ["mrk_aa_1", "mrk_aa_2", "mrk_aa_3"];

			{
				_x setMarkerAlpha 1;
			} forEach _markers;
		}] call BIS_fnc_addScriptedEventHandler;
	} forEach allCurators;


	// Add a scripted event that notifies all clients via systemChat when the intel is found:
	[
		_object,
		"IntelObjectFound",
		{
			params ["", "_foundBy"];
			private _msg = format ["Intel found by %1", name _foundBy];
			_msg remoteExec ["systemChat", 0];
		}
	] call BIS_fnc_addScriptedEventHandler;
};