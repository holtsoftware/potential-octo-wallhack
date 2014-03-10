#include "pch.h"
#include "Grass.h"

using namespace Sannel::EcoSystem::Interfaces;

namespace Sannel
{
	namespace EcoSystem
	{
		namespace Parts
		{
			Grass::Grass(Uri^ image, ITerrainSpawner^ tSpawner)
			{
				this->imageFile = image;
				this->spawner = tSpawner;
			}

			Grass::~Grass()
			{

			}

			void Grass::Tick()
			{

			}
		}
	}
}
