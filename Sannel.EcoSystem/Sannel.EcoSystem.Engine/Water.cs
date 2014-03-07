using Sannel.EcoSystem.Interfaces;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sannel.EcoSystem.Engine
{
	public class Water : ITerrain
	{
		byte ITerrain.Water
		{
			get { return byte.MaxValue; }
		}

		public byte WaterQuality
		{
			get { return 0; }
		}

		public byte Sun
		{
			get;
			set;
		}

		public Uri ImageFile
		{
			get;
			set;
		}

		public void Dispose()
		{
		}


		public ITerrainSpawner Spawner
		{
			get;
			set;
		}
	}
}
