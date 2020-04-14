#pragma once

struct Pallet
{
	int m_w;
	int m_h;	
};

void Rotate(Pallet& pallet);

void SortPalletes(Pallet* palletes);

int ArrangePalleats(Pallet* palletes);

int RunPalletes();