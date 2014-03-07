#pragma once

using namespace Sannel::EcoSystem::Interfaces;
using namespace Windows::Foundation;

namespace Sannel
{
	namespace EcoSystem
	{
		namespace Parts
		{
			ref class Grass sealed : 
			public Sannel::EcoSystem::Interfaces::ITerrain
			{
			internal:
				Grass(Uri^ image, ITerrainSpawner^ tSpawner);

			public:
				virtual ~Grass();

				virtual property byte Water{
					byte get(){
						return 40;
					}
				}

				virtual property byte WaterQuality{
					byte get(){
						return 20;
					}
				}

				virtual property byte Sun{
					byte get(){
						return sun;
					}
					void set(byte value){
						sun = value;
					}
				}

				virtual property Windows::Foundation::Uri^ ImageFile{
					Windows::Foundation::Uri^ get()
					{
						return imageFile;
					}

					void set(Windows::Foundation::Uri^ value)
					{
						imageFile = value;
					}
				}

				virtual property ITerrainSpawner^ Spawner
				{
					ITerrainSpawner^ get()
					{
						return spawner;
					}
				}

			private:
				byte sun;
				Windows::Foundation::Uri^ imageFile;
				ITerrainSpawner^ spawner;
			};
		}
	}
}

