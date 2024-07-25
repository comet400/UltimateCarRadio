/* File: PioneerAM.cpp
Project: OOP:: A-05 : The PioneerCarRadio Project
Programmer: Lukas Fukuoka Vieira
First version: 25 of July, 2024
Description: Implementation of the PioneerAM class, which extends the PioneerCarRadio class with AM-only functionality.
*/

#include "PioneerAM.h"
#include <iostream>
#include <conio.h> // For _getch()

// Constructor for PioneerAM with power parameter
PioneerAM::PioneerAM(bool power) : PioneerCarRadio(power)
{
    strcpy(band, "AM");
}

// Constructor for PioneerAM with power parameter and preset frequencies
PioneerAM::PioneerAM(bool power, Freqs presets[5]) : PioneerCarRadio(power, presets)
{
    strcpy(band, "AM");
}

// Destructor for PioneerAM
PioneerAM::~PioneerAM()
{
    if (displayDestructor == 2)
    {
        std::cout << "Destroying Pioneer XS440-AM Radio\n";
    }
}

// Overridden method to prevent band toggling
void PioneerAM::ToggleBand()
{
    // Do nothing since it's an AM-only radio
}

// Overridden method to show current radio settings
void PioneerAM::DisplayOutput()
{
	displayDestructor = 2;
    printf("\nPioneer XS440-AM\n");
    ShowCurrentSettings(); // Show current radio settings
}

void PioneerAM::ShowCurrentSettings()
{
    if (on)
    {
        printf("Radio is on\n");
        printf("Volume: %d\n", volume);
        printf("Current Station: %.1f %s\n", current_station, band);
        printf("AM Buttons: ");
        for (int i = 0; i < 5; ++i)
        {
            printf("%d: %d, ", i + 1, button[i].AMFreq);
        }
        printf("\n");
    }
    else
    {
        printf("Radio is off\n");
    }
}

void PioneerAM::HandleKeyPress()
{
    char key;
    while (true)
    {
        key = _getch(); // Get a key press
        if (key == 'x')
            break; // Exit loop if 'x' is pressed

        if (key == 'o')
        {
            PowerToggle(); // Toggle power
            DisplayOutput(); // Display radio output
            continue; // Skip the rest of the loop if 'o' is pressed
        }

        bool validKey = true;

        if (on)
        {
            switch (key)
            {
            case '+':
                SetVolume(volume + 1); // Increase volume
                break;
            case '_':
                SetVolume(volume - 1); // Decrease volume
                break;
            case '=':
                ScanUp(); // Scan up stations
                break;
            case '-':
                ScanDown(); // Scan down stations
                break;
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
                SelectPresetButton(key - '1'); // Select preset button
                break;
            case '!':
                SetPresetButton(0); // Set preset button 1
                break;
            case '@':
                SetPresetButton(1); // Set preset button 2
                break;
            case '#':
                SetPresetButton(2); // Set preset button 3
                break;
            case '$':
                SetPresetButton(3); // Set preset button 4
                break;
            case '%':
                SetPresetButton(4); // Set preset button 5
                break;
            default:
                validKey = false;
                break;
            }

            if (validKey)
                DisplayOutput(); // Display radio output if key is valid
        }
        else
        {
            switch (key)
            {
            case '+':
            case '_':
            case '=':
            case '-':
            case 'b':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '!':
            case '@':
            case '#':
            case '$':
            case '%':
                DisplayOutput(); // Display radio output if key is pressed when radio is off
                break;
            default:
                validKey = false;
                break;
            }
        }
    }
}

