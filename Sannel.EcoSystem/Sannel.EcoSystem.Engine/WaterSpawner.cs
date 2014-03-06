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
		public byte GeneratePrecentage
		{
			get { return 64; }
		}

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

		public void Dispose()
		{
			
		}
	}
}
