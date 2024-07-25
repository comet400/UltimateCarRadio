#include "PioneerCarRadio.h"
#include "PioneerAM.h"
#include "PioneerWorld.h"
#include <iostream>
#include <stdexcept>
#include <conio.h>

PioneerCarRadio* createRadio(const std::string& type);
void handleInteractiveInput();
void handleCommandLineArgs(int argc, char* argv[]);

PioneerCarRadio* createRadio(const std::string& type)
{
    Freqs presets[5] = { {1000, 102.1}, {1210, 104.3}, {800, 100.1}, {700, 99.3}, {1300, 89.7} };
    if (type == "-car")
    {
        return new PioneerCarRadio(false,presets);
    }
    else if (type == "-am")
    {
        return new PioneerAM(false,presets);
    }
    else if (type == "-world")
    {
        return new PioneerWorld(false);
    }
    else
    {
        throw std::invalid_argument("Invalid radio type");
    }
}

void handleCommandLineArgs(int argc, char* argv[]) 
{
    if (argc > 1) 
    {
        std::string type = argv[1];
        PioneerCarRadio* pRadio = nullptr;
        try 
        {
            pRadio = createRadio(type);
            if (type == "-car")
            {
                pRadio->setDisplayDestructor(1);
            }
            else if (type == "-am")
            {
                pRadio->setDisplayDestructor(2);
            }
            else if (type == "-world")
            {
                pRadio->setDisplayDestructor(3);
            }
            pRadio->HandleKeyPress();
            delete pRadio;
        }
        catch (const std::exception& e)
        {
            std::cout << "Error: " << e.what() << std::endl;
			exit(1);
        }
    }
}

void handleInteractiveInput() 
{
    Freqs presets[5] = { {1000, 102.1}, {1210, 104.3}, {800, 100.1}, {700, 99.3}, {1300, 89.7} };
    PioneerCarRadio* pRadio = nullptr;
    std::string choice;
    while (true) 
    {
        std::cout << "Press 'c' to create a PioneerCarRadio, 'a' for PioneerAM, 'w' for PioneerWorld, 'x' to quit: ";
		choice = _getch();

        if (choice == "x") 
        {
            break;
        }

        try 
        {
            if (choice != "c" && choice != "a" && choice != "w" && choice != "x")
            {
				while (choice != "c" && choice != "a" && choice != "w" && choice != "x")
				{
					choice = _getch();
				}
            }
                if (choice == "c")
                {
                    pRadio = new PioneerCarRadio(false, presets);
                    pRadio->setDisplayDestructor(1);
                }
                else if (choice == "a")
                {
                    pRadio = new PioneerAM(false, presets);
                    pRadio->setDisplayDestructor(2);
                }
                else if (choice == "w")
                {
                    pRadio = new PioneerWorld(false);
                    pRadio->setDisplayDestructor(3);
                }
                else
                {
                    continue;
                }
            
            pRadio->HandleKeyPress();
            delete pRadio;
        }
        catch (const std::exception& e) 
        {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
}


int main(int argc, char* argv[])
{
    
    if (argc > 1)
    {
        handleCommandLineArgs(argc, argv);
    }
        handleInteractiveInput();

    return 0;
}

