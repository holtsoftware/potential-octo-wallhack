#pragma once
using namespace Windows::Foundation;

namespace Sannel
{
	namespace EcoSystem
	{
		namespace Parts
		{
			public ref class GrassSpawner sealed :
				public Sannel::EcoSystem::Interfaces::ITerrainSpawner
			{
			public:
				GrassSpawner();
				virtual ~GrassSpawner();

				virtual property Uri^ ImageFile
				{
					Uri^ get();
					void set(Uri^ value);
				}

				virtual property float GenerationPrecentage
				{
					float get(){
						return 0.10f;
					}
				}

				virtual property Sannel::EcoSystem::Interfaces::GenerationShape Shape{
					Sannel::EcoSystem::Interfaces::GenerationShape get()
					{
						return Sannel::EcoSystem::Interfaces::GenerationShape::OneTile;
					}
				}

				virtual property byte ShapeSize{
					byte get(){
						return 1;
					}
				}

				virtual Sannel::EcoSystem::Interfaces::ITerrain^ Create(void);
				/*	public ITerrain Create()
				{
				return new Water()
				{
				ImageFile = ImageFile
				};
				}



				public byte ShapeSize
				{
				get{ return 2; }
				}*/

			private:
				Uri^ imageUrl;
			};
		}
	}
}

