private _position = (getMarkerPos "mrk_radar");
private _radar = nearestTerrainObjects [_position, ["Hide", "House"], 50];

{

	hideObjectGlobal _x;
	
} forEach _radar;

private _ruin = "Land_Skola_ruins" createVehicle [0,0,0];
_ruin setDir 45;
_ruin setPos _position;

private _fx = "Bo_GBU12_LGB" createVehicle _position;
_fx setDamage 1;

/*
private _fx = ["BombExp1",
"ExpSparksBig",
"LightExpBig",
"Shockwave_1"];

{
private _source01 = "#particlesource" createVehicleLocal position player;
_source01 setParticleClass _x;
} forEach _fx;

*/