/* File: PioneerCarRadio.h
Project : OOP:: A-05 : The PioneerCarRadio Project
Programmer : Lukas Fukuoka Vieira
First version : 19 of July, 2024
Description : Header file for the PioneerCarRadio class, which extends the AmFmRadio class with additional functionality.
*/

#ifndef _PIONEER_CAR_RADIO_H
#define _PIONEER_CAR_RADIO_H

#include "AmFmRadio.h"

// PioneerCarRadio class definition
class PioneerCarRadio : public AmFmRadio
{
public:
    // Constructors
    PioneerCarRadio(bool power = false); // Default constructor with power parameter
    PioneerCarRadio(bool power, Freqs presets[5]); // Constructor with power and presets parameters

    // Destructor
    virtual ~PioneerCarRadio(); // Destructor

    // Methods
    virtual void HandleKeyPress(); // Method to handle key presses
    virtual void ShowCurrentSettings() override; // Override to include radio name

private:
    void DisplayOutput(); // Method to display output
};

#endif

