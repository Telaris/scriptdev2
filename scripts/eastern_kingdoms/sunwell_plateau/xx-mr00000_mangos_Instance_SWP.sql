/* SUNWELL PLATEAU */ 
-- ----------------------------- --
-- Instance SWP & Database Fixes --
-- ----------------------------- --
UPDATE `creature_template` SET `modelid_2` = 26628 WHERE `entry` = 24892; -- missing dispaly id for horde for sathrovarr

DELETE FROM `creature` WHERE `id`=24892; -- Sathrovarr the Corruptor spawned in wrong spot  .. will be spawned again in later script
DELETE FROM `creature` WHERE `id`=24891; -- Kalecgos humaniod form is spawned in wrong spot .. will be spawned again in later script

UPDATE `creature_template` SET `spell1` = 45026, `spell2` = 45027 WHERE `entry` = 24891; -- update kalecgos humaniod spells on creature template



-- -----------------------------------------------------------------------------------------------------------
-- ---------------
-- SWP SCRIPTNAMES
-- ---------------
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

-- ------------------------------------------------------------------------------------ --
