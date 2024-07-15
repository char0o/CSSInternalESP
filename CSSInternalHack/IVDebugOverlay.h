#pragma once
#include "pch.h"
#include "util.h"
#include "QAngle.h"
#include "Vector.h"
class IVDebugOverlay
{
public:
	void AddBoxOverlay(const Vector& origin, const Vector& mins, const Vector& max, QAngle const& orientation, int r, int g, int b, int a, float duration)
	{
		typedef void(__thiscall* OriginalFn)(void*, const Vector& origin, const Vector& mins, const Vector& max, QAngle const& orientation, int r, int g, int b, int a, float duration);
		CallFunc<OriginalFn>(this, 1)(this, origin, mins, max, orientation, r, g, b, a, duration);
	};
	int ScreenPosition(const Vector& vIn, Vector& vOut)
	{
		return find_vfunc<int(__thiscall*)(PVOID,const Vector&, Vector&)>(this, 9)(this, vIn, vOut);
	};
	bool WorldToScreen(Vector& world, Vector& screen) //from my old cheat
	{
		return (ScreenPosition(world, screen) != 1);
	}
};