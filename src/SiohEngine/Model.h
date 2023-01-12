#ifndef SIOHENGINE_MODEL_H
#define SIOHENGINE_MODEL_H

#include <iostream>
#include "rend/rend.h"
#include <string>
#include "Component.h"
#include "Cache.h"

namespace SiohEngine
{
	struct ModelRenderer;

	struct Model : Resource
	{
		/**
		 * @brief A function to load a model onto the cache. Appends to m_model.
		 * @param _path The file path to search for the model
		*/
		void LoadModel(const std::string& _path);

		/**
		 * @brief A function that calls LoadModel using given path.
		*/
		void OnLoad();

	private:
		friend ModelRenderer;

		std::shared_ptr<rend::Model> m_model; ///< A pointer to the stored model
	};

}
#endif