/* File: PioneerCarRadio.cpp
Project : OOP:: A-05 : The PioneerCarRadio Project
Programmer : Lukas Fukuoka Vieira
First version : 19 of July, 2024
Description : Handles the implementation of the PioneerCarRadio class, which inherits from the AmFmRadio class.
*/

#include "PioneerCarRadio.h"
#include <conio.h> // For _getch()
#include <iostream> // For C++ style output

// Constructor for PioneerCarRadio with power parameter
PioneerCarRadio::PioneerCarRadio(bool power) : AmFmRadio(power) {}

// Constructor for PioneerCarRadio with power parameter and preset frequencies
PioneerCarRadio::PioneerCarRadio(bool power, Freqs presets[5]) : AmFmRadio(power, presets) {}

// Destructor for PioneerCarRadio
PioneerCarRadio::~PioneerCarRadio()
{
    if (displayDestructor == 1)
    {
        printf("Destroying PioneerCarRadio\n");
    }
}

// Method to handle key presses for radio functions
void PioneerCarRadio::HandleKeyPress()
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
            case 'b':
                ToggleBand(); // Toggle band
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

// Method to display radio output
void PioneerCarRadio::DisplayOutput()
{
    displayDestructor = 1;
    printf("\nPioneer XS440\n");
    ShowCurrentSettings(); // Show current radio settings
}

// Method to show current radio settings
void PioneerCarRadio::ShowCurrentSettings()
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
        printf("\nFM Buttons: ");
        for (int j = 0; j < 5; ++j)
        {
            printf("%d: %.1f, ", j + 1, button[j].FMFreq);
        }
        printf("\n");
    }
    else
    {
        printf("Radio is off\n");
    }
}
