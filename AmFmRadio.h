/* File: AmFmRadio.h
Project : OOP:: A-05 : The PioneerCarRadio Project
Programmer : Lukas Fukuoka Vieira
First version : 19 of June, 2024
Description : Header file for the AmFmRadio class, which simulates a car radio with AM and FM bands.
*/

#ifndef _AMFM_RADIO_H
#define _AMFM_RADIO_H

#include <iostream> // Include for C++ style output
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#pragma warning(disable: 4244)
#pragma warning(disable: 4996)

#define INITIAL_FREQUENCY_AM 531 // Initial AM frequency
#define INITIAL_FREQUENCY_FM 87.9 // Initial FM frequency

// Struct to store frequencies for AM and FM bands
struct Freqs
{
    int AMFreq; // AM frequency
    double FMFreq; // FM frequency
};

// AmFmRadio class definition
class AmFmRadio
{
protected:
    Freqs button[5]; // Preset buttons
    double current_station; // Current station frequency
    char band[3]; // Current band (AM/FM)
    int volume; // Current volume level
    bool on; // Power status
    Freqs last_freq; // Last frequency settings
    int last_volume; // Last volume setting
    bool displayOutput; // Display output flag
    int displayDestructor;
public:
    // Constructors
    AmFmRadio(bool power = false); // Default constructor with power parameter
    AmFmRadio(bool power, Freqs presets[5]); // Constructor with power and presets parameters

    // Destructor
    virtual ~AmFmRadio(); // Destructor

    // Methods
    virtual void PowerToggle(); // Method to toggle power on/off
    virtual bool IsRadioOn(); // Method to check if radio is on
    virtual void ToggleBand(); // Method to toggle between AM and FM bands
    virtual int SetPresetButton(int button_num); // Method to set a preset button
    virtual int SelectPresetButton(int button_num); // Method to select a preset button
    virtual int SetVolume(); // Method to set volume with user input
    virtual int SetVolume(int new_volume); // Method to set volume with given value
    virtual void ScanUp(); // Method to scan up the stations
    virtual void ScanDown(); // Method to scan down the stations

    // Mutators
    void SetDisplayOutput(bool display); // Method to set display output flag
    bool GetDisplayOutput() const; // Method to get display output flag
    double GetCurrentStation() const; // Method to get current station
    int GetCurrentVolume() const; // Method to get current volume
    const Freqs* GetRadioPresets() const; // Method to get radio presets
    const char* GetCurrentBand() const; // Method to get current band
    virtual void ShowCurrentSettings(); // Method to show current radio settings
    int setDisplayDestructor(int displayDestructor);
    int getDisplayDestructor();
};

#endif
