#ifndef SIOHENGINE_AUDIOCLIP_H
#define SIOHENGINE_AUDIOCLIP_H

#include <iostream>
#include <vector>
#include <stdexcept>
#include <AL/al.h>
#include <AL/alc.h>

namespace SiohEngine
{
	struct AudioSource;

	//! A container for audio data
	/*! An audio clip stores the audio file as an ogg vorbis*/

	struct AudioClip
	{
		AudioClip();
		 
		/**
		 * @brief A getter for the buffer Id
		 * @return The stored buffer Id
		*/
		ALuint GetBufferId() { return m_bufferId; }

		/**
		 * @brief Loads an ogg vorbis audio file from a directory path
		 * @param _path The file name to be processed
		 * @param _buffer The data to be buffered
		 * @param _format The format of audio
		 * @param _freq The frequency of audio
		*/
		static void load_ogg(const std::string& _path, std::vector<unsigned char>& _buffer,
			ALenum& _format, ALsizei& _freq);

	private:
		ALenum m_format; ///< Stored audio format 
		ALsizei m_freq; ///< Stored audio frequency
		ALuint m_bufferId; ///< Stored buffer Id
	};
}
#endif