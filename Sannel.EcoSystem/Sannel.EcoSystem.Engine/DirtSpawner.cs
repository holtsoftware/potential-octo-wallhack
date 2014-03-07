using Sannel.EcoSystem.Interfaces;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sannel.EcoSystem.Engine
{
	public class DirtSpawner : ITerrainSpawner
	{

		public Uri ImageFile
		{
			get;
			set;
		}

		public ITerrain Create()
		{
			return new Dirt()
			{
				ImageFile = ImageFile
			};
		}

		public void Dispose()
		{
		}


		public GenerationShape Shape
		{
			get { return GenerationShape.OneTile; }
		}

		public float GenerationPrecentage
		{
			get { return 1f; }
		}


		public byte ShapeSize
		{
			get { return 1; }
		}
	}
}
