#ifndef SIOHENGINE_MODELLOAD_H
#define SIOHENGINE_MODELLOAD_H

#include <iostream>
#include "rend/rend.h"
#include <string>
#include "Component.h"
#include "Cache.h"

namespace SiohEngine
{
	struct ModelLoad : Resource
	{
		/**
		 * @brief A getter for the stored model
		 * @return The stored model (m_model)
		*/
		rend::Model* GetRenderModel() { return m_model; }

		/**
		 * @brief A function to load a model onto the cache. Appends to m_model.
		 * @param _path The file path to search for the model
		*/
		void LoadModel(const std::string _path);

		/**
		 * @brief A function that calls LoadModel using given path.
		*/
		void OnLoad();

	private:
		rend::Model* m_model; ///< A pointer to the stored model
	};

}
#endif