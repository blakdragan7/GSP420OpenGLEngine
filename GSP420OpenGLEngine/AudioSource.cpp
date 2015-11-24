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

#include "AudioSource.h"

#pragma once

using namespace std;


//GLOBAL VARIABLES
DWORD 	size, 
		sample_rate, 
		average_bytes_per_second, 
		data_size, chunk_data;
//these variables work with the types of sound data

short	format,
		channel,
		bits_per_sample,
		bytes_per_sample;
//the variables above help with various parts of the sound data

ALCdevice * device;
ALCcontext * context;
//above variables do stuff

FILE * 	source = NULL;	//This is the file "name", it's currently NULL until someone places a 
						//a sound file in it.

bool	looping; 	//The looping determines whether or not the sound is
					//suppose to loop or not.
			
char 	type_size[4];	//this helps determine the type of file the sound is coming from

unsigned char *buffer = new unsigned char[data_size];	 //this is to hold information for the sound data
	
//The ALuint and ALenum variables are in use for the audio buffer
ALuint	AL_source,
		AL_buffer,
		frequency = sample_rate;
			
ALenum	AL_format = 0;
	
ALfloat	SourcePos[] = {0.0, 0.0, 0.0},						
		SourceVel[] = {0.0, 0.0, 0.0},
		ListenerPos[] = {0.0, 0.0, 0.0},
		ListenerVel[] = {0.0, 0.0, 0.0},
		ListenerOri[] = {0.0, 0.0, -1.0, 0.0, 1.0, 0.0};
		//This helps the OpenAL know "where to play" the sound in
		//terms of position and velocity of the source as well as the
		//position, velocity, and orientation of the listener

//PUBLIC FUNCTIONS
void AudioSource::Load_Sound(FILE *source, short bits_per_sample, short channel, char type_size, bool looping)
{
	/**
	The purpose of this particular function is to make it easier for the user
	to load the sound file before playing the file. That way the user would not have to 
	call various functions to open the sound file, initialize the OpenAL, load the sound file, and THEN play it.
	**/
	
	//Please uncomment the blocked comments below to open the new audio file.
	
	
	source = fopen("insert file name here", "rb"); //This is to open the sound file.
	bits_per_sample = 8;  //insert an integer here, either '8' or '16'
							//'bits_per_sample' determines which channel the game should focus on.
	
	channel = 1; //insert an integer here, either '1' or '2'
					//the 'channel' determines the format of the sound being played.
					
	looping = AL_FALSE;	//insert a boolean value, either 'AL_TRUE' or 'AL_FALSE'
						// 'looping' controls the looping of the sound file.
	
	
	Check_Sound(source, &type_size, size); 
	Read(chunk_data, format, channel, sample_rate,
			average_bytes_per_second, bytes_per_sample, bits_per_sample);
	File_Size(&type_size,data_size);
	
	//Initializing and working with OpenAL
	Initialize();
	Buffer_Sound(AL_source, AL_buffer);
	Format_Sound(bits_per_sample, channel);
	Load_Buffer(AL_buffer, format, buffer, data_size, frequency);
	Position_Sound(AL_source, *SourcePos, *SourceVel, 
		*ListenerPos, *ListenerOri, *ListenerVel, looping);
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

void AudioSource::Delete(FILE *source, ALuint AL_source, ALuint AL_buffer, unsigned char *buffer, ALCcontext *context, ALCdevice *device)
{
	fclose(source);
	delete[] buffer;
	alDeleteSources(1, &AL_source);
	alDeleteBuffers(1, &AL_buffer);
	alcMakeContextCurrent(NULL);
	alcDestroyContext(context);
	alcCloseDevice(device);
}


//PRIVATE FUNCTIONS

void AudioSource::Check_Sound(FILE *source, char type_size[], DWORD &size)
{
	fread(type_size,sizeof(char),4,source);
	
	if(type_size[0] != 'm' || type_size[1] != 'p' || type_size[2] != '3' ||
		type_size[3] != ' ')
		{
			endWithError((char*)"Not MP3");
		}
	fread(&size, sizeof(DWORD), 1, source);
	fread(type_size, sizeof(char), 4, source);
	
	if(type_size[0] != 'W' || type_size[1] != 'A' || type_size[2] != 'V' ||
		type_size[3] != 'E')
		{
			return endWithError("Not WAVE");
		}
}
void AudioSource::Read(DWORD chunk_data, short format, short channel, DWORD sample_rate,
			DWORD average_bytes_per_second, short bytes_per_sample, short bits_per_sample)
{
	fread(&chunk_data, sizeof(DWORD), 1, source);
	fread(&format, sizeof(short), 1, source);
	fread(&channel, sizeof(short), 1, source);
	fread(&sample_rate,sizeof(DWORD),1, source);
	fread(&average_bytes_per_second, sizeof(DWORD),1, source);
	fread(&bytes_per_sample, sizeof(short), 1, source);
	fread(&bits_per_sample, sizeof(short), 1, source);
}
void AudioSource::File_Size(char type_size[], DWORD data_size)
{
	fread(type_size, sizeof(char),4, source);
	
	if(type_size[0] != 'D' || type_size[1] != 'A' || type_size[2] != 'T' ||
		type_size[3] != 'A')
		{
			return endWithError("Not DATA");
		}
	fread(&data_size, sizeof(DWORD), 1, source);
	
	unsigned char *buffer = new unsigned char [data_size];
	fread(buffer, sizeof(BYTE),data_size, source);
}
	
	//Initializing and working with OpenAL
void AudioSource::Initialize()
{
	
	device = alcOpenDevice(NULL);
	if(!device)
	{
		return endWithError("no sound device");
	}
	
	context = alcCreateContext(device, NULL);
	alcMakeContextCurrent(context);
	if(!context)
	{
		return endWithError("no sound context");
	}
}
void AudioSource::Buffer_Sound(ALuint AL_source, ALuint AL_buffer)
{
	alGenBuffers(1, &AL_buffer);
	alGenSources(1, &AL_source);
}
void AudioSource::Format_Sound(short bits_per_sample, short channel)
{
	if(bits_per_sample == 8)
	{
		if(channel == 1)
		{
			format = AL_FORMAT_MONO8;
		}
		else if(channel == 2)
		{
			format = AL_FORMAT_STEREO8;
		}
	}
	else if(bits_per_sample == 16)
	{
		if(channel == 1)
		{
			format = AL_FORMAT_MONO16;
		}
		else if(channel == 2)
		{
			format = AL_FORMAT_STEREO16;
		}	
	}
}
void AudioSource::Load_Buffer(ALuint AL_buffer, short format, unsigned char *buffer, DWORD data_size, ALuint frequency)
{
	alBufferData(AL_buffer, format, &buffer, data_size, frequency);
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
exit(0);
}
