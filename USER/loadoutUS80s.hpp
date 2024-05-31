#ifdef NIGHTVISION
  #define NVITEM "rhsusf_ANPVS_15"
#else
  #define NVITEM ""
#endif

#ifdef LASERS
  #define LLITEM "rhsusf_acc_anpeq15A"
#else
  #define LLITEM ""
#endif

#ifdef GUNLIGHTS
  #define LLITEM "acc_flashlight"
#endif

#ifdef SUPPRESSORS
  #define SUPPRESSORITEM "rhsusf_acc_nt4_black"
#else
  #define SUPPRESSORITEM ""
#endif

class US80s {
    class AllUnits {
        uniform[] = {"UK3CB_CW_US_B_LATE_U_CombatUniform_01_WDL", "UK3CB_CW_US_B_LATE_U_CombatUniform_02_WDL", "UK3CB_CW_US_B_LATE_U_CombatUniform_03_WDL", "UK3CB_CW_US_B_LATE_U_CombatUniform_04_WDL"};
        vest = "UK3CB_CW_US_B_LATE_B_RIF";
        backpack[] = {"UK3CB_CW_US_B_LATE_B_RIF", "UK3CB_CW_US_B_LATE_B_RIF_02", "UK3CB_CW_US_B_LATE_B_RIF_03", "UK3CB_B_Kitbag_WDL_01", "UK3CB_B_Kitbag_WDL_02", "UK3CB_B_Kitbag_WDL_03"};
        headgear = "UK3CB_CW_US_B_LATE_H_BoonieHat_WDL_01";
        primaryWeapon = "rhs_weap_m16a4_carryhandle";
        primaryWeaponMagazine = "UK3CB_M16_30rnd_556x45_R";
        primaryWeaponMuzzle = SUPPRESSORITEM;
        primaryWeaponPointer = LLITEM;
        primaryWeaponOptics = "rhsusf_acc_nt4_black";
        primaryWeaponUnderbarrel = "";
		primaryWeaponUnderbarrelMagazine = "";
        secondaryWeapon = "";
        secondaryWeaponMagazine = "";
        handgunWeapon = "rhsusf_weap_m9";
        handgunWeaponMagazine = "rhsusf_mag_15Rnd_9x19_JHP";
        binoculars = "Binocular";
        map = "ItemMap";
        compass = "ItemCompass";
        watch = "ItemWatch";
        gps = "";
        radio = "tfar_anprc152";
        nvgoggles = NVITEM;
    };
    class Type {
        //Rifleman
        class Soldier_F {
            addItemsToUniform[] = {
                LIST_1("ACE_MapTools"),
                LIST_1("ACE_DefusalKit"),
                LIST_2("ACE_CableTie"),
                LIST_1("ACE_Flashlight_MX991"),

                GRAD_FACTIONS_MEDICITEMS_INF_LIST
            };
            addItemsToVest[] = {
                LIST_2("HandGrenade"),
                LIST_2("SmokeShell"),
                LIST_2("rhsusf_mag_15Rnd_9x19_JHP"),
                LIST_7("UK3CB_M16_30rnd_556x45_R")
            };
        };

        //Asst. Autorifleman
        class soldier_AAR_F: Soldier_F {
            addItemsToBackpack[] = {
                LIST_2("rhsusf_100Rnd_762x51"),
                "rhsusf_100Rnd_556x45_soft_pouch"
            };
        };

    	//Asst. Gunner (MMG) / Ammo Bearer
        class soldier_A_F: Soldier_F {
            addItemsToBackpack[] = {
                LIST_2("rhsusf_100Rnd_762x51_m62_tracer"),
                "rhsusf_100Rnd_762x51"
            };
    	};

        //Asst. Gunner (HMG/GMG)
        class support_AMG_F: Soldier_F {
            backpack = "RHS_M2_MiniTripod_Bag";
        };

        //Asst. Missile Specialist (AA)
        class soldier_AAA_F: Soldier_F {
            addItemsToBackpack[] = {
                "rhs_fim92_mag"
            };
        };

        //Asst. Missile Specialist (AT)
        class soldier_AAT_F: Soldier_F {
            addItemsToBackpack[] = {
                "rhs_fgm148_magazine_AT"
            };
        };

