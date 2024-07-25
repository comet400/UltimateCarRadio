/* File: PioneerAM.h
Project: OOP:: A-05 : The PioneerCarRadio Project
Programmer: Lukas Fukuoka Vieira
First version: 25 of July, 2024
Description: Header file for the PioneerAM class, which extends the PioneerCarRadio class with AM-only functionality.
*/

#ifndef _PIONEER_AM_H
#define _PIONEER_AM_H

#include "PioneerCarRadio.h"

// PioneerAM class definition
class PioneerAM : public PioneerCarRadio
{
public:
    // Constructors
    PioneerAM(bool power = false);
    PioneerAM(bool power, Freqs presets[5]);

    // Destructor
    virtual ~PioneerAM();

    // Overridden methods
    virtual void ToggleBand() override;
    virtual void ShowCurrentSettings() override;
    virtual void HandleKeyPress();
    virtual void DisplayOutput();
};

#endif
