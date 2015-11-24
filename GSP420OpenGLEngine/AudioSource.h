#pragma once

#include <AL/al.h>
#include <AL/alc.h>

class AudioSource
{
	private:
	//Functions
	void Check_Sound(FILE *source, char type_size[], DWORD &size);	//This is to check if the sound file is an acceptable sound file type.
	void Read(DWORD chunk_data, short format, short channel, DWORD sample_rate,
			DWORD average_bytes_per_second, short bytes_per_sample, short bits_per_sample);	//This reads and stores the information into the sound file.
	void File_Size(char type_size[], DWORD data_size);	//This is to check to see if the sound data is the right file size
	
	
	void Initialize();	//Initializing and working with OpenAL
	void Buffer_Sound(ALuint AL_source, ALuint AL_buffer);	//This is to create a place (source) to play the sound and the buffer is to store the sound data
	void Format_Sound(short bits_per_sample, short channel);	//This determines which format you want to use for your sound
	void Load_Buffer(ALuint AL_buffer, short format, unsigned char *buffer, DWORD data_size, ALuint frequency);	//Afterwards, we need to load the sound file to the buffer
	void Position_Sound(ALuint AL_source, ALfloat SourcePos, ALfloat SourceVel, 
					ALfloat ListenerPos, ALfloat ListenerOri, ALfloat ListenerVel, bool looping);	//This function utilizes the position of the sound in reference to the listener
					
	void endWithError(char *message); //Error Message function
	
	public:
	/**
	THESE ARE THE FUNCTIONS YOU CAN USE FOR THE GAME ENGINE
	EVERYTHING ELSE IS PRIVATE TO THE CLASS ONLY
	**/
	//Functions
	void Load_Sound(FILE *source, short bits_per_sample, short channel, char type_size, bool looping);
	/*The function above is to be the first step of four for the main game engine when it comes to the audio core.
	The first step is to open and load the sound file into the system.*/
	void Play_Sound();
	//After opening and loading the sound file, you are ready to start playing the sound file.
	void Pause();
	//If the player decides to pause the game, this function is to pause the sound file while it's playing.
	void Delete(FILE *source, ALuint AL_source, ALuint AL_buffer, unsigned char *buffer, ALCcontext *context, ALCdevice *device);
	/*Finally after playing the game, just about everything is deleted and erased from memory; 
		this includes: the OpenAL device and the sound files */
	
};