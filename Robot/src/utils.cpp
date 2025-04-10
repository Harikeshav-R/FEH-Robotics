#include "utils.h"


namespace robot
{
    float degrees_to_radians(int degrees)
    {
        return (3.14 / 180) * degrees;
    }

    float degrees_to_radians(float degrees)
    {
        return (3.14 / 180) * degrees;
    }

    void sing_the_zelda_theme_song()
    {
        Buzzer.Tone(FEHBuzzer::A5, 1000);
        Buzzer.Tone(FEHBuzzer::A5, 100);
        Buzzer.Tone(FEHBuzzer::A5, 100);
        Buzzer.Tone(FEHBuzzer::A5, 100);
        Buzzer.Tone(FEHBuzzer::A5, 100);
        Buzzer.Tone(FEHBuzzer::A5, 500);
        Buzzer.Tone(FEHBuzzer::G4, 100);
        Buzzer.Tone(FEHBuzzer::A5, 500);
        Buzzer.Tone(FEHBuzzer::A5, 100);
        Buzzer.Tone(FEHBuzzer::A5, 100);
        Buzzer.Tone(FEHBuzzer::A5, 100);
        Buzzer.Tone(FEHBuzzer::A5, 100);
        Buzzer.Tone(FEHBuzzer::A5, 500);
        Buzzer.Tone(FEHBuzzer::G4, 100);
        Buzzer.Tone(FEHBuzzer::A5, 500);
        Buzzer.Tone(FEHBuzzer::A5, 100);
        Buzzer.Tone(FEHBuzzer::A5, 100);
        Buzzer.Tone(FEHBuzzer::A5, 100);
        Buzzer.Tone(FEHBuzzer::A5, 100);
        Buzzer.Tone(FEHBuzzer::A5, 100);
        Buzzer.Tone(FEHBuzzer::E4, 50);
        Buzzer.Tone(FEHBuzzer::E4, 50);
        Buzzer.Tone(FEHBuzzer::E4, 100);
        Buzzer.Tone(FEHBuzzer::E4, 50);
        Buzzer.Tone(FEHBuzzer::E4, 50);
        Buzzer.Tone(FEHBuzzer::E4, 100);
        Buzzer.Tone(FEHBuzzer::E4, 50);
        Buzzer.Tone(FEHBuzzer::E4, 50);
        Buzzer.Tone(FEHBuzzer::E4, 100);
        Buzzer.Tone(FEHBuzzer::E4, 100);
        Buzzer.Tone(FEHBuzzer::A5, 500);
        Buzzer.Tone(FEHBuzzer::E4, 750);
        Buzzer.Tone(FEHBuzzer::A5, 100);
        Buzzer.Tone(FEHBuzzer::A5, 50);
        Buzzer.Tone(FEHBuzzer::B5, 50);
        Buzzer.Tone(FEHBuzzer::Cs5, 50);
        Buzzer.Tone(FEHBuzzer::D5, 50);
        Buzzer.Tone(FEHBuzzer::E5, 1000);
        Buzzer.Tone(FEHBuzzer::E5, 100);
        Buzzer.Tone(FEHBuzzer::E5, 100);
        Buzzer.Tone(FEHBuzzer::F5, 100);
        Buzzer.Tone(FEHBuzzer::G5, 100);
        Buzzer.Tone(FEHBuzzer::A6, 1000);
        Buzzer.Tone(FEHBuzzer::A6, 100);
        Buzzer.Tone(FEHBuzzer::A6, 100);
        Buzzer.Tone(FEHBuzzer::G5, 100);
        Buzzer.Tone(FEHBuzzer::F5, 100);
        Buzzer.Tone(FEHBuzzer::G5, 250);
        Buzzer.Tone(FEHBuzzer::F5, 100);
        Buzzer.Tone(FEHBuzzer::E5, 1000);
    }
}