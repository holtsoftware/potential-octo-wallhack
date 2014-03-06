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
		public byte GeneratePrecentage
		{
			get { return byte.MaxValue; }
		}

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
	}
}
