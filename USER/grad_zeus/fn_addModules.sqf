[] spawn {
  waitUntil {!isNull player};
  waitUntil {  time > 3 };

  {
    private _curator = _x;
    
      _curator addEventHandler ["CuratorGroupPlaced", {
          params ["", "_group"];

          ["GRAD_missionControl_setServerAsOwner", [_group]] call CBA_fnc_serverEvent;
      }];

      _curator addEventHandler ["CuratorObjectPlaced", {
          params ["", "_object"];

          if (_object isKindOf "CAManBase") then {
             if (count units _object == 1) then {
                 ["GRAD_missionControl_setServerAsOwner", [group _object]] call CBA_fnc_serverEvent;
             };
          } else {
             if (count crew _object > 1) then {
                 ["GRAD_missionControl_setServerAsOwner", [group (crew _object select 0)]] call CBA_fnc_serverEvent;
             };
         };

      }];

  } forEach allCurators;
};


//////////////
////////////// SCUD
//////////////

["RAPID SHIELD - SCUD", "Launch all Scuds 2",
{
  params [["_position", [0,0,0], [[]], 3], ["_objectUnderCursor", objNull, [objNull]]];

  _position = ASLtoAGL _position;

  
  private _scuds = [worldsize/2, worldsize/2] nearObjects ["UK3CB_CW_SOV_O_LATE_MAZ_543_SCUD", worldSize/2];
  
  {
    if (alive _x) then {

        [_x] spawn {
            params ["_scud"];
            waitUntil { _scud animationSourcePhase "Scud_Hide" == 0 };
            sleep random 2 + 1;
            [_scud,'UK3CB_Factions_Scud_Launcher',[-1]] call BIS_fnc_fire; 
            sleep 1;
            _scud animateSource ['Scud_Hide', 1]; 
            _scud animateSource ['Scud_Raise1', 0]; 
        };
    };
  } forEach _scuds;

}] call zen_custom_modules_fnc_register;


["RAPID SHIELD - SCUD", "Raise all Scuds",
{
  params [["_position", [0,0,0], [[]], 3], ["_objectUnderCursor", objNull, [objNull]]];

  _position = ASLtoAGL _position;

  
  private _scuds = [worldsize/2, worldsize/2] nearObjects ["UK3CB_CW_SOV_O_LATE_MAZ_543_SCUD", worldSize/2];
  
  {
    if (alive _x) then {

        [_x] spawn {
            params ["_scud"];
            sleep random 2 + 1;
            _scud addWeaponTurret ['UK3CB_Factions_Scud_Launcher', [-1]];
            _scud animateSource ['Scud_Hide', 0];
            _scud animateSource ['Scud_Raise1', 1];
        };
    };
  } forEach _scuds;

}] call zen_custom_modules_fnc_register;



["RAPID SHIELD - HELI", "Skin as Medic UH60",
{
  params [["_position", [0,0,0], [[]], 3], ["_objectUnderCursor", objNull, [objNull]]];

  _position = ASLtoAGL _position;

  if (!isNull _objectUnderCursor) then {
    if (_objectUnderCursor isKindOf "Air") then {
      [_objectUnderCursor] execvm "USER\scripts\skinHeli.sqf";
    };
  };

}] call zen_custom_modules_fnc_register;


["RAPID SHIELD - MARKERS", "Make AA markers visible",
{
  params [["_position", [0,0,0], [[]], 3], ["_objectUnderCursor", objNull, [objNull]]];

  _position = ASLtoAGL _position;

  
  private _markers = ["mrk_aa_1", "mrk_aa_2"];
  
  {
    _x setMarkerAlpha 1;
  } forEach _markers;

}] call zen_custom_modules_fnc_register;


["RAPID SHIELD - MARKERS", "Make AA markers invisible",
{
  params [["_position", [0,0,0], [[]], 3], ["_objectUnderCursor", objNull, [objNull]]];

  _position = ASLtoAGL _position;

  
  private _markers = ["mrk_aa_1", "mrk_aa_2"];
  
  {
    _x setMarkerAlpha 0;
  } forEach _markers;

}] call zen_custom_modules_fnc_register;



//////////////
////////////// NOTES
//////////////


["GRAD NOTES", "Write + Spawn Note",
{
        params ["_modulePosition"]; 

        _modulePosition = ASLToATL _modulePosition;

        ["Example Dialog", [["EDIT", "Your text?", "string ping"]], {
			   params ["_message", "_position"]; 
                  // systemchat str _position; 
                  // systemchat (_message select 0);
			   [_position, random 360, _message select 0, ["somewhat",["cramped","EtelkaNarrowMediumPro"]]] remoteExec ["GRAD_leaveNotes_fnc_spawnNote", 2, false];
		  }, { systemchat "cancelled"; }, _modulePosition] call zen_dialog_fnc_create;        

}] call zen_custom_modules_fnc_register;

