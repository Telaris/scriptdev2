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
SDName: boss_muru
SD%Complete:
SDComment:
SDCategory: Sunwell Plateau
EndScriptData */

#include "precompiled.h"
#include "sunwell_plateau.h"

enum spells // Boss spells
{
    ENRAGE                      = 26662,
    SPELL_NEGATIVE              = 46285,
    SPELL_NEGATIVEENERGY        = 46008,
    SPELL_NEGATIVEENERGY_CHAIN  = 46289,

    AURA_SINGULARITY            = 46228,
    AURA_SUNWELL_RADIANCE       = 45769,

    DARKNESS                    = 45996, // dokladnie sprawdzic
    ENTROPIUS_EFFECT            = 46223, // lipny ale zawsze cos

    //Dark Fiend
    DARK_FIEND_AURA             = 45934, // latajaca czaszka :D
    DARK_FIEND_DEBUFF           = 45944,
    SPELL_DISPELL               = 32375,
    SPELL_PURGE                 = 8012,

    SPELL_ARCANEFORM            = 48019, // Chaotic Rift visual

    VOID_AURA                   = 46087,
    VOID_BLAST                  = 46161,
};

enum summons
{
    ID_SWB                      = 25799, // ok
    ID_SWM                      = 25798, // ok niema bufa
    ID_DARK_FIEND               = 25744, // ok
    ID_VOID_SENTINEL            = 25772, // ok
    ID_SINGULARITY              = 25855, // visual effect i nie bic mele zmeiniac target?
    ID_SPAWN                    = 25824, // ok
};

//Boss sounds
#define SOUND_CHANGE_PHASE 12560
#define SAY_ENTROPIUS_SUMMON	-1950000
 
// Sumoned trash coordinates
float Trash[6][2] =
{
        {1853.300f,588.653f},
        {1781.502f,659.254f},
        {1853.300f,588.653f},
        {1853.300f,588.653f},     
        {1781.502f,659.254f},
        {1781.502f,659.254f},
};

float ShadowPortalSpawn[5][3] =
{
        {1797.644f,613.744f,0.56290f},
        {1822.956f,646.437f,4.40262f},
        {1794.275f,626.539f,6.23522f},
        {1809.726f,646.494f,5.01348f},     
        {1798.854f,638.952f,5.62435f}
};

/*####
# boss_muru
####*/

struct MANGOS_DLL_DECL boss_muruAI : public ScriptedAI
{
    boss_muruAI(Creature *c) : ScriptedAI(c) 
    {
	    pInstance = ((ScriptedInstance*)c->GetInstanceData());
	    Reset(); 
    }

    ScriptedInstance* pInstance;

    void Reset()
    {
         m_creature->SetVisibility(VISIBILITY_ON);
   
        if(m_creature->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
            m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);

       // if(!m_creature->HasAura(AURA_SUNWELL_RADIANCE, 0))
         //   m_creature->CastSpell(m_creature, AURA_SUNWELL_RADIANCE, true);

        if(pInstance)
            pInstance->SetData(TYPE_MURU, NOT_STARTED);
    }

    void Aggro(Unit *who) 
    {
        m_creature->StopMoving();
        m_creature->GetMotionMaster()->Clear();
        m_creature->GetMotionMaster()->MoveIdle();
    } 

    void KilledUnit(Unit *Victim) {}

    void JustDied(Unit* Killer) 
    {
        if(!Killer)
            return;
    }
};

CreatureAI* GetAI_boss_muru(Creature *_Creature)
{
    return new boss_muruAI(_Creature);
}

void AddSC_boss_muru()
{
    Script *newscript;
        
    newscript = new Script;
    newscript->Name="boss_muru";
    newscript->GetAI = &GetAI_boss_muru;
    newscript->RegisterSelf();
}
