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
SDName: boss_felmyst
SD%Complete:
SDComment:
SDCategory: Sunwell Plateau
EndScriptData */

#include "precompiled.h"
#include "sunwell_plateau.h"

enum
{
    SAY_INTRO           = -1580036,
    SAY_KILL_1          = -1580037,
    SAY_KILL_2          = -1580038,
    //SAY_KILL_3          = ???????,
    //SAY_AGGRO           = ???????,
    //SAY_CLEAVE          = ???????,
    SAY_DEATH           = -1580042,
    SAY_TAKEOFF         = -1580040,
    SAY_BREATH          = -1580039,
    SAY_BERSERK         = -1580041,
    SAY_KALECGOS_OUTRO  = -1580043,

    //Aura
    SPELL_SUNWELLRADIANCE_AURA  = 45769,
    SPELL_NOXIOUSFUMES_AURA     = 47002,
 
    //Land Phase
    SPELL_CLEAVE                = 19983, 
    SPELL_CORROSION             = 45866,
    SPELL_GASNOVA               = 45855,
    SPELL_ENCAPSULATE_CHANNEL   = 45661,
    SPELL_ENCAPSULATE_AOE       = 45662,
   
    //Flight Phase
    SPELL_VAPOR_DAMAGE          = 46931, // vapor damage, 4000
    SPELL_TRAIL_TRIGGER         = 45399, // trail to self, trigger 454
   
    //Other
    SPELL_ENRAGE                = 26662,
    SPELL_BERSERK               = 45078,

    //Fog of Mind Control
    SPELL_FOG_TRIGGER           = 45582, // Visual Effect
    SPELL_FOG_CHARM             = 45717, // Damage, Speed Increased
    SPELL_KILL                  = 5,

    //Image Of Players Spells
    SPELL_PRIEST                = 47077, // 100%
    SPELL_PALADIN               = 37369, // 100%
    SPELL_PALADIN2              = 37369, // 100%
    SPELL_WARLOCK               = 46190, // 100%
    SPELL_WARLOCK2              = 47076, // 100%
    SPELL_MAGE                  = 47074, // 100%
    SPELL_ROGUE                 = 45897, // 100%
    SPELL_WARRIOR               = 17207, // 100%
    SPELL_DRUID                 = 47072, // 100%
    SPELL_SHAMAN                = 47071, // 100%
    SPELL_HUNTER                = 48098, // 100%
};
 
enum Creatures
{
    MOB_FELMYST         = 25038,
    MOB_DEAD            = 25268, //undead podczas fly fazy
 
    MOB_MADRIGOSA       = 25160,
    MOB_FELMYST_VISUAL  = 25041,
    MOB_FLIGHT_LEFT     = 25357,
    MOB_FLIGHT_RIGHT    = 25358,
 
    MOB_VAPOR           = 25265,
    MOB_VAPOR_TRAIL     = 25267,

    MOB_DEATH_CLOUD     = 25703,

    CREATURE_IMAGE      = 25708,
};

struct MANGOS_DLL_DECL boss_felmystAI : public ScriptedAI
{
    boss_felmystAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = ((ScriptedInstance*)c->GetInstanceData());
        Reset();
    }

    ScriptedInstance* pInstance;


    void Reset()
    {
        //Event Resets
        m_creature->SetVisibility(VISIBILITY_OFF);
        m_creature->setFaction(35);

        if(pInstance)
            pInstance->SetData(TYPE_FELMYST, NOT_STARTED);

        if(!m_creature->HasAura(SPELL_SUNWELLRADIANCE_AURA))
            DoCast(m_creature, SPELL_SUNWELLRADIANCE_AURA);
    }

    void Aggro(Unit *who)
    {
        m_creature->SetInCombatWithZone();
        DoScriptText(YELL_AGGRO, m_creature);
 
        if (pInstance)
            pInstance->SetData(TYPE_FELMYST, IN_PROGRESS);
    }

    void KilledUnit(Unit* victim)
    {
        switch(rand()%3)
        {
            case 0: DoScriptText(YELL_SLAY1, m_creature); break;
            case 1: DoScriptText(YELL_SLAY2, m_creature); break;
            case 2: DoScriptText(YELL_SLAY3, m_creature); break;
        }
        switch(rand()%2)
        {
            case 0: DoPlaySoundToSet(m_creature, 12480); break;
            case 1: DoPlaySoundToSet(m_creature, 12481); break;
        }
    }
 
    void JustDied(Unit* Killer)
    {
        DoScriptText(YELL_DEATH, m_creature);
        DoPlaySoundToSet(m_creature, 12483);

        if(pInstance)
            pInstance->SetData(TYPE_FELMYST, DONE);
    }

CreatureAI* GetAI_boss_felmyst(Creature *_Creature)
{
    return new boss_felmystAI(_Creature);
}

void AddSC_boss_felmyst()
{
    Script *newscript;
 
    newscript = new Script;
    newscript->Name = "boss_felmyst";
    newscript->GetAI = &GetAI_boss_felmyst;
    newscript->RegisterSelf();
}
