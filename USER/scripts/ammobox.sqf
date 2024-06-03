params ["_box"];

if (!isServer) exitWith {};

private _ammo =
[
	["UGL_FlareGreen_F", 30],
	["UGL_FlareWhite_F", 30],
	["UGL_FlareRed_F", 30],
	["SmokeShell", 30],
	["rhsusf_mag_15Rnd_9x19_JHP", 30],
	["UK3CB_M16_30rnd_556x45_R", 250],
	["SatchelCharge_Remote_Mag", 10],
	["rhsusf_100Rnd_762x51", 30],
	["HandGrenade", 30],
	["rhs_mag_maaws_HEAT", 30],
	["TFAR_rt1523g_green", 3]
];

{
	_box addMagazineCargoGlobal [_x#0, _x#1];
} forEach _ammo;