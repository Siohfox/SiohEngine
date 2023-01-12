#ifndef SIOHENGINE_AUDIOSOURCE_H
#define SIOHENGINE_AUDIOSOURCE_H

#include "Component.h"
#include "AudioClip.h"
#include <string>
#include <vector>
#include <AL/al.h>
#include <AL/alc.h>

namespace SiohEngine
{
	struct AudioSource : Component
	{
		/**
		 * @brief Audio source constructor
		*/
		AudioSource();
		
		/**
		 * @brief A getter for the source Id
		 * @return The source Id
		*/
		ALuint GetSourceId() { return m_sourceId; }

		/**
		 * @brief Plays a sound at the audio source with a given sound clip
		 * @param clip The audio clip to play
		 * @param volume How loud to play the clip (0.0f - 1.0f)
		*/
		void PlaySound(std::shared_ptr<AudioClip> clip, ALfloat volume);

	private:
		ALuint m_sourceId; ///< The audio source Id
	};
}
#endif