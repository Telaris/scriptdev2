/* Copyright (C) 2006 - 2011 ScriptDev2 <http://www.scriptdev2.com/>
   Copyright (C) 2011 MangosR2_ScriptDev2 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/* ScriptData
SDName: boss_eredar_twins
SD%Complete:
SDComment:
SDCategory: Sunwell Plateau
EndScriptData */

#include "precompiled.h"
#include "sunwell_plateau.h"

enum
{
    SAY_INTRO_1                             = -1580044,
    SAY_INTRO_2                             = -1580045,
    SAY_INTRO_3                             = -1580046,
    SAY_INTRO_4                             = -1580047,
    SAY_INTRO_5                             = -1580048,
    SAY_INTRO_6                             = -1580049,
    SAY_INTRO_7                             = -1580050,
    SAY_INTRO_8                             = -1580051,

    SAY_SACROLASH_SHADOW_NOVA               = -1580052,
    SAY_SACROLASH_EMPOWER                   = -1580053,
    SAY_SACROLASH_KILL_1                    = -1580054,
    SAY_SACROLASH_KILL_2                    = -1580055,
    SAY_SACROLASH_DEAD                      = -1580056,
    SAY_SACROLASH_BERSERK                   = -1580057,

    SAY_ALYTHESS_CANFLAGRATION              = -1580058,
    SAY_ALYTHESS_EMPOWER                    = -1580059,
    SAY_ALYTHESS_KILL_1                     = -1580060,
    SAY_ALYTHESS_KILL_2                     = -1580061,
    SAY_ALYTHESS_DEAD                       = -1580062,
    SAY_ALYTHESS_BERSERK                    = -1580063,

    //Lady Sacrolash
    SPELL_DARK_TOUCHED      = 45347,
    SPELL_SHADOW_BLADES     = 45248, //10 secs
    SPELL_DARK_STRIKE       = 45271,
    SPELL_SHADOW_NOVA       = 45329, //30-35 secs
    SPELL_CONFOUNDING_BLOW  = 45256, //25 secs

    //Shadow Image spells
    SPELL_SHADOWFURY        = 45270,
    SPELL_IMAGE_VISUAL      = 45263,

    //Misc spells
    SPELL_TWINS_ENRAGE      = 46587, //27680
    SPELL_EMPOWER           = 45366,
    SPELL_DARK_FLAME        = 45345,
    AURA_CONF               = 44867, // :D

    //Grand Warlock Alythess spells
    SPELL_PYROGENICS        = 45230, //15secs
    SPELL_FLAME_TOUCHED     = 45348,
    SPELL_CONFLAGRATION     = 45342, //30-35 secs
    SPELL_CONFLAGRATION_DEV = 46768, //dmg
    SPELL_BLAZE             = 45235, //on main target every 3 secs
    SPELL_FLAME_SEAR        = 46771,

    //
    SPELL_BANISH            = 44836,
};

enum Creatures
{
    GRAND_WARLOCK_ALYTHESS  =   25166,
    MOB_SHADOW_IMAGE        =   25214,
    LADY_SACROLASH          =   25165
};

/*####
# boss_alythess
####*/

CreatureAI* GetAI_boss_alythess(Creature *_Creature)
{
    return new boss_alythessAI (_Creature);
}

/*####
# boss_sacrolash
####*/

CreatureAI* GetAI_boss_sacrolash(Creature *_Creature)
{
    return new boss_sacrolashAI (_Creature);
}

void AddSC_boss_eredar_twins()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_alythess";
    newscript->GetAI = &GetAI_boss_alythess;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "boss_sacrolash";
    newscript->GetAI = &GetAI_boss_sacrolash;
    newscript->RegisterSelf();
}