        //Autorifleman
        class soldier_AR_F: Soldier_F {
            primaryWeapon = "rhs_weap_m240G";
            primaryWeaponMagazine = "rhsusf_100Rnd_762x51";
            handgunWeapon = "";
            handgunWeaponMagazine = "";
            vest = "UK3CB_CW_US_B_LATE_V_PASGT_MG_Vest";
            addItemsToBackpack[] = {
                LIST_2("rhsusf_100Rnd_762x51"),
                "rhsusf_100Rnd_762x51"
            };
            addItemsToVest[] = {
                LIST_2("HandGrenade"),
                LIST_2("SmokeShell")
            };
        };

        //Combat Life Saver
        class medic_F: Soldier_F {
            vest = "rhsusf_iotv_ocp_Medic";
            backpack = "UK3CB_B_Backpack_Med_OLI";
            addItemsToUniform[] = {
                "ACE_MapTools",
                "ACE_Flashlight_MX991"
            };
            addItemsToVest[] = {
                LIST_2("SmokeShellPurple"),
                LIST_8("SmokeShell"),
                LIST_2("rhsusf_mag_15Rnd_9x19_JHP"),
                LIST_8("UK3CB_M16_30rnd_556x45_R")
            };

            class Rank {
                class PRIVATE {
                    GRAD_FACTIONS_MEDICITEMS_CFR
                };
                class CORPORAL {
                    GRAD_FACTIONS_MEDICITEMS_SQ
                };
                class SERGEANT {
                    GRAD_FACTIONS_MEDICITEMS_PT
                };
                class LIEUTENANT: SERGEANT {};
                class CAPTAIN: SERGEANT {};
                class MAJOR: SERGEANT {};
                class COLONEL: SERGEANT {};
            };
        };

        //Explosive Specialist
        class soldier_exp_F: Soldier_F {
            addItemsToBackpack[] = {
                "ACE_Clacker",
                "ACE_M26_Clacker",
                "SatchelCharge_Remote_Mag",
                LIST_3("DemoCharge_Remote_Mag")
            };
        };

        //Grenadier
        class Soldier_GL_F: Soldier_F {
            primaryWeapon = "rhs_weap_m16a4_carryhandle_M203";
            addItemsToVest[] = {
                LIST_2("HandGrenade"),
                LIST_2("SmokeShell"),
                LIST_2("rhsusf_mag_15Rnd_9x19_JHP"),
                LIST_7("UK3CB_M16_30rnd_556x45_R"),
                LIST_6("rhs_mag_M441_HE"),
                LIST_2("rhs_mag_m713_Red")
            };
        };

        //Heavy Gunner (MMG)
        class HeavyGunner_F: Soldier_F {
            primaryWeapon = "rhs_weap_m240B";
            primaryWeaponMagazine = "rhsusf_100Rnd_762x51";
            primaryWeaponMuzzle = "";
            handgunWeapon = "";
            handgunWeaponMagazine = "";
            addItemsToBackpack[] = {
                LIST_2("rhsusf_100Rnd_762x51_m62_tracer"),
                "rhsusf_100Rnd_762x51"
            };
            addItemsToVest[] = {
                LIST_2("HandGrenade"),
                LIST_2("SmokeShell")
            };
        };

    	//Gunner (HMG/GMG)
        class support_MG_F: Soldier_F {
            backpack = "RHS_M2_Gun_Bag";
    	};

        //Marksman
        class soldier_M_F: Soldier_F {
            primaryWeapon = "rhs_weap_sr25_ec";
            primaryWeaponMagazine = "rhsusf_20Rnd_762x51_SR25_m118_special_Mag";
            primaryWeaponMuzzle = "";
            primaryWeaponPointer = "";
            primaryWeaponOptics = "optic_DMS";
            primaryWeaponUnderbarrel = "bipod_01_F_blk";
            addItemsToVest[] = {
                LIST_2("SmokeShell"),
                LIST_2("rhsusf_mag_15Rnd_9x19_JHP"),
                LIST_7("rhsusf_20Rnd_762x51_SR25_m118_special_Mag")
            };
        };

