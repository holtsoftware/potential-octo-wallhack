#pragma once
namespace Sannel
{
	namespace EcoSystem
	{
		namespace Parts
		{
			ref class Grass sealed : 
			public Sannel::EcoSystem::Interfaces::ITerrain
			{
			public:
				Grass();
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

			private:
				byte sun;
				Windows::Foundation::Uri^ imageFile;
			};
		}
	}
}

