// Helper functions for music
//Peer review comments signed MAN by Michael A. Nowiszewski
// Excellent code breakdown - very organized, logical layout. Clean code. I enjoyed how you broke it down into individual modules here in order to understand it prior to combining all three functions in helpers.c! -MAN
// Also thought your use of printfs along the way was a useful tool for self check. Saw this and mentioned it in class prior to being teamed up! - MAN
// Included one or two small notes - great job G! Passes all checks for style50 and check50, makes and plays BDAY.txt accurately as well! - MAN
#include <cs50.h>
#include <math.h> //pow - exponents
#include <stdio.h>
#include <stdlib.h> //atoi - converts str to int
#include <string.h>
#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string test)
{
    int numerator = atoi(&test[0]);
    int denominator = atoi(&test[2]);

    // for the above data, the demoninator determines what to do with the numerator to return "number of eight notes"

    switch (denominator)
    {
        case 8 :
            return numerator;
        case 4 :
            return numerator * 2;
        case 2 :
            return numerator * 4;
    }

    printf("The number of eights is %i\n", numerator);

    return numerator;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    int letter = note[0]; //the ASCII char for the given note, used in the switch logic below

    int octave;  //initialize octave
    int accidental = 0; //accidental starts at 0
    int noteLength =  strlen(note); //length of the note string (should be less than 3)

    float letterHz = 0.00; //Hz for given letter starts at 0.00
    float accidentalHz = 0.0; //Hz for accidental starts at 0.0
    float accidentalTotalHz; //place to hold the total hz for all accidentals for a note
    float octaveHz; //hz of the octave

    // based on how long the input is, we know if there is an accidental or not
    if (noteLength == 3)
    {
        octave = note[2]; //the octave is in position 2
        accidental = note[1]; //the acciental is in position 1
    }
    else
    {
        octave = note[1]; //only have to factor in the octave, bc no accidentals
    }

    //first switch statement handles frequency of ONLY notes A - G (no accidentals or octaves yet)
    switch (letter)
    {
        case 'A' : //for note 65 --> A
            letterHz = 440; //HZ is 440, the base for the functions below
            // printf("The Hz at A %f\n", letterHz);
            break;
        case 'B' : //for note B
            letterHz = 440. * pow(2, 2. / 12); //mulitply 2 to the power of 2/12
            break;
        case 'C' : //for note C
            letterHz = 440. / pow(2.00, 9.00 / 12); //multiply 2 to the power of 9/12 // Do we need the ".00" here? - MAN
            // printf("The Hz at C %f\n", letterHz);
            break;
        case 'D' : //for note D
            letterHz = 440. / pow(2, 7. / 12); //multiply 2 to the power of 7/12
            break;
        case 'E' : //for note E
            letterHz = 440. / pow(2, 5. / 12); //multiply 2 to the power of 5/12
            break;
        case 'F' : //for note F
            letterHz = 440. / pow(2, 4. / 12); //multiply 2 to the power of 4/12
            break;
        case 'G' : //for note G
            letterHz = 440. / pow(2, 2. / 12); //multiply 2 to the power of 2/12
            break;
    }

    // if statements for accidentals
    if (accidental == 35) // char 35 --> # sharp
    {
        accidentalHz = letterHz * pow(2, 1. / 12);
        accidentalTotalHz = accidentalHz;
    }
    else if (accidental == 98) // char 98 --> b flat // Neat way to adjust for accidentals! -MAN
    {
        accidentalHz = letterHz / pow(2, 1. / 12);
        accidentalTotalHz = accidentalHz;
    }
    else
    {
        accidentalTotalHz = letterHz;
        // printf("The Hz for accidentals %f\n", letterHz); // Big fan of the printf self checks! Our 'console.log' in C!! - MAN
    }

    // switch statement for octave
    switch (octave)
    {
        case '4' : // 4th octave
            octaveHz = accidentalTotalHz;
            break;
        case '3' : // 3rd octave
            octaveHz = accidentalTotalHz / 2.;
            break;
        case '2' : // 2nd octave
            octaveHz = accidentalTotalHz / 4.;
            break;
        case '1' : // 1st octave
            octaveHz = accidentalTotalHz / 8.;
            break;
        case '5' : //5th octave
            octaveHz = accidentalTotalHz * 2.; // Good use of switch statements to move between octaves and adjust! - MAN
            break;
        case '6' : //6th octave
            octaveHz = accidentalTotalHz * 4.;
            // printf("The Hz of the octave is: %f\n", octaveHz);
            break;
        case '7' : //7th octave
            octaveHz = accidentalTotalHz * 8.;
            break;
        case '8' : //8th octave
            octaveHz = accidentalTotalHz * 16.;
    }

    int ret = lroundf(octaveHz); //outputs the rounded frequency of the note in Hz
    // printf("The rounded frequency of the given note in HZ %i\n", ret);
    return ret;
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    string checking = "";
    if (strcmp(s, checking) == 0) //if a line in the string is an empty new line (aka a rest)
    {
        return true;
    }
    else
    {
        return false;
    }
}
