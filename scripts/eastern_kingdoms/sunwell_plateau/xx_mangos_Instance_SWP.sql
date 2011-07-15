/* SUNWELL PLATEAU */ 
-- -----------------------------------------------------------
-- official sd2 mangos scriptname sql and mangosR2 scriptnames
-- -----------------------------------------------------------

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
