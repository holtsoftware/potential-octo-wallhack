using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sannel.EcoSystem.Interfaces
{
	public interface ITerrainSpawner : IDisposable
	{
		/// <summary>
		/// The Precentage chance of this terrain being generated 
		/// </summary>
		byte GeneratePrecentage
		{
			get;
		}

		Uri ImageFile
		{
			get;
			set;
		}

		ITerrain Create();
	}
}
