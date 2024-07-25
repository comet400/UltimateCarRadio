/* File: AmFmRadio.cpp
Project : OOP:: A-05 : The PioneerCarRadio Project
Programmer : Lukas Fukuoka Vieira
First version : 19 of july, 2024
Description : Implementation of the AmFmRadio class, which simulates the functionality of a car radio with AM and FM bands.
*/

#include "AmFmRadio.h"

// Constructor for AmFmRadio with power parameter
AmFmRadio::AmFmRadio(bool power)
{
    // Initialize preset buttons with initial frequencies
    for (int i = 0; i < 5; ++i)
    {
        button[i].AMFreq = INITIAL_FREQUENCY_AM;
        button[i].FMFreq = INITIAL_FREQUENCY_FM;
    }
    current_station = INITIAL_FREQUENCY_AM; // Set current station to initial AM frequency
    strcpy(band, "AM"); // Set band to AM
    volume = 0; // Initialize volume to 0
    on = power; // Set power status
    last_freq.AMFreq = INITIAL_FREQUENCY_AM; // Store last AM frequency
    last_freq.FMFreq = INITIAL_FREQUENCY_FM; // Store last FM frequency
    last_volume = 0; // Store last volume
    displayOutput = false; // Ensure display output is disabled
	displayDestructor = 0;
}

// Constructor for AmFmRadio with power parameter and preset frequencies
AmFmRadio::AmFmRadio(bool power, Freqs presets[5])
{
    // Initialize preset buttons with given frequencies
    for (int i = 0; i < 5; ++i)
    {
        button[i] = presets[i];
    }
    current_station = presets[0].AMFreq; // Set current station to first preset AM frequency
    strcpy(band, "AM"); // Set band to AM
    volume = 0; // Initialize volume to 0
    on = power; // Set power status
    last_freq = presets[0]; // Store last frequency
    last_volume = 0; // Store last volume
    displayOutput = false; // Ensure display output is disabled
	displayDestructor = 0;
}

// Destructor for AmFmRadio
AmFmRadio::~AmFmRadio()
{
       printf("Destroying AmFmRadio\n"); // Display destruction message if enabled
}

// Method to toggle power on/off
void AmFmRadio::PowerToggle()
{
    if (on)
    {
        on = false; // Turn off radio
        last_volume = volume; // Store last volume
        volume = 0; // Set volume to 0

        if (strcmp(band, "AM") == 0)
        {
            last_freq.AMFreq = current_station; // Store current AM frequency
            current_station = 0; // Reset current station
        }
        else
        {
            last_freq.FMFreq = current_station; // Store current FM frequency
            current_station = 0; // Reset current station
        }
    }
    else
    {
        on = true; // Turn on radio
        volume = last_volume; // Restore last volume

        if (strcmp(band, "AM") == 0)
        {
            current_station = last_freq.AMFreq; // Restore last AM frequency
        }
        else
        {
            current_station = last_freq.FMFreq; // Restore last FM frequency
        }
    }
}

int AmFmRadio::setDisplayDestructor(int displayDestructor)
{
    this->displayDestructor = displayDestructor;
	return 1;
}

int AmFmRadio::getDisplayDestructor()
{
    return displayDestructor;
}

// Method to check if radio is on
bool AmFmRadio::IsRadioOn()
{
    return on;
}

// Method to toggle between AM and FM bands
void AmFmRadio::ToggleBand()
{
    if (strcmp(band, "AM") == 0)
    {
        strcpy(band, "FM"); // Switch to FM band
        last_freq.AMFreq = current_station; // Store current AM frequency
        current_station = last_freq.FMFreq; // Set current station to last FM frequency
    }
    else
    {
        strcpy(band, "AM"); // Switch to AM band
        last_freq.FMFreq = current_station; // Store current FM frequency
        current_station = last_freq.AMFreq; // Set current station to last AM frequency
    }
}

// Method to set a preset button
int AmFmRadio::SetPresetButton(int button_num)
{
    if ((button_num >= 0) && (button_num <= 4))
    {
        if (strcmp(band, "AM") == 0)
        {
            button[button_num].AMFreq = current_station; // Set AM frequency for button
        }
        else if (strcmp(band, "FM") == 0)
        {
            button[button_num].FMFreq = current_station; // Set FM frequency for button
        }
        else
        {
            return 0; // Failure
        }
        return 1; // Success
    }
    return 0; // Failure
}

