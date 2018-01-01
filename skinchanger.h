/*MIT License

Copyright (c) namazso 2018 

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.*/

/*
      ___           ___           ___           ___     
     /\  \         |\__\         /\  \         /\__\    
    /::\  \        |:|  |       /::\  \       /::|  |   
   /:/\:\  \       |:|  |      /:/\:\  \     /:|:|  |   
  /:/  \:\  \      |:|__|__   /::\~\:\  \   /:/|:|  |__ 
 /:/__/ \:\__\     /::::\__\ /:/\:\ \:\__\ /:/ |:| /\__\
 \:\  \  \/__/    /:/~~/~~   \/__\:\/:/  / \/__|:|/:/  /
  \:\  \         /:/  /           \::/  /      |:/:/  / 
   \:\  \        \/__/            /:/  /       |::/  /  
    \:\__\                       /:/  /        /:/  /   
     \/__/                       \/__/         \/__/    

revolt (4/2017)
credit: Synraw @ unknowncheats.me
*/

#pragma once

#ifndef SKINCHANGER_H
#define SKINCHANGER_H

#include <unordered_map>
#include "IBaseClientDLL.h"

struct SkinObject_t
{
public:
	SkinObject_t() = default;
	SkinObject_t(int ind, int nSeed, int paint, float fl, bool stat, int trak, int quality, const char* n = "", int s1 = 0, int s2 = 0, int s3 = 0, int s4 = 0);

	int index;
	int seed;
	int iPaintKit;
	float flFloat;
	bool bStatTrak;
	int iStatTrak;
	int iEntityQuality;
	std::string name;

	int iStickerOne;
	int iStickerTwo;
	int iStickerThree;
	int iStickerFour;

	void AddStickers(int, int, int, int);
	int GetStickerID(int slot);
	AttribItem_t ToAttribItem();
};

namespace SkinChanger
{
	extern std::unordered_map<int, SkinObject_t> skin_map;
	
	void FrameStageNotify();

	SkinObject_t* GetSkinObjectByIndex(ItemDefinitionIndex);
	std::string GetSkinNameByIndex(int);

	void Initialize();
	void SaveConfig();
	void LoadConfig();

	void SaveMenuToMap();
	void ForceRefresh();

	void Hooked_RecvProxy_Viewmodel(const CRecvProxyData*, void*, void*);
}

#endif
