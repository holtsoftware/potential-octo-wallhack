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
		public uint Min { get; set; }

		public uint Max { get; set; }

		public ITerrainSpawner Spawner { get; set; }
	}
}
