using Sannel.EcoSystem.Interfaces;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sannel.EcoSystem.Engine
{
	public class WaterSpawner : ITerrainSpawner
	{
		public Uri ImageFile
		{
			get;
			set;
		}

		public ITerrain Create()
		{
			return new Water()
			{
				ImageFile = ImageFile
			};
		}


		public GenerationShape Shape
		{
			get { return GenerationShape.Square; }
		}

		public float GenerationPrecentage
		{
			get { return 0.005f; }
		}

		public void Dispose()
		{
		}


		public byte ShapeSize
		{
			get { return 2; }
		}
	}
}
