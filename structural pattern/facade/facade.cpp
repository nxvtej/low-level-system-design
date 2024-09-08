#include <iostream>
#include <string>

// Subsystem 1: DVD Player
class DVDPlayer
{
public:
    void on()
    {
        std::cout << "DVD Player is on." << std::endl;
    }
    void play(const std::string &movie)
    {
        std::cout << "Playing movie: " << movie << std::endl;
    }
    void off()
    {
        std::cout << "DVD Player is off." << std::endl;
    }
};

// Subsystem 2: Projector
class Projector
{
public:
    void on()
    {
        std::cout << "Projector is on." << std::endl;
    }
    void off()
    {
        std::cout << "Projector is off." << std::endl;
    }
    void wideScreenMode()
    {
        std::cout << "Projector is in widescreen mode." << std::endl;
    }
};

// Subsystem 3: Sound System
class SoundSystem
{
public:
    void on()
    {
        std::cout << "Sound System is on." << std::endl;
    }
    void setSurroundSound()
    {
        std::cout << "Sound System set to surround sound." << std::endl;
    }
    void off()
    {
        std::cout << "Sound System is off." << std::endl;
    }
};

// Subsystem 4: Lights
class TheaterLights
{
public:
    void dim(int level)
    {
        std::cout << "Lights dimming to " << level << "%" << std::endl;
    }
};

// Facade: Home Theater Facade
class HomeTheaterFacade
{
private:
    DVDPlayer *dvdPlayer;
    Projector *projector;
    SoundSystem *soundSystem;
    TheaterLights *lights;

public:
    HomeTheaterFacade(DVDPlayer *dvd, Projector *proj, SoundSystem *sound, TheaterLights *light)
        : dvdPlayer(dvd), projector(proj), soundSystem(sound), lights(light) {}

    // Simplified interface to start the movie
    void watchMovie(const std::string &movie)
    {
        std::cout << "Get ready to watch a movie..." << std::endl;
        lights->dim(10);
        projector->on();
        projector->wideScreenMode();
        soundSystem->on();
        soundSystem->setSurroundSound();
        dvdPlayer->on();
        dvdPlayer->play(movie);
    }

    // Simplified interface to end the movie
    void endMovie()
    {
        std::cout << "Shutting movie theater down..." << std::endl;
        lights->dim(100);
        projector->off();
        soundSystem->off();
        dvdPlayer->off();
    }
};

// Main function to demonstrate the Facade Pattern
int main()
{
    // Create subsystem objects
    DVDPlayer dvd;
    Projector projector;
    SoundSystem soundSystem;
    TheaterLights lights;

    // Create a facade to simplify the operation of the home theater system
    HomeTheaterFacade homeTheater(&dvd, &projector, &soundSystem, &lights);

    // Using the facade to watch a movie
    homeTheater.watchMovie("The Matrix");

    std::cout << std::endl;

    // Using the facade to shut down the system
    homeTheater.endMovie();

    return 0;
}
