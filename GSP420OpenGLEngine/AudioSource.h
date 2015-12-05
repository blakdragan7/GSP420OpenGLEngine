#pragma once

#include <Windows.h>
#include <AL/al.h>
#include <AL/alc.h>

class AudioSource
{
private:
	ALuint	AL_source;
	ALuint  AL_buffer;
	ALenum	AL_format;
	FILE *source;

	ALuint frequency;
	unsigned char* buffer;

	
DWORD 	size /*varies depending on audio file*/, 
		sample_rate, 
		block_align,
		average_bytes_per_second,
		data_size /*varies depending on audio file*/, 
		chunk_data;
//these variables work with the types of sound data
short
		channel,
		bits_per_sample,
		bytes_per_sample;

private:
	//Functions
	void Initialize();	//Initializing and working with OpenAL
	void Buffer_Sound(const char* fileName);	//This is to create a place (source) to play the sound and the buffer is to store the sound data
	void Position_Sound(ALuint AL_source, ALfloat SourcePos, ALfloat SourceVel, 
					ALfloat ListenerPos, ALfloat ListenerOri, ALfloat ListenerVel, bool looping);	//This function utilizes the position of the sound in reference to the listener
	
	
	void endWithError(char *message); //Error Message function
	
	public:
	//Variables

	char* filename;
	bool looping;
	int volume;

	/**
	THESE ARE THE FUNCTIONS YOU CAN USE FOR THE GAME ENGINE
	EVERYTHING ELSE IS PRIVATE TO THE CLASS ONLY
	**/
	//Functions
	AudioSource();
	~AudioSource();
	
	void Load(char* filename, bool looping);
	/*The function above is to be the first step of four for the main game engine when it comes to the audio core.
	The first step is to open and load the sound file into the system. */
	void Play_Sound();
	//After opening and loading the sound file, you are ready to start playing the sound file.
	void Pause();
	//If the player decides to pause the game, this function is to pause the sound file while it's playing.
	void Stop();
	//If the player wants to stop the audio, then this function does the job
	void Volume(int volume);
	//If the player wants to increase or lower volume, then this will help
	void Delete();
	/*Finally after playing the game, just about everything is deleted and erased from memory; 
		this includes: the OpenAL device and the sound files */
	
};

