/* File: PioneerWorld.cpp
Project: OOP:: A-05 : The PioneerCarRadio Project
Programmer: Lukas Fukuoka Vieira
First version: 25 of July, 2024
Description: Implementation of the PioneerWorld class, which extends the PioneerAM class with different frequency range and intervals.
*/

#include "PioneerWorld.h"
#include <iostream>

// Constructor for PioneerWorld with power parameter
PioneerWorld::PioneerWorld(bool power) : PioneerAM(power)
{
    // Initialize all presets to 531
    for (int i = 0; i < 5; ++i)
    {
        button[i].AMFreq = PIONEER_WORLD_FREQUENCY;
    }
    current_station = PIONEER_WORLD_FREQUENCY;
}

// Constructor for PioneerWorld with power parameter and preset frequencies
PioneerWorld::PioneerWorld(bool power, Freqs presets[5]) : PioneerAM(power, presets)
{
    // Initialize all presets to 531
    for (int i = 0; i < 5; ++i)
    {
        button[i] = presets[0];
    }
    current_station = PIONEER_WORLD_FREQUENCY;
}

// Destructor for PioneerWorld
PioneerWorld::~PioneerWorld()
{
    if (displayDestructor == 3)
    {
        std::cout << "Destroying Pioneer XS440-WRLD Radio\n";
    }
}

// Overridden method to scan up the stations
void PioneerWorld::ScanUp()
{
    if (current_station >= 1602)
    {
        current_station = 531;
    }
    else
    {
        current_station += 9;
    }
}

// Overridden method to scan down the stations
void PioneerWorld::ScanDown()
{
    if (current_station <= 531)
    {
        current_station = 1602;
    }
    else
    {
        current_station -= 9;
    }
}


void PioneerWorld::DisplayOutput()
{
	displayDestructor = 3;
    printf("\nPioneer XS440-WRLD\n");
    ShowCurrentSettings(); // Show current radio settings
}






