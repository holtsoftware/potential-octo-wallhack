#include "pch.h"
#include "GrassSpawner.h"
#include "Grass.h"

namespace Sannel
{
	namespace EcoSystem
	{
		namespace Parts
		{
			GrassSpawner::GrassSpawner()
			{
			}


			GrassSpawner::~GrassSpawner()
			{
			}

			Uri^ GrassSpawner::ImageFile::get()
			{
				return imageUrl;
			}

			void GrassSpawner::ImageFile::set(Uri^ value)
			{
				imageUrl = value;
			}

			Sannel::EcoSystem::Interfaces::ITerrain ^GrassSpawner::Create(void)
			{
				auto g = ref new Grass(ImageFile, this);
				return g;
			}

		}
	}
}
