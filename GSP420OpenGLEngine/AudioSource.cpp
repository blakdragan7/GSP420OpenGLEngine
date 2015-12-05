/***************************
Object Name: This is the code for the Audio Core of the Engine Project
Description: The goal is to create a single class that will create sounds
			 whenever the actual game engine calls for them.
Create Date:  November 11, 2015
Modification (Use IDs):
*ID 1: 
***************************/
#include <cstdlib>
#include <iostream>
#include <windows.h>
#include <Al\alut.h>

#include "Engine.h"
#include "AudioSource.h"

#pragma once

using namespace std;

static bool isInit = false;

//above variables do stuff
	
ALfloat	SourcePos[] = {0.0, 0.0, 0.0},						
		SourceVel[] = {0.0, 0.0, 0.0},
		ListenerPos[] = {0.0, 0.0, 0.0},
		ListenerVel[] = {0.0, 0.0, 0.0},
		ListenerOri[] = {0.0, 0.0, -1.0, 0.0, 1.0, 0.0};
		//This helps the OpenAL know "where to play" the sound in
		//terms of position and velocity of the source as well as the
		//position, velocity, and orientation of the listener

//PUBLIC FUNCTIONS
AudioSource::AudioSource()
{ 
	AL_format = AL_FORMAT_MONO8;
	looping = AL_FALSE; //The looping determines whether or not the sound is supposed to loop or not. It's set to AL_FALSE as default.

	Initialize();
}


AudioSource::~AudioSource()
{
}

void AudioSource::Load(char* filename, bool looping)
{
	Buffer_Sound(filename);
	Position_Sound(AL_source, *SourcePos, *SourceVel, *ListenerPos, *ListenerOri, *ListenerVel, looping);
}


void AudioSource::Play_Sound()
{
	//This is the simplest part of the entire class. Simply play the sound file.
	alSourcePlay(AL_source);
}

void AudioSource::Pause()
{
	//This is just as simple. Just pause the selected sound file whenever desired.
	alSourcePause(AL_source);
}

void AudioSource::Stop()
{
	//This is a simple function to stop the audio.
	alSourceStop(AL_source);
}

void AudioSource::Volume(int volume)
{
	//The purpose of this function is to give you the ability to change the volume of an asset.
	//For instance, if we were to have a volume slider built in the game in the options menu; the slider will 
	//control the volume of the background music. 
	//Another example is the variety of volumes set manually within the code.
	switch(volume)
	{
	case '0':
		alSourcef(AL_source, AL_GAIN, 0.0f);
		break;
	case '10':
		alSourcef(AL_source, AL_GAIN, 0.1f);
		break;
	case '20':
		alSourcef(AL_source, AL_GAIN, 0.2f);
		break;
	case '30':
		alSourcef(AL_source, AL_GAIN, 0.3f);
		break;
	case '40':
		alSourcef(AL_source, AL_GAIN, 0.4f);
		break;
	case '50':
		alSourcef(AL_source, AL_GAIN, 0.5f);
		break;
	case '60':
		alSourcef(AL_source, AL_GAIN, 0.6f);
		break;
	case '70':
		alSourcef(AL_source, AL_GAIN, 0.7f);
		break;
	case '80':
		alSourcef(AL_source, AL_GAIN, 0.8f);
		break;
	case '90':
		alSourcef(AL_source, AL_GAIN, 0.9f);
		break;
	case '100':
		alSourcef(AL_source, AL_GAIN, 1.0f);
		break;
	default:
		alSourcef(AL_source, AL_GAIN, 1.0f);
	}
}

void AudioSource::Delete()
{
	fclose(source);
	delete[] buffer;
	alDeleteSources(1, &AL_source);
	alDeleteBuffers(1, &AL_buffer);
}

//Initializing and working with OpenAL
void AudioSource::Initialize()
{
	if(!isInit)
	{
		isInit = alutInit(&Engine::argc,(char**)Engine::argv);
	}
}
void AudioSource::Buffer_Sound(const char* fileName)
{
	AL_buffer = alutCreateBufferFromFile(fileName);
	ALenum err = alutGetError();
	if(err != AL_NO_ERROR)
	{
		cout << "Error Creating Buffer " << alutGetErrorString(err) << endl;
	}

	alGenSources(1, &AL_source);

	err = alGetError();
	if(err != AL_NO_ERROR)
	{
		cout << "Error Creating Source " << err << endl;
	}
}

void AudioSource::Position_Sound(ALuint AL_source, ALfloat SourcePos, ALfloat SourceVel, 
					ALfloat ListenerPos, ALfloat ListenerOri, ALfloat ListenerVel, bool looping)
{
	alListenerfv(AL_POSITION, &ListenerPos);
	alListenerfv(AL_VELOCITY, &ListenerVel);
	alListenerfv(AL_ORIENTATION, &ListenerOri);
	
	alSourcei(AL_source, AL_BUFFER, AL_buffer);
	alSourcef(AL_source, AL_PITCH, 1.0f);
	alSourcef(AL_source, AL_GAIN, 1.0f);
	alSourcefv(AL_source, AL_POSITION, &SourcePos);
	alSourcefv(AL_source, AL_VELOCITY, &SourceVel);
	alSourcei(AL_source, AL_LOOPING, looping);
	//All of these aligns the variables to the OpenAL variables in regards to position and location
}					


void AudioSource::endWithError(char *message)
{
	cout << message << "\n";
}

/*

THIS IS HOW YOU UTILIZE THE SOUND FILES AND AUDIO CORE
DO NOT UNCOMMENT UNLESS YOU WANT TO MAKE CHANGES

int main(int argc, char *argv[])
{
	AudioSource example; 
	example.Load("hello.wav",AL_FALSE);

	[insert button mechanic]
	[detect if button has been clicked]
	[if button is clicked then play sound]

	example.Play_Sound();

	[if you need to pause or mute the sound, click a button to pause]
	example.Pause();

	[Once game is over or button clicked, then stop or delete the sound]
	example.Stop();
	example.Delete();

	//***Volume only varies with how you use it.
	example.Volume(10);
}
*/