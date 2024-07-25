/* File: PioneerWorld.h
Project: OOP:: A-05 : The PioneerCarRadio Project
Programmer: Lukas Fukuoka Vieira
First version: 25 of July, 2024
Description: Header file for the PioneerWorld class, which extends the PioneerAM class with different frequency range and intervals.
*/

#ifndef _PIONEER_WORLD_H
#define _PIONEER_WORLD_H

#include "PioneerAM.h"
#define PIONEER_WORLD_FREQUENCY 531

// PioneerWorld class definition
class PioneerWorld : public PioneerAM
{
public:
    // Constructors
    PioneerWorld(bool power = false);
    PioneerWorld(bool power, Freqs presets[5]);

    // Destructor
    virtual ~PioneerWorld();

    // Overridden methods
    virtual void ScanUp() override;
    virtual void ScanDown() override;
    virtual void DisplayOutput();
};

#endif
