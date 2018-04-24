#include <cs50.h>
#include <math.h> //pow - exponents
#include <stdio.h>
#include <stdlib.h> //atoi - converts str to int
#include <string.h>
#include "helpers.h"

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    char letter = note[0]; //the ASCII char for the given note

    int octave;
    int accidental = 0;
    int noteLength =  strlen(note);

    float letterHz = 0.00;
    float accidentalHz = 0.0;
    float accidentalTotalHz;
    float octaveHz;

    if (noteLength == 3)
    {
        octave = note[2];
        accidental = note[1];
    }
    else
    {
        octave = note[1];
    }

    switch (letter)
    //pow - for exponents
    {
        case 65 : //for ASCII note 65 --> A
            letterHz = 440; //HZ is 440
            break;
        case 66 : //for note B
            letterHz = 440 * pow(2, 2. / 12); //mulitply 2 to the power of 2/12
            break;
        case 67 : //for note C
            letterHz = 440 * pow(2, 9. / 12); //multiply 2 to the power of 9/12
            break;
        case 68 : //for note D
            letterHz = 440 * pow(2, 7. / 12); //multiply 2 to the power of 7/12
            break;
        case 69 : //for note E
            letterHz = 440 * pow(2, 5. / 12); //multiply 2 to the power of 5/12
            break;
        case 70 : //for note F
            letterHz = 440 * pow(2, 4. / 12); //multiply 2 to the power of 4/12
            break;
        case 71 : //for note G
            letterHz = 440 * pow(2, 2. / 12); //multiply 2 to the power of 2/12
            break;
    }

    // if statements for accidentals
    if (accidental == 35) // char 35 --> # sharp
    {
        accidentalHz = letterHz * pow(2, 1. / 12);
        accidentalTotalHz = accidentalHz;
    }
    else if (accidental == 98) // char 98 --> b flat
    {
        accidentalHz = letterHz / pow(2, 1. / 12);
        accidentalTotalHz = accidentalHz;
    }
    else
    {
        accidentalTotalHz = letterHz;
    }

    switch (octave)
    {
        case 52 : //char 52 --> 4 for 4th octave
            octaveHz = accidentalTotalHz;
            break;
        case 51 : //char 51 --> 3 for 3rd octave
            octaveHz = accidentalTotalHz / 2.;
            break;
        case 50 : //char 50 --> 2 for 2nd octave
            octaveHz = accidentalTotalHz / 4.;
            break;
        case 49 : //char 49 --> 1 for 1st octave
            octaveHz = accidentalTotalHz / 8.;
            break;
        case 53 : //char 53 --> 5 for 5th octave
            octaveHz = accidentalTotalHz / 2.;
            break;
        case 54 : //char 54 --> 6 for 6th octave
            octaveHz = accidentalTotalHz / 4.;
            break;
        case 55 : //char 55 --> 7 for 7th octave
            octaveHz = accidentalTotalHz / 8.;
            break;
        case 56 : //char 56 --> 8 for 8th octave
            octaveHz = accidentalTotalHz / 16.;
    }

    int ret = lroundf(octaveHz);
    return ret;
    // printf("%i\n, octave); testing octave numbers

}