#pragma once
#include "pch.h"
#include "util.h"
struct player_info_t
{
	char name[32];
};
class Engine
{
public:
	bool GetPlayerInfo(int index, player_info_t* info)
	{
		typedef bool(__thiscall* GetPlayerInfoFn)(void*, int, player_info_t*);
		return CallFunc<GetPlayerInfoFn>(this, 8)(this, index, info);
	}
	int GetLocalPlayer()
	{
		typedef int(__thiscall* GetLocalPlayerFn)(void*);
		return CallFunc<GetLocalPlayerFn>(this, 12)(this);
	}

};