        //Missile Specialist (AA)
        class soldier_AA_F: Soldier_F {
            secondaryWeapon = "rhs_weap_fim92";
            secondaryWeaponMagazine = "rhs_fim92_mag";
            addItemsToBackpack[] = {
                "rhs_fim92_mag"
            };
        };

        //Missile Specialist (AT)
        class soldier_AT_F: Soldier_F {
            secondaryWeapon = "rhs_weap_maaws";
            secondaryWeaponMagazine = "rhs_mag_maaws_HEAT";
            addItemsToBackpack[] = {
                "rhs_mag_maaws_HEAT"
            };
        };

        //Repair Specialist
        class soldier_repair_F: Soldier_F {
            addItemsToBackpack[] = {
                "ToolKit",
                "ACE_wirecutter"
            };
        };

        //Rifleman (AT)
        class soldier_LAT_F: Soldier_F {
            secondaryWeapon = "rhs_weap_M136";
        };

		// Heli Pilot
		class HeliPilot_F: Soldier_F {
			primaryWeapon = "UK3CB_M16_Carbine";
			headgear = "UK3CB_H_Pilot_Helmet";
			backpack = "UK3CB_B_Backpack_Med_OLI";
			vest = "UK3CB_CW_US_B_LATE_V_PASGT_Medic_Vest";
			uniform = "UK3CB_CW_US_B_LATE_U_H_Pilot_Uniform_01_NATO";
			gps = "ItemGPS";

			addItemsToUniform[] = {
                "ACE_MapTools",
                "ACE_Flashlight_MX991"
            };
            addItemsToVest[] = {
                LIST_2("SmokeShellPurple"),
                LIST_8("SmokeShell"),
                LIST_2("rhsusf_mag_15Rnd_9x19_JHP"),
                LIST_8("UK3CB_M16_30rnd_556x45_R")
            };

            class Rank {
                class PRIVATE {
                    GRAD_FACTIONS_MEDICITEMS_CFR
                };
                class CORPORAL {
                    GRAD_FACTIONS_MEDICITEMS_SQ
                };
                class SERGEANT {
                    GRAD_FACTIONS_MEDICITEMS_PT
                };
                class LIEUTENANT: SERGEANT {};
                class CAPTAIN: SERGEANT {};
                class MAJOR: SERGEANT {};
                class COLONEL: SERGEANT {};
            };
		};

        //Squad Leader
        class Soldier_SL_F: Soldier_F {
            backpack = "TFAR_rt1523g_green";
            headgear[] = {"UK3CB_H_Cap_WDL_01", "UK3CB_H_Cap_WDL_02", "UK3CB_H_Cap_WDL_03"};
			gps = "ItemGPS";
            addItemsToBackpack[] = {
                LIST_2("SmokeShellBlue"),
                LIST_2("SmokeShellGreen"),
                LIST_4("UGL_FlareGreen_F"),
                LIST_4("UGL_FlareRed_F"),
                LIST_4("UGL_FlareWhite_F"),
                LIST_2("SmokeShell")
            };
        };

        //Team Leader
        class Soldier_TL_F: Soldier_F {
            primaryWeapon = "rhs_weap_m16a4_carryhandle_M203";
            headgear[] = {"UK3CB_H_Bandanna_WDL_01", "UK3CB_H_Bandanna_WDL_02", "UK3CB_H_Bandanna_WDL_03"};
			vest = "UK3CB_CW_US_B_LATE_V_PASGT_Rif_Vest";
			gps = "ItemGPS";
            addItemsToVest[] = {
                LIST_2("HandGrenade"),
                LIST_2("SmokeShell"),
                LIST_2("rhsusf_mag_15Rnd_9x19_JHP"),
                LIST_8("UK3CB_M16_30rnd_556x45_R"),
                LIST_2("1Rnd_SmokeRed_Grenade_shell"),
                LIST_4("UGL_FlareGreen_F"),
                LIST_4("UGL_FlareRed_F"),
                LIST_4("UGL_FlareWhite_F")
            };
        };
    };
    class Rank {
        class LIEUTENANT {
            headgear = "UK3CB_H_MilCap_WDL_01";
        };
    };
};
