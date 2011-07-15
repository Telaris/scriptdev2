/* SUNWELL PLATEAU */ 
-- -----------------------------------------------------------
-- official sd2 mangos scriptname sql and mangosR2 scriptnames
-- -----------------------------------------------------------
UPDATE `instance_template` SET `ScriptName` ='instance_sunwell_plateau' WHERE map = 580;
UPDATE `creature_template` SET `ScriptName` = 'boss_brutallus' WHERE `entry` = 24882;
UPDATE `creature_template` SET `ScriptName` = 'boss_felmyst' WHERE `entry` = 25038;
UPDATE `creature_template` SET `ScriptName` = 'mob_felmyst_vapor' WHERE `entry`= 25265;
UPDATE `creature_template` SET `ScriptName` = 'mob_deathcloud' WHERE `entry`= 25703;
UPDATE `creature_template` SET `ScriptName` = 'boss_kalecgos' WHERE entry = 24850;
UPDATE `creature_template` SET `ScriptName` = 'boss_sacrolash' WHERE `entry` = 25165;
UPDATE `creature_template` SET `ScriptName` = 'boss_alythess' WHERE `entry` = 25166;
UPDATE `creature_template` SET `ScriptName` = 'boss_muru' WHERE `entry` = 25741;
UPDATE `creature_template` SET `ScriptName` = 'mob_kiljaeden_controller' WHERE `entry` = 25608;
UPDATE `creature_template` SET `ScriptName` = 'mob_deceiver' WHERE `entry`= 25588;
UPDATE `creature_template` SET `ScriptName` = 'boss_kiljaeden' WHERE `entry`= 25315;
UPDATE `creature_template` SET `ScriptName` = 'mob_volatile_felfire_fiend' WHERE `entry` = 25598;
UPDATE `creature_template` SET `ScriptName` = 'mob_armagedon' WHERE `entry` = 25735;
UPDATE `creature_template` SET `ScriptName` = 'mob_orb' WHERE `entry` = 25502;
UPDATE `creature_template` SET `ScriptName` = 'dragon' WHERE `entry` = 25653;
UPDATE `creature_template` SET `ScriptName` = 'mob_shadowspike' WHERE `entry` = 30598;
UPDATE `creature_template` SET `ScriptName` = 'dark_fiend' WHERE `entry` = 25744;
UPDATE `creature_template` SET `ScriptName` = 'mob_voidsentinel' WHERE `entry` = 25772;
UPDATE `creature_template` SET `ScriptName` = 'mob_singularity' WHERE `entry` = 25855;
UPDATE `creature_template` SET `ScriptName` = 'npc_shadow_image' WHERE `entry` = 25214;
UPDATE `creature_template` SET `ScriptName` = 'boss_kalecgos_humanoid' WHERE `entry` = 24891;
UPDATE `creature_template` SET `ScriptName` = 'boss_sathrovarr' WHERE `entry` = 24892;
-- UPDATE `creature_template` SET `ScriptName` = 'mob_sunblade_scout' WHERE `entry` = 25372;
-- --
-- GO 
UPDATE `gameobject_template` SET ScriptName = 'go_spectral_rift' WHERE entry = 187055;
-- -------------
-- area triggers
DELETE FROM `scripted_areatrigger` WHERE entry = 4853;
INSERT INTO `scripted_areatrigger` VALUES (4853,'at_madrigosa');
-- -------------
-- spell_scripts for burn and stomp
-- scripts for 'burn' and 'stomp'
DELETE FROM `spell_scripts` WHERE `id` IN (45141, 45185);
INSERT INTO `spell_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`,`comments`) VALUES
('45141', '0', '15', '46394', '2', '0', '0', '0', '0', '0',""),
('45185', '0', '14', '46394', '1', '0', '0', '0', '0', '0',"");

-- ---------
-- felmyst
-- ---------
/* felmyst fight fixes

	Demonic Vampor (der Läufer)
    - unit flags (not attackable, pacified, not selectable)
    - bosslevel, fractions
    - speed
    - spawn/dmg aura
*/
UPDATE `creature_template` SET `unit_flags` = 0x2020002, `faction_A` = '16', `faction_H` = '16', `speed_run` = '0.95', `minlevel` = '73', `maxlevel` = '73', `ScriptName` = 'mob_felmyst_vapor' WHERE `entry` = 25265;
DELETE FROM `creature_template_addon` WHERE `entry` = '25265';
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `b2_0_sheath`, `b2_1_pvp_state`, `emote`, `moveflags`, `auras`) VALUES ('25265', '0', '0', '0', '0', '0', '0', '45411');
/*
	Demonic Vampor Trail ()
    - unit flags (not attackable, pacified, not selectable)
    - bosslevel, fractions
    - dmg auras
*/
UPDATE `creature_template` SET `unit_flags` = 0x2020002, `faction_A` = '16', `faction_H` = '16', `minlevel` = '73', `maxlevel` = '73', `ScriptName` = 'mob_felmyst_vapor_trail' WHERE `entry` = '25267';
/*
    Unyielding Death:
    - EventAI (Combat Pulse), "aggro range"
    - Aura
*/
UPDATE `creature_template` SET `AIName` = 'EventAI' WHERE `creature_template`.`entry` = 25268;
DELETE FROM `creature_template_addon` WHERE `entry` = '25268';
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `b2_0_sheath`, `b2_1_pvp_state`, `emote`, `moveflags`, `auras`) VALUES ('25268', '0', '0', '0', '0', '0', '0', '45415');
DELETE FROM `creature_ai_scripts` WHERE `id` = 2526801;
INSERT INTO `creature_ai_scripts` (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `comment`) VALUES
('2526801', '25268', '1', '0', '100', '2', '500', '500', '10000', '10000', '38', '0', '0', '0', 'Unyielding Death - zone combat pulse if ooc');
/* scipt targets spell */
DELETE FROM `spell_script_target` WHERE `entry` IN (45388);
INSERT INTO `spell_script_target` (`entry` ,`type` ,`targetEntry`)VALUES
('45388', '1', '25038');
/* Felmyst, bounding radius model */
UPDATE `creature_model_info` SET `bounding_radius` = '8', `combat_reach` = '5' WHERE `creature_model_info`.`modelid` = 22838;

-- ----------------------------- --
-- Instance SWP & Database Fixes --
-- ----------------------------- --

UPDATE `creature_template` SET `modelid_2` = 26628 WHERE `entry` = 24892; -- missing dispaly id for horde for sathrovarr
