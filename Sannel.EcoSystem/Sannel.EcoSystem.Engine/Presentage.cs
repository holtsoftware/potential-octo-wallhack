using Sannel.EcoSystem.Interfaces;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sannel.EcoSystem.Engine
{
	public class Presentage
	{
		public int Min { get; set; }

		public int Max { get; set; }

		public ITerrainSpawner Spawner { get; set; }
	}
}