void AmFmRadio::ShowCurrentSettings()
{
    if (displayOutput)
    {
        if (on)
        {
            printf("\n\nRadio is on.\n");
        }
        else
        {
            printf("\n\nRadio is off.\n");
        }
        printf("\nRadio Band: %s\n", band); // Display band
        printf("Volume: %d\n", volume); // Display volume
        printf("Current Station: %.1f %s\n", current_station, band); // Display current station and band
        printf("AM Button Settings: ");
        for (int i = 0; i < 5; ++i)
        {
            printf("%d) %6d ", i + 1, button[i].AMFreq); // Display AM button settings
        }
        printf("\nFM Button Settings: ");
        for (int j = 0; j < 5; ++j)
        {
            printf("%d) %6.1f ", j + 1, button[j].FMFreq); // Display FM button settings
        }
    }
}

// Method to select a preset button
int AmFmRadio::SelectPresetButton(int button_num)
{
    if ((button_num >= 0) && (button_num <= 4))
    {
        if (strcmp("AM", band) == 0)
        {
            current_station = button[button_num].AMFreq; // Set current station to preset AM frequency
        }
        else
        {
            current_station = button[button_num].FMFreq; // Set current station to preset FM frequency
        }
        return 1; // Success
    }
    return 0; // Failure
}

// Method to set volume with user input
int AmFmRadio::SetVolume()
{
    char buf[20] = "";
    fgets(buf, sizeof buf, stdin); // Get user input for volume
    volume = atoi(buf); // Convert input to integer

    if (volume < 0)
    {
        volume = 0; // Set volume to 0 if input is negative
        return 0; // Volume set to 0
    }
    if (volume > 100)
    {
        volume = 100; // Set volume to 100 if input exceeds 100
        return 2; // Volume set to 100
    }
    return 1; // Volume set successfully
}

// Method to set volume with given value
int AmFmRadio::SetVolume(int new_volume)
{
    volume = new_volume;
    printf("\nEnter the volume level (0 - 100). "); // Prompt user for volume input
    if (volume < 0)
    {
        volume = 0; // Set volume to 0 if input is negative
        return 0; // Volume set to 0
    }
    if (volume > 100)
    {
        volume = 100; // Set volume to 100 if input exceeds 100
        return 2; // Volume set to 100
    }
    return 1; // Volume set successfully
}

// Method to scan up the stations
void AmFmRadio::ScanUp()
{
    if (strcmp("AM", band) == 0)
    {
        if (current_station >= 1700)
        {
            current_station = 530; // Wrap around to initial AM frequency
        }
        else
        {
            current_station += 10; // Increment AM frequency
        }
    }
    else
    {
        if (current_station >= 107.9)
        {
            current_station = 87.9; // Wrap around to initial FM frequency
        }
        else
        {
            current_station += 0.2; // Increment FM frequency
        }
    }
}

// Method to scan down the stations
void AmFmRadio::ScanDown()
{
    if (strcmp("AM", band) == 0)
    {
        if (current_station <= 530)
        {
            current_station = 1700; // Wrap around to maximum AM frequency
        }
        else
        {
            current_station -= 10; // Decrement AM frequency
        }
    }
    else
    {
        if (current_station <= 87.9)
        {
            current_station = 107.9; // Wrap around to maximum FM frequency
        }
        else
        {
            current_station -= 0.2; // Decrement FM frequency
        }
    }
}

// Method to set display output flag
void AmFmRadio::SetDisplayOutput(bool display)
{
    displayOutput = display;
}

// Method to get display output flag
bool AmFmRadio::GetDisplayOutput() const
{
    return displayOutput;
}

// Method to get current station
double AmFmRadio::GetCurrentStation() const
{
    return current_station;
}

// Method to get current volume
int AmFmRadio::GetCurrentVolume() const
{
    return volume;
}

// Method to get radio presets
const Freqs* AmFmRadio::GetRadioPresets() const
{
    return button;
}

// Method to get current band
const char* AmFmRadio::GetCurrentBand() const
{
    return band;
}
