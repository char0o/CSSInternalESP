#pragma once
#include "pch.h"

class ESP
{
public:
	ESP();
	ESP(Interfaces* interfaces)
	{
		I = interfaces;
		localPlayer = reinterpret_cast<CBaseEntity*>(I->entityList->GetClientEntity(I->engine->GetLocalPlayer()));
	}
	CBaseEntity* localPlayer;
	Interfaces* I;
	void Draw()
	{
		for (int i = 1; i < 64; i++)
		{
			CBaseEntity* player = reinterpret_cast<CBaseEntity*>(I->entityList->GetClientEntity(i));
			if (!player)
				continue;
			if (!player->IsPlayer())
				continue;
			if (player == localPlayer)
				continue;
			if (player->GetTeam() == localPlayer->GetTeam())
				continue;
			if (!player->IsAlive())
				continue;
			if (player->IsDormant())
				continue;
			I->debugOverlay->AddBoxOverlay(player->GetPos(), Vector(-20, -20, 0), Vector(20, 20, 60), QAngle(0, 0, 0), 200, 0, 0, 5, 0.1);
		}
	}
};